/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "parser.tab.h"
    int yylex(void);
    extern FILE *yyin;

#line 77 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_NUMLIT = 4,                     /* NUMLIT  */
  YYSYMBOL_CHARLIT = 5,                    /* CHARLIT  */
  YYSYMBOL_STRLIT = 6,                     /* STRLIT  */
  YYSYMBOL_FLOATLIT = 7,                   /* FLOATLIT  */
  YYSYMBOL_PLUSPLUS = 8,                   /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 9,                 /* MINUSMINUS  */
  YYSYMBOL_INDSEL = 10,                    /* INDSEL  */
  YYSYMBOL_SHL = 11,                       /* SHL  */
  YYSYMBOL_SHR = 12,                       /* SHR  */
  YYSYMBOL_GEQ = 13,                       /* GEQ  */
  YYSYMBOL_LEQ = 14,                       /* LEQ  */
  YYSYMBOL_EQEQ = 15,                      /* EQEQ  */
  YYSYMBOL_NEQ = 16,                       /* NEQ  */
  YYSYMBOL_LOGAND = 17,                    /* LOGAND  */
  YYSYMBOL_LOGOR = 18,                     /* LOGOR  */
  YYSYMBOL_TIMESEQ = 19,                   /* TIMESEQ  */
  YYSYMBOL_PLUSEQ = 20,                    /* PLUSEQ  */
  YYSYMBOL_XOREQ = 21,                     /* XOREQ  */
  YYSYMBOL_MINUSEQ = 22,                   /* MINUSEQ  */
  YYSYMBOL_DIVEQ = 23,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 24,                     /* MODEQ  */
  YYSYMBOL_SHLEQ = 25,                     /* SHLEQ  */
  YYSYMBOL_SHREQ = 26,                     /* SHREQ  */
  YYSYMBOL_ANDEQ = 27,                     /* ANDEQ  */
  YYSYMBOL_OREQ = 28,                      /* OREQ  */
  YYSYMBOL_ELLIPSIS = 29,                  /* ELLIPSIS  */
  YYSYMBOL_AUTO = 30,                      /* AUTO  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 36,                   /* DEFAULT  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_ENUM = 40,                      /* ENUM  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 42,                     /* FLOAT  */
  YYSYMBOL_FOR = 43,                       /* FOR  */
  YYSYMBOL_GOTO = 44,                      /* GOTO  */
  YYSYMBOL_IF = 45,                        /* IF  */
  YYSYMBOL_INLINE = 46,                    /* INLINE  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_LONG = 48,                      /* LONG  */
  YYSYMBOL_REGISTER = 49,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 50,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_SIGNED = 53,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 54,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 55,                    /* STATIC  */
  YYSYMBOL_STRUCT = 56,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 58,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 59,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 60,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 61,                      /* VOID  */
  YYSYMBOL_VOLATILE = 62,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 63,                     /* WHILE  */
  YYSYMBOL__BOOL = 64,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 65,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 66,                /* _IMAGINARY  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* '['  */
  YYSYMBOL_70_ = 70,                       /* ']'  */
  YYSYMBOL_71_ = 71,                       /* '.'  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '*'  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '~'  */
  YYSYMBOL_77_ = 77,                       /* '!'  */
  YYSYMBOL_78_ = 78,                       /* '/'  */
  YYSYMBOL_79_ = 79,                       /* '%'  */
  YYSYMBOL_80_ = 80,                       /* '<'  */
  YYSYMBOL_81_ = 81,                       /* '>'  */
  YYSYMBOL_82_ = 82,                       /* '^'  */
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '?'  */
  YYSYMBOL_85_ = 85,                       /* ':'  */
  YYSYMBOL_86_ = 86,                       /* '='  */
  YYSYMBOL_87_ = 87,                       /* ','  */
  YYSYMBOL_88_ = 88,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 89,                  /* $accept  */
  YYSYMBOL_program = 90,                   /* program  */
  YYSYMBOL_91_ident_expr = 91,             /* ident-expr  */
  YYSYMBOL_92_primary_expression = 92,     /* primary-expression  */
  YYSYMBOL_93_postfix_expression = 93,     /* postfix-expression  */
  YYSYMBOL_94_unary_expression = 94,       /* unary-expression  */
  YYSYMBOL_95_cast_expression = 95,        /* cast-expression  */
  YYSYMBOL_96_multiplicative_expression = 96, /* multiplicative-expression  */
  YYSYMBOL_97_additive_expression = 97,    /* additive-expression  */
  YYSYMBOL_98_shift_expression = 98,       /* shift-expression  */
  YYSYMBOL_99_relational_expression = 99,  /* relational-expression  */
  YYSYMBOL_100_equality_expression = 100,  /* equality-expression  */
  YYSYMBOL_101_bitand_expression = 101,    /* bitand-expression  */
  YYSYMBOL_102_bitxor_expression = 102,    /* bitxor-expression  */
  YYSYMBOL_103_bitor_expression = 103,     /* bitor-expression  */
  YYSYMBOL_104_logand_expression = 104,    /* logand-expression  */
  YYSYMBOL_105_logor_expression = 105,     /* logor-expression  */
  YYSYMBOL_106_conditional_expression = 106, /* conditional-expression  */
  YYSYMBOL_107_assignment_expression = 107, /* assignment-expression  */
  YYSYMBOL_expression = 108,               /* expression  */
  YYSYMBOL_109_expression_stmt = 109       /* expression-stmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    79,    72,     2,
      67,    68,    73,    74,    87,    75,    71,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    88,
      80,    86,    81,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    83,     2,    76,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   101,   104,   112,   113,   120,   127,   133,
     140,   143,   144,   146,   147,   148,   149,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   177,   181,   182,   183,
     184,   187,   188,   189,   192,   193,   194,   197,   198,   199,
     200,   201,   204,   205,   206,   209,   210,   213,   214,   217,
     218,   221,   222,   225,   226,   229,   230,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   247,
     248,   255
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "NUMLIT",
  "CHARLIT", "STRLIT", "FLOATLIT", "PLUSPLUS", "MINUSMINUS", "INDSEL",
  "SHL", "SHR", "GEQ", "LEQ", "EQEQ", "NEQ", "LOGAND", "LOGOR", "TIMESEQ",
  "PLUSEQ", "XOREQ", "MINUSEQ", "DIVEQ", "MODEQ", "SHLEQ", "SHREQ",
  "ANDEQ", "OREQ", "ELLIPSIS", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL",
  "_COMPLEX", "_IMAGINARY", "'('", "')'", "'['", "']'", "'.'", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "'='", "','", "';'", "$accept", "program",
  "ident-expr", "primary-expression", "postfix-expression",
  "unary-expression", "cast-expression", "multiplicative-expression",
  "additive-expression", "shift-expression", "relational-expression",
  "equality-expression", "bitand-expression", "bitxor-expression",
  "bitor-expression", "logand-expression", "logor-expression",
  "conditional-expression", "assignment-expression", "expression",
  "expression-stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,   -70,   -70,   -70,   -70,   -70,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    20,   -70,   -70,    23,     2,
     -70,   -69,   -63,    64,   -11,    63,   -37,   -38,   -35,    33,
     -13,   -70,   -70,    19,    10,   -70,   -70,   -25,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    65,    10,
      65,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,   -70,   -70,   -70,   -70,   -24,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -69,   -69,   -63,   -63,    64,    64,    64,    64,
     -11,   -11,    63,   -37,   -38,   -35,    33,   -40,   -70,   -70,
      10,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     6,     8,     9,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    11,    17,    26,
      27,    31,    34,    37,    42,    45,    47,    49,    51,    53,
      55,    57,    69,     0,     2,    18,    19,     0,    26,    20,
      21,    22,    23,    24,    25,     1,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     3,    10,    14,     0,    13,    59,    62,
      68,    63,    60,    61,    64,    65,    66,    67,    58,    28,
      29,    30,    32,    33,    35,    36,    41,    40,    38,    39,
      43,    44,    46,    48,    50,    52,    54,     0,    70,    12,
       0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,    59,    24,   -70,   -70,     0,    27,    43,    45,    -5,
      37,    39,    40,    38,    41,    42,   -70,    -3,    44,    -7,
     -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    38,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    37,    69,    70,    62,    79,    35,    36,    19,    63,
      64,    65,    66,     1,     2,     3,     4,     5,     6,     7,
      45,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    46,    47,    48,    19,    75,    39,    40,    41,    42,
      43,    44,    86,    84,    76,   120,   119,    81,    77,    19,
      78,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    81,    81,   106,   107,   108,   109,     1,    71,
      72,    80,    85,   117,    87,    67,    68,     8,    73,    74,
      19,    19,     9,    10,    11,    12,    13,    14,    61,    99,
     100,   101,    49,    83,    50,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    81,    82,   102,   103,
     110,   111,   104,   105,   112,   114,   113,   121,     0,   115,
       0,   116,     0,     0,     0,   118
};

static const yytype_int8 yycheck[] =
{
       0,     8,    13,    14,    73,    18,     6,     7,     8,    78,
      79,    74,    75,     3,     4,     5,     6,     7,     8,     9,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     8,     9,    10,    34,    72,     9,    10,    11,    12,
      13,    14,    49,    68,    82,    85,    70,    87,    83,    49,
      17,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    87,    87,    69,    70,    71,    72,     3,    80,
      81,    84,    48,    80,    50,    11,    12,    67,    15,    16,
      80,    81,    72,    73,    74,    75,    76,    77,    86,    62,
      63,    64,    69,    34,    71,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    87,    88,    65,    66,
      73,    74,    67,    68,    75,    77,    76,   120,    -1,    78,
      -1,    79,    -1,    -1,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    67,    72,
      73,    74,    75,    76,    77,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,    94,    94,   108,    94,    95,
      95,    95,    95,    95,    95,     0,     8,     9,    10,    69,
      71,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    86,    73,    78,    79,    74,    75,    11,    12,    13,
      14,    80,    81,    15,    16,    72,    82,    83,    17,    18,
      84,    87,    88,    90,    68,    91,   108,    91,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      99,    99,   100,   101,   102,   103,   104,   108,   107,    70,
      85,   106
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    89,    90,    90,    91,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    99,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     3,     3,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* ident-expr: IDENT  */
#line 104 "parser.y"
          {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = AST_IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        (yyval.node) = ident_node;
    }
