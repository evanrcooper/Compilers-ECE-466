%{
#include <stdio.h>
// #include "tokens.h"
#include "../Parser/parser.tab.h"

/* extern */ int line_number = 1;
/* extern */ char *filename;

#define DEFAULT_D_STR_LEN 32 /* >= 2 */

// YYSTYPE yylval;

%}

%x char_lit
%x str_lit

%%

";"             {return ';';}
"+"             {return '+';}
"-"             {return '-';}
"="             {return '=';}
"-"             {return '-';}
"&"             {return '&';}
"|"             {return '|';}
"("             {return '(';}
")"             {return ')';}
"["             {return '[';}
"]"             {return ']';}
"/"             {return '/';}
"%"             {return '%';}
"^"             {return '^';}
"!"             {return '!';}
"~"             {return '~';}
"."             {return '.';}
">"             {return '>';}
"<"             {return '<';}
","             {return ',';}
"."             {return '.';}
":"             {return ':';}
"?"             {return '?';}
"*"             {return '*';}
"{"             {return '{';}
"}"             {return '}';}

"->"            {return INDSEL;}
"++"            {return PLUSPLUS;}
"--"            {return MINUSMINUS;}
"<<"            {return SHL;}
">>"            {return SHR;}
"<="            {return LEQ;}
">="            {return GEQ;}
"=="            {return EQEQ;}
"!="            {return NEQ;}
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
} /* catch newline and add line to line number */

#" "*[0-9]+" "*\".+\"" "*[0-9 ]+ { /* match preprocesser lines '# 41 main.c 1' and catch new filename and new line number */
    char extracted_filename[256];
    if (sscanf(yytext, "# %d \"%255[^\"]\"", &line_number, extracted_filename) >= 2) {
        filename = strdup(extracted_filename);
    }
}

[1-9][0-9]* { /* decimal numbers */
    yylval.int_val = strtoll(yytext, NULL, 10);
    return NUMLIT;
}

0[bB][01]+ { /* binary numbers */
    yylval.int_val = (long long int) strtoll(yytext+2, NULL, 2);
    return NUMLIT;
}

0[xX][0-9A-Fa-f]+ { /* hex numbers */
    yylval.int_val = (long long int) strtoll(yytext+2, NULL, 16);
    return NUMLIT;
}

0[0-7]+ { /* octal numbers */
    yylval.int_val = (long long int) strtoll(yytext+1, NULL, 8);
    return NUMLIT;
}

