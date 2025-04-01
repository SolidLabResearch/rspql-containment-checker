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
#line 1 "parser.ypp"


  /* Syntax analyzer */

  
#include <string>
#include "query.hpp"
#include "rdf.hpp"
using namespace std;

#define YYDEBUG 1

extern int yylex();
void yyerror(string s);
 
extern Query *subQuery;
extern Query *superQuery;
extern Query *schema;
 

#line 92 "parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_select_token = 3,               /* select_token  */
  YYSYMBOL_distinct_token = 4,             /* distinct_token  */
  YYSYMBOL_where_token = 5,                /* where_token  */
  YYSYMBOL_as_token = 6,                   /* as_token  */
  YYSYMBOL_union_token = 7,                /* union_token  */
  YYSYMBOL_optional_token = 8,             /* optional_token  */
  YYSYMBOL_minus_token = 9,                /* minus_token  */
  YYSYMBOL_prefix_token = 10,              /* prefix_token  */
  YYSYMBOL_schema_token = 11,              /* schema_token  */
  YYSYMBOL_superquery_token = 12,          /* superquery_token  */
  YYSYMBOL_subquery_token = 13,            /* subquery_token  */
  YYSYMBOL_limit_token = 14,               /* limit_token  */
  YYSYMBOL_from_token = 15,                /* from_token  */
  YYSYMBOL_named_token = 16,               /* named_token  */
  YYSYMBOL_order_by_token = 17,            /* order_by_token  */
  YYSYMBOL_asc_token = 18,                 /* asc_token  */
  YYSYMBOL_desc_token = 19,                /* desc_token  */
  YYSYMBOL_filter_token = 20,              /* filter_token  */
  YYSYMBOL_regex_token = 21,               /* regex_token  */
  YYSYMBOL_group_by_token = 22,            /* group_by_token  */
  YYSYMBOL_and_token = 23,                 /* and_token  */
  YYSYMBOL_or_token = 24,                  /* or_token  */
  YYSYMBOL_graph_token = 25,               /* graph_token  */
  YYSYMBOL_builtin_str_token = 26,         /* builtin_str_token  */
  YYSYMBOL_noteq_token = 27,               /* noteq_token  */
  YYSYMBOL_bind_token = 28,                /* bind_token  */
  YYSYMBOL_round_token = 29,               /* round_token  */
  YYSYMBOL_offset_token = 30,              /* offset_token  */
  YYSYMBOL_abs_token = 31,                 /* abs_token  */
  YYSYMBOL_datatype_token = 32,            /* datatype_token  */
  YYSYMBOL_values_token = 33,              /* values_token  */
  YYSYMBOL_contains_token = 34,            /* contains_token  */
  YYSYMBOL_lcase_token = 35,               /* lcase_token  */
  YYSYMBOL_is_literal_token = 36,          /* is_literal_token  */
  YYSYMBOL_is_uri_token = 37,              /* is_uri_token  */
  YYSYMBOL_bound_token = 38,               /* bound_token  */
  YYSYMBOL_var_token = 39,                 /* var_token  */
  YYSYMBOL_iri_token = 40,                 /* iri_token  */
  YYSYMBOL_str_token = 41,                 /* str_token  */
  YYSYMBOL_string_token = 42,              /* string_token  */
  YYSYMBOL_blank_node_token = 43,          /* blank_node_token  */
  YYSYMBOL_int_token = 44,                 /* int_token  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_geq_token = 49,                 /* geq_token  */
  YYSYMBOL_leq_token = 50,                 /* leq_token  */
  YYSYMBOL_51_ = 51,                       /* '+'  */
  YYSYMBOL_52_ = 52,                       /* '-'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* '.'  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_a_ = 62,                     /* 'a'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_Schema = 66,                    /* Schema  */
  YYSYMBOL_SuperQuery = 67,                /* SuperQuery  */
  YYSYMBOL_SubQuery = 68,                  /* SubQuery  */
  YYSYMBOL_Query = 69,                     /* Query  */
  YYSYMBOL_SubSelect = 70,                 /* SubSelect  */
  YYSYMBOL_Decl = 71,                      /* Decl  */
  YYSYMBOL_PrefixDecl = 72,                /* PrefixDecl  */
  YYSYMBOL_Prefix = 73,                    /* Prefix  */
  YYSYMBOL_SelectClause = 74,              /* SelectClause  */
  YYSYMBOL_DistinctClause = 75,            /* DistinctClause  */
  YYSYMBOL_Selects = 76,                   /* Selects  */
  YYSYMBOL_Projections = 77,               /* Projections  */
  YYSYMBOL_Projection = 78,                /* Projection  */
  YYSYMBOL_Var = 79,                       /* Var  */
  YYSYMBOL_Expression = 80,                /* Expression  */
  YYSYMBOL_DatasetClause = 81,             /* DatasetClause  */
  YYSYMBOL_WhereClause = 82,               /* WhereClause  */
  YYSYMBOL_GroupGraphPattern = 83,         /* GroupGraphPattern  */
  YYSYMBOL_GroupGraphPatternSub = 84,      /* GroupGraphPatternSub  */
  YYSYMBOL_GroupGraphPatternSubS = 85,     /* GroupGraphPatternSubS  */
  YYSYMBOL_TriplesBlock = 86,              /* TriplesBlock  */
  YYSYMBOL_TriplesSameSubjectPath = 87,    /* TriplesSameSubjectPath  */
  YYSYMBOL_VarOrTerm = 88,                 /* VarOrTerm  */
  YYSYMBOL_VarOrIri = 89,                  /* VarOrIri  */
  YYSYMBOL_IRIRef = 90,                    /* IRIRef  */
  YYSYMBOL_RDFLiteral = 91,                /* RDFLiteral  */
  YYSYMBOL_PropertyListPathNotEmpty = 92,  /* PropertyListPathNotEmpty  */
  YYSYMBOL_Verb = 93,                      /* Verb  */
  YYSYMBOL_ObjectList = 94,                /* ObjectList  */
  YYSYMBOL_Object = 95,                    /* Object  */
  YYSYMBOL_GraphPatternNotTriples = 96,    /* GraphPatternNotTriples  */
  YYSYMBOL_GroupOrUnionGraphPattern = 97,  /* GroupOrUnionGraphPattern  */
  YYSYMBOL_OptionalGraphPattern = 98,      /* OptionalGraphPattern  */
  YYSYMBOL_MinusGraphPattern = 99,         /* MinusGraphPattern  */
  YYSYMBOL_SolutionModifier = 100,         /* SolutionModifier  */
  YYSYMBOL_LimitOffset = 101,              /* LimitOffset  */
  YYSYMBOL_OrderList = 102,                /* OrderList  */
  YYSYMBOL_OrderElem = 103,                /* OrderElem  */
  YYSYMBOL_Filter = 104,                   /* Filter  */
  YYSYMBOL_GroupConditions = 105,          /* GroupConditions  */
  YYSYMBOL_GroupCondition = 106,           /* GroupCondition  */
  YYSYMBOL_BuiltInCall = 107,              /* BuiltInCall  */
  YYSYMBOL_GraphGraphPattern = 108,        /* GraphGraphPattern  */
  YYSYMBOL_Bind = 109,                     /* Bind  */
  YYSYMBOL_ValuesClause = 110,             /* ValuesClause  */
  YYSYMBOL_DataBlockValue = 111            /* DataBlockValue  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   595

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
       2,     2,     2,    45,     2,     2,     2,     2,     2,     2,
      56,    57,    53,    51,    63,    52,    60,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    61,
      46,    48,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    73,    79,    83,    88,    93,    98,   115,
     122,   127,   133,   138,   141,   146,   152,   155,   160,   163,
     168,   172,   178,   181,   187,   193,   196,   199,   202,   205,
     208,   211,   214,   217,   220,   223,   226,   229,   232,   235,
     238,   241,   244,   249,   254,   259,   264,   269,   274,   277,
     282,   304,   354,   360,   380,   385,   394,   399,   402,   407,
     411,   415,   420,   424,   431,   435,   440,   445,   452,   455,
     460,   464,   470,   475,   478,   481,   484,   487,   490,   495,
     522,   527,   532,   538,   541,   545,   550,   553,   556,   559,
     562,   567,   572,   579,   583,   587,   593,   596,   601,   604,
     609,   614,   617,   621,   624,   627,   630,   633,   636,   639,
     642,   645,   650,   655,   660,   665,   670,   674
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
  "\"end of file\"", "error", "\"invalid token\"", "select_token",
  "distinct_token", "where_token", "as_token", "union_token",
  "optional_token", "minus_token", "prefix_token", "schema_token",
  "superquery_token", "subquery_token", "limit_token", "from_token",
  "named_token", "order_by_token", "asc_token", "desc_token",
  "filter_token", "regex_token", "group_by_token", "and_token", "or_token",
  "graph_token", "builtin_str_token", "noteq_token", "bind_token",
  "round_token", "offset_token", "abs_token", "datatype_token",
  "values_token", "contains_token", "lcase_token", "is_literal_token",
  "is_uri_token", "bound_token", "var_token", "iri_token", "str_token",
  "string_token", "blank_node_token", "int_token", "'!'", "'<'", "'>'",
  "'='", "geq_token", "leq_token", "'+'", "'-'", "'*'", "'/'", "':'",
  "'('", "')'", "'{'", "'}'", "'.'", "';'", "'a'", "','", "$accept",
  "Program", "Schema", "SuperQuery", "SubQuery", "Query", "SubSelect",
  "Decl", "PrefixDecl", "Prefix", "SelectClause", "DistinctClause",
  "Selects", "Projections", "Projection", "Var", "Expression",
  "DatasetClause", "WhereClause", "GroupGraphPattern",
  "GroupGraphPatternSub", "GroupGraphPatternSubS", "TriplesBlock",
  "TriplesSameSubjectPath", "VarOrTerm", "VarOrIri", "IRIRef",
  "RDFLiteral", "PropertyListPathNotEmpty", "Verb", "ObjectList", "Object",
  "GraphPatternNotTriples", "GroupOrUnionGraphPattern",
  "OptionalGraphPattern", "MinusGraphPattern", "SolutionModifier",
  "LimitOffset", "OrderList", "OrderElem", "Filter", "GroupConditions",
  "GroupCondition", "BuiltInCall", "GraphGraphPattern", "Bind",
  "ValuesClause", "DataBlockValue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -76,    24,   110,   310,     3,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    -6,   -26,   -76,   -24,   -76,
     -76,   -76,    27,    68,   -76,    93,   104,   -76,    79,   310,
     -76,   -76,    77,   185,    98,   -76,   151,   -76,   -76,   -76,
     -76,   -24,   -76,    91,   -76,   118,   -76,   -76,    73,     7,
     -76,   185,   185,   -76,   -76,   -76,   247,   -76,   -21,   -76,
     -76,   101,    14,   102,    91,   -76,   106,   116,   119,   123,
     124,   126,   129,   130,   132,   133,   247,   247,   -76,   150,
     134,   -76,   -76,   -76,     2,   -76,    87,   -76,    76,   122,
       9,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     153,   541,   274,   153,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   136,   188,   146,
     105,   -76,   163,   164,   -76,    76,   -76,   -76,   122,   -76,
     178,   186,   198,   194,   289,   321,   333,   365,   212,   377,
     409,   421,   175,   -76,   176,    25,    13,   117,   117,   117,
     117,   117,   117,    78,    78,   -76,   -76,   453,   -76,   102,
     -76,   101,   101,   273,    96,   181,   -76,   -76,   310,   227,
     -76,   -76,   -76,   -76,   -76,   199,   210,   -76,   -76,   220,
     237,   153,   -76,   247,   -76,   -76,   -76,   -76,   247,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   247,   -76,
     101,   247,   105,   101,   195,   196,   211,   223,   213,    94,
     465,   497,   -76,   160,   -76,   -76,   -76,   -76,   -76,   -76,
      87,   -76,   247,   -76,   -76,   153,   -76,   -33,   509,   197,
     -76,   -76,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    12,     0,     0,    56,    10,     1,    12,    12,    59,
      62,    13,    64,    60,    65,     0,     4,    54,    14,    57,
      61,    58,    14,     0,     6,     0,     0,     7,     0,    56,
      69,    68,    55,    14,     0,    12,    17,    46,    12,    63,
      53,    14,    72,    67,    71,     0,     3,    16,     0,     0,
       2,    14,    14,    11,    24,    19,    14,    15,    18,    21,
      22,     0,    14,    85,    66,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    14,    40,     0,
      43,    41,    39,    20,    56,    47,    14,    44,     0,     0,
      90,    14,    14,    14,    14,    14,    14,    14,    14,    14,
       0,    37,     0,     0,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,     0,     0,     0,
      52,    45,     0,     0,    95,    83,    92,   100,    84,    99,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    35,    36,    34,    29,    30,
      31,    32,    33,    25,    26,    27,    28,     0,    49,    85,
      48,     0,     0,     0,    14,     0,    80,    50,    56,    73,
      74,    75,    76,    77,    78,     0,     0,    91,    98,    88,
      89,     0,     8,    14,   103,   104,   105,   106,    14,   108,
     109,   110,   111,    23,    42,     9,    81,    82,    14,    97,
       0,    14,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,    51,    79,    94,    93,    86,    87,
      14,   101,    14,   107,    96,     0,   117,    14,     0,     0,
     114,   116,   102,   113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   218,   234,    -2,   -76,   269,   -76,   250,
     190,   -76,   -76,   -76,   219,   -47,    -7,   -76,   162,   -51,
     -76,    88,   -75,   264,   -31,   -14,    -4,    -1,   -76,   254,
     245,   248,   -76,   -76,   -76,   -76,   147,   -76,   -76,   189,
     -76,   -76,   187,   154,   -76,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    23,    26,    24,   117,    25,     5,    15,
      37,    48,    57,    58,    59,    78,    79,    49,    63,   166,
     119,   167,    16,    17,    18,    19,    80,    81,    32,    33,
      43,    44,   168,   169,   170,   171,    90,   132,   125,   126,
     172,   128,   129,    82,   173,   174,   182,   227
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    60,    42,    21,    31,    36,    27,    10,    11,   120,
      85,    60,    61,    22,    20,     9,    10,    11,    54,    13,
      42,    42,    62,   130,     6,    20,   230,    31,    21,    20,
      86,     1,    21,    27,    29,    56,   104,    20,    30,   131,
     106,     9,    10,    11,    12,    13,    14,    20,    20,    28,
      21,    21,   106,   142,    10,    11,   144,   -14,    87,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    11,   101,
     102,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      20,    35,   121,    21,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   202,   122,   123,    36,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     196,   197,    54,   161,   162,   124,    38,   104,   105,    88,
      39,   106,     7,     8,    89,   163,    55,    10,    11,    56,
     164,   114,   115,   165,   208,     9,    10,    11,    41,    13,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   212,
     200,   221,   215,    45,    52,    47,   103,   222,    53,    84,
      20,   127,    91,    84,    20,    29,   225,    21,   112,   113,
     114,   115,    92,   104,   105,    93,   209,   106,   229,    94,
      95,   210,    96,   104,   105,    97,    98,   106,    99,   100,
     116,   211,    54,    61,   213,   158,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   160,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   228,   226,   104,   105,   175,
     176,   106,   179,   231,     9,    10,    11,    12,    13,    14,
     180,   181,   192,   193,   203,   104,   105,   201,   204,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   205,
     206,   207,   216,   217,   233,   218,    50,   183,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   219,    66,    46,
       4,   220,    34,    67,   118,   188,    68,    83,    69,    70,
     159,    71,    72,    73,    74,    75,    54,    10,    11,    12,
     214,    14,    76,    40,    66,    51,    64,   104,   105,    67,
      65,   106,    68,    77,    69,    70,   195,    71,    72,    73,
      74,    75,   104,   105,   177,   178,   106,   199,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   198,
       0,   143,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   104,   105,   184,     0,   106,     9,
      10,    11,    12,    13,    14,     0,   104,   105,     0,     0,
     106,     0,     0,     0,     0,   -14,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,   185,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   104,   105,
     186,     0,   106,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,   106,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,   187,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   104,   105,   189,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,   106,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,   190,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   104,   105,   191,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,   106,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
     194,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     104,   105,   223,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   104,   105,     0,     0,   106,     0,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,   224,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   104,   105,   232,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       4,    48,    33,     4,    18,     3,     8,    40,    41,    84,
      61,    58,     5,    10,    18,    39,    40,    41,    39,    43,
      51,    52,    15,    14,     0,    29,    59,    41,    29,    33,
      16,    11,    33,    35,    60,    56,    23,    41,    62,    30,
      27,    39,    40,    41,    42,    43,    44,    51,    52,    55,
      51,    52,    27,   100,    40,    41,   103,    55,    62,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    41,    76,
      77,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      84,    13,    86,    84,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   168,    18,    19,     3,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     161,   162,    39,     8,     9,    39,    12,    23,    24,    17,
      41,    27,    12,    13,    22,    20,    53,    40,    41,    56,
      25,    53,    54,    28,   181,    39,    40,    41,    61,    43,
      46,    47,    48,    49,    50,    51,    52,    53,    54,   200,
     164,    57,   203,    55,    63,     4,     6,    63,    40,    58,
     164,    39,    56,    58,   168,    60,     6,   168,    51,    52,
      53,    54,    56,    23,    24,    56,   183,    27,   225,    56,
      56,   188,    56,    23,    24,    56,    56,    27,    56,    56,
      56,   198,    39,     5,   201,    59,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    59,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   222,   220,    23,    24,    56,
      56,    27,    44,   227,    39,    40,    41,    42,    43,    44,
      44,    33,    57,    57,     7,    23,    24,    56,    39,    27,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    39,
      30,    14,    57,    57,    57,    44,    38,    63,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    44,    21,    35,
       1,    58,    22,    26,    84,    63,    29,    58,    31,    32,
     118,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     202,    44,    45,    29,    21,    41,    51,    23,    24,    26,
      52,    27,    29,    56,    31,    32,   159,    34,    35,    36,
      37,    38,    23,    24,   125,   128,    27,   163,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    56,
      -1,    57,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    23,    24,    57,    -1,    27,    39,
      40,    41,    42,    43,    44,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    55,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    57,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    23,    24,
      57,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    57,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    23,    24,    57,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    23,    24,    57,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      23,    24,    57,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    57,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    23,    24,    57,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    65,    66,    71,    72,     0,    12,    13,    39,
      40,    41,    42,    43,    44,    73,    86,    87,    88,    89,
      90,    91,    10,    67,    69,    71,    68,    69,    55,    60,
      62,    89,    92,    93,    73,    13,     3,    74,    12,    41,
      87,    61,    88,    94,    95,    55,    68,     4,    75,    81,
      67,    93,    63,    40,    39,    53,    56,    76,    77,    78,
      79,     5,    15,    82,    94,    95,    21,    26,    29,    31,
      32,    34,    35,    36,    37,    38,    45,    56,    79,    80,
      90,    91,   107,    78,    58,    83,    16,    90,    17,    22,
     100,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    80,    80,     6,    23,    24,    27,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    56,    70,    74,    84,
      86,    90,    18,    19,    39,   102,   103,    39,   105,   106,
      14,    30,   101,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    79,    57,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    59,    82,
      59,     8,     9,    20,    25,    28,    83,    85,    96,    97,
      98,    99,   104,   108,   109,    56,    56,   103,   106,    44,
      44,    33,   110,    63,    57,    57,    57,    57,    63,    57,
      57,    57,    57,    57,    57,   100,    83,    83,    56,   107,
      89,    56,    86,     7,    39,    39,    30,    14,    79,    80,
      80,    80,    83,    80,    85,    83,    57,    57,    44,    44,
      58,    57,    63,    57,    57,     6,    90,   111,    80,    79,
      59,    90,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    68,    69,    70,
      71,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    82,    83,    83,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   105,   105,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   109,   110,   110,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     5,     3,     0,     1,     1,     7,     3,
       1,     5,     0,     1,     0,     3,     1,     0,     1,     1,
       2,     1,     1,     5,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     4,     1,     3,     4,     0,     2,     3,     3,
       2,     3,     0,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     2,     2,     0,     4,     4,     2,     2,
       0,     2,     1,     4,     4,     1,     4,     2,     2,     1,
       1,     6,     8,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     3,     6,     5,     0,     2,     1
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
  case 2: /* Program: Schema subquery_token SubQuery superquery_token SuperQuery  */
