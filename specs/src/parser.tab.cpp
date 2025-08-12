/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     select_token = 258,
     distinct_token = 259,
     where_token = 260,
     as_token = 261,
     union_token = 262,
     optional_token = 263,
     minus_token = 264,
     prefix_token = 265,
     schema_token = 266,
     superquery_token = 267,
     subquery_token = 268,
     limit_token = 269,
     from_token = 270,
     named_token = 271,
     order_by_token = 272,
     asc_token = 273,
     desc_token = 274,
     filter_token = 275,
     regex_token = 276,
     group_by_token = 277,
     and_token = 278,
     or_token = 279,
     graph_token = 280,
     builtin_str_token = 281,
     noteq_token = 282,
     bind_token = 283,
     round_token = 284,
     offset_token = 285,
     abs_token = 286,
     datatype_token = 287,
     values_token = 288,
     contains_token = 289,
     lcase_token = 290,
     is_literal_token = 291,
     is_uri_token = 292,
     bound_token = 293,
     var_token = 294,
     iri_token = 295,
     str_token = 296,
     string_token = 297,
     blank_node_token = 298,
     int_token = 299,
     leq_token = 300,
     geq_token = 301
   };
#endif
/* Tokens.  */
#define select_token 258
#define distinct_token 259
#define where_token 260
#define as_token 261
#define union_token 262
#define optional_token 263
#define minus_token 264
#define prefix_token 265
#define schema_token 266
#define superquery_token 267
#define subquery_token 268
#define limit_token 269
#define from_token 270
#define named_token 271
#define order_by_token 272
#define asc_token 273
#define desc_token 274
#define filter_token 275
#define regex_token 276
#define group_by_token 277
#define and_token 278
#define or_token 279
#define graph_token 280
#define builtin_str_token 281
#define noteq_token 282
#define bind_token 283
#define round_token 284
#define offset_token 285
#define abs_token 286
#define datatype_token 287
#define values_token 288
#define contains_token 289
#define lcase_token 290
#define is_literal_token 291
#define is_uri_token 292
#define bound_token 293
#define var_token 294
#define iri_token 295
#define str_token 296
#define string_token 297
#define blank_node_token 298
#define int_token 299
#define leq_token 300
#define geq_token 301




