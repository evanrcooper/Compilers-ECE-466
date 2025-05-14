/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 10 "parser.y"

    #include "ast.h"
    #include "../SymbolTable/sym_tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(const char *s);

#line 57 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    NUMLIT = 259,                  /* NUMLIT  */
    CHARLIT = 260,                 /* CHARLIT  */
    STRLIT = 261,                  /* STRLIT  */
    FLOATLIT = 262,                /* FLOATLIT  */
    PLUSPLUS = 263,                /* PLUSPLUS  */
    MINUSMINUS = 264,              /* MINUSMINUS  */
    INDSEL = 265,                  /* INDSEL  */
    SHL = 266,                     /* SHL  */
    SHR = 267,                     /* SHR  */
    GEQ = 268,                     /* GEQ  */
    LEQ = 269,                     /* LEQ  */
    EQEQ = 270,                    /* EQEQ  */
    NEQ = 271,                     /* NEQ  */
    LOGAND = 272,                  /* LOGAND  */
    LOGOR = 273,                   /* LOGOR  */
    TIMESEQ = 274,                 /* TIMESEQ  */
    PLUSEQ = 275,                  /* PLUSEQ  */
    XOREQ = 276,                   /* XOREQ  */
    MINUSEQ = 277,                 /* MINUSEQ  */
    DIVEQ = 278,                   /* DIVEQ  */
    MODEQ = 279,                   /* MODEQ  */
    SHLEQ = 280,                   /* SHLEQ  */
    SHREQ = 281,                   /* SHREQ  */
    ANDEQ = 282,                   /* ANDEQ  */
    OREQ = 283,                    /* OREQ  */
    ELLIPSIS = 284,                /* ELLIPSIS  */
    CASE = 285,                    /* CASE  */
    CONST = 286,                   /* CONST  */
    DEFAULT = 287,                 /* DEFAULT  */
    DOUBLE = 288,                  /* DOUBLE  */
    ENUM = 289,                    /* ENUM  */
    FLOAT = 290,                   /* FLOAT  */
    INLINE = 291,                  /* INLINE  */
    RESTRICT = 292,                /* RESTRICT  */
    STRUCT = 293,                  /* STRUCT  */
    SWITCH = 294,                  /* SWITCH  */
    TYPEDEF = 295,                 /* TYPEDEF  */
    UNION = 296,                   /* UNION  */
    VOLATILE = 297,                /* VOLATILE  */
    _BOOL = 298,                   /* _BOOL  */
    _COMPLEX = 299,                /* _COMPLEX  */
    _IMAGINARY = 300,              /* _IMAGINARY  */
    AUTO = 301,                    /* AUTO  */
    BREAK = 302,                   /* BREAK  */
    CHAR = 303,                    /* CHAR  */
    CONTINUE = 304,                /* CONTINUE  */
    DO = 305,                      /* DO  */
    ELSE = 306,                    /* ELSE  */
    EXTERN = 307,                  /* EXTERN  */
    FOR = 308,                     /* FOR  */
    GOTO = 309,                    /* GOTO  */
    IF = 310,                      /* IF  */
    INT = 311,                     /* INT  */
    LONG = 312,                    /* LONG  */
    REGISTER = 313,                /* REGISTER  */
    RETURN = 314,                  /* RETURN  */
    SHORT = 315,                   /* SHORT  */
    SIGNED = 316,                  /* SIGNED  */
    SIZEOF = 317,                  /* SIZEOF  */
    STATIC = 318,                  /* STATIC  */
    UNSIGNED = 319,                /* UNSIGNED  */
    VOID = 320,                    /* VOID  */
    WHILE = 321                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    char *str_val;
    long long int_val;
    long double real_val;
    char char_val;
    D_STRING d_str_val;
    ast_node* node;

#line 149 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
