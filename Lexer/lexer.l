%{
#include <stdio.h>
#include "tokens.h"

extern int line_number = 1;
extern char *filename = "<stdin>";

typedef union {
    char *string_val;
    long long int_val;
    long double real_val;
} YYSTYPE;

YYSTYPE yylval;

%}

%%
/\n/ {line_number++;}
/\# *[0-9]+ *\".+\" *[0-9 ]+/ 
/[0-9]+|0[bx][0-9]+/ 
%%

int main(int argc, char *argv[]) {
    int tok_id = yylex();

    do {
        print(tok_id);
    } while (tok_id = yylex());
    
    return 0;
}