/* Copy the first part of user declarations.  */
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
 


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.ypp"
{
  string *s;
  Pattern *p;
  RDFValue *v;
  vector <RDFValue* > *v1;
  vector <pair<RDFValue*, vector<RDFValue*> > > *v2;
  vector <Expression*> *v3;
  pair<vector <Expression*>, bool> *vb3;
  map<string, string> *m;
  Query *q;
  Expression *e;
  int i;
  pair<set<string>, set<string> > *ss;
  pair<int, int> *pii;
  pair<RDFValue *, bool> *pvb;
  vector<pair<RDFValue *, bool>> *vpvb;
  bool b;
}
/* Line 193 of yacc.c.  */
#line 228 "parser.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 241 "parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    15,    19,    20,    22,    24,    32,
      36,    38,    44,    45,    47,    48,    52,    54,    55,    57,
      59,    62,    64,    66,    72,    74,    78,    82,    86,    90,
      94,    98,   102,   106,   110,   114,   118,   122,   125,   129,
     131,   133,   135,   140,   142,   146,   151,   152,   155,   159,
     163,   166,   170,   171,   175,   177,   180,   181,   183,   185,
     187,   189,   191,   193,   197,   199,   201,   206,   209,   211,
     213,   217,   219,   221,   223,   225,   227,   229,   231,   233,
     237,   239,   242,   245,   248,   251,   252,   257,   262,   265,
     268,   269,   272,   274,   279,   284,   286,   291,   294,   297,
     299,   301,   308,   317,   322,   327,   332,   337,   344,   349,
     354,   359,   364,   368,   375,   381,   382,   385
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    13,    68,    12,    67,    -1,    66,
      12,    67,    13,    68,    -1,    11,    71,    86,    -1,    -1,
      69,    -1,    69,    -1,    71,    74,    81,    82,   100,   101,
     110,    -1,    74,    82,   100,    -1,    72,    -1,    72,    10,
      73,    55,    40,    -1,    -1,    41,    -1,    -1,     3,    75,
      76,    -1,     4,    -1,    -1,    77,    -1,    53,    -1,    77,
      78,    -1,    78,    -1,    79,    -1,    56,    80,     6,    79,
      57,    -1,    39,    -1,    80,    51,    80,    -1,    80,    52,
      80,    -1,    80,    53,    80,    -1,    80,    54,    80,    -1,
      80,    46,    80,    -1,    80,    47,    80,    -1,    80,    48,
      80,    -1,    80,    50,    80,    -1,    80,    49,    80,    -1,
      80,    27,    80,    -1,    80,    23,    80,    -1,    80,    24,
      80,    -1,    45,    80,    -1,    56,    80,    57,    -1,   107,
      -1,    79,    -1,    91,    -1,    90,    56,    80,    57,    -1,
      90,    -1,    81,    15,    90,    -1,    81,    15,    16,    90,
      -1,    -1,     5,    83,    -1,    58,    84,    59,    -1,    58,
      70,    59,    -1,    86,    85,    -1,    96,    86,    85,    -1,
      -1,    86,    60,    87,    -1,    87,    -1,    88,    92,    -1,
      -1,    89,    -1,    91,    -1,    39,    -1,    43,    -1,    90,
      -1,    40,    -1,    73,    55,    41,    -1,    42,    -1,    44,
      -1,    92,    61,    93,    94,    -1,    93,    94,    -1,    89,
      -1,    62,    -1,    94,    63,    95,    -1,    95,    -1,    88,
      -1,    97,    -1,    98,    -1,    99,    -1,   104,    -1,   108,
      -1,   109,    -1,    97,     7,    83,    -1,    83,    -1,     8,
      83,    -1,     9,    83,    -1,    17,   102,    -1,    22,   105,
      -1,    -1,    14,    44,    30,    44,    -1,    30,    44,    14,
      44,    -1,    14,    44,    -1,    30,    44,    -1,    -1,   102,
     103,    -1,   103,    -1,    19,    56,    39,    57,    -1,    18,
      56,    39,    57,    -1,    39,    -1,    20,    56,    80,    57,
      -1,    20,   107,    -1,   105,   106,    -1,   106,    -1,    39,
      -1,    21,    56,    80,    63,    80,    57,    -1,    21,    56,
      80,    63,    80,    63,    80,    57,    -1,    26,    56,    80,
      57,    -1,    29,    56,    80,    57,    -1,    31,    56,    80,
      57,    -1,    32,    56,    80,    57,    -1,    34,    56,    80,
      63,    80,    57,    -1,    35,    56,    80,    57,    -1,    36,
      56,    80,    57,    -1,    37,    56,    80,    57,    -1,    38,
      56,    79,    57,    -1,    25,    89,    83,    -1,    28,    56,
      80,     6,    79,    57,    -1,    33,    79,    58,   111,    59,
      -1,    -1,   111,    90,    -1,    90,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "select_token", "distinct_token",
  "where_token", "as_token", "union_token", "optional_token",
  "minus_token", "prefix_token", "schema_token", "superquery_token",
  "subquery_token", "limit_token", "from_token", "named_token",
  "order_by_token", "asc_token", "desc_token", "filter_token",
  "regex_token", "group_by_token", "and_token", "or_token", "graph_token",
  "builtin_str_token", "noteq_token", "bind_token", "round_token",
  "offset_token", "abs_token", "datatype_token", "values_token",
  "contains_token", "lcase_token", "is_literal_token", "is_uri_token",
  "bound_token", "var_token", "iri_token", "str_token", "string_token",
  "blank_node_token", "int_token", "'!'", "'<'", "'>'", "'='", "leq_token",
  "geq_token", "'+'", "'-'", "'*'", "'/'", "':'", "'('", "')'", "'{'",
  "'}'", "'.'", "';'", "'a'", "','", "$accept", "Program", "Schema",
  "SuperQuery", "SubQuery", "Query", "SubSelect", "Decl", "PrefixDecl",
  "Prefix", "SelectClause", "DistinctClause", "Selects", "Projections",
  "Projection", "Var", "Expression", "DatasetClause", "WhereClause",
  "GroupGraphPattern", "GroupGraphPatternSub", "GroupGraphPatternSubS",
  "TriplesBlock", "TriplesSameSubjectPath", "VarOrTerm", "VarOrIri",
  "IRIRef", "RDFLiteral", "PropertyListPathNotEmpty", "Verb", "ObjectList",
  "Object", "GraphPatternNotTriples", "GroupOrUnionGraphPattern",
  "OptionalGraphPattern", "MinusGraphPattern", "SolutionModifier",
  "LimitOffset", "OrderList", "OrderElem", "Filter", "GroupConditions",
  "GroupCondition", "BuiltInCall", "GraphGraphPattern", "Bind",
  "ValuesClause", "DataBlockValue", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    33,    60,    62,    61,   300,
     301,    43,    45,    42,    47,    58,    40,    41,   123,   125,
      46,    59,    97,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
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
      31,    33,    32,    25,    26,    27,    28,     0,    49,    85,
      48,     0,     0,     0,    14,     0,    80,    50,    56,    73,
      74,    75,    76,    77,    78,     0,     0,    91,    98,    88,
      89,     0,     8,    14,   103,   104,   105,   106,    14,   108,
     109,   110,   111,    23,    42,     9,    81,    82,    14,    97,
       0,    14,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,    51,    79,    94,    93,    86,    87,
      14,   101,    14,   107,    96,     0,   117,    14,     0,     0,
     114,   116,   102,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    23,    26,    24,   117,    25,     5,    15,
      37,    48,    57,    58,    59,    78,    79,    49,    63,   166,
     119,   167,    16,    17,    18,    19,    80,    81,    32,    33,
      43,    44,   168,   169,   170,   171,    90,   132,   125,   126,
     172,   128,   129,    82,   173,   174,   182,   227
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   218,   234,    -2,   -76,   269,   -76,   250,
     190,   -76,   -76,   -76,   219,   -47,    -7,   -76,   162,   -51,
     -76,    88,   -75,   264,   -31,   -14,    -4,    -1,   -76,   254,
     245,   248,   -76,   -76,   -76,   -76,   147,   -76,   -76,   189,
     -76,   -76,   187,   154,   -76,   -76,   -76,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
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

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 69 "parser.ypp"
    {
  subQuery = (yyvsp[(3) - (5)].q);
  superQuery = (yyvsp[(5) - (5)].q);
 ;}
    break;

  case 3:
