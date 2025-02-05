%{
#include <stdio.h>
#include "tokens.h"

/* extern */ int line_number = 1;
/* extern */ char *filename;

#define STRMAXSIZ 4095

typedef union {
    char *string_val;
    long long int_val;
    long double real_val;
    char char_val;
} YYSTYPE;

/* extern */ YYSTYPE yylval;

%}

%%

";"            {return SEMICOLON;}

"->"            {return INDSEL;}
"++"            {return PLUSPLUS;}
"--"            {return MINUSMINUS;}
"<<"            {return SHL;}
">>"            {return SHR;}
"<="            {return LTEQ;}
">="            {return GTEQ;}
"=="            {return EQEQ;}
"!="            {return NOTEQ;}
"&&"            {return LOGAND;}
"||"            {return LOGOR;}
"..."           {return ELLIPSIS;}
"*="            {return TIMESEQ;}
"/="            {return DIVEQ;}
"%="            {return MODEQ;}
"+="            {return PLUSEQ;}
"-="            {return MINUSEQ;}
"<<="           {return SHLEQ;}
">>="           {return SHREQ;}
"&="            {return ANDEQ;}
"|="            {return OREQ;}
"^="            {return XOREQ;}

"auto"          {return AUTO;}
"break"         {return BREAK;}
"case"          {return CASE;}
"char"          {return CHAR;}
"const"         {return CONST;}
"continue"      {return CONTINUE;}
"default"       {return DEFAULT;}
"do"            {return DO;}
"double"        {return DOUBLE;}
"else"          {return ELSE;}
"enum"          {return ENUM;}
"extern"        {return EXTERN;}
"float"         {return FLOAT;}
"for"           {return FOR;}
"goto"          {return GOTO;}
"if"            {return IF;}
"inline"        {return INLINE;}
"int"           {return INT;}
"long"          {return LONG;}
"register"      {return REGISTER;}
"restrict"      {return RESTRICT;}
"return"        {return RETURN;}
"short"         {return SHORT;}
"signed"        {return SIGNED;}
"sizeof"        {return SIZEOF;}
"static"        {return STATIC;}
"struct"        {return STRUCT;}
"switch"        {return SWITCH;}
"typedef"       {return TYPEDEF;}
"union"         {return UNION;}
"unsigned"      {return UNSIGNED;}
"void"          {return VOID;}
"volatile"      {return VOLATILE;}
"while"         {return WHILE;}

"_bool"         {return _BOOL;}
"_complex"      {return _COMPLEX;}
"_imaginary"    {return _IMAGINARY;}



\n {
    line_number++; 
    return NEWLINE;
} /* catch newline and add line to line number */

#" "*[0-9]+" "*\".+\"" "*[0-9 ]+ { /* match preprocesser lines '# 41 main.c 1' and catch new filename and new line number */
    char extracted_filename[256];
    if (sscanf(yytext, "# %d \"%255[^\"]\"", &line_number, extracted_filename) >= 2) {
        filename = strdup(extracted_filename);
    }
    return SKIP;
}


[-+]?[0]+ { /* zero literal octal/decimal */
    yylval.int_val = 0;
    return NUMBERLIT;
}
[-+]?[1-9][0-9]* { /* decimal numbers */
    yylval.int_val = strtoll(yytext, NULL, 10);
    return NUMBERLIT;
}
[-+]?0[bB][01]+ { /* binary numbers */
    if (yytext[0] == '+') {
        yylval.int_val = (long long int) strtoll(yytext+3, NULL, 2);
    } else if (yytext[0] == '-') {
        yylval.int_val = -((long long int) strtoll(yytext+3, NULL, 2));
    } else {
        yylval.int_val = (long long int) strtoll(yytext+2, NULL, 2);
    }
    return NUMBERLIT;
}
[-+]?0[xX][0-9A-Fa-f]+ { /* hex numbers */
    if (yytext[0] == '+') {
        yylval.int_val = (long long int) strtoll(yytext+3, NULL, 16);
    } else if (yytext[0] == '-') {
        yylval.int_val = -((long long int) strtoll(yytext+3, NULL, 16));
    } else {
        yylval.int_val = (long long int) strtoll(yytext+2, NULL, 16);
    }
    return NUMBERLIT;
}
[-+]?0[0-7]+ { /* octal numbers */
    if (yytext[0] == '+') {
        yylval.int_val = (long long int) strtoll(yytext+2, NULL, 8);
    } else if (yytext[0] == '-') {
        yylval.int_val = -((long long int) strtoll(yytext+2, NULL, 8));
    } else {
        yylval.int_val = (long long int) strtoll(yytext+1, NULL, 8);
    }    return NUMBERLIT;
}


[-+]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fFlL]? { /* decimal floats and exponents */
    /* https://stackoverflow.com/a/12643073 */
    yylval.real_val = (long double) strtold(yytext, NULL);
    return FLOATLIT;
}
[-+]?0[xX]([0-9A-Fa-f]+([.][0-9A-Fa-f]*)?|[.][0-9A-Fa-f]+)([pP][+-]?[0-9]+)?[fFlL]? { /* decimal floats and exponents */
    /* https://stackoverflow.com/a/12643073 */
    yylval.real_val = (long double) strtold(yytext, NULL);
    return FLOATLIT;
}


[-+]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fFlL]?[iI] {
    yylval.real_val = (long double) strtod(yytext, NULL);
    return IMAGINARYLIT;
}

[-+]?0[xX]([0-9A-Fa-f]+([.][0-9A-Fa-f]*)?|[.][0-9A-Fa-f]+)([pP][+-]?[0-9]+)?[fFlL]?[iI] {
    yylval.real_val = (long double) strtod(yytext, NULL);
    return IMAGINARYLIT;
}

[_A-Za-z][_A-Za-z0-9]* {return IDENT;}

%%

int main(int argc, char *argv[]) {
    int tok_id = yylex();

    do {
        if (tok_id == NEWLINE) 
            printf("NEWLINE\n");
		} else if (tok_id == NUMBERLIT) {
			printf("TOKID: %d, LINE_NUM: %d, NUMLIT: %lld, TOKEN: %s\n", tok_id, line_number, yylval.int_val, yytext);
		} else if (tok_id == FLOATLIT) {
			printf("TOKID: %d, LINE_NUM: %d, FLIT: %Lf, TOKEN: %s\n", tok_id, line_number, yylval.real_val, yytext);
		} else if (tok_id == IMAGINARYLIT) {
			printf("TOKID: %d, LINE_NUM: %d, ILIT: %Lf, TOKEN: %s\n", tok_id, line_number, yylval.real_val, yytext);
		} else {
			printf("TOKID: %d, LINE_NUM: %d, TOKEN: %s\n", tok_id, line_number, yytext);
		}
    } while (tok_id = yylex());
    
    return 0;
}

int yywrap(){return(1);}