#line 1273 "parser.tab.c"
    break;

  case 5: /* primary-expression: ident-expr  */
#line 112 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1279 "parser.tab.c"
    break;

  case 6: /* primary-expression: NUMLIT  */
#line 113 "parser.y"
             {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = AST_NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        numlit_node->val.numlit.type = N_LLI;
        (yyval.node) = numlit_node;
    }
#line 1291 "parser.tab.c"
    break;

  case 7: /* primary-expression: FLOATLIT  */
#line 120 "parser.y"
               {
        ast_node *flit_node = calloc(1, sizeof(ast_node));
        flit_node->node_type = AST_NUMLIT;
        flit_node->val.numlit.val.real_val = yylval.real_val;
        flit_node->val.numlit.type = N_LLF;
        (yyval.node) = flit_node;
    }
#line 1303 "parser.tab.c"
    break;

  case 8: /* primary-expression: CHARLIT  */
#line 127 "parser.y"
              {
        ast_node *charlit_node = calloc(1, sizeof(ast_node));
        charlit_node->node_type = AST_CHARLIT;
        charlit_node->val.charlit.val = yylval.char_val;
        (yyval.node) = charlit_node;
    }
#line 1314 "parser.tab.c"
    break;

  case 9: /* primary-expression: STRLIT  */