#line 73 "parser.ypp"
    {
  subQuery = (yyvsp[(5) - (5)].q);
  superQuery = (yyvsp[(3) - (5)].q);
 ;}
    break;

  case 4:
#line 79 "parser.ypp"
    {
  schema = new Query(*(yyvsp[(2) - (3)].m), vector<Expression*>(), (yyvsp[(3) - (3)].p));
  delete (yyvsp[(2) - (3)].m);
 ;}
    break;

  case 5:
#line 83 "parser.ypp"
    {
  schema = nullptr;
 ;}
    break;

  case 6:
#line 88 "parser.ypp"
    {
  (yyval.q) = (yyvsp[(1) - (1)].q);
 ;}
    break;

  case 7:
#line 93 "parser.ypp"
    {
  (yyval.q) = (yyvsp[(1) - (1)].q);
 ;}
    break;

  case 8:
#line 98 "parser.ypp"
    {
  RDFValue *v = nullptr;
  vector<RDFValue*> values;
  if ((yyvsp[(7) - (7)].v1)->size() > 0) {
    v = (*(yyvsp[(7) - (7)].v1))[0];
    values = vector<RDFValue*>((yyvsp[(7) - (7)].v1)->begin() + 1, (yyvsp[(7) - (7)].v1)->end());
  }
  delete (yyvsp[(7) - (7)].v1);
  (yyval.q) = new Query(*(yyvsp[(1) - (7)].m), (yyvsp[(2) - (7)].vb3)->first, (yyvsp[(4) - (7)].p), (yyvsp[(2) - (7)].vb3)->second, *(yyvsp[(5) - (7)].vpvb), *(yyvsp[(3) - (7)].ss), (yyvsp[(6) - (7)].pii)->first, (yyvsp[(6) - (7)].pii)->second, v, values);
  delete (yyvsp[(1) - (7)].m);
  delete (yyvsp[(2) - (7)].vb3);
  delete (yyvsp[(3) - (7)].ss);
  delete (yyvsp[(5) - (7)].vpvb);
  delete (yyvsp[(6) - (7)].pii);
 ;}
    break;

  case 9:
