%{
    #include "parser.tab.h"
    int yylex(void);
    extern FILE *yyin;
    struct symbol_table_dll_node *CURRENT_SCOPE;
    struct type_builder CURRENT_TYPE_BUILDER = {0};
    int CURRENT_STORAGE_CLASS = 0;
%}

%code requires {
    #include "ast.h"
    #include "../SymbolTable/sym_tab.h"
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

%token _BOOL
%token _COMPLEX
%token _IMAGINARY


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
%type <node> constant-expression
%type <node> expression-stmt
%type <node> ident-expr
%type <node> numlit-expr
%type <node> pointer
%type <node> direct-declarator
%type <node> declarator-list
%type <node> type-specifier
%type <node> storage-class-specifier
%type <node> declarator
%type <node> declaration-specifiers
%type <node> declaration

%%

/* C-99 Standard: http://faculty.cooper.edu/hak/ece466/n1124.pdf */
/* See Page 415 */

/* 6.5 EXPRESSIONS */

program:
    /* empty */
    | program expression-stmt
    | program declaration

ident-expr:
    IDENT {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = AST_IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        /* ident_node->val.ident.symbol = 0; */
        $$ = ident_node;
    }

numlit-expr:
    NUMLIT {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = AST_NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        numlit_node->val.numlit.type = N_LLI;
        $$ = numlit_node;
    }

primary-expression:
    ident-expr {$$ = $1;}
    | numlit-expr {
        $$ = $1;
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
        strlit_node->node_type = AST_STRLIT;
        strlit_node->val.strlit.val = yylval.d_str_val.str_val;
        strlit_node->val.strlit.len = yylval.d_str_val.str_len;
        $$ = strlit_node;
    }
    | '(' expression ')' {$$ = $2;}

postfix-expression:
    primary-expression {$$ = $1;}
    | postfix-expression '[' expression ']' {$$ = create_unop_node(U_DEREF, create_binop_node(B_PLUS, $1, $3));}
    /* | postfix-expression '(' argument-expression-list-opt ')' {} */
    | postfix-expression '.' ident-expr {$$ = create_binop_node(B_STRUCT_OFFSET, $1, $3);}
    | postfix-expression INDSEL ident-expr {$$ = create_binop_node(B_INDSEL, $1, $3);}
    | postfix-expression PLUSPLUS {$$ = create_unop_node(U_POST_PLUSPLUS, $1);}
    | postfix-expression MINUSMINUS {$$ = create_unop_node(U_POST_MINUSMINUS, $1);}
    /* | '(' type-name ')' '{' initializer-list '}' */
    /* | '(' type-name ')' '{' initializer-list ',' '}' */

argument-expression-list-opt:
    /* empty */
    | argument-expression-list

argument-expression-list:
    assignment-expression
    | argument-expression-list ',' assignment-expression


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
    | SIZEOF unary-expression {$$ = create_unop_node(U_SIZEOF_EXPRESSION, $2);}
    /* | SIZEOF '(' type-name ')' {$$ = create_unop_node(U_SIZEOF_TYPENAME, $3);} */

cast-expression:
    unary-expression {$$ = $1;}
    /* | '(' type-name ')' cast-expression {$$ = create_binop_node(B_TYPECAST, $2, $4);} */

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
    | expression ',' assignment-expression {$$ = create_binop_node(B_COMMA, $1, $3);}

/* 6.6 CONSTANT EXPRESSIONS */
constant-expression:
    conditional-expression {$$ = $1;}

expression-stmt:
    expression ';' {
        print_ast_tree($1);
        $$ = NULL;
    }

/* 6.7 DECLARATORS */

declaration:
    declaration-specifiers declarator-list ';' {
        if (!$2) {
            yyerror("no declarator provided");
        }
        ast_node *current_declarator_comma_node = $2; // always B_COMMA node
        while (current_declarator_comma_node->val.binop.left) {
            ast_node *current_declarator = current_declarator_comma_node->val.binop.right;
            while (current_declarator->node_type != AST_IDENT) {
                switch (current_declarator->node_type) {
                    case AST_UNOP:
                        current_declarator = current_declarator->val.unop.center;
                        break;
                    case AST_TYPE_MOD:
                        current_declarator = current_declarator->val.type_mod.next;
                        break;
                    default:
                        yyerror("unknown ast node encountered while traversing declarator list");
                }
            }
            int CURRENT_SYMBOL_SCOPE = 0;
            switch (CURRENT_SCOPE->scope) {
                case TABLE_GLOBAL:
                    CURRENT_SYMBOL_SCOPE = SYM_GLOBAL;
                    if (CURRENT_STORAGE_CLASS == SC_AUTO || CURRENT_STORAGE_CLASS == SC_REGISTER) {
                        yyerror("storage class not allowed in current scope");
                    } else if (!CURRENT_STORAGE_CLASS) {
                        CURRENT_STORAGE_CLASS = SC_EXTERN_IMPLICIT;
                    }
                    break;
                case TABLE_FUNCTION:
                    CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                    break;
                case TABLE_BLOCK:
                    CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                    break;
                default:
                    yyerror("unknown storage class encountered while traversing declarator list");
                    break;
            }
            insert_symbol_var(current_declarator->val.ident.ident_name, CURRENT_SYMBOL_SCOPE, CURRENT_STORAGE_CLASS);
            current_declarator_comma_node = current_declarator_comma_node->val.binop.left;
        }
    }

declaration-specifiers:
    storage-class-specifier declaration-specifiers {$$ = NULL;}
    | storage-class-specifier {$$ = NULL;}
    | type-specifier declaration-specifiers {$$ = NULL;}
    | type-specifier {$$ = NULL;}

declarator-list:
    declarator {$$ = create_binop_node(B_COMMA, NULL, $1);}
    | declarator-list ',' declarator {$$ = create_binop_node(B_COMMA, $1, $3);}

storage-class-specifier:
    EXTERN {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_EXTERN_EXPLICIT;
        $$ = NULL;
    }
    | STATIC {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        $$ = NULL;
    }
    | AUTO {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_AUTO;
        $$ = NULL;
    }
    | REGISTER {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        $$ = NULL;
    }

type-specifier:
    CHAR {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'char' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("too many 'char' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("conflict between 'char' and 'int' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_char = 1;
        $$ = NULL;
    }
    | INT {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'int' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("too many 'int' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'int' and 'char' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_int = 1;
        $$ = NULL;
    }
    | SHORT {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'short' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("conflict between 'short' and 'long long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("too many 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'short' and 'char' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_short = 1;
        }
        $$ = NULL;
    }
    | LONG {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'long' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("too many 'long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("conflict between 'long' and 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long) {
            CURRENT_TYPE_BUILDER.is_long_long = 1;
            CURRENT_TYPE_BUILDER.is_long = 0;
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'long' and 'char' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_long = 1;
        }
        $$ = NULL;
    }
    | SIGNED {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'signed' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("conflict between 'signed' and 'unsigned' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("too many 'signed' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_signed = 1;
        }
        $$ = NULL;
    }
    | UNSIGNED {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'unsigned' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("conflict between 'unsigned' and 'signed' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("too many 'unsigned' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_unsigned = 1;
        }
        $$ = NULL;
    }
    | VOID {
        if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("conflict between 'void' and 'signed' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("conflict between 'void' and 'unsigned' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("conflict between 'void' and 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long) {
            yyerror("conflict between 'void' and 'long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("conflict between 'void' and 'long long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'void' and 'char' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("conflict between 'void' and 'int' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_void = 1;
        $$ = NULL;
    }

declarator:
    pointer direct-declarator {
        ast_node *tail = $1;
        while (tail->val.type_mod.next) {
            tail = tail->val.type_mod.next;
        }
        tail->val.type_mod.next = $2;
        $$ = $1;
    }
    | direct-declarator {$$ = $1;}

direct-declarator:
    ident-expr {$$ = $1;}
    | '(' declarator ')' {$$ = $2;}
    | direct-declarator '[' numlit-expr ']' {
        int array_size = $3->val.numlit.val.int_val;
        free($3);
        ast_node *node = create_type_modifier_node(CONSTANT_SIZED_ARRAY, array_size);
        node->val.type_mod.next = $1;
        $$ = node;
    }
    | direct-declarator '[' ']' {
        ast_node *node = create_type_modifier_node(UNSIZED_ARRAY, 0);
        node->val.type_mod.next = $1;
        $$ = node;
    }
    | direct-declarator '(' ')' {$$ = create_unop_node(U_FUNCTION_TYPE, $1);}

pointer:
    '*' {$$ = create_type_modifier_node(POINTER, 0);}
    | '*' pointer {
        ast_node *node = create_type_modifier_node(POINTER, 0);
        node->val.type_mod.next = $2;
        $$ = node;
    }

/* type-name:
    type-specifier-list abstract-declarator
    | type-specifier-list

abstract-declarator:
    pointer
    | pointer direct-abstract-declarator
    | direct-abstract-declarator

direct-abstract-declarator:
    '(' abstract-declarator ')'
    | direct-abstract-declarator '[' assignment-expression ']'
    | direct-abstract-declarator '[' ']'
    | '[' assignment-expression ']'
    | '[' ']'
    | direct-abstract-declarator '(' ')'
    | '(' ')' */

%%

int main() {
    init_global_table();
    yydebug = 0;
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}