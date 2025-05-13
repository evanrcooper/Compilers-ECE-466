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
    struct symbol_table_dll_node *CURRENT_SCOPE;
    struct type_builder CURRENT_TYPE_BUILDER = {0};
    int CURRENT_STORAGE_CLASS = 0;

#line 80 "parser.tab.c"

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
  YYSYMBOL_CASE = 30,                      /* CASE  */
  YYSYMBOL_CONST = 31,                     /* CONST  */
  YYSYMBOL_DEFAULT = 32,                   /* DEFAULT  */
  YYSYMBOL_DOUBLE = 33,                    /* DOUBLE  */
  YYSYMBOL_ENUM = 34,                      /* ENUM  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_INLINE = 36,                    /* INLINE  */
  YYSYMBOL_RESTRICT = 37,                  /* RESTRICT  */
  YYSYMBOL_STRUCT = 38,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 39,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 40,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 41,                     /* UNION  */
  YYSYMBOL_VOLATILE = 42,                  /* VOLATILE  */
  YYSYMBOL__BOOL = 43,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 44,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 45,                /* _IMAGINARY  */
  YYSYMBOL_AUTO = 46,                      /* AUTO  */
  YYSYMBOL_BREAK = 47,                     /* BREAK  */
  YYSYMBOL_CHAR = 48,                      /* CHAR  */
  YYSYMBOL_CONTINUE = 49,                  /* CONTINUE  */
  YYSYMBOL_DO = 50,                        /* DO  */
  YYSYMBOL_ELSE = 51,                      /* ELSE  */
  YYSYMBOL_EXTERN = 52,                    /* EXTERN  */
  YYSYMBOL_FOR = 53,                       /* FOR  */
  YYSYMBOL_GOTO = 54,                      /* GOTO  */
  YYSYMBOL_IF = 55,                        /* IF  */
  YYSYMBOL_INT = 56,                       /* INT  */
  YYSYMBOL_LONG = 57,                      /* LONG  */
  YYSYMBOL_REGISTER = 58,                  /* REGISTER  */
  YYSYMBOL_RETURN = 59,                    /* RETURN  */
  YYSYMBOL_SHORT = 60,                     /* SHORT  */
  YYSYMBOL_SIGNED = 61,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 62,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 63,                    /* STATIC  */
  YYSYMBOL_UNSIGNED = 64,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 65,                      /* VOID  */
  YYSYMBOL_WHILE = 66,                     /* WHILE  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* '['  */
  YYSYMBOL_70_ = 70,                       /* ']'  */
  YYSYMBOL_71_ = 71,                       /* '&'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '+'  */
  YYSYMBOL_74_ = 74,                       /* '-'  */
  YYSYMBOL_75_ = 75,                       /* '~'  */
  YYSYMBOL_76_ = 76,                       /* '!'  */
  YYSYMBOL_77_ = 77,                       /* '/'  */
  YYSYMBOL_78_ = 78,                       /* '%'  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_80_ = 80,                       /* '>'  */
  YYSYMBOL_81_ = 81,                       /* '^'  */
  YYSYMBOL_82_ = 82,                       /* '|'  */
  YYSYMBOL_83_ = 83,                       /* '?'  */
  YYSYMBOL_84_ = 84,                       /* ':'  */
  YYSYMBOL_85_ = 85,                       /* '='  */
  YYSYMBOL_86_ = 86,                       /* ','  */
  YYSYMBOL_87_ = 87,                       /* ';'  */
  YYSYMBOL_88_ = 88,                       /* '}'  */
  YYSYMBOL_89_ = 89,                       /* '{'  */
  YYSYMBOL_YYACCEPT = 90,                  /* $accept  */
  YYSYMBOL_program = 91,                   /* program  */
  YYSYMBOL_92_ident_expr = 92,             /* ident-expr  */
  YYSYMBOL_93_numlit_expr = 93,            /* numlit-expr  */
  YYSYMBOL_94_primary_expression = 94,     /* primary-expression  */
  YYSYMBOL_95_postfix_expression = 95,     /* postfix-expression  */
  YYSYMBOL_96_unary_expression = 96,       /* unary-expression  */
  YYSYMBOL_97_cast_expression = 97,        /* cast-expression  */
  YYSYMBOL_98_multiplicative_expression = 98, /* multiplicative-expression  */
  YYSYMBOL_99_additive_expression = 99,    /* additive-expression  */
  YYSYMBOL_100_shift_expression = 100,     /* shift-expression  */
  YYSYMBOL_101_relational_expression = 101, /* relational-expression  */
  YYSYMBOL_102_equality_expression = 102,  /* equality-expression  */
  YYSYMBOL_103_bitand_expression = 103,    /* bitand-expression  */
  YYSYMBOL_104_bitxor_expression = 104,    /* bitxor-expression  */
  YYSYMBOL_105_bitor_expression = 105,     /* bitor-expression  */
  YYSYMBOL_106_logand_expression = 106,    /* logand-expression  */
  YYSYMBOL_107_logor_expression = 107,     /* logor-expression  */
  YYSYMBOL_108_conditional_expression = 108, /* conditional-expression  */
  YYSYMBOL_109_assignment_expression = 109, /* assignment-expression  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_declaration = 111,              /* declaration  */
  YYSYMBOL_112_declaration_specifiers = 112, /* declaration-specifiers  */
  YYSYMBOL_113_declarator_list = 113,      /* declarator-list  */
  YYSYMBOL_114_storage_class_specifier = 114, /* storage-class-specifier  */
  YYSYMBOL_115_type_specifier = 115,       /* type-specifier  */
  YYSYMBOL_declarator = 116,               /* declarator  */
  YYSYMBOL_117_direct_declarator = 117,    /* direct-declarator  */
  YYSYMBOL_pointer = 118,                  /* pointer  */
  YYSYMBOL_119_type_specifier_list = 119,  /* type-specifier-list  */
  YYSYMBOL_statement = 120,                /* statement  */
  YYSYMBOL_121_labeled_statement = 121,    /* labeled-statement  */
  YYSYMBOL_122_compound_statement = 122,   /* compound-statement  */
  YYSYMBOL_123_compound_start = 123,       /* compound-start  */
  YYSYMBOL_124_compound_body = 124,        /* compound-body  */
  YYSYMBOL_125_block_item_list = 125,      /* block-item-list  */
  YYSYMBOL_126_block_item = 126,           /* block-item  */
  YYSYMBOL_127_expression_statement = 127, /* expression-statement  */
  YYSYMBOL_128_selection_statement = 128,  /* selection-statement  */
  YYSYMBOL_129_expression_opt = 129,       /* expression-opt  */
  YYSYMBOL_130_iteration_statement = 130,  /* iteration-statement  */
  YYSYMBOL_131_jump_statement = 131,       /* jump-statement  */
  YYSYMBOL_132_external_declaration = 132, /* external-declaration  */
  YYSYMBOL_133_function_definition = 133   /* function-definition  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

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
       2,     2,     2,    76,     2,     2,     2,    78,    71,     2,
      67,    68,    72,    73,    86,    74,     2,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    87,
      79,    85,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,    82,    88,    75,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   135,   138,   152,   161,   162,   165,   172,
     178,   185,   188,   189,   190,   204,   205,   206,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   223,   227,
     228,   229,   230,   233,   234,   235,   238,   239,   240,   243,
     244,   245,   246,   247,   250,   251,   252,   255,   256,   259,
     260,   263,   264,   267,   268,   271,   272,   275,   276,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   293,   294,   303,   395,   396,   397,   398,   401,   402,
     405,   412,   419,   426,   435,   446,   457,   471,   488,   500,
     512,   533,   541,   544,   545,   546,   553,   558,   561,   562,
     569,   570,   602,   603,   604,   605,   606,   607,   610,   631,
     639,   642,   647,   650,   651,   669,   670,   673,   674,   677,
     685,   695,   696,   699,   706,   713,   724,   736,   741,   746,
     756,   760,   761,   767
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
  "ANDEQ", "OREQ", "ELLIPSIS", "CASE", "CONST", "DEFAULT", "DOUBLE",
  "ENUM", "FLOAT", "INLINE", "RESTRICT", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "VOLATILE", "_BOOL", "_COMPLEX", "_IMAGINARY", "AUTO", "BREAK",
  "CHAR", "CONTINUE", "DO", "ELSE", "EXTERN", "FOR", "GOTO", "IF", "INT",
  "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "UNSIGNED", "VOID", "WHILE", "'('", "')'", "'['", "']'", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "':'", "'='", "','", "';'", "'}'", "'{'", "$accept", "program",
  "ident-expr", "numlit-expr", "primary-expression", "postfix-expression",
  "unary-expression", "cast-expression", "multiplicative-expression",
  "additive-expression", "shift-expression", "relational-expression",
  "equality-expression", "bitand-expression", "bitxor-expression",
  "bitor-expression", "logand-expression", "logor-expression",
  "conditional-expression", "assignment-expression", "expression",
  "declaration", "declaration-specifiers", "declarator-list",
  "storage-class-specifier", "type-specifier", "declarator",
  "direct-declarator", "pointer", "type-specifier-list", "statement",
  "labeled-statement", "compound-statement", "compound-start",
  "compound-body", "block-item-list", "block-item", "expression-statement",
  "selection-statement", "expression-opt", "iteration-statement",
  "jump-statement", "external-declaration", "function-definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,   182,   -99,   -99,   -99,   -99,   -99,   -99,    95,    95,
     -99,   -73,   -99,   -35,   287,   -99,    -7,    61,     5,   -99,
     -99,   -99,    95,   -99,   -99,    95,   -99,   -99,   -99,     9,
      95,    95,    95,    95,    95,    95,    95,   -99,    -9,    -3,
     -99,   -99,    24,    20,   -99,   -15,     0,    57,     4,   119,
      19,    11,    13,    89,    -6,   -99,   -99,    50,   -99,     8,
     321,    99,   321,   -99,   -99,   -99,   256,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    64,    95,
      54,    95,    67,    71,   -99,    95,   -33,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   287,   -99,   -99,    61,    86,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,   -99,     8,    93,   -99,    53,    72,   -18,    22,
     -99,   -99,   -99,   -99,     8,   -99,    84,   256,   -99,   106,
      87,   -99,   -32,   -99,   -31,   -99,   -99,   -99,   -99,   -20,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -15,   -15,     0,     0,    57,    57,
      57,    57,     4,     4,   119,    19,    11,    13,    89,   -25,
     -99,   107,   -99,     8,   -99,   -99,   108,    15,   -18,   -99,
     -99,   -99,    95,    95,   287,   287,   -99,    95,   -99,   -99,
     -99,   -99,   109,   -30,    90,   129,   -99,   -99,   -99,    94,
      95,   287,   -99,   115,   -99,   287,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,     5,     9,    10,     8,     0,     0,
      82,     0,    84,     0,     0,    80,     0,     0,     0,    85,
      87,    83,   121,    86,    88,     0,    81,    89,    90,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   111,     6,
       7,    12,    18,    28,    29,    33,    36,    39,    44,    47,
      49,    51,    53,    55,    57,    59,    71,     0,   130,     0,
      75,   100,    77,   131,   102,   103,     0,   104,   105,   106,
     107,     3,   132,     6,    19,    20,   128,   127,     0,   121,
       0,     0,   122,     0,    27,     0,     0,    28,    21,    22,
      23,    24,    25,    26,   110,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,    98,    93,     0,    78,    92,     0,
      74,   101,    76,   115,     0,   116,     0,   112,   113,     0,
       0,   126,     0,   129,     0,    11,   108,    15,    14,     0,
      61,    64,    70,    65,    62,    63,    66,    67,    68,    69,
      60,    30,    31,    32,    34,    35,    37,    38,    43,    42,
      40,    41,    45,    46,    48,    50,    52,    54,    56,     0,
      72,     0,    99,     0,    73,   133,     0,     0,    91,    78,
     109,   114,     0,   121,     0,     0,    13,     0,    94,    79,
      97,    96,     0,     0,     0,   119,   123,    58,    95,     0,
     121,     0,   124,     0,   120,     0,   125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,    -1,   -13,   -99,   -99,    -5,   -26,    29,    32,
     -98,    28,    68,    69,    70,    73,    65,   -99,   -11,   176,
      48,   197,    66,   -99,   -99,   -99,   -62,    60,    74,   139,
       1,   -99,    75,   -99,   -99,   -99,    62,   -99,   -99,   -78,
     -99,   -99,   -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    73,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   143,   144,   136,    60,    61,   137,   138,   139,    62,
     145,    64,    65,    66,   146,   147,   148,    67,    68,    83,
      69,    70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,   150,    63,    74,    75,    88,    89,    90,    91,    92,
      93,     3,   129,    39,    76,    78,    80,   119,   120,     4,
      84,   178,   179,   180,   181,     3,    87,    87,    87,    87,
      87,    87,    96,    97,    98,   155,   204,   205,   219,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   196,
     206,   197,    77,   131,   131,   131,   131,   112,   135,   207,
      79,   131,   113,   114,     3,    39,   131,    59,   117,   118,
      82,   191,    81,   115,   116,   133,    85,   130,    86,    94,
     134,    95,   199,   121,   122,   211,   171,   172,   173,   133,
     125,    99,   126,   100,    39,   127,   156,   157,     3,     4,
       5,     6,     7,     8,     9,   111,   128,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,   214,   140,    82,   142,   152,
     149,   209,   135,   154,   123,   124,   131,   132,   135,   193,
     194,   151,   223,   135,   174,   175,    39,    12,   159,   176,
     177,   182,   183,   131,   158,    19,    20,    25,   153,    23,
      24,    38,    30,    27,    28,   134,    31,    32,    33,    34,
      35,    36,   200,   202,   203,   208,   210,   220,   189,   218,
     221,   222,     2,   225,   212,     3,     4,     5,     6,     7,
       8,     9,   135,   184,   188,   185,   217,   186,    58,   198,
     141,   187,    87,    39,    39,   215,   216,     0,   192,   201,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
      39,     0,   224,     0,    39,     0,   226,     0,    10,    11,
      12,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     213,    82,     0,    31,    32,    33,    34,    35,    36,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    82,    37,
       0,    38,     0,     0,     0,     0,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,   190,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,    33,
      34,    35,    36,     0,    11,     0,    13,    14,     0,     0,
      16,    17,    18,    37,     0,    38,    22,     0,     0,    25,
       0,     0,     0,    29,    30,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    10,     0,    12,
       0,     0,     0,    15,    37,     0,    38,    19,    20,    21,
       0,    23,    24,     0,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
       1,    79,     1,     8,     9,    31,    32,    33,    34,    35,
      36,     3,    18,    14,    87,    14,    17,    13,    14,     4,
      25,   119,   120,   121,   122,     3,    31,    32,    33,    34,
      35,    36,     8,     9,    10,    68,    68,    68,    68,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    67,
      70,    69,    87,    86,    86,    86,    86,    72,    59,    84,
      67,    86,    77,    78,     3,    66,    86,     1,    11,    12,
      22,   133,    67,    73,    74,    67,    67,    83,    30,    88,
      72,    84,   144,    79,    80,    70,   112,   113,   114,    67,
      71,    67,    81,    69,    95,    82,    95,    98,     3,     4,
       5,     6,     7,     8,     9,    85,    17,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   203,    60,    79,    62,    81,
      66,   193,   133,    85,    15,    16,    86,    87,   139,    86,
      87,    87,   220,   144,   115,   116,   147,    48,   100,   117,
     118,   123,   124,    86,    68,    56,    57,    62,    87,    60,
      61,    89,    67,    64,    65,    72,    71,    72,    73,    74,
      75,    76,    88,    67,    87,    68,    68,    87,   130,    70,
      51,    87,     0,    68,   197,     3,     4,     5,     6,     7,
       8,     9,   193,   125,   129,   126,   207,   127,     1,   139,
      61,   128,   207,   204,   205,   204,   205,    -1,   134,   147,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,    -1,   221,    -1,   225,    -1,   225,    -1,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     202,   203,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,   220,    87,
      -1,    89,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,   131,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    47,    -1,    49,    50,    -1,    -1,
      53,    54,    55,    87,    -1,    89,    59,    -1,    -1,    62,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    46,    -1,    48,
      -1,    -1,    -1,    52,    87,    -1,    89,    56,    57,    58,
      -1,    60,    61,    -1,    63,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    91,     0,     3,     4,     5,     6,     7,     8,     9,
      46,    47,    48,    49,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    71,    72,    73,    74,    75,    76,    87,    89,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     114,   115,   119,   120,   121,   122,   123,   127,   128,   130,
     131,   132,   133,    92,    96,    96,    87,    87,   120,    67,
      92,    67,   110,   129,    96,    67,   110,    96,    97,    97,
      97,    97,    97,    97,    88,    84,     8,     9,    10,    67,
      69,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    85,    72,    77,    78,    73,    74,    11,    12,    13,
      14,    79,    80,    15,    16,    71,    81,    82,    17,    18,
      83,    86,    87,    67,    72,    92,   113,   116,   117,   118,
     112,   119,   112,   111,   112,   120,   124,   125,   126,    66,
     129,    87,   110,    87,   110,    68,   120,    92,    68,   110,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   101,   101,   102,   103,   104,   105,   106,   110,
     109,   116,   118,    86,    87,   122,    67,    69,   117,   116,
      88,   126,    67,    87,    68,    68,    70,    84,    68,   116,
      68,    70,    93,   110,   129,   120,   120,   108,    70,    68,
      87,    51,    87,   129,   120,    68,   120
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   111,   112,   112,   112,   112,   113,   113,
     114,   114,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   121,   122,
     122,   123,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     3,     3,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     2,     1,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     4,     3,     3,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     1,     1,     1,     2,     1,     1,     1,     2,     5,
       7,     0,     1,     5,     7,     9,     3,     2,     2,     3,
       1,     1,     1,     3
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
  case 3: /* program: program external-declaration  */