#line 69 "parser.ypp"
                                                                    {
  subQuery = (yyvsp[-2].q);
  superQuery = (yyvsp[0].q);
 }
#line 1435 "parser.tab.cpp"
    break;

  case 3: /* Program: Schema superquery_token SuperQuery subquery_token SubQuery  */
#line 73 "parser.ypp"
                                                             {
  subQuery = (yyvsp[0].q);
  superQuery = (yyvsp[-2].q);
 }
#line 1444 "parser.tab.cpp"
    break;

  case 4: /* Schema: schema_token Decl TriplesBlock  */
#line 79 "parser.ypp"
                                       {
  schema = new Query(*(yyvsp[-1].m), vector<Expression*>(), (yyvsp[0].p));
  delete (yyvsp[-1].m);
 }
#line 1453 "parser.tab.cpp"
    break;

  case 5: /* Schema: %empty  */
#line 83 "parser.ypp"
  {
  schema = nullptr;
 }
#line 1461 "parser.tab.cpp"
    break;

  case 6: /* SuperQuery: Query  */
#line 88 "parser.ypp"
                  {
  (yyval.q) = (yyvsp[0].q);
 }
#line 1469 "parser.tab.cpp"
    break;

  case 7: /* SubQuery: Query  */
#line 93 "parser.ypp"
                {
  (yyval.q) = (yyvsp[0].q);
 }