#line 115 "parser.ypp"
    {
  Query *q = new Query(map<string, string>(), (yyvsp[(1) - (3)].vb3)->first, (yyvsp[(2) - (3)].p), (yyvsp[(1) - (3)].vb3)->second, *(yyvsp[(3) - (3)].vpvb));
  (yyval.p) = new SubqueryPattern(q);
  delete (yyvsp[(3) - (3)].vpvb);
 ;}
    break;

  case 10:
#line 122 "parser.ypp"
    {
  (yyval.m) = (yyvsp[(1) - (1)].m);
 ;}
    break;

  case 11:
#line 127 "parser.ypp"
    {
  (yyval.m) = (yyvsp[(1) - (5)].m);
  (*(yyval.m))[*(yyvsp[(3) - (5)].s)] = *(yyvsp[(5) - (5)].s);
  delete (yyvsp[(3) - (5)].s);
  delete (yyvsp[(5) - (5)].s);
 ;}
    break;

  case 12:
#line 133 "parser.ypp"
    {
  (yyval.m) = new map<string, string>();
 ;}
    break;

  case 13:
#line 138 "parser.ypp"
    {
  (yyval.s) = (yyvsp[(1) - (1)].s);
 ;}
    break;

  case 14:
#line 141 "parser.ypp"
    {
  (yyval.s) = new string("");
 ;}
    break;

  case 15:
#line 146 "parser.ypp"
    {
  (yyval.vb3) = new pair<vector<Expression*>, bool>(*(yyvsp[(3) - (3)].v3), (yyvsp[(2) - (3)].b));
  delete (yyvsp[(3) - (3)].v3);
;}
    break;

  case 16:
#line 152 "parser.ypp"
    {
  (yyval.b) = true;
 ;}
    break;

  case 17:
#line 155 "parser.ypp"
    {
  (yyval.b) = false;
 ;}
    break;

  case 18:
#line 160 "parser.ypp"
    {
  (yyval.v3) = (yyvsp[(1) - (1)].v3);
 ;}
    break;

  case 19:
#line 163 "parser.ypp"
    {
  (yyval.v3) = new vector<Expression*>();
 ;}
    break;

  case 20:
#line 168 "parser.ypp"
    {
  (yyval.v3) = (yyvsp[(1) - (2)].v3);
  (yyval.v3)->push_back((yyvsp[(2) - (2)].e));
 ;}
    break;

  case 21:
#line 172 "parser.ypp"
    {
  (yyval.v3) = new vector<Expression*>();
  (yyval.v3)->push_back((yyvsp[(1) - (1)].e));
 ;}
    break;

  case 22:
#line 178 "parser.ypp"
    {
  (yyval.e) = new PrimaryExpression((Variable*)(yyvsp[(1) - (1)].v));
 ;}
    break;

  case 23:
#line 181 "parser.ypp"
    {
  (yyval.e) = new EqExpression(new PrimaryExpression((yyvsp[(4) - (5)].v)), (yyvsp[(2) - (5)].e));
  //$$ = new PrimaryExpression($4);
 ;}
    break;

  case 24:
#line 187 "parser.ypp"
    {
  (yyval.v) = new Variable(*(yyvsp[(1) - (1)].s));
  delete (yyvsp[(1) - (1)].s);
 ;}
    break;

  case 25:
