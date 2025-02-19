%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyerror(const char *s);

%}

%token 

%%

/* http://faculty.cooper.edu/hak/ece466/n1124.pdf */

/* 6.5 EXPRESSIONS */

primary-expression:
    identifier
    | NUMLIT
    | CHARLIT
    | STRLIT
    | '(' expression ')'

postfix-expression:
    primary-expression
    | postfix-expression '[' expression ']'
    | postfix-expression '(' argument-expression-list-opt ')'
    | postfix-expression '.' identifier
    | postfix-expression INDSEL identifier
    | postfix-expression PLUSPLUS
    | postfix-expression MINUSMINUS
    | '(' type-name ')' '{' initializer-list '}'
    | '(' type-name ')' '{' initializer-list ',' '}'

argument-expression-list-opt:
    /* empty */
    | argument-expression-list

argument-expression-list:
    assignment-expression
    | argument-expression-list ',' assignment-expression

unary-operator:
    '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'

unary-expression:
    postfix-expression
    | PLUSPLUS unary-expression
    | MINUSMINUS unary-expression
    | unary-operator cast-expression
    | SIZEOF unary-expression
    | SIZEOF '(' type-name ')'

cast-expression:
    unary-expression
    | '(' type-name ')' cast-expression

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
    relational-expression
    | equality-expression EQEQ relational-expression
    | equality-expression NEQ relational-expression

bitand-expression: /* AND-expression */
    equality-expression
    | bitand-expression '&' equality-expression

bitxor-expression: /* exclusive-OR-expression */
    bitand-expression
    | bitxor-expression '^' bitand-expression

bitor-expression: /* inclusive-OR-expression */
    bitxor-expression
    | bitor-expression '|' bitxor-expression

logand-expression: /* logical-AND-expression */
    bitor-expression
    | logand-expression LOGAND bitor-expression

logor-expression: /* logical-OR-expression */
    logand-expression
    | logor-expression LOGOR logand-expression

conditional-expression:
    logor-expression
    | logor-expression '?' expression ':' conditional-expression

assignment-operator:
    '='
    | TIMESEQ
    | DIVEQ
    | MODEQ
    | PLUSEQ
    | MINUSEQ
    | SHLEQ
    | SHREQ
    | ANDEQ
    | OREQ
    | XOREQ

assignment-expression:
    conditional-expression
    | unary-expression assignment-operator assignment-expression

expression:
    assignment-expression
    | expression ',' assignment-expression

/* 6.6 CONSTANT EXPRESSIONS */

constant-expression:
    conditional-expression

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