#line 135 "parser.y"
                                   {print_ast_tree((yyvsp[0].node));}
#line 1405 "parser.tab.c"
    break;

  case 4: /* ident-expr: IDENT  */
#line 138 "parser.y"
          {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = AST_IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        ident_node->val.ident.symbol = find_symbol_in_scope(ident_node->val.ident.ident_name, CURRENT_SCOPE);

        if (!ident_node->val.ident.symbol) {
            printf("Warning: unresolved identifier '%s'\n", ident_node->val.ident.ident_name);
        }

        (yyval.node) = ident_node;
    }
#line 1422 "parser.tab.c"
    break;

  case 5: /* numlit-expr: NUMLIT  */
#line 152 "parser.y"
           {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = AST_NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        numlit_node->val.numlit.type = N_LLI;
        (yyval.node) = numlit_node;
    }
#line 1434 "parser.tab.c"
    break;

  case 6: /* primary-expression: ident-expr  */
#line 161 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1440 "parser.tab.c"
    break;

  case 7: /* primary-expression: numlit-expr  */
#line 162 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1448 "parser.tab.c"
    break;

  case 8: /* primary-expression: FLOATLIT  */
#line 165 "parser.y"
               {
        ast_node *flit_node = calloc(1, sizeof(ast_node));
        flit_node->node_type = AST_NUMLIT;
        flit_node->val.numlit.val.real_val = yylval.real_val;
        flit_node->val.numlit.type = N_LLF;
        (yyval.node) = flit_node;
    }
