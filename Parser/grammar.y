%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyerror(const char *s);

%}

%union {
    ast_node* node;
    char char_val;
    long long unsigned int token;
}

%token IDENT NUMLIT CHARLIT STRLIT FLOATLIT
%token PLUSPLUS MINUSMINUS
%token INDSEL
%token SHL SHR
%token GEQ LEQ EQEQ NEQ
%token LOGAND LOGOR
%token TIMESEQ PLUSEQ XOREQ MINUSEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ

%type <node> primary-expression 
%type <node> postfix-expression 
%type <char_val> unary-operator
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
%type <token> assignment-operator
%type <node> assignment-expression
%type <node> expression
%type <node> constant-expression

%%

/* C-99 Standard: http://faculty.cooper.edu/hak/ece466/n1124.pdf */
/* See Page 415 */

/* 6.5 EXPRESSIONS */

program:
    /* empty */
    | expression ';' program

primary-expression:
    IDENT {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        $$ = ident_node;
    }
    | NUMLIT {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        $$ = numlit_node;
    }
    | FLOATLIT {
        ast_node *flit_node = calloc(1, sizeof(ast_node));
        flit_node->node_type = NUMLIT;
        flit_node->val.numlit.val.real_val = yylval.real_val;
        $$ = flit_node;
    }
    | CHARLIT {
        ast_node *charlit_node = calloc(1, sizeof(ast_node));
        charlit_node->node_type = CHARLIT;
        charlit_node->val.charlit.val = yylval.char_val;
        $$ = charlit_node;
    }
    | STRLIT {
        ast_node *strlit_node = calloc(1, sizeof(ast_node));
        strlit_node->node_type = NUMLIT;
        strlit_node->val.strlit.val = yylval.s_str_val.str_val;
        strlit_node->val.strlit.len = yylval.s_str_val.str_len;
        $$ = strlit_node;
    }
    | '(' expression ')' {$$ = $2;}

postfix-expression:
    primary-expression {$$ = $1;}
    | postfix-expression '[' expression ']' {}
    /* | postfix-expression '(' argument-expression-list-opt ')' */
    /* | postfix-expression '.' IDENT */
    /* | postfix-expression INDSEL IDENT */
    | postfix-expression PLUSPLUS {}
    | postfix-expression MINUSMINUS {}
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

unary-operator:
    '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'

unary-expression:
    postfix-expression {$$ = $1;}
    | PLUSPLUS unary-expression {}
    | MINUSMINUS unary-expression {}
    | unary-operator cast-expression {/* new ast node un op and set op to $-1 */}
    /* | SIZEOF unary-expression */
    /* | SIZEOF '(' type-name ')' */

cast-expression:
    unary-expression {$$ = $1;}
    /* | '(' type-name ')' cast-expression */

multiplicative-expression:
    cast-expression
    | multiplicative-expression '*' cast-expression
    | multiplicative-expression '/' cast-expression
    | multiplicative-expression '%' cast-expression

additive-expression:
    multiplicative-expression
    | additive-expression '+' multiplicative-expression
    | additive-expression '-' multiplicative-expression

shift-expression:
    additive-expression
    | shift-expression SHL additive-expression
    | shift-expression SHR additive-expression

relational-expression:
    shift-expression
    | relational-expression '<' shift-expression
    | relational-expression '>' shift-expression
    | relational-expression LEQ shift-expression
    | relational-expression GEQ shift-expression

equality-expression:
    relational-expression {$$ = $1;}
    | equality-expression EQEQ relational-expression
    | equality-expression NEQ relational-expression

bitand-expression: /* AND-expression */
    equality-expression {$$ = $1;}
    | bitand-expression '&' equality-expression

bitxor-expression: /* exclusive-OR-expression */
    bitand-expression {$$ = $1;}
    | bitxor-expression '^' bitand-expression

bitor-expression: /* inclusive-OR-expression */
    bitxor-expression {$$ = $1;}
    | bitor-expression '|' bitxor-expression

logand-expression: /* logical-AND-expression */
    bitor-expression {$$ = $1;}
    | logand-expression LOGAND bitor-expression

logor-expression: /* logical-OR-expression */
    logand-expression {$$ = $1;}
    | logor-expression LOGOR logand-expression

conditional-expression:
    logor-expression {$$ = $1;}
    | logor-expression '?' expression ':' conditional-expression

assignment-operator:
    '=' {$$ = '=';}
    | TIMESEQ {$$ = TIMESEQ;}
    | DIVEQ {$$ = DIVEQ;}
    | MODEQ {$$ = MODEQ;}
    | PLUSEQ {$$ = PLUSEQ;}
    | MINUSEQ {$$ = MINUSEQ;}
    | SHLEQ {$$ = SHLEQ;}
    | SHREQ {$$ = SHREQ;}
    | ANDEQ {$$ = ANDEQ;}
    | OREQ {$$ = OREQ;}
    | XOREQ {$$ = XOREQ;}

assignment-expression:
    conditional-expression {$$ = $1;}
    | unary-expression assignment-operator assignment-expression

expression:
    assignment-expression {$$ = $1;}
    | expression ',' assignment-expression

/* 6.6 CONSTANT EXPRESSIONS */

constant-expression:
    conditional-expression {$$ = $1;}

/* 6.7 DECLARATIONS */


%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

