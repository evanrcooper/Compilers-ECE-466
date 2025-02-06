%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyerror(const char *s);

%}

%token IDENT NUMBER SEMICOLON PLUSPLUS MINUSMINUS INDSEL LTEQ GTEQ EQEQ NOTEQ LOGAND SHL SHR LOGOR TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ SHREQ ANDEQ OREQ XOREQ POSTOP PREOP PAREN BRACKET

%%

program: /* START */
    program expr_stmt
    | /* empty */
    ;

expr_stmt:
    expr SEMICOLON
    ;

expr:
    NUMBER
    | ident_stmt

    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr

    | expr '&' expr
    | expr '|' expr
    | expr '^' expr

    | expr '%' expr

    | expr '>' expr
    | expr '<' expr

    | '!' expr
    | '~' expr

    | '(' expr ')' %prec PAREN
    | '+' expr
    | '-' expr

    | expr LTEQ expr
    | expr GTEQ expr
    | expr EQEQ expr
    | expr NOTEQ expr
    | expr LOGAND expr
    | expr LOGOR expr
    | expr SHL expr
    | expr SHR expr
    | expr LOGOR expr

    | expr '=' expr
    | ident_stmt TIMESEQ expr
    | ident_stmt DIVEQ expr
    | ident_stmt MODEQ expr
    | ident_stmt PLUSEQ expr
    | ident_stmt MINUSEQ expr
    | ident_stmt SHLEQ expr
    | ident_stmt SHREQ expr
    | ident_stmt ANDEQ expr
    | ident_stmt OREQ expr
    | ident_stmt XOREQ expr

    | expr '?' expr ':' expr %prec '?'

ident_stmt:
    IDENT
    | ident_stmt PLUSPLUS %prec POSTOP
    | PLUSPLUS ident_stmt %prec PREOP

    | ident_stmt MINUSMINUS %prec POSTOP
    | MINUSMINUS ident_stmt %prec PREOP

    | ident_stmt INDSEL ident_stmt
    | ident_stmt '.' ident_stmt

    | '*' ident_stmt
    | '&' ident_stmt
    | ident_stmt '[' expr ']' %prec BRACKET
    | '(' ident_stmt ')' %prec PAREN

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