#line 1477 "parser.tab.cpp"
    break;

  case 8: /* Query: Decl SelectClause DatasetClause WhereClause SolutionModifier LimitOffset ValuesClause  */
#line 98 "parser.ypp"
                                                                                             {
  RDFValue *v = nullptr;
  vector<RDFValue*> values;
  if ((yyvsp[0].v1)->size() > 0) {
    v = (*(yyvsp[0].v1))[0];
    values = vector<RDFValue*>((yyvsp[0].v1)->begin() + 1, (yyvsp[0].v1)->end());
  }
  delete (yyvsp[0].v1);
  (yyval.q) = new Query(*(yyvsp[-6].m), (yyvsp[-5].vb3)->first, (yyvsp[-3].p), (yyvsp[-5].vb3)->second, *(yyvsp[-2].vpvb), *(yyvsp[-4].ss), (yyvsp[-1].pii)->first, (yyvsp[-1].pii)->second, v, values);
  delete (yyvsp[-6].m);
  delete (yyvsp[-5].vb3);
  delete (yyvsp[-4].ss);
  delete (yyvsp[-2].vpvb);
  delete (yyvsp[-1].pii);
 }
#line 1497 "parser.tab.cpp"
    break;

  case 9: /* SubSelect: SelectClause WhereClause SolutionModifier  */