#line 133 "parser.y"
             {
        ast_node *strlit_node = calloc(1, sizeof(ast_node));
        strlit_node->node_type = AST_NUMLIT;
        strlit_node->val.strlit.val = yylval.d_str_val.str_val;
        strlit_node->val.strlit.len = yylval.d_str_val.str_len;
        (yyval.node) = strlit_node;
    }
#line 1326 "parser.tab.c"
    break;

  case 10: /* primary-expression: '(' expression ')'  */
#line 140 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1332 "parser.tab.c"
    break;

  case 11: /* postfix-expression: primary-expression  */
#line 143 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1338 "parser.tab.c"
    break;

  case 12: /* postfix-expression: postfix-expression '[' expression ']'  */
#line 144 "parser.y"
                                            {(yyval.node) = create_unop_node(U_DEREF, create_binop_node(B_PLUS, (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1344 "parser.tab.c"
    break;

  case 13: /* postfix-expression: postfix-expression '.' ident-expr  */
#line 146 "parser.y"
                                        {(yyval.node) = create_binop_node(B_STRUCT_OFFSET, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1350 "parser.tab.c"
    break;

  case 14: /* postfix-expression: postfix-expression INDSEL ident-expr  */
#line 147 "parser.y"
                                           {(yyval.node) = create_binop_node(B_INDSEL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1356 "parser.tab.c"
    break;

  case 15: /* postfix-expression: postfix-expression PLUSPLUS  */
#line 148 "parser.y"
                                  {(yyval.node) = create_unop_node(U_POST_PLUSPLUS, (yyvsp[-1].node));}
#line 1362 "parser.tab.c"
    break;

  case 16: /* postfix-expression: postfix-expression MINUSMINUS  */
#line 149 "parser.y"
                                    {(yyval.node) = create_unop_node(U_POST_MINUSMINUS, (yyvsp[-1].node));}
#line 1368 "parser.tab.c"
    break;

  case 17: /* unary-expression: postfix-expression  */
#line 164 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1374 "parser.tab.c"
    break;

  case 18: /* unary-expression: PLUSPLUS unary-expression  */
#line 165 "parser.y"
                                {(yyval.node) = create_unop_node(U_PRE_PLUSPLUS, (yyvsp[0].node));}
#line 1380 "parser.tab.c"
    break;

  case 19: /* unary-expression: MINUSMINUS unary-expression  */
#line 166 "parser.y"
                                  {(yyval.node) = create_unop_node(U_PRE_MINUSMINUS, (yyvsp[0].node));}
#line 1386 "parser.tab.c"
    break;

  case 20: /* unary-expression: '&' cast-expression  */
#line 167 "parser.y"
                          {(yyval.node) = create_unop_node(U_ADDRESSOF, (yyvsp[0].node));}
#line 1392 "parser.tab.c"
    break;

  case 21: /* unary-expression: '*' cast-expression  */
#line 168 "parser.y"
                          {(yyval.node) = create_unop_node(U_DEREF, (yyvsp[0].node));}
#line 1398 "parser.tab.c"
    break;

  case 22: /* unary-expression: '+' cast-expression  */
#line 169 "parser.y"
                          {(yyval.node) = create_unop_node(U_POS, (yyvsp[0].node));}
#line 1404 "parser.tab.c"
    break;

  case 23: /* unary-expression: '-' cast-expression  */
#line 170 "parser.y"
                          {(yyval.node) = create_unop_node(U_NEG, (yyvsp[0].node));}
#line 1410 "parser.tab.c"
    break;

  case 24: /* unary-expression: '~' cast-expression  */
#line 171 "parser.y"
                          {(yyval.node) = create_unop_node(U_BIT_NOT, (yyvsp[0].node));}
#line 1416 "parser.tab.c"
    break;

  case 25: /* unary-expression: '!' cast-expression  */
#line 172 "parser.y"
                          {(yyval.node) = create_unop_node(U_NOT, (yyvsp[0].node));}
#line 1422 "parser.tab.c"
    break;

  case 26: /* cast-expression: unary-expression  */
#line 177 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1428 "parser.tab.c"
    break;

  case 27: /* multiplicative-expression: cast-expression  */
#line 181 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1434 "parser.tab.c"
    break;

  case 28: /* multiplicative-expression: multiplicative-expression '*' cast-expression  */
#line 182 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_TIMES, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1440 "parser.tab.c"
    break;

  case 29: /* multiplicative-expression: multiplicative-expression '/' cast-expression  */
#line 183 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_DIVIDE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1446 "parser.tab.c"
    break;

  case 30: /* multiplicative-expression: multiplicative-expression '%' cast-expression  */
#line 184 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_MOD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1452 "parser.tab.c"
    break;

  case 31: /* additive-expression: multiplicative-expression  */
#line 187 "parser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 1458 "parser.tab.c"
    break;

  case 32: /* additive-expression: additive-expression '+' multiplicative-expression  */
#line 188 "parser.y"
                                                        {(yyval.node) = create_binop_node(B_PLUS, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1464 "parser.tab.c"
    break;

  case 33: /* additive-expression: additive-expression '-' multiplicative-expression  */
#line 189 "parser.y"
                                                        {(yyval.node) = create_binop_node(B_MINUS, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1470 "parser.tab.c"
    break;

  case 34: /* shift-expression: additive-expression  */
#line 192 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1476 "parser.tab.c"
    break;

  case 35: /* shift-expression: shift-expression SHL additive-expression  */
#line 193 "parser.y"
                                               {(yyval.node) = create_binop_node(B_SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1482 "parser.tab.c"
    break;

  case 36: /* shift-expression: shift-expression SHR additive-expression  */
#line 194 "parser.y"
                                               {(yyval.node) = create_binop_node(B_SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1488 "parser.tab.c"
    break;

  case 37: /* relational-expression: shift-expression  */
#line 197 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1494 "parser.tab.c"
    break;

  case 38: /* relational-expression: relational-expression '<' shift-expression  */
#line 198 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_LT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1500 "parser.tab.c"
    break;

  case 39: /* relational-expression: relational-expression '>' shift-expression  */
#line 199 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_GT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1506 "parser.tab.c"
    break;

  case 40: /* relational-expression: relational-expression LEQ shift-expression  */
#line 200 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1512 "parser.tab.c"
    break;

  case 41: /* relational-expression: relational-expression GEQ shift-expression  */
#line 201 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1518 "parser.tab.c"
    break;

  case 42: /* equality-expression: relational-expression  */
#line 204 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1524 "parser.tab.c"
    break;

  case 43: /* equality-expression: equality-expression EQEQ relational-expression  */
#line 205 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1530 "parser.tab.c"
    break;

  case 44: /* equality-expression: equality-expression NEQ relational-expression  */
#line 206 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1536 "parser.tab.c"
    break;

  case 45: /* bitand-expression: equality-expression  */
#line 209 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1542 "parser.tab.c"
    break;

  case 46: /* bitand-expression: bitand-expression '&' equality-expression  */
#line 210 "parser.y"
                                                {(yyval.node) = create_binop_node(B_BIT_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1548 "parser.tab.c"
    break;

  case 47: /* bitxor-expression: bitand-expression  */
#line 213 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1554 "parser.tab.c"
    break;

  case 48: /* bitxor-expression: bitxor-expression '^' bitand-expression  */
#line 214 "parser.y"
                                              {(yyval.node) = create_binop_node(B_BIT_XOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1560 "parser.tab.c"
    break;

  case 49: /* bitor-expression: bitxor-expression  */
#line 217 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1566 "parser.tab.c"
    break;

  case 50: /* bitor-expression: bitor-expression '|' bitxor-expression  */
#line 218 "parser.y"
                                             {(yyval.node) = create_binop_node(B_BIT_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1572 "parser.tab.c"
    break;

  case 51: /* logand-expression: bitor-expression  */
#line 221 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1578 "parser.tab.c"
    break;

  case 52: /* logand-expression: logand-expression LOGAND bitor-expression  */
#line 222 "parser.y"
                                                {(yyval.node) = create_binop_node(B_LOG_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1584 "parser.tab.c"
    break;

  case 53: /* logor-expression: logand-expression  */
#line 225 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1590 "parser.tab.c"
    break;

  case 54: /* logor-expression: logor-expression LOGOR logand-expression  */
#line 226 "parser.y"
                                               {(yyval.node) = create_binop_node(B_LOG_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1596 "parser.tab.c"
    break;

  case 55: /* conditional-expression: logor-expression  */
#line 229 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1602 "parser.tab.c"
    break;

  case 56: /* conditional-expression: logor-expression '?' expression ':' conditional-expression  */
#line 230 "parser.y"
                                                                 {(yyval.node) = create_triop_node(T_TERNARY, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1608 "parser.tab.c"
    break;

  case 57: /* assignment-expression: conditional-expression  */
#line 233 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 1614 "parser.tab.c"
    break;

  case 58: /* assignment-expression: unary-expression '=' assignment-expression  */
#line 234 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_EQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1620 "parser.tab.c"
    break;

  case 59: /* assignment-expression: unary-expression TIMESEQ assignment-expression  */
#line 235 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_TIMESEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1626 "parser.tab.c"
    break;

  case 60: /* assignment-expression: unary-expression DIVEQ assignment-expression  */
#line 236 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_DIVEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1632 "parser.tab.c"
    break;

  case 61: /* assignment-expression: unary-expression MODEQ assignment-expression  */
#line 237 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_MODEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1638 "parser.tab.c"
    break;

  case 62: /* assignment-expression: unary-expression PLUSEQ assignment-expression  */
#line 238 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_PLUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1644 "parser.tab.c"
    break;

  case 63: /* assignment-expression: unary-expression MINUSEQ assignment-expression  */
#line 239 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_MINUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1650 "parser.tab.c"
    break;

  case 64: /* assignment-expression: unary-expression SHLEQ assignment-expression  */
#line 240 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_SHLEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1656 "parser.tab.c"
    break;

  case 65: /* assignment-expression: unary-expression SHREQ assignment-expression  */
#line 241 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_SHREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1662 "parser.tab.c"
    break;

  case 66: /* assignment-expression: unary-expression ANDEQ assignment-expression  */
#line 242 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_BIT_ANDEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1668 "parser.tab.c"
    break;

  case 67: /* assignment-expression: unary-expression OREQ assignment-expression  */
#line 243 "parser.y"
                                                  {(yyval.node) = create_binop_node(B_BIT_OREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1674 "parser.tab.c"
    break;

  case 68: /* assignment-expression: unary-expression XOREQ assignment-expression  */
#line 244 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_BIT_XOREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1680 "parser.tab.c"
    break;

  case 69: /* expression: assignment-expression  */
#line 247 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1686 "parser.tab.c"
    break;

  case 70: /* expression: expression ',' assignment-expression  */
#line 248 "parser.y"
                                           {(yyval.node) = create_binop_node(B_ASSIGN_LIST, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1692 "parser.tab.c"
    break;

  case 71: /* expression-stmt: expression ';'  */
#line 255 "parser.y"
                   {
        print_ast_tree((yyvsp[-1].node));
        // free_ast_tree($1);
        (yyval.node) = NULL;
    }
#line 1702 "parser.tab.c"
    break;


#line 1706 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 261 "parser.y"


int main() {
    yydebug = 0;
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