#line 193 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_add", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 26:
#line 196 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_sub", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 27:
#line 199 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_mul", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 28:
#line 202 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_div", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 29:
#line 205 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_lt", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 30:
#line 208 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_gt", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 31:
#line 211 "parser.ypp"
    {
  (yyval.e) = new EqExpression((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 32:
#line 214 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_geq", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 33:
#line 217 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_leq", (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
  ;}
    break;

  case 34:
#line 220 "parser.ypp"
    {
  (yyval.e) = new NotExpression(new EqExpression((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e)));
 ;}
    break;

  case 35:
#line 223 "parser.ypp"
    {
  (yyval.e) = new AndExpression((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
 ;}
    break;

  case 36:
#line 226 "parser.ypp"
    {
  (yyval.e) = new OrExpression((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e));
 ;}
    break;

  case 37:
#line 229 "parser.ypp"
    {
  (yyval.e) = new NotExpression((yyvsp[(2) - (2)].e));
  ;}
    break;

  case 38:
#line 232 "parser.ypp"
    {
  (yyval.e) = (yyvsp[(2) - (3)].e);
  ;}
    break;

  case 39:
#line 235 "parser.ypp"
    {
  (yyval.e) = (yyvsp[(1) - (1)].e);
  ;}
    break;

  case 40:
#line 238 "parser.ypp"
    {
  (yyval.e) = new PrimaryExpression((yyvsp[(1) - (1)].v));
  ;}
    break;

  case 41:
#line 241 "parser.ypp"
    {
  (yyval.e) = new PrimaryExpression((yyvsp[(1) - (1)].v));
  ;}
    break;

  case 42:
#line 244 "parser.ypp"
    {
  if (((IRI*)(yyvsp[(1) - (4)].v))->getIri() != "xsd:string")
    throw "TODO: IRIRef(Expression)";
  (yyval.e) = new BuiltinUnExpression("f_xsd_string", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 43:
#line 249 "parser.ypp"
    {
  (yyval.e) = new PrimaryExpression((yyvsp[(1) - (1)].v));
  ;}
    break;

  case 44:
#line 254 "parser.ypp"
    {
  (yyval.ss) = (yyvsp[(1) - (3)].ss);
  (yyval.ss)->first.insert(((IRI*)(yyvsp[(3) - (3)].v))->getIri());
  delete (yyvsp[(3) - (3)].v);
;}
    break;

  case 45:
#line 259 "parser.ypp"
    {
  (yyval.ss) = (yyvsp[(1) - (4)].ss);
  (yyval.ss)->second.insert(((IRI*)(yyvsp[(4) - (4)].v))->getIri());
  delete (yyvsp[(4) - (4)].v);
 ;}
    break;

  case 46:
#line 264 "parser.ypp"
    {
  (yyval.ss) = new pair<set<string>, set<string> > ();
 ;}
    break;

  case 47:
#line 269 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(2) - (2)].p);
 ;}
    break;

  case 48:
#line 274 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(2) - (3)].p);
 ;}
    break;

  case 49:
#line 277 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(2) - (3)].p);
  ;}
    break;

  case 50:
#line 282 "parser.ypp"
    {
  /*
  $$ = $1;
  addAddClausesToAdd($$, $2);
  */
  if ((yyvsp[(1) - (2)].p) == nullptr && (yyvsp[(2) - (2)].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[(1) - (2)].p) == nullptr && (yyvsp[(2) - (2)].p) != nullptr) {
    (yyval.p) = (yyvsp[(2) - (2)].p);
  }
  else if ((yyvsp[(1) - (2)].p) != nullptr && (yyvsp[(2) - (2)].p) == nullptr) {
    (yyval.p) = (yyvsp[(1) - (2)].p);
  }
  else if ((yyvsp[(1) - (2)].p) != nullptr && (yyvsp[(2) - (2)].p) != nullptr) {
    (yyval.p) = new And();
    ((And*)(yyval.p))->addPattern((yyvsp[(1) - (2)].p));
    ((And*)(yyval.p))->addPattern((yyvsp[(2) - (2)].p));
  }
 ;}
    break;

  case 51:
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
  if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(2) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(2) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    (yyval.p) = (yyvsp[(3) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(2) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = (yyvsp[(2) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(2) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    tmp->addPattern((yyvsp[(2) - (3)].p));
    tmp->addPattern((yyvsp[(3) - (3)].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(2) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = (yyvsp[(1) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(2) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    tmp->addPattern((yyvsp[(1) - (3)].p));
    tmp->addPattern((yyvsp[(3) - (3)].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(2) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    tmp->addPattern((yyvsp[(1) - (3)].p));
    tmp->addPattern((yyvsp[(2) - (3)].p));
    (yyval.p) = tmp;
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(2) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    tmp->addPattern((yyvsp[(1) - (3)].p));
    tmp->addPattern((yyvsp[(2) - (3)].p));
    And *tmp1 = new And();
    tmp1->addPattern(tmp);
    tmp1->addPattern((yyvsp[(3) - (3)].p));
    (yyval.p) = tmp1;
  }
 ;}
    break;

  case 52:
#line 354 "parser.ypp"
    {
  (yyval.p) = nullptr;
 ;}
    break;

  case 53:
#line 360 "parser.ypp"
    {
  /*
  $$ = $1;
  addAddClausesToAdd($$, $3);
  */
  if ((yyvsp[(1) - (3)].p) == nullptr  && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[(1) - (3)].p) == nullptr  && (yyvsp[(3) - (3)].p) != nullptr) {
    (yyval.p) = (yyvsp[(3) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr  && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = (yyvsp[(1) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr  && (yyvsp[(3) - (3)].p) != nullptr) {
    (yyval.p) = new And();
    ((And*)(yyval.p))->addPattern((yyvsp[(1) - (3)].p));
    ((And*)(yyval.p))->addPattern((yyvsp[(3) - (3)].p));
  }
 ;}
    break;

  case 54:
#line 380 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
 ;}
    break;

  case 55:
#line 385 "parser.ypp"
    {
  (yyval.p) = new And();
  for (auto a : *(yyvsp[(2) - (2)].v2)) {
    for (auto b : a.second)
      ((And*)(yyval.p))->addPattern(new TriplePattern((yyvsp[(1) - (2)].v)->clone(), a.first, b));
  }
  delete (yyvsp[(1) - (2)].v);
  delete (yyvsp[(2) - (2)].v2);
 ;}
    break;

  case 56:
#line 394 "parser.ypp"
    {
  (yyval.p) = nullptr;
 ;}
    break;

  case 57:
#line 399 "parser.ypp"
    {
  (yyval.v) = (yyvsp[(1) - (1)].v);
 ;}
    break;

  case 58:
#line 402 "parser.ypp"
    {
  (yyval.v) = (yyvsp[(1) - (1)].v);
 ;}
    break;

  case 59:
#line 407 "parser.ypp"
    {
  (yyval.v) = new Variable(*(yyvsp[(1) - (1)].s));
  delete (yyvsp[(1) - (1)].s);
 ;}
    break;

  case 60:
#line 411 "parser.ypp"
    {
  (yyval.v) = new BlankNode(*(yyvsp[(1) - (1)].s));
  delete (yyvsp[(1) - (1)].s);
  ;}
    break;

  case 61:
#line 415 "parser.ypp"
    {
  (yyval.v) = (yyvsp[(1) - (1)].v);
  ;}
    break;

  case 62:
#line 420 "parser.ypp"
    {
  (yyval.v) = new IRI(*(yyvsp[(1) - (1)].s));
  delete (yyvsp[(1) - (1)].s);
  ;}
    break;

  case 63:
#line 424 "parser.ypp"
    {
  (yyval.v) = new IRI(*(yyvsp[(1) - (3)].s) + ":" + *(yyvsp[(3) - (3)].s));
  delete (yyvsp[(1) - (3)].s);
  delete (yyvsp[(3) - (3)].s);
  ;}
    break;

  case 64:
#line 431 "parser.ypp"
    {
  (yyval.v) = new Literal(*(yyvsp[(1) - (1)].s));
  delete (yyvsp[(1) - (1)].s);
 ;}
    break;

  case 65:
#line 435 "parser.ypp"
    {
  (yyval.v) = new Literal(to_string((yyvsp[(1) - (1)].i)));
  ;}
    break;

  case 66:
#line 440 "parser.ypp"
    {
  (yyval.v2) = (yyvsp[(1) - (4)].v2);
  (yyval.v2)->push_back(make_pair((yyvsp[(3) - (4)].v), *(yyvsp[(4) - (4)].v1)));
  delete (yyvsp[(4) - (4)].v1);
 ;}
    break;

  case 67:
#line 445 "parser.ypp"
    {
  (yyval.v2) = new vector <pair<RDFValue*, vector<RDFValue*> > > ();
  (yyval.v2)->push_back(make_pair((yyvsp[(1) - (2)].v), *(yyvsp[(2) - (2)].v1)));
  delete (yyvsp[(2) - (2)].v1);
 ;}
    break;

  case 68:
#line 452 "parser.ypp"
    {
  (yyval.v) = (yyvsp[(1) - (1)].v);
 ;}
    break;

  case 69:
#line 455 "parser.ypp"
    {
  (yyval.v) = new IRI("a");
 ;}
    break;

  case 70:
#line 460 "parser.ypp"
    {
  (yyval.v1) = (yyvsp[(1) - (3)].v1);
  (yyval.v1)->push_back((yyvsp[(3) - (3)].v));
 ;}
    break;

  case 71:
#line 464 "parser.ypp"
    {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[(1) - (1)].v));
 ;}
    break;

  case 72:
#line 470 "parser.ypp"
    {
  (yyval.v) = (yyvsp[(1) - (1)].v);
 ;}
    break;

  case 73:
#line 475 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
 ;}
    break;

  case 74:
#line 478 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
 ;}
    break;

  case 75:
#line 481 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
 ;}
    break;

  case 76:
#line 484 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
  ;}
    break;

  case 77:
#line 487 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
  ;}
    break;

  case 78:
#line 490 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
  ;}
    break;

  case 79:
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
  if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = nullptr;
  }
  else if ((yyvsp[(1) - (3)].p) == nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    (yyval.p) = (yyvsp[(3) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) == nullptr) {
    (yyval.p) = (yyvsp[(1) - (3)].p);
  }
  else if ((yyvsp[(1) - (3)].p) != nullptr && (yyvsp[(3) - (3)].p) != nullptr) {
    (yyval.p) = new Union();
    ((Union*)(yyval.p))->addPattern((yyvsp[(1) - (3)].p));
    ((Union*)(yyval.p))->addPattern((yyvsp[(3) - (3)].p));
  }
 ;}
    break;

  case 80:
#line 522 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(1) - (1)].p);
 ;}
    break;

  case 81:
#line 527 "parser.ypp"
    {
  (yyval.p) = new OptionalPattern((yyvsp[(2) - (2)].p));
;}
    break;

  case 82:
#line 532 "parser.ypp"
    {
  (yyval.p) = new MinusPattern((yyvsp[(2) - (2)].p));
;}
    break;

  case 83:
#line 538 "parser.ypp"
    {
  (yyval.vpvb) = (yyvsp[(2) - (2)].vpvb);
;}
    break;

  case 84:
#line 541 "parser.ypp"
    {
  // ovo nista ne znaci bez agregatnih fja
  (yyval.vpvb) = new vector<pair <RDFValue*, bool> >();
 ;}
    break;

  case 85:
#line 545 "parser.ypp"
    {
  (yyval.vpvb) = new vector<pair <RDFValue*, bool> >();
  ;}
    break;

  case 86:
#line 550 "parser.ypp"
    {
  (yyval.pii) = new pair<int, int>((yyvsp[(2) - (4)].i), (yyvsp[(4) - (4)].i));
 ;}
    break;

  case 87:
#line 553 "parser.ypp"
    {
  (yyval.pii) = new pair<int, int>((yyvsp[(4) - (4)].i), (yyvsp[(2) - (4)].i));
 ;}
    break;

  case 88:
#line 556 "parser.ypp"
    {
  (yyval.pii) = new pair<int, int>((yyvsp[(2) - (2)].i), -1);
 ;}
    break;

  case 89:
#line 559 "parser.ypp"
    {
  (yyval.pii) = new pair<int, int>(-1, (yyvsp[(2) - (2)].i));
 ;}
    break;

  case 90:
#line 562 "parser.ypp"
    {
  (yyval.pii) = new pair<int, int>(-1, -1);
  ;}
    break;

  case 91:
#line 567 "parser.ypp"
    {
  (yyval.vpvb) = (yyvsp[(1) - (2)].vpvb);
  (yyval.vpvb)->push_back(*(yyvsp[(2) - (2)].pvb));
  delete (yyvsp[(2) - (2)].pvb);
 ;}
    break;

  case 92:
#line 572 "parser.ypp"
    {
  (yyval.vpvb) = new vector< pair<RDFValue*, bool> >();
  (yyval.vpvb)->push_back(*(yyvsp[(1) - (1)].pvb));
  delete (yyvsp[(1) - (1)].pvb);
 ;}
    break;

  case 93:
#line 579 "parser.ypp"
    {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[(3) - (4)].s)), false);
  delete (yyvsp[(3) - (4)].s);
 ;}
    break;

  case 94:
