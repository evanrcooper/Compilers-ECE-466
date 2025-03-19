%{
    #include "parser.tab.h"
    int yylex(void);
    extern FILE *yyin;
%}

%code requires {
    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(const char *s);
}

%define parse.trace

%union {
    char *str_val;
    long long int_val;
    long double real_val;
    char char_val;
    D_STRING d_str_val;
    ast_node* node;
}

%token IDENT NUMLIT CHARLIT STRLIT FLOATLIT
%token PLUSPLUS MINUSMINUS
%token INDSEL
%token SHL SHR
%token GEQ LEQ EQEQ NEQ
%token LOGAND LOGOR
%token TIMESEQ PLUSEQ XOREQ MINUSEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ

%token ELLIPSIS
%token AUTO
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE

%token _BOOL _COMPLEX _IMAGINARY

%type <node> primary-expression 
%type <node> postfix-expression 
%type <node> unary-expression
%type <node> cast-expression
%type <node> multiplicative-expression
%type <node> additive-expression
%type <node> shift-expression
%type <node> relational-expression
%type <node> equality-expression
%type <node> bitand-expression
%type <node> bitxor-expression
%type <node> bitor-expression
%type <node> logand-expression
%type <node> logor-expression
%type <node> conditional-expression
%type <node> assignment-expression
%type <node> expression
/* %type <node> constant-expression */
%type <node> expression-stmt
%type <node> ident-expr

%%

/* C-99 Standard: http://faculty.cooper.edu/hak/ece466/n1124.pdf */
/* See Page 415 */

/* 6.5 EXPRESSIONS */

program:
    /* empty */
    | expression-stmt program

ident-expr:
    IDENT {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = AST_IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        $$ = ident_node;
    }

primary-expression:
    ident-expr {$$ = $1;}
    | NUMLIT {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = AST_NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        numlit_node->val.numlit.type = N_LLI;
        $$ = numlit_node;
    }
    | FLOATLIT {
        ast_node *flit_node = calloc(1, sizeof(ast_node));
        flit_node->node_type = AST_NUMLIT;
        flit_node->val.numlit.val.real_val = yylval.real_val;
        flit_node->val.numlit.type = N_LLF;
        $$ = flit_node;
    }
    | CHARLIT {
        ast_node *charlit_node = calloc(1, sizeof(ast_node));
        charlit_node->node_type = AST_CHARLIT;
        charlit_node->val.charlit.val = yylval.char_val;
        $$ = charlit_node;
    }
    | STRLIT {
        ast_node *strlit_node = calloc(1, sizeof(ast_node));
        strlit_node->node_type = AST_NUMLIT;
        strlit_node->val.strlit.val = yylval.d_str_val.str_val;
        strlit_node->val.strlit.len = yylval.d_str_val.str_len;
        $$ = strlit_node;
    }
    | '(' expression ')' {$$ = $2;}

postfix-expression:
    primary-expression {$$ = $1;}
    | postfix-expression '[' expression ']' {
        $$ = create_unop_node(U_DEREF, create_binop_node(B_PLUS, $1, $3));
    }
    /* | postfix-expression '(' argument-expression-list-opt ')' {} */
    | postfix-expression '.' ident-expr {create_binop_node(B_STRUCT_OFFSET, $1, $3);}
    | postfix-expression INDSEL ident-expr {create_binop_node(B_INDSEL, $1, $3);}
    | postfix-expression PLUSPLUS {$$ = create_unop_node(U_POST_PLUSPLUS, $1);}
    | postfix-expression MINUSMINUS {$$ = create_unop_node(U_POST_MINUSMINUS, $1);}
    /* | '(' type-name ')' '{' initializer-list '}' */
    /* | '(' type-name ')' '{' initializer-list ',' '}' */

/* argument-expression-list-opt: */
    /* empty */
    /* | argument-expression-list */

/*
argument-expression-list:
    assignment-expression
    | argument-expression-list ',' assignment-expression
*/

unary-expression:
    postfix-expression {$$ = $1;}
    | PLUSPLUS unary-expression {$$ = create_unop_node(U_PRE_PLUSPLUS, $2);}
    | MINUSMINUS unary-expression {$$ = create_unop_node(U_PRE_MINUSMINUS, $2);}
    | '&' cast-expression {$$ = create_unop_node(U_ADDRESSOF, $2);}
    | '*' cast-expression {$$ = create_unop_node(U_DEREF, $2);}
    | '+' cast-expression {$$ = create_unop_node(U_POS, $2);}
    | '-' cast-expression {$$ = create_unop_node(U_NEG, $2);}
    | '~' cast-expression {$$ = create_unop_node(U_BIT_NOT, $2);}
    | '!' cast-expression {$$ = create_unop_node(U_NOT, $2);}
    /* | SIZEOF unary-expression */
    /* | SIZEOF '(' type-name ')' */