#line 115 "parser.ypp"
                                                     {
  Query *q = new Query(map<string, string>(), (yyvsp[-2].vb3)->first, (yyvsp[-1].p), (yyvsp[-2].vb3)->second, *(yyvsp[0].vpvb));
  (yyval.p) = new SubqueryPattern(q);
  delete (yyvsp[0].vpvb);
 }
#line 1507 "parser.tab.cpp"
    break;

  case 10: /* Decl: PrefixDecl  */
#line 122 "parser.ypp"
                 {
  (yyval.m) = (yyvsp[0].m);
 }
#line 1515 "parser.tab.cpp"
    break;

  case 11: /* PrefixDecl: PrefixDecl prefix_token Prefix ':' iri_token  */
#line 127 "parser.ypp"
                                                         {
  (yyval.m) = (yyvsp[-4].m);
  (*(yyval.m))[*(yyvsp[-2].s)] = *(yyvsp[0].s);
  delete (yyvsp[-2].s);
  delete (yyvsp[0].s);
 }
#line 1526 "parser.tab.cpp"
    break;

  case 12: /* PrefixDecl: %empty  */
#line 133 "parser.ypp"
   {
  (yyval.m) = new map<string, string>();
 }
#line 1534 "parser.tab.cpp"
    break;

  case 13: /* Prefix: str_token  */
#line 138 "parser.ypp"
                  {
  (yyval.s) = (yyvsp[0].s);
 }
#line 1542 "parser.tab.cpp"
    break;

  case 14: /* Prefix: %empty  */
#line 141 "parser.ypp"
  {
  (yyval.s) = new string("");
 }
#line 1550 "parser.tab.cpp"
    break;

  case 15: /* SelectClause: select_token DistinctClause Selects  */
#line 146 "parser.ypp"
                                                  {
  (yyval.vb3) = new pair<vector<Expression*>, bool>(*(yyvsp[0].v3), (yyvsp[-1].b));
  delete (yyvsp[0].v3);
}
#line 1559 "parser.tab.cpp"
    break;

  case 16: /* DistinctClause: distinct_token  */
#line 152 "parser.ypp"
                               {
  (yyval.b) = true;
 }
#line 1567 "parser.tab.cpp"
    break;

  case 17: /* DistinctClause: %empty  */
#line 155 "parser.ypp"
  {
  (yyval.b) = false;
 }
#line 1575 "parser.tab.cpp"
    break;

  case 18: /* Selects: Projections  */
#line 160 "parser.ypp"
                     {
  (yyval.v3) = (yyvsp[0].v3);
 }
#line 1583 "parser.tab.cpp"
    break;

  case 19: /* Selects: '*'  */
#line 163 "parser.ypp"
      {
  (yyval.v3) = new vector<Expression*>();
 }
#line 1591 "parser.tab.cpp"
    break;

  case 20: /* Projections: Projections Projection  */
#line 168 "parser.ypp"
                                    {
  (yyval.v3) = (yyvsp[-1].v3);
  (yyval.v3)->push_back((yyvsp[0].e));
 }
#line 1600 "parser.tab.cpp"
    break;

  case 21: /* Projections: Projection  */
#line 172 "parser.ypp"
             {
  (yyval.v3) = new vector<Expression*>();
  (yyval.v3)->push_back((yyvsp[0].e));
 }
#line 1609 "parser.tab.cpp"
    break;

  case 22: /* Projection: Var  */
#line 178 "parser.ypp"
                {
  (yyval.e) = new PrimaryExpression((Variable*)(yyvsp[0].v));
 }
#line 1617 "parser.tab.cpp"
    break;

  case 23: /* Projection: '(' Expression as_token Var ')'  */
#line 181 "parser.ypp"
                                  {
  (yyval.e) = new EqExpression(new PrimaryExpression((yyvsp[-1].v)), (yyvsp[-3].e));
  //$$ = new PrimaryExpression($4);
 }
#line 1626 "parser.tab.cpp"
    break;

  case 24: /* Var: var_token  */
#line 187 "parser.ypp"
               {
  (yyval.v) = new Variable(*(yyvsp[0].s));
  delete (yyvsp[0].s);
 }
#line 1635 "parser.tab.cpp"
    break;

  case 25: /* Expression: Expression '+' Expression  */