#line 583 "parser.ypp"
    {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[(3) - (4)].s)), true);
  delete (yyvsp[(3) - (4)].s);
 ;}
    break;

  case 95:
#line 587 "parser.ypp"
    {
  (yyval.pvb) = new pair<RDFValue*, bool>(new Variable(*(yyvsp[(1) - (1)].s)), true);
  delete (yyvsp[(1) - (1)].s);
 ;}
    break;

  case 96:
#line 593 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(3) - (4)].e);
 ;}
    break;

  case 97:
#line 596 "parser.ypp"
    {
  (yyval.p) = (yyvsp[(2) - (2)].e);
 ;}
    break;

  case 98:
#line 601 "parser.ypp"
    {
  // ovo nista ne znaci bez agregatnih fja
 ;}
    break;

  case 99:
#line 604 "parser.ypp"
    {
  // ovo nista ne znaci bez agregatnih fja
  ;}
    break;

  case 100:
#line 609 "parser.ypp"
    {
  // ovo nista ne znaci bez agregatnih fja
 ;}
    break;

  case 101:
#line 614 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_regex", (yyvsp[(3) - (6)].e), (yyvsp[(5) - (6)].e));
;}
    break;

  case 102:
#line 617 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_regex", (yyvsp[(3) - (8)].e), (yyvsp[(5) - (8)].e));
  delete (yyvsp[(7) - (8)].e);