cast-expression:
    unary-expression {$$ = $1;}
    /* | '(' type-name ')' cast-expression */

multiplicative-expression:
    cast-expression {$$ = $1;}
    | multiplicative-expression '*' cast-expression {$$ = create_binop_node(B_TIMES, $1, $3);}
    | multiplicative-expression '/' cast-expression {$$ = create_binop_node(B_DIVIDE, $1, $3);}
    | multiplicative-expression '%' cast-expression {$$ = create_binop_node(B_MOD, $1, $3);}

additive-expression:
    multiplicative-expression {$$ = $1;}
    | additive-expression '+' multiplicative-expression {$$ = create_binop_node(B_PLUS, $1, $3);}
    | additive-expression '-' multiplicative-expression {$$ = create_binop_node(B_MINUS, $1, $3);}

shift-expression:
    additive-expression {$$ = $1;}
    | shift-expression SHL additive-expression {$$ = create_binop_node(B_SHL, $1, $3);}
    | shift-expression SHR additive-expression {$$ = create_binop_node(B_SHR, $1, $3);}

relational-expression:
    shift-expression {$$ = $1;}
    | relational-expression '<' shift-expression {$$ = create_binop_node(B_LT, $1, $3);}
    | relational-expression '>' shift-expression {$$ = create_binop_node(B_GT, $1, $3);}
    | relational-expression LEQ shift-expression {$$ = create_binop_node(B_LTEQ, $1, $3);}
    | relational-expression GEQ shift-expression {$$ = create_binop_node(B_GTEQ, $1, $3);}

equality-expression:
    relational-expression {$$ = $1;}
    | equality-expression EQEQ relational-expression {$$ = create_binop_node(B_EQEQ, $1, $3);}
    | equality-expression NEQ relational-expression {$$ = create_binop_node(B_NOTEQ, $1, $3);}

bitand-expression: /* AND-expression */
    equality-expression {$$ = $1;}
    | bitand-expression '&' equality-expression {$$ = create_binop_node(B_BIT_AND, $1, $3);}

bitxor-expression: /* exclusive-OR-expression */
    bitand-expression {$$ = $1;}
    | bitxor-expression '^' bitand-expression {$$ = create_binop_node(B_BIT_XOR, $1, $3);}

bitor-expression: /* inclusive-OR-expression */
    bitxor-expression {$$ = $1;}
    | bitor-expression '|' bitxor-expression {$$ = create_binop_node(B_BIT_OR, $1, $3);}

logand-expression: /* logical-AND-expression */
    bitor-expression {$$ = $1;}
    | logand-expression LOGAND bitor-expression {$$ = create_binop_node(B_LOG_AND, $1, $3);}

logor-expression: /* logical-OR-expression */
    logand-expression {$$ = $1;}
    | logor-expression LOGOR logand-expression {$$ = create_binop_node(B_LOG_OR, $1, $3);}

conditional-expression:
    logor-expression {$$ = $1;}
    | logor-expression '?' expression ':' conditional-expression {$$ = create_triop_node(T_TERNARY, $1, $3, $5);}

assignment-expression:
    conditional-expression {$$ = $1;}
    | unary-expression '=' assignment-expression {$$ = create_binop_node(B_EQ, $1, $3);}
    | unary-expression TIMESEQ assignment-expression {$$ = create_binop_node(B_TIMESEQ, $1, $3);}
    | unary-expression DIVEQ assignment-expression {$$ = create_binop_node(B_DIVEQ, $1, $3);}
    | unary-expression MODEQ assignment-expression {$$ = create_binop_node(B_MODEQ, $1, $3);}
    | unary-expression PLUSEQ assignment-expression {$$ = create_binop_node(B_PLUSEQ, $1, $3);}
    | unary-expression MINUSEQ assignment-expression {$$ = create_binop_node(B_MINUSEQ, $1, $3);}
    | unary-expression SHLEQ assignment-expression {$$ = create_binop_node(B_SHLEQ, $1, $3);}
    | unary-expression SHREQ assignment-expression {$$ = create_binop_node(B_SHREQ, $1, $3);}
    | unary-expression ANDEQ assignment-expression {$$ = create_binop_node(B_BIT_ANDEQ, $1, $3);}
    | unary-expression OREQ assignment-expression {$$ = create_binop_node(B_BIT_OREQ, $1, $3);}
    | unary-expression XOREQ assignment-expression {$$ = create_binop_node(B_BIT_XOREQ, $1, $3);}

expression:
    assignment-expression {$$ = $1;}
    | expression ',' assignment-expression {$$ = create_binop_node(B_ASSIGN_LIST, $1, $3);}

/* 6.6 CONSTANT EXPRESSIONS */
/* constant-expression:
    conditional-expression {$$ = $1;} */

expression-stmt:
    expression ';' {
        print_ast_tree($1);
        $$ = $1;
    }

%%

int main() {
    yydebug = 0;
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