#line 193 "parser.ypp"
                                      {
  (yyval.e) = new BuiltinBinExpression("f_add", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1643 "parser.tab.cpp"
    break;

  case 26: /* Expression: Expression '-' Expression  */
#line 196 "parser.ypp"
                            {
  (yyval.e) = new BuiltinBinExpression("f_sub", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1651 "parser.tab.cpp"
    break;

  case 27: /* Expression: Expression '*' Expression  */
#line 199 "parser.ypp"
                            {
  (yyval.e) = new BuiltinBinExpression("f_mul", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1659 "parser.tab.cpp"
    break;

  case 28: /* Expression: Expression '/' Expression  */
#line 202 "parser.ypp"
                            {
  (yyval.e) = new BuiltinBinExpression("f_div", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1667 "parser.tab.cpp"
    break;

  case 29: /* Expression: Expression '<' Expression  */
#line 205 "parser.ypp"
                            {
  (yyval.e) = new BuiltinBinExpression("f_lt", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1675 "parser.tab.cpp"
    break;

  case 30: /* Expression: Expression '>' Expression  */
#line 208 "parser.ypp"
                            {
  (yyval.e) = new BuiltinBinExpression("f_gt", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1683 "parser.tab.cpp"
    break;

  case 31: /* Expression: Expression '=' Expression  */
#line 211 "parser.ypp"
                            {
  (yyval.e) = new EqExpression((yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1691 "parser.tab.cpp"
    break;

  case 32: /* Expression: Expression geq_token Expression  */
#line 214 "parser.ypp"
                                  {
  (yyval.e) = new BuiltinBinExpression("f_geq", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1699 "parser.tab.cpp"
    break;

  case 33: /* Expression: Expression leq_token Expression  */
#line 217 "parser.ypp"
                                  {
  (yyval.e) = new BuiltinBinExpression("f_leq", (yyvsp[-2].e), (yyvsp[0].e));
  }
#line 1707 "parser.tab.cpp"
    break;

  case 34: /* Expression: Expression noteq_token Expression  */
#line 220 "parser.ypp"
                                    {
  (yyval.e) = new NotExpression(new EqExpression((yyvsp[-2].e), (yyvsp[0].e)));
 }
#line 1715 "parser.tab.cpp"
    break;

  case 35: /* Expression: Expression and_token Expression  */
#line 223 "parser.ypp"
                                  {
  (yyval.e) = new AndExpression((yyvsp[-2].e), (yyvsp[0].e));
 }
#line 1723 "parser.tab.cpp"
    break;

  case 36: /* Expression: Expression or_token Expression  */
#line 226 "parser.ypp"
                                 {
  (yyval.e) = new OrExpression((yyvsp[-2].e), (yyvsp[0].e));
 }
#line 1731 "parser.tab.cpp"
    break;

  case 37: /* Expression: '!' Expression  */
#line 229 "parser.ypp"
                 {
  (yyval.e) = new NotExpression((yyvsp[0].e));
  }
#line 1739 "parser.tab.cpp"
    break;

  case 38: /* Expression: '(' Expression ')'  */
#line 232 "parser.ypp"
                     {
  (yyval.e) = (yyvsp[-1].e);
  }
#line 1747 "parser.tab.cpp"
    break;

  case 39: /* Expression: BuiltInCall  */
#line 235 "parser.ypp"
              {
  (yyval.e) = (yyvsp[0].e);
  }
#line 1755 "parser.tab.cpp"
    break;

  case 40: /* Expression: Var  */
#line 238 "parser.ypp"
      {
  (yyval.e) = new PrimaryExpression((yyvsp[0].v));
  }
#line 1763 "parser.tab.cpp"
    break;

  case 41: /* Expression: RDFLiteral  */
#line 241 "parser.ypp"
             {
  (yyval.e) = new PrimaryExpression((yyvsp[0].v));
  }
#line 1771 "parser.tab.cpp"
    break;

  case 42: /* Expression: IRIRef '(' Expression ')'  */
#line 244 "parser.ypp"
                            {
  if (((IRI*)(yyvsp[-3].v))->getIri() != "xsd:string")
    throw "TODO: IRIRef(Expression)";
  (yyval.e) = new BuiltinUnExpression("f_xsd_string", (yyvsp[-1].e));
  }
#line 1781 "parser.tab.cpp"
    break;

  case 43: /* Expression: IRIRef  */
#line 249 "parser.ypp"
         {
  (yyval.e) = new PrimaryExpression((yyvsp[0].v));
  }
#line 1789 "parser.tab.cpp"
    break;

  case 44: /* DatasetClause: DatasetClause from_token IRIRef  */
#line 254 "parser.ypp"
                                               {
  (yyval.ss) = (yyvsp[-2].ss);
  (yyval.ss)->first.insert(((IRI*)(yyvsp[0].v))->getIri());
  delete (yyvsp[0].v);
}
#line 1799 "parser.tab.cpp"
    break;

  case 45: /* DatasetClause: DatasetClause from_token named_token IRIRef  */
#line 259 "parser.ypp"
                                              {
  (yyval.ss) = (yyvsp[-3].ss);
  (yyval.ss)->second.insert(((IRI*)(yyvsp[0].v))->getIri());
  delete (yyvsp[0].v);
 }
#line 1809 "parser.tab.cpp"
    break;

  case 46: /* DatasetClause: %empty  */
#line 264 "parser.ypp"
  {
  (yyval.ss) = new pair<set<string>, set<string> > ();
 }
#line 1817 "parser.tab.cpp"
    break;

  case 47: /* WhereClause: where_token GroupGraphPattern  */
#line 269 "parser.ypp"
                                           {
  (yyval.p) = (yyvsp[0].p);
 }
#line 1825 "parser.tab.cpp"
    break;

  case 48: /* GroupGraphPattern: '{' GroupGraphPatternSub '}'  */
#line 274 "parser.ypp"
                                                {
  (yyval.p) = (yyvsp[-1].p);
 }
#line 1833 "parser.tab.cpp"
    break;

  case 49: /* GroupGraphPattern: '{' SubSelect '}'  */
#line 277 "parser.ypp"
                    {
  (yyval.p) = (yyvsp[-1].p);
  }
#line 1841 "parser.tab.cpp"
    break;

  case 50: /* GroupGraphPatternSub: TriplesBlock GroupGraphPatternSubS  */
#line 282 "parser.ypp"
                                                         {
  /*
  $$ = $1;
  addAddClausesToAdd($$, $2);
  */
  if ((yyvsp[-1].p) == nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[-1].p) == nullptr && (yyvsp[0].p) != nullptr) {
    (yyval.p) = (yyvsp[0].p);
  }
  else if ((yyvsp[-1].p) != nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = (yyvsp[-1].p);
  }
  else if ((yyvsp[-1].p) != nullptr && (yyvsp[0].p) != nullptr) {
    (yyval.p) = new And();
    ((And*)(yyval.p))->addPattern((yyvsp[-1].p));
    ((And*)(yyval.p))->addPattern((yyvsp[0].p));
  }
 }
#line 1866 "parser.tab.cpp"
    break;

  case 51: /* GroupGraphPatternSubS: GraphPatternNotTriples TriplesBlock GroupGraphPatternSubS  */
#line 304 "parser.ypp"
                                                                                 {
  /*
  And* tmp = dynamic_cast<And*>($1);
  if (tmp != nullptr) {
    $$ = $1;
  }
  else {
    $$ = new And();
    ((And*)$$)->addPattern($1);
  }
  addAddClausesToAdd($$, $2);
  addAddClausesToAdd($$, $3);
  */
  And *tmp = new And();
  if ((yyvsp[-2].p) == nullptr && (yyvsp[-1].p) == nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[-2].p) == nullptr && (yyvsp[-1].p) == nullptr && (yyvsp[0].p) != nullptr) {
    (yyval.p) = (yyvsp[0].p);
  }
  else if ((yyvsp[-2].p) == nullptr && (yyvsp[-1].p) != nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = (yyvsp[-1].p);
  }
  else if ((yyvsp[-2].p) == nullptr && (yyvsp[-1].p) != nullptr && (yyvsp[0].p) != nullptr) {
    tmp->addPattern((yyvsp[-1].p));
    tmp->addPattern((yyvsp[0].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[-1].p) == nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = (yyvsp[-2].p);
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[-1].p) == nullptr && (yyvsp[0].p) != nullptr) {
    tmp->addPattern((yyvsp[-2].p));
    tmp->addPattern((yyvsp[0].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[-1].p) != nullptr && (yyvsp[0].p) == nullptr) {
    tmp->addPattern((yyvsp[-2].p));
    tmp->addPattern((yyvsp[-1].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[-1].p) != nullptr && (yyvsp[0].p) != nullptr) {
    tmp->addPattern((yyvsp[-2].p));
    tmp->addPattern((yyvsp[-1].p));
    And *tmp1 = new And();
    tmp1->addPattern(tmp);
    tmp1->addPattern((yyvsp[0].p));
    (yyval.p) = tmp1;
  }
 }
#line 1921 "parser.tab.cpp"
    break;

  case 52: /* GroupGraphPatternSubS: %empty  */
#line 354 "parser.ypp"
  {
  (yyval.p) = nullptr;
 }
#line 1929 "parser.tab.cpp"
    break;

  case 53: /* TriplesBlock: TriplesBlock '.' TriplesSameSubjectPath  */
#line 360 "parser.ypp"
                                                      {
  /*
  $$ = $1;
  addAddClausesToAdd($$, $3);
  */
  if ((yyvsp[-2].p) == nullptr  && (yyvsp[0].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[-2].p) == nullptr  && (yyvsp[0].p) != nullptr) {
    (yyval.p) = (yyvsp[0].p);
  }
  else if ((yyvsp[-2].p) != nullptr  && (yyvsp[0].p) == nullptr) {
    (yyval.p) = (yyvsp[-2].p);
  }
  else if ((yyvsp[-2].p) != nullptr  && (yyvsp[0].p) != nullptr) {
    (yyval.p) = new And();
    ((And*)(yyval.p))->addPattern((yyvsp[-2].p));
    ((And*)(yyval.p))->addPattern((yyvsp[0].p));
  }
 }
#line 1954 "parser.tab.cpp"
    break;

  case 54: /* TriplesBlock: TriplesSameSubjectPath  */
#line 380 "parser.ypp"
                         {
  (yyval.p) = (yyvsp[0].p);
 }
#line 1962 "parser.tab.cpp"
    break;

  case 55: /* TriplesSameSubjectPath: VarOrTerm PropertyListPathNotEmpty  */
#line 385 "parser.ypp"
                                                           {
  (yyval.p) = new And();
  for (auto a : *(yyvsp[0].v2)) {
    for (auto b : a.second)
      ((And*)(yyval.p))->addPattern(new TriplePattern((yyvsp[-1].v)->clone(), a.first, b));
  }
  delete (yyvsp[-1].v);
  delete (yyvsp[0].v2);
 }
#line 1976 "parser.tab.cpp"
    break;

  case 56: /* TriplesSameSubjectPath: %empty  */
#line 394 "parser.ypp"
  {
  (yyval.p) = nullptr;
 }
#line 1984 "parser.tab.cpp"
    break;

  case 57: /* VarOrTerm: VarOrIri  */
#line 399 "parser.ypp"
                    {
  (yyval.v) = (yyvsp[0].v);
 }
#line 1992 "parser.tab.cpp"
    break;

  case 58: /* VarOrTerm: RDFLiteral  */
#line 402 "parser.ypp"
             {
  (yyval.v) = (yyvsp[0].v);
 }
#line 2000 "parser.tab.cpp"
    break;

  case 59: /* VarOrIri: var_token  */
#line 407 "parser.ypp"
                    {
  (yyval.v) = new Variable(*(yyvsp[0].s));
  delete (yyvsp[0].s);
 }
#line 2009 "parser.tab.cpp"
    break;

  case 60: /* VarOrIri: blank_node_token  */
#line 411 "parser.ypp"
                   {
  (yyval.v) = new BlankNode(*(yyvsp[0].s));
  delete (yyvsp[0].s);
  }
#line 2018 "parser.tab.cpp"
    break;

  case 61: /* VarOrIri: IRIRef  */
#line 415 "parser.ypp"
         {
  (yyval.v) = (yyvsp[0].v);
  }
#line 2026 "parser.tab.cpp"
    break;

  case 62: /* IRIRef: iri_token  */
#line 420 "parser.ypp"
                  {
  (yyval.v) = new IRI(*(yyvsp[0].s));
  delete (yyvsp[0].s);
  }
#line 2035 "parser.tab.cpp"
    break;

  case 63: /* IRIRef: Prefix ':' str_token  */
#line 424 "parser.ypp"
                       {
  (yyval.v) = new IRI(*(yyvsp[-2].s) + ":" + *(yyvsp[0].s));
  delete (yyvsp[-2].s);
  delete (yyvsp[0].s);
  }
#line 2045 "parser.tab.cpp"
    break;

  case 64: /* RDFLiteral: string_token  */
#line 431 "parser.ypp"
                         {
  (yyval.v) = new Literal(*(yyvsp[0].s));
  delete (yyvsp[0].s);
 }
#line 2054 "parser.tab.cpp"
    break;

  case 65: /* RDFLiteral: int_token  */
#line 435 "parser.ypp"
            {
  (yyval.v) = new Literal(to_string((yyvsp[0].i)));
  }
#line 2062 "parser.tab.cpp"
    break;

  case 66: /* PropertyListPathNotEmpty: PropertyListPathNotEmpty ';' Verb ObjectList  */
#line 440 "parser.ypp"
                                                                       {
  (yyval.v2) = (yyvsp[-3].v2);
  (yyval.v2)->push_back(make_pair((yyvsp[-1].v), *(yyvsp[0].v1)));
  delete (yyvsp[0].v1);
 }
#line 2072 "parser.tab.cpp"
    break;

  case 67: /* PropertyListPathNotEmpty: Verb ObjectList  */
#line 445 "parser.ypp"
                  {
  (yyval.v2) = new vector <pair<RDFValue*, vector<RDFValue*> > > ();
  (yyval.v2)->push_back(make_pair((yyvsp[-1].v), *(yyvsp[0].v1)));
  delete (yyvsp[0].v1);
 }
#line 2082 "parser.tab.cpp"
    break;

  case 68: /* Verb: VarOrIri  */
#line 452 "parser.ypp"
                {
  (yyval.v) = (yyvsp[0].v);
 }
#line 2090 "parser.tab.cpp"
    break;

  case 69: /* Verb: 'a'  */
#line 455 "parser.ypp"
      {
  (yyval.v) = new IRI("a");
 }
#line 2098 "parser.tab.cpp"
    break;

  case 70: /* ObjectList: ObjectList ',' Object  */
#line 460 "parser.ypp"
                                  {
  (yyval.v1) = (yyvsp[-2].v1);
  (yyval.v1)->push_back((yyvsp[0].v));
 }
#line 2107 "parser.tab.cpp"
    break;

  case 71: /* ObjectList: Object  */
#line 464 "parser.ypp"
         {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[0].v));
 }
#line 2116 "parser.tab.cpp"
    break;

  case 72: /* Object: VarOrTerm  */
#line 470 "parser.ypp"
                  {
  (yyval.v) = (yyvsp[0].v);
 }
#line 2124 "parser.tab.cpp"
    break;

  case 73: /* GraphPatternNotTriples: GroupOrUnionGraphPattern  */
#line 475 "parser.ypp"
                                                 {
  (yyval.p) = (yyvsp[0].p);
 }
#line 2132 "parser.tab.cpp"
    break;

  case 74: /* GraphPatternNotTriples: OptionalGraphPattern  */
#line 478 "parser.ypp"
                       {
  (yyval.p) = (yyvsp[0].p);
 }
#line 2140 "parser.tab.cpp"
    break;

  case 75: /* GraphPatternNotTriples: MinusGraphPattern  */
#line 481 "parser.ypp"
                    {
  (yyval.p) = (yyvsp[0].p);
 }
#line 2148 "parser.tab.cpp"
    break;

  case 76: /* GraphPatternNotTriples: Filter  */
#line 484 "parser.ypp"
         {
  (yyval.p) = (yyvsp[0].p);
  }
#line 2156 "parser.tab.cpp"
    break;

  case 77: /* GraphPatternNotTriples: GraphGraphPattern  */
#line 487 "parser.ypp"
                    {
  (yyval.p) = (yyvsp[0].p);
  }
#line 2164 "parser.tab.cpp"
    break;

  case 78: /* GraphPatternNotTriples: Bind  */
#line 490 "parser.ypp"
       {
  (yyval.p) = (yyvsp[0].p);
  }
#line 2172 "parser.tab.cpp"
    break;

  case 79: /* GroupOrUnionGraphPattern: GroupOrUnionGraphPattern union_token GroupGraphPattern  */
#line 495 "parser.ypp"
                                                                                 {
  /*
  Union* tmp = dynamic_cast<Union*>($1);
  if (tmp != nullptr)
    tmp->addPattern($3);
  else {
    tmp = new Union();
    tmp->addPattern($1);
    tmp->addPattern($3);
  }
  $$ = tmp;
  */
  if ((yyvsp[-2].p) == nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[-2].p) == nullptr && (yyvsp[0].p) != nullptr) {
    (yyval.p) = (yyvsp[0].p);
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[0].p) == nullptr) {
    (yyval.p) = (yyvsp[-2].p);
  }
  else if ((yyvsp[-2].p) != nullptr && (yyvsp[0].p) != nullptr) {
    (yyval.p) = new Union();
    ((Union*)(yyval.p))->addPattern((yyvsp[-2].p));
    ((Union*)(yyval.p))->addPattern((yyvsp[0].p));
  }
 }
#line 2204 "parser.tab.cpp"
    break;

  case 80: /* GroupOrUnionGraphPattern: GroupGraphPattern  */
#line 522 "parser.ypp"
                    {
  (yyval.p) = (yyvsp[0].p);
 }
#line 2212 "parser.tab.cpp"
    break;

  case 81: /* OptionalGraphPattern: optional_token GroupGraphPattern  */
#line 527 "parser.ypp"
                                                       {
  (yyval.p) = new OptionalPattern((yyvsp[0].p));
}
#line 2220 "parser.tab.cpp"
    break;

  case 82: /* MinusGraphPattern: minus_token GroupGraphPattern  */
#line 532 "parser.ypp"
                                                 {
  (yyval.p) = new MinusPattern((yyvsp[0].p));
}
#line 2228 "parser.tab.cpp"
    break;

  case 83: /* SolutionModifier: order_by_token OrderList  */
#line 538 "parser.ypp"
                                            {
  (yyval.vpvb) = (yyvsp[0].vpvb);
}
#line 2236 "parser.tab.cpp"
    break;

  case 84: /* SolutionModifier: group_by_token GroupConditions  */
#line 541 "parser.ypp"
                                 {
  // ovo nista ne znaci bez agregatnih fja
  (yyval.vpvb) = new vector<pair <RDFValue*, bool> >();
 }
#line 2245 "parser.tab.cpp"
    break;

  case 85: /* SolutionModifier: %empty  */
#line 545 "parser.ypp"
  {
  (yyval.vpvb) = new vector<pair <RDFValue*, bool> >();
  }
#line 2253 "parser.tab.cpp"
    break;

  case 86: /* LimitOffset: limit_token int_token offset_token int_token  */
#line 550 "parser.ypp"
                                                          {
  (yyval.pii) = new pair<int, int>((yyvsp[-2].i), (yyvsp[0].i));
 }
#line 2261 "parser.tab.cpp"
    break;

  case 87: /* LimitOffset: offset_token int_token limit_token int_token  */
#line 553 "parser.ypp"
                                               {
  (yyval.pii) = new pair<int, int>((yyvsp[0].i), (yyvsp[-2].i));
 }
#line 2269 "parser.tab.cpp"
    break;

  case 88: /* LimitOffset: limit_token int_token  */
#line 556 "parser.ypp"
                        {
  (yyval.pii) = new pair<int, int>((yyvsp[0].i), -1);
 }
#line 2277 "parser.tab.cpp"
    break;

  case 89: /* LimitOffset: offset_token int_token  */
#line 559 "parser.ypp"
                         {
  (yyval.pii) = new pair<int, int>(-1, (yyvsp[0].i));
 }
#line 2285 "parser.tab.cpp"
    break;

  case 90: /* LimitOffset: %empty  */
#line 562 "parser.ypp"
   {
  (yyval.pii) = new pair<int, int>(-1, -1);
  }
#line 2293 "parser.tab.cpp"
    break;

  case 91: /* OrderList: OrderList OrderElem  */
#line 567 "parser.ypp"
                               {
  (yyval.vpvb) = (yyvsp[-1].vpvb);
  (yyval.vpvb)->push_back(*(yyvsp[0].pvb));
  delete (yyvsp[0].pvb);
 }
#line 2303 "parser.tab.cpp"
    break;

  case 92: /* OrderList: OrderElem  */
#line 572 "parser.ypp"
            {
  (yyval.vpvb) = new vector< pair<RDFValue*, bool> >();
  (yyval.vpvb)->push_back(*(yyvsp[0].pvb));
  delete (yyvsp[0].pvb);
 }
#line 2313 "parser.tab.cpp"
    break;

  case 93: /* OrderElem: desc_token '(' var_token ')'  */
#line 579 "parser.ypp"
                                        {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[-1].s)), false);
  delete (yyvsp[-1].s);
 }
#line 2322 "parser.tab.cpp"
    break;

  case 94: /* OrderElem: asc_token '(' var_token ')'  */
#line 583 "parser.ypp"
                              {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[-1].s)), true);
  delete (yyvsp[-1].s);
 }
#line 2331 "parser.tab.cpp"
    break;

  case 95: /* OrderElem: var_token  */
#line 587 "parser.ypp"
            {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[0].s)), true);
  delete (yyvsp[0].s);
 }
#line 2340 "parser.tab.cpp"
    break;

  case 96: /* Filter: filter_token '(' Expression ')'  */
#line 593 "parser.ypp"
                                        {
  (yyval.p) = (yyvsp[-1].e);
 }
#line 2348 "parser.tab.cpp"
    break;

  case 97: /* Filter: filter_token BuiltInCall  */
#line 596 "parser.ypp"
                           {
  (yyval.p) = (yyvsp[0].e);
 }
#line 2356 "parser.tab.cpp"
    break;

  case 98: /* GroupConditions: GroupConditions GroupCondition  */
#line 601 "parser.ypp"
                                                {
  // ovo nista ne znaci bez agregatnih fja
 }
#line 2364 "parser.tab.cpp"
    break;

  case 99: /* GroupConditions: GroupCondition  */
#line 604 "parser.ypp"
                 {
  // ovo nista ne znaci bez agregatnih fja
  }
#line 2372 "parser.tab.cpp"
    break;

  case 100: /* GroupCondition: var_token  */
#line 609 "parser.ypp"
                          {
  // ovo nista ne znaci bez agregatnih fja
 }
#line 2380 "parser.tab.cpp"
    break;

  case 101: /* BuiltInCall: regex_token '(' Expression ',' Expression ')'  */
#line 614 "parser.ypp"
                                                           {
  (yyval.e) = new BuiltinBinExpression("f_regex", (yyvsp[-3].e), (yyvsp[-1].e));
}
#line 2388 "parser.tab.cpp"
    break;

  case 102: /* BuiltInCall: regex_token '(' Expression ',' Expression ',' Expression ')'  */
#line 617 "parser.ypp"
                                                               {
  (yyval.e) = new BuiltinBinExpression("f_regex", (yyvsp[-5].e), (yyvsp[-3].e));
  delete (yyvsp[-1].e);
}
#line 2397 "parser.tab.cpp"
    break;

  case 103: /* BuiltInCall: builtin_str_token '(' Expression ')'  */
#line 621 "parser.ypp"
                                       {
  (yyval.e) = new BuiltinUnExpression("f_str", (yyvsp[-1].e));
  }
#line 2405 "parser.tab.cpp"
    break;

  case 104: /* BuiltInCall: round_token '(' Expression ')'  */
#line 624 "parser.ypp"
                                 {
  (yyval.e) = new BuiltinUnExpression("f_round", (yyvsp[-1].e));
  }
#line 2413 "parser.tab.cpp"
    break;

  case 105: /* BuiltInCall: abs_token '(' Expression ')'  */
#line 627 "parser.ypp"
                               {
  (yyval.e) = new BuiltinUnExpression("f_abs", (yyvsp[-1].e));
  }
#line 2421 "parser.tab.cpp"
    break;

  case 106: /* BuiltInCall: datatype_token '(' Expression ')'  */
#line 630 "parser.ypp"
                                    {
  (yyval.e) = new BuiltinUnExpression("f_datatype", (yyvsp[-1].e));
  }
#line 2429 "parser.tab.cpp"
    break;

  case 107: /* BuiltInCall: contains_token '(' Expression ',' Expression ')'  */
#line 633 "parser.ypp"
                                                   {
  (yyval.e) = new BuiltinBinExpression("f_contains", (yyvsp[-3].e), (yyvsp[-1].e));
  }
#line 2437 "parser.tab.cpp"
    break;

  case 108: /* BuiltInCall: lcase_token '(' Expression ')'  */
#line 636 "parser.ypp"
                                 {
  (yyval.e) = new BuiltinUnExpression("f_lcase", (yyvsp[-1].e));
  }
#line 2445 "parser.tab.cpp"
    break;

  case 109: /* BuiltInCall: is_literal_token '(' Expression ')'  */
#line 639 "parser.ypp"
                                      {
  (yyval.e) = new BuiltinUnExpression("f_isliteral", (yyvsp[-1].e));
  }
#line 2453 "parser.tab.cpp"
    break;

  case 110: /* BuiltInCall: is_uri_token '(' Expression ')'  */
#line 642 "parser.ypp"
                                  {
  (yyval.e) = new BuiltinUnExpression("f_isuri", (yyvsp[-1].e));
  }
#line 2461 "parser.tab.cpp"
    break;

  case 111: /* BuiltInCall: bound_token '(' Var ')'  */
#line 645 "parser.ypp"
                          {
  (yyval.e) = new BuiltinUnExpression("f_bound", new PrimaryExpression((yyvsp[-1].v)));
  }
#line 2469 "parser.tab.cpp"
    break;

  case 112: /* GraphGraphPattern: graph_token VarOrIri GroupGraphPattern  */
#line 650 "parser.ypp"
                                                          {
  (yyval.p) = new GraphPattern((yyvsp[-1].v), (yyvsp[0].p));
}
#line 2477 "parser.tab.cpp"
    break;

  case 113: /* Bind: bind_token '(' Expression as_token Var ')'  */
#line 655 "parser.ypp"
                                                 {
  (yyval.p) = new EqExpression(new PrimaryExpression((yyvsp[-1].v)), (yyvsp[-3].e));
 }
#line 2485 "parser.tab.cpp"
    break;

  case 114: /* ValuesClause: values_token Var '{' DataBlockValue '}'  */
#line 660 "parser.ypp"
                                                      {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[-3].v));
  (yyval.v1)->insert((yyval.v1)->end(), (yyvsp[-1].v1)->begin(), (yyvsp[-1].v1)->end());
}
#line 2495 "parser.tab.cpp"
    break;

  case 115: /* ValuesClause: %empty  */
#line 665 "parser.ypp"
  {
  (yyval.v1) = new vector<RDFValue*>();
}
#line 2503 "parser.tab.cpp"
    break;

  case 116: /* DataBlockValue: DataBlockValue IRIRef  */
#line 670 "parser.ypp"
                                      {
  (yyval.v1) = (yyvsp[-1].v1);
  (yyval.v1)->push_back((yyvsp[0].v));
}
#line 2512 "parser.tab.cpp"
    break;

  case 117: /* DataBlockValue: IRIRef  */
#line 674 "parser.ypp"
         {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[0].v));
 }
#line 2521 "parser.tab.cpp"
    break;


#line 2525 "parser.tab.cpp"

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

#line 680 "parser.ypp"