;}
    break;

  case 103:
#line 621 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_str", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 104:
#line 624 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_round", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 105:
#line 627 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_abs", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 106:
#line 630 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_datatype", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 107:
#line 633 "parser.ypp"
    {
  (yyval.e) = new BuiltinBinExpression("f_contains", (yyvsp[(3) - (6)].e), (yyvsp[(5) - (6)].e));
  ;}
    break;

  case 108:
#line 636 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_lcase", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 109:
#line 639 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_isliteral", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 110:
#line 642 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_isuri", (yyvsp[(3) - (4)].e));
  ;}
    break;

  case 111:
#line 645 "parser.ypp"
    {
  (yyval.e) = new BuiltinUnExpression("f_bound", new PrimaryExpression((yyvsp[(3) - (4)].v)));
  ;}
    break;

  case 112:
#line 650 "parser.ypp"
    {
  (yyval.p) = new GraphPattern((yyvsp[(2) - (3)].v), (yyvsp[(3) - (3)].p));
;}
    break;

  case 113:
#line 655 "parser.ypp"
    {
  (yyval.p) = new EqExpression(new PrimaryExpression((yyvsp[(5) - (6)].v)), (yyvsp[(3) - (6)].e));
 ;}
    break;

  case 114:
#line 660 "parser.ypp"
    {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[(2) - (5)].v));
  (yyval.v1)->insert((yyval.v1)->end(), (yyvsp[(4) - (5)].v1)->begin(), (yyvsp[(4) - (5)].v1)->end());
;}
    break;

  case 115:
#line 665 "parser.ypp"
    {
  (yyval.v1) = new vector<RDFValue*>();
;}
    break;

  case 116:
#line 670 "parser.ypp"
    {
  (yyval.v1) = (yyvsp[(1) - (2)].v1);
  (yyval.v1)->push_back((yyvsp[(2) - (2)].v));
;}
    break;

  case 117:
#line 674 "parser.ypp"
    {
  (yyval.v1) = new vector<RDFValue*>();
  (yyval.v1)->push_back((yyvsp[(1) - (1)].v));
 ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2709 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 680 "parser.ypp"