#line 1460 "parser.tab.c"
    break;

  case 9: /* primary-expression: CHARLIT  */
#line 172 "parser.y"
              {
        ast_node *charlit_node = calloc(1, sizeof(ast_node));
        charlit_node->node_type = AST_CHARLIT;
        charlit_node->val.charlit.val = yylval.char_val;
        (yyval.node) = charlit_node;
    }
#line 1471 "parser.tab.c"
    break;

  case 10: /* primary-expression: STRLIT  */
#line 178 "parser.y"
             {
        ast_node *strlit_node = calloc(1, sizeof(ast_node));
        strlit_node->node_type = AST_STRLIT;
        strlit_node->val.strlit.val = yylval.d_str_val.str_val;
        strlit_node->val.strlit.len = yylval.d_str_val.str_len;
        (yyval.node) = strlit_node;
    }
#line 1483 "parser.tab.c"
    break;

  case 11: /* primary-expression: '(' expression ')'  */
#line 185 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1489 "parser.tab.c"
    break;

  case 12: /* postfix-expression: primary-expression  */
#line 188 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1495 "parser.tab.c"
    break;

  case 13: /* postfix-expression: postfix-expression '[' expression ']'  */
#line 189 "parser.y"
                                            {(yyval.node) = create_unop_node(U_DEREF, create_binop_node(B_PLUS, (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1501 "parser.tab.c"
    break;

  case 14: /* postfix-expression: postfix-expression '(' ')'  */
#line 190 "parser.y"
                                 {
        if ((yyvsp[-2].node)->node_type != AST_IDENT) {
            yyerror("Impossible Function Call");
        }
        struct symbol_table_entry_ll_node *entry = find_symbol_in_scope((yyvsp[-2].node)->val.ident.ident_name, CURRENT_SCOPE);
        free((yyvsp[-2].node));
        if (!entry) {
            yyerror("Unresolved Function Call");
        }
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FUNCTION_CALL;
        node->val.function_call.fn = entry;
        (yyval.node) = node;
    }
#line 1520 "parser.tab.c"
    break;

  case 15: /* postfix-expression: postfix-expression INDSEL ident-expr  */
#line 204 "parser.y"
                                           {(yyval.node) = create_binop_node(B_INDSEL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1526 "parser.tab.c"
    break;

  case 16: /* postfix-expression: postfix-expression PLUSPLUS  */
#line 205 "parser.y"
                                  {(yyval.node) = create_unop_node(U_POST_PLUSPLUS, (yyvsp[-1].node));}
#line 1532 "parser.tab.c"
    break;

  case 17: /* postfix-expression: postfix-expression MINUSMINUS  */
#line 206 "parser.y"
                                    {(yyval.node) = create_unop_node(U_POST_MINUSMINUS, (yyvsp[-1].node));}
#line 1538 "parser.tab.c"
    break;

  case 18: /* unary-expression: postfix-expression  */
#line 210 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1544 "parser.tab.c"
    break;

  case 19: /* unary-expression: PLUSPLUS unary-expression  */
#line 211 "parser.y"
                                {(yyval.node) = create_unop_node(U_PRE_PLUSPLUS, (yyvsp[0].node));}
#line 1550 "parser.tab.c"
    break;

  case 20: /* unary-expression: MINUSMINUS unary-expression  */
#line 212 "parser.y"
                                  {(yyval.node) = create_unop_node(U_PRE_MINUSMINUS, (yyvsp[0].node));}
#line 1556 "parser.tab.c"
    break;

  case 21: /* unary-expression: '&' cast-expression  */
#line 213 "parser.y"
                          {(yyval.node) = create_unop_node(U_ADDRESSOF, (yyvsp[0].node));}
#line 1562 "parser.tab.c"
    break;

  case 22: /* unary-expression: '*' cast-expression  */
#line 214 "parser.y"
                          {(yyval.node) = create_unop_node(U_DEREF, (yyvsp[0].node));}
#line 1568 "parser.tab.c"
    break;

  case 23: /* unary-expression: '+' cast-expression  */
#line 215 "parser.y"
                          {(yyval.node) = create_unop_node(U_POS, (yyvsp[0].node));}
#line 1574 "parser.tab.c"
    break;

  case 24: /* unary-expression: '-' cast-expression  */
#line 216 "parser.y"
                          {(yyval.node) = create_unop_node(U_NEG, (yyvsp[0].node));}
#line 1580 "parser.tab.c"
    break;

  case 25: /* unary-expression: '~' cast-expression  */
#line 217 "parser.y"
                          {(yyval.node) = create_unop_node(U_BIT_NOT, (yyvsp[0].node));}
#line 1586 "parser.tab.c"
    break;

  case 26: /* unary-expression: '!' cast-expression  */
#line 218 "parser.y"
                          {(yyval.node) = create_unop_node(U_NOT, (yyvsp[0].node));}
#line 1592 "parser.tab.c"
    break;

  case 27: /* unary-expression: SIZEOF unary-expression  */
#line 219 "parser.y"
                              {(yyval.node) = create_unop_node(U_SIZEOF_EXPRESSION, (yyvsp[0].node));}
#line 1598 "parser.tab.c"
    break;

  case 28: /* cast-expression: unary-expression  */
#line 223 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1604 "parser.tab.c"
    break;

  case 29: /* multiplicative-expression: cast-expression  */
#line 227 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1610 "parser.tab.c"
    break;

  case 30: /* multiplicative-expression: multiplicative-expression '*' cast-expression  */
#line 228 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_TIMES, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1616 "parser.tab.c"
    break;

  case 31: /* multiplicative-expression: multiplicative-expression '/' cast-expression  */
#line 229 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_DIVIDE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1622 "parser.tab.c"
    break;

  case 32: /* multiplicative-expression: multiplicative-expression '%' cast-expression  */
#line 230 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_MOD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1628 "parser.tab.c"
    break;

  case 33: /* additive-expression: multiplicative-expression  */
#line 233 "parser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 1634 "parser.tab.c"
    break;

  case 34: /* additive-expression: additive-expression '+' multiplicative-expression  */
#line 234 "parser.y"
                                                        {(yyval.node) = create_binop_node(B_PLUS, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1640 "parser.tab.c"
    break;

  case 35: /* additive-expression: additive-expression '-' multiplicative-expression  */
#line 235 "parser.y"
                                                        {(yyval.node) = create_binop_node(B_MINUS, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1646 "parser.tab.c"
    break;

  case 36: /* shift-expression: additive-expression  */
#line 238 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1652 "parser.tab.c"
    break;

  case 37: /* shift-expression: shift-expression SHL additive-expression  */
#line 239 "parser.y"
                                               {(yyval.node) = create_binop_node(B_SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1658 "parser.tab.c"
    break;

  case 38: /* shift-expression: shift-expression SHR additive-expression  */
#line 240 "parser.y"
                                               {(yyval.node) = create_binop_node(B_SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1664 "parser.tab.c"
    break;

  case 39: /* relational-expression: shift-expression  */
#line 243 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1670 "parser.tab.c"
    break;

  case 40: /* relational-expression: relational-expression '<' shift-expression  */
#line 244 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_LT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1676 "parser.tab.c"
    break;

  case 41: /* relational-expression: relational-expression '>' shift-expression  */
#line 245 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_GT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1682 "parser.tab.c"
    break;

  case 42: /* relational-expression: relational-expression LEQ shift-expression  */
#line 246 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1688 "parser.tab.c"
    break;

  case 43: /* relational-expression: relational-expression GEQ shift-expression  */
#line 247 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1694 "parser.tab.c"
    break;

  case 44: /* equality-expression: relational-expression  */
#line 250 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1700 "parser.tab.c"
    break;

  case 45: /* equality-expression: equality-expression EQEQ relational-expression  */
#line 251 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1706 "parser.tab.c"
    break;

  case 46: /* equality-expression: equality-expression NEQ relational-expression  */
#line 252 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1712 "parser.tab.c"
    break;

  case 47: /* bitand-expression: equality-expression  */
#line 255 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1718 "parser.tab.c"
    break;

  case 48: /* bitand-expression: bitand-expression '&' equality-expression  */
#line 256 "parser.y"
                                                {(yyval.node) = create_binop_node(B_BIT_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1724 "parser.tab.c"
    break;

  case 49: /* bitxor-expression: bitand-expression  */
#line 259 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1730 "parser.tab.c"
    break;

  case 50: /* bitxor-expression: bitxor-expression '^' bitand-expression  */
#line 260 "parser.y"
                                              {(yyval.node) = create_binop_node(B_BIT_XOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1736 "parser.tab.c"
    break;

  case 51: /* bitor-expression: bitxor-expression  */
#line 263 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1742 "parser.tab.c"
    break;

  case 52: /* bitor-expression: bitor-expression '|' bitxor-expression  */
#line 264 "parser.y"
                                             {(yyval.node) = create_binop_node(B_BIT_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1748 "parser.tab.c"
    break;

  case 53: /* logand-expression: bitor-expression  */
#line 267 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1754 "parser.tab.c"
    break;

  case 54: /* logand-expression: logand-expression LOGAND bitor-expression  */
#line 268 "parser.y"
                                                {(yyval.node) = create_binop_node(B_LOG_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1760 "parser.tab.c"
    break;

  case 55: /* logor-expression: logand-expression  */
#line 271 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1766 "parser.tab.c"
    break;

  case 56: /* logor-expression: logor-expression LOGOR logand-expression  */
#line 272 "parser.y"
                                               {(yyval.node) = create_binop_node(B_LOG_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1772 "parser.tab.c"
    break;

  case 57: /* conditional-expression: logor-expression  */
#line 275 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1778 "parser.tab.c"
    break;

  case 58: /* conditional-expression: logor-expression '?' expression ':' conditional-expression  */
#line 276 "parser.y"
                                                                 {(yyval.node) = create_triop_node(T_TERNARY, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1784 "parser.tab.c"
    break;

  case 59: /* assignment-expression: conditional-expression  */
#line 279 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 1790 "parser.tab.c"
    break;

  case 60: /* assignment-expression: unary-expression '=' assignment-expression  */
#line 280 "parser.y"
                                                 {(yyval.node) = create_binop_node(B_EQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1796 "parser.tab.c"
    break;

  case 61: /* assignment-expression: unary-expression TIMESEQ assignment-expression  */
#line 281 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_TIMESEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1802 "parser.tab.c"
    break;

  case 62: /* assignment-expression: unary-expression DIVEQ assignment-expression  */
#line 282 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_DIVEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1808 "parser.tab.c"
    break;

  case 63: /* assignment-expression: unary-expression MODEQ assignment-expression  */
#line 283 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_MODEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1814 "parser.tab.c"
    break;

  case 64: /* assignment-expression: unary-expression PLUSEQ assignment-expression  */
#line 284 "parser.y"
                                                    {(yyval.node) = create_binop_node(B_PLUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1820 "parser.tab.c"
    break;

  case 65: /* assignment-expression: unary-expression MINUSEQ assignment-expression  */
#line 285 "parser.y"
                                                     {(yyval.node) = create_binop_node(B_MINUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1826 "parser.tab.c"
    break;

  case 66: /* assignment-expression: unary-expression SHLEQ assignment-expression  */
#line 286 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_SHLEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1832 "parser.tab.c"
    break;

  case 67: /* assignment-expression: unary-expression SHREQ assignment-expression  */
#line 287 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_SHREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1838 "parser.tab.c"
    break;

  case 68: /* assignment-expression: unary-expression ANDEQ assignment-expression  */
#line 288 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_BIT_ANDEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1844 "parser.tab.c"
    break;

  case 69: /* assignment-expression: unary-expression OREQ assignment-expression  */
#line 289 "parser.y"
                                                  {(yyval.node) = create_binop_node(B_BIT_OREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1850 "parser.tab.c"
    break;

  case 70: /* assignment-expression: unary-expression XOREQ assignment-expression  */
#line 290 "parser.y"
                                                   {(yyval.node) = create_binop_node(B_BIT_XOREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1856 "parser.tab.c"
    break;

  case 71: /* expression: assignment-expression  */
#line 293 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1862 "parser.tab.c"
    break;

  case 72: /* expression: expression ',' assignment-expression  */
#line 294 "parser.y"
                                           {(yyval.node) = create_binop_node(B_COMMA, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1868 "parser.tab.c"
    break;

  case 73: /* declaration: declaration-specifiers declarator-list ';'  */
#line 303 "parser.y"
                                               {
        if (!(yyvsp[-1].node)) {
            yyerror("no declarator provided");
        }

        ast_node *current_declarator_comma_node = (yyvsp[-1].node);

        // Process all comma-separated declarators except the final one
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
                        yyerror("unknown AST node in declarator traversal");
                }
            }

            int CURRENT_SYMBOL_SCOPE = 0;
            switch (CURRENT_SCOPE->scope) {
                case TABLE_GLOBAL:
                    CURRENT_SYMBOL_SCOPE = SYM_GLOBAL;
                    if (CURRENT_STORAGE_CLASS == SC_AUTO || CURRENT_STORAGE_CLASS == SC_REGISTER) {
                        yyerror("storage class not allowed in global scope");
                    } else if (!CURRENT_STORAGE_CLASS) {
                        CURRENT_STORAGE_CLASS = SC_EXTERN_IMPLICIT;
                    }
                    break;
                case TABLE_FUNCTION:
                case TABLE_BLOCK:
                    CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                    break;
                default:
                    yyerror("unrecognized table scope");
            }

            struct symbol_table_entry_ll_node *node = insert_symbol_var(current_declarator->val.ident.ident_name, CURRENT_SYMBOL_SCOPE, CURRENT_STORAGE_CLASS);
            node->specs.variable.is_defined = 1;
            node->specs.variable.type = build_full_type_from_declarator(current_declarator, &CURRENT_TYPE_BUILDER);

            current_declarator_comma_node = current_declarator_comma_node->val.binop.left;
        }

        // Handle the final (leftmost) declarator (left == NULL)
        ast_node *first_declarator = current_declarator_comma_node->val.binop.right;
        while (first_declarator->node_type != AST_IDENT) {
            switch (first_declarator->node_type) {
                case AST_UNOP:
                    first_declarator = first_declarator->val.unop.center;
                    break;
                case AST_TYPE_MOD:
                    first_declarator = first_declarator->val.type_mod.next;
                    break;
                default:
                    yyerror("unknown AST node in final declarator traversal");
            }
        }

        int CURRENT_SYMBOL_SCOPE = 0;
        switch (CURRENT_SCOPE->scope) {
            case TABLE_GLOBAL:
                CURRENT_SYMBOL_SCOPE = SYM_GLOBAL;
                if (CURRENT_STORAGE_CLASS == SC_AUTO || CURRENT_STORAGE_CLASS == SC_REGISTER) {
                    yyerror("storage class not allowed in global scope");
                } else if (!CURRENT_STORAGE_CLASS) {
                    CURRENT_STORAGE_CLASS = SC_EXTERN_IMPLICIT;
                }
                break;
            case TABLE_FUNCTION:
            case TABLE_BLOCK:
                CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                break;
            default:
                yyerror("unrecognized table scope");
        }

        struct symbol_table_entry_ll_node *first_node = insert_symbol_var(first_declarator->val.ident.ident_name, CURRENT_SYMBOL_SCOPE, CURRENT_STORAGE_CLASS);
        first_node->specs.variable.is_defined = 1;
        first_node->specs.variable.type = build_full_type_from_declarator(first_declarator, &CURRENT_TYPE_BUILDER);

        reset_current_type_builder();
        CURRENT_STORAGE_CLASS = 0;
    }
#line 1962 "parser.tab.c"
    break;

  case 74: /* declaration-specifiers: storage-class-specifier declaration-specifiers  */
#line 395 "parser.y"
                                                   {(yyval.node) = NULL;}
#line 1968 "parser.tab.c"
    break;

  case 75: /* declaration-specifiers: storage-class-specifier  */
#line 396 "parser.y"
                              {(yyval.node) = NULL;}
#line 1974 "parser.tab.c"
    break;

  case 76: /* declaration-specifiers: type-specifier-list declaration-specifiers  */
#line 397 "parser.y"
                                                 {(yyval.node) = NULL;}
#line 1980 "parser.tab.c"
    break;

  case 77: /* declaration-specifiers: type-specifier-list  */
#line 398 "parser.y"
                          {(yyval.node) = NULL;}
#line 1986 "parser.tab.c"
    break;

  case 78: /* declarator-list: declarator  */
#line 401 "parser.y"
               {(yyval.node) = create_binop_node(B_COMMA, NULL, (yyvsp[0].node));}
#line 1992 "parser.tab.c"
    break;

  case 79: /* declarator-list: declarator-list ',' declarator  */
#line 402 "parser.y"
                                     {(yyval.node) = create_binop_node(B_COMMA, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1998 "parser.tab.c"
    break;

  case 80: /* storage-class-specifier: EXTERN  */
#line 405 "parser.y"
           {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_EXTERN_EXPLICIT;
        (yyval.node) = NULL;
    }
#line 2010 "parser.tab.c"
    break;

  case 81: /* storage-class-specifier: STATIC  */
#line 412 "parser.y"
             {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        (yyval.node) = NULL;
    }
#line 2022 "parser.tab.c"
    break;

  case 82: /* storage-class-specifier: AUTO  */
#line 419 "parser.y"
           {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_AUTO;
        (yyval.node) = NULL;
    }
#line 2034 "parser.tab.c"
    break;

  case 83: /* storage-class-specifier: REGISTER  */
#line 426 "parser.y"
               {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        (yyval.node) = NULL;
    }
#line 2046 "parser.tab.c"
    break;

  case 84: /* type-specifier: CHAR  */
#line 435 "parser.y"
         {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'char' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("too many 'char' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("conflict between 'char' and 'int' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_char = 1;
        (yyval.node) = NULL;
    }
#line 2062 "parser.tab.c"
    break;

  case 85: /* type-specifier: INT  */
#line 446 "parser.y"
          {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'int' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("too many 'int' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'int' and 'char' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_int = 1;
        (yyval.node) = NULL;
    }
#line 2078 "parser.tab.c"
    break;

  case 86: /* type-specifier: SHORT  */
#line 457 "parser.y"
            {
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
        (yyval.node) = NULL;
    }
#line 2097 "parser.tab.c"
    break;

  case 87: /* type-specifier: LONG  */
#line 471 "parser.y"
           {
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
        (yyval.node) = NULL;
    }
#line 2119 "parser.tab.c"
    break;

  case 88: /* type-specifier: SIGNED  */
#line 488 "parser.y"
             {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'signed' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("conflict between 'signed' and 'unsigned' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("too many 'signed' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_signed = 1;
        }
        (yyval.node) = NULL;
    }
#line 2136 "parser.tab.c"
    break;

  case 89: /* type-specifier: UNSIGNED  */
#line 500 "parser.y"
               {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'unsigned' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("conflict between 'unsigned' and 'signed' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("too many 'unsigned' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_unsigned = 1;
        }
        (yyval.node) = NULL;
    }
#line 2153 "parser.tab.c"
    break;

  case 90: /* type-specifier: VOID  */
#line 512 "parser.y"
           {
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
        (yyval.node) = NULL;
    }
#line 2177 "parser.tab.c"
    break;

  case 91: /* declarator: pointer direct-declarator  */
#line 533 "parser.y"
                              {
        ast_node *tail = (yyvsp[-1].node);
        while (tail->val.type_mod.next) {
            tail = tail->val.type_mod.next;
        }
        tail->val.type_mod.next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2190 "parser.tab.c"
    break;

  case 92: /* declarator: direct-declarator  */
#line 541 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2196 "parser.tab.c"
    break;

  case 93: /* direct-declarator: ident-expr  */
#line 544 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2202 "parser.tab.c"
    break;

  case 94: /* direct-declarator: '(' declarator ')'  */
#line 545 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 2208 "parser.tab.c"
    break;

  case 95: /* direct-declarator: direct-declarator '[' numlit-expr ']'  */
#line 546 "parser.y"
                                            {
        int array_size = (yyvsp[-1].node)->val.numlit.val.int_val;
        free((yyvsp[-1].node));
        ast_node *node = create_type_modifier_node(CONSTANT_SIZED_ARRAY, array_size);
        node->val.type_mod.next = (yyvsp[-3].node);
        (yyval.node) = node;
    }
#line 2220 "parser.tab.c"
    break;

  case 96: /* direct-declarator: direct-declarator '[' ']'  */
#line 553 "parser.y"
                                {
        ast_node *node = create_type_modifier_node(UNSIZED_ARRAY, 0);
        node->val.type_mod.next = (yyvsp[-2].node);
        (yyval.node) = node;
    }
#line 2230 "parser.tab.c"
    break;

  case 97: /* direct-declarator: direct-declarator '(' ')'  */
#line 558 "parser.y"
                                {(yyval.node) = create_unop_node(U_FUNCTION_TYPE, (yyvsp[-2].node));}
#line 2236 "parser.tab.c"
    break;

  case 98: /* pointer: '*'  */
#line 561 "parser.y"
        {(yyval.node) = create_type_modifier_node(POINTER, 0);}
#line 2242 "parser.tab.c"
    break;

  case 99: /* pointer: '*' pointer  */
#line 562 "parser.y"
                  {
        ast_node *node = create_type_modifier_node(POINTER, 0);
        node->val.type_mod.next = (yyvsp[0].node);
        (yyval.node) = node;
    }
#line 2252 "parser.tab.c"
    break;

  case 100: /* type-specifier-list: type-specifier  */
#line 569 "parser.y"
                   {(yyval.node) = NULL;}
#line 2258 "parser.tab.c"
    break;

  case 101: /* type-specifier-list: type-specifier type-specifier-list  */
#line 570 "parser.y"
                                         {(yyval.node) = NULL;}
#line 2264 "parser.tab.c"
    break;

  case 102: /* statement: labeled-statement  */
#line 602 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2270 "parser.tab.c"
    break;

  case 103: /* statement: compound-statement  */
#line 603 "parser.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2276 "parser.tab.c"
    break;

  case 104: /* statement: expression-statement  */
#line 604 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2282 "parser.tab.c"
    break;

  case 105: /* statement: selection-statement  */
#line 605 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 2288 "parser.tab.c"
    break;

  case 106: /* statement: iteration-statement  */
#line 606 "parser.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 2294 "parser.tab.c"
    break;

  case 107: /* statement: jump-statement  */
#line 607 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2300 "parser.tab.c"
    break;

  case 108: /* labeled-statement: ident-expr ':' statement  */
#line 610 "parser.y"
                             {
        char *name = (yyvsp[-2].node)->val.ident.ident_name;
        free((yyvsp[-2].node));
        int scope;
        switch (CURRENT_SCOPE->scope) {
            case TABLE_GLOBAL:
                scope = SYM_GLOBAL;
            case TABLE_FUNCTION:
                scope = SYM_LOCAL;
            case TABLE_BLOCK:
                scope = SYM_BLOCK;
            default:
                yyerror("Unknown Scope");
        }
        struct symbol_table_entry_ll_node *entry = insert_symbol_lab(name, scope);
        entry->specs.label.is_defined = 1;
        entry->specs.label.jump_loc = (yyvsp[0].node);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2324 "parser.tab.c"
    break;

  case 109: /* compound-statement: compound-start compound-body '}'  */
#line 631 "parser.y"
                                     {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_COMPOUND_STATEMENT;
        node->val.compound.blocks = (yyvsp[-1].node);
        node->val.compound.scope = CURRENT_SCOPE;
        exit_scope();
        (yyval.node) = node;
    }
#line 2337 "parser.tab.c"
    break;

  case 110: /* compound-statement: '{' '}'  */
#line 639 "parser.y"
              {(yyval.node) = NULL;}
#line 2343 "parser.tab.c"
    break;

  case 111: /* compound-start: '{'  */
#line 642 "parser.y"
        {
        CURRENT_SCOPE = new_scope(TABLE_BLOCK);
    }
#line 2351 "parser.tab.c"
    break;

  case 112: /* compound-body: block-item-list  */
#line 647 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2357 "parser.tab.c"
    break;

  case 113: /* block-item-list: block-item  */
#line 650 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2363 "parser.tab.c"
    break;

  case 114: /* block-item-list: block-item-list block-item  */
#line 651 "parser.y"
                                 {
        if (!(yyvsp[-1].node)) {
            (yyval.node) = (yyvsp[0].node);
        } else {
            ast_node *current_block = (yyvsp[-1].node);
            while (current_block && current_block->node_type == AST_BLOCK && current_block->val.block.next) {
                current_block = current_block->val.block.next;
            }
            if (current_block && current_block->node_type == AST_BLOCK) {
                current_block->val.block.next = (yyvsp[0].node);
            } else {
                yyerror("block-item-list structure corrupted: non-AST_BLOCK node in .next chain");
            }
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 2384 "parser.tab.c"
    break;

  case 115: /* block-item: declaration  */
#line 669 "parser.y"
                {(yyval.node) = create_block_node(NULL);}
#line 2390 "parser.tab.c"
    break;

  case 116: /* block-item: statement  */
#line 670 "parser.y"
                {(yyval.node) = create_block_node((yyvsp[0].node));}
#line 2396 "parser.tab.c"
    break;

  case 117: /* expression-statement: ';'  */
#line 673 "parser.y"
        {(yyval.node) = NULL;}
#line 2402 "parser.tab.c"
    break;

  case 118: /* expression-statement: expression ';'  */
#line 674 "parser.y"
                     {(yyval.node) = (yyvsp[-1].node);}
#line 2408 "parser.tab.c"
    break;

  case 119: /* selection-statement: IF '(' expression ')' statement  */
#line 677 "parser.y"
                                    {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_IF;
        node->val.if_statement.expression = (yyvsp[-2].node);
        node->val.if_statement.statement = (yyvsp[0].node);
        node->val.if_statement.else_statement = NULL;
        (yyval.node) = node;
    }
#line 2421 "parser.tab.c"
    break;

  case 120: /* selection-statement: IF '(' expression ')' statement ELSE statement  */
#line 685 "parser.y"
                                                     {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_IF;
        node->val.if_statement.expression = (yyvsp[-4].node);
        node->val.if_statement.statement = (yyvsp[-2].node);
        node->val.if_statement.else_statement = (yyvsp[0].node);
        (yyval.node) = node;
    }
#line 2434 "parser.tab.c"
    break;

  case 121: /* expression-opt: %empty  */
#line 695 "parser.y"
                {(yyval.node) = NULL;}
#line 2440 "parser.tab.c"
    break;

  case 122: /* expression-opt: expression  */
#line 696 "parser.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2446 "parser.tab.c"
    break;

  case 123: /* iteration-statement: WHILE '(' expression ')' statement  */
#line 699 "parser.y"
                                       {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_WHILE;
        node->val.while_statement.expression = (yyvsp[-2].node);
        node->val.do_while_statement.statement = (yyvsp[0].node);
        (yyval.node) = node;
    }
#line 2458 "parser.tab.c"
    break;

  case 124: /* iteration-statement: DO statement WHILE '(' expression ')' ';'  */
#line 706 "parser.y"
                                                {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_DO_WHILE;
        node->val.do_while_statement.expression = (yyvsp[-2].node);
        node->val.do_while_statement.statement = (yyvsp[-5].node);
        (yyval.node) = node;
    }
#line 2470 "parser.tab.c"
    break;

  case 125: /* iteration-statement: FOR '(' expression-opt ';' expression-opt ';' expression-opt ')' statement  */
#line 713 "parser.y"
                                                                                 {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FOR;
        node->val.for_statement.expr_1 = (yyvsp[-6].node);
        node->val.for_statement.expr_2 = (yyvsp[-4].node);
        node->val.for_statement.expr_3 = (yyvsp[-2].node);
        node->val.for_statement.statement = (yyvsp[0].node);
        (yyval.node) = node;
    }
#line 2484 "parser.tab.c"
    break;

  case 126: /* jump-statement: GOTO ident-expr ';'  */
#line 724 "parser.y"
                        {
        char *name = (yyvsp[-1].node)->val.ident.ident_name;
        free((yyvsp[-1].node));
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_GOTO;
        struct symbol_table_entry_ll_node *symbol = find_symbol_in_table(name, CURRENT_SCOPE);
        if (!symbol) {
            yyerror("Undefined Label");
        }
        node->val.goto_label.label = symbol;
        (yyval.node) = node;
    }
#line 2501 "parser.tab.c"
    break;

  case 127: /* jump-statement: CONTINUE ';'  */
#line 736 "parser.y"
                   {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_CONTINUE;
        (yyval.node) = node;
    }
#line 2511 "parser.tab.c"
    break;

  case 128: /* jump-statement: BREAK ';'  */
#line 741 "parser.y"
                {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_BREAK;
        (yyval.node) = node;
    }
#line 2521 "parser.tab.c"
    break;

  case 129: /* jump-statement: RETURN expression-opt ';'  */
#line 746 "parser.y"
                                {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_RETURN;
        node->val.return_statement.expression = (yyvsp[-1].node);
        (yyval.node) = node;
    }
#line 2532 "parser.tab.c"
    break;

  case 130: /* external-declaration: declaration  */
#line 756 "parser.y"
                {
        print_symbol_table(CURRENT_SCOPE, 0);
        (yyval.node) = NULL;
    }
#line 2541 "parser.tab.c"
    break;

  case 131: /* external-declaration: statement  */
#line 760 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2547 "parser.tab.c"
    break;

  case 132: /* external-declaration: function-definition  */
#line 761 "parser.y"
                          {
        print_symbol_table(CURRENT_SCOPE, 0);
        (yyval.node) = (yyvsp[0].node);
    }
#line 2556 "parser.tab.c"
    break;

  case 133: /* function-definition: declaration-specifiers declarator compound-statement  */
#line 767 "parser.y"
                                                         {
        ast_node *ident_node = (yyvsp[-1].node);
        while (ident_node->node_type != AST_IDENT) {
            if (ident_node->node_type == AST_UNOP && ident_node->val.unop.op == U_FUNCTION_TYPE) {
                ident_node = ident_node->val.unop.center;
            } else if (ident_node->node_type == AST_TYPE_MOD) {
                ident_node = ident_node->val.type_mod.next;
            } else {
                yyerror("could not find identifier in function declarator");
            }
        }
        if (!ident_node) {
            yyerror("function definition missing identifier");
        }
        ast_node *type = build_full_type_from_declarator((yyvsp[-1].node), &CURRENT_TYPE_BUILDER);
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FUNCTION_DEF;
        node->val.fn_def.return_type = type;
        node->val.fn_def.content = (yyvsp[0].node);

        struct symbol_table_entry_ll_node *fn_symbol = insert_symbol_fn(ident_node->val.ident.ident_name, SYM_GLOBAL);

        ident_node->val.ident.symbol = fn_symbol;

        fn_symbol->specs.function.return_type = type;
        fn_symbol->specs.function.content = (yyvsp[0].node);
        (yyval.node) = node;

        reset_current_type_builder();
        CURRENT_STORAGE_CLASS = 0;
    }
#line 2592 "parser.tab.c"
    break;


#line 2596 "parser.tab.c"

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

#line 799 "parser.y"


int main(int argc, char **argv) {
    init_global_table();
    yydebug = 0;

    if (argc >= 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    } else {
        yyin = stdin;
    }
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