([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fFlL]? { /* decimal floats and exponents */
    /* https://stackoverflow.com/a/12643073 */
    yylval.real_val = (long double) strtold(yytext, NULL);
    return FLOATLIT;
}

0[xX]([0-9A-Fa-f]+([.][0-9A-Fa-f]*)?|[.][0-9A-Fa-f]+)([pP][+-]?[0-9]+)?[fFlL]? { /* hex floats and exponents */
    /* https://stackoverflow.com/a/12643073 */
    yylval.real_val = (long double) strtold(yytext, NULL);
    return FLOATLIT;
}

['] {BEGIN(char_lit);}

<char_lit>\\[abefnrtv\\'"?]['] {
    switch (yytext[1]) {
        case 'a':
            yylval.char_val = '\a';
            break;
        case 'b':
            yylval.char_val = '\b';
            break;
        case 'e':
            yylval.char_val = '\033' /* \e */;
            break;
        case 'f':
            yylval.char_val = '\f';
            break;
        case 'n':
            yylval.char_val = '\n';
            break;
        case 'r':
            yylval.char_val = '\r';
            break;
        case 't':
            yylval.char_val = '\t';
            break;
        case 'v':
            yylval.char_val = '\v';
            break;
        case '\\':
            yylval.char_val = '\\';
            break;
        case '\'':
            yylval.char_val = '\'';
            break;
        case '\"':
            yylval.char_val = '\"';
            break;
        case '\?':
            yylval.char_val = '\?';
            break;
        default:
            REJECT
            break;
    }
    BEGIN(INITIAL);
    return CHARLIT;
}

<char_lit>\\[xX][0-9A-Fa-f]{2}['] {
    char *endptr = yytext + 4;
    yylval.char_val = (char) strtoll(yytext + 2, &endptr, 16);
    BEGIN(INITIAL);
    return CHARLIT;
}

<char_lit>\\[0-7]{3}['] {
    char *endptr = yytext + 4;
    yylval.char_val = (char) strtoll(yytext + 1, &endptr + 4, 8);
    BEGIN(INITIAL);
    return CHARLIT;
}

<char_lit>[ -~]['] {
    yylval.char_val = yytext[0];
    BEGIN(INITIAL);
    return CHARLIT;
}

<char_lit>. {
    REJECT
    BEGIN(INITIAL);
}

["] {
    yylval.d_str_val.str_val = (char*) calloc(DEFAULT_D_STR_LEN, sizeof(char));
    yylval.d_str_val.str_len = 0;
    yylval.d_str_val.str_max_len = DEFAULT_D_STR_LEN;
    BEGIN(str_lit);
}

<str_lit>\\[xX][0-9A-Fa-f]{2} {
    /* TODO */;
}

<str_lit>\\[0-7]{3} {
    /* TODO */;
}

<str_lit>\\[abefnrtv\\'"?0] {
    if (yylval.d_str_val.str_len + 2 > yylval.d_str_val.str_max_len) {
        yylval.d_str_val.str_val = realloc(yylval.d_str_val.str_val, yylval.d_str_val.str_max_len * 2);
        if (yylval.d_str_val.str_val == NULL) {
            REJECT
        }
        yylval.d_str_val.str_max_len *= 2;
    }
    switch (yytext[1]) {
    case 'a':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\a';
        break;
    case 'b':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\b';
        break;
    case 'e':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\033' /* \e */;
        break;
    case 'f':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\f';
        break;
    case 'n':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\n';
        break;
    case 'r':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\r';
        break;
    case 't':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\t';
        break;
    case 'v':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\v';
        break;
    case '\\':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\\';
        break;
    case '\'':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\'';
        break;
    case '\"':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\"';
        break;
    case '\?':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\?';
        break;
    case '0':
        yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\0';
        break;
    default:
        REJECT
        break;
    }
    yylval.d_str_val.str_len += 1;
}

<str_lit>[ !~#-\[\]-~] { /* match any printable character other than backslash and double quote */
    if (yylval.d_str_val.str_len + 2 > yylval.d_str_val.str_max_len) {
        yylval.d_str_val.str_val = realloc(yylval.d_str_val.str_val, yylval.d_str_val.str_max_len * 2);
        if (yylval.d_str_val.str_val == NULL) {
            REJECT
        }
        yylval.d_str_val.str_max_len *= 2;
    }
    yylval.d_str_val.str_val[yylval.d_str_val.str_len] = yytext[0];
    yylval.d_str_val.str_len += 1;
}

<str_lit>["] {
    yylval.d_str_val.str_val = realloc(yylval.d_str_val.str_val, yylval.d_str_val.str_len + 1);
    yylval.d_str_val.str_val[yylval.d_str_val.str_len] = '\0';
    yylval.d_str_val.str_len += 1;
    BEGIN(INITIAL);
    return STRLIT;
}

[_A-Za-z][_A-Za-z0-9]* {
    yylval.str_val = strdup(yytext);
    return IDENT;
}

[ \t\n]+ {}

. {printf("INVALID TOKEN: %s\n", yytext);}

%%

/* int main(int argc, char *argv[]) {
    int tok_id = yylex();

    do {
        if (tok_id == NUMLIT) {
			printf("TOKID: %d, LINE_NUM: %d, NUMLIT: %lld, TOKEN: %s\n", tok_id, line_number, yylval.int_val, yytext);
		} else if (tok_id == FLOATLIT) {
			printf("TOKID: %d, LINE_NUM: %d, FLIT: %Lf, TOKEN: %s\n", tok_id, line_number, yylval.real_val, yytext);
		} else if (tok_id == CHARLIT) {
            printf("TOKID: %d, LINE_NUM: %d, CHAR: \'%c\'\n", tok_id, line_number, yylval.char_val);
        } else if (tok_id == STRLIT) {
            printf("TOKID: %d, LINE_NUM: %d, STRLIT: \"%s\"\n", tok_id, line_number, yylval.str_val);
        } else {
			printf("TOKID: %d, LINE_NUM: %d, TOKEN: %s\n", tok_id, line_number, yytext);
		}
    } while (tok_id = yylex());
    
    return 0;
} */

int yywrap(){return(1);}