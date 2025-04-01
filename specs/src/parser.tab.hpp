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

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    select_token = 258,            /* select_token  */
    distinct_token = 259,          /* distinct_token  */
    where_token = 260,             /* where_token  */
    as_token = 261,                /* as_token  */
    union_token = 262,             /* union_token  */
    optional_token = 263,          /* optional_token  */
    minus_token = 264,             /* minus_token  */
    prefix_token = 265,            /* prefix_token  */
    schema_token = 266,            /* schema_token  */
    superquery_token = 267,        /* superquery_token  */
    subquery_token = 268,          /* subquery_token  */
    limit_token = 269,             /* limit_token  */
    from_token = 270,              /* from_token  */
    named_token = 271,             /* named_token  */
    order_by_token = 272,          /* order_by_token  */
    asc_token = 273,               /* asc_token  */
    desc_token = 274,              /* desc_token  */
    filter_token = 275,            /* filter_token  */
    regex_token = 276,             /* regex_token  */
    group_by_token = 277,          /* group_by_token  */
    and_token = 278,               /* and_token  */
    or_token = 279,                /* or_token  */
    graph_token = 280,             /* graph_token  */
    builtin_str_token = 281,       /* builtin_str_token  */
    noteq_token = 282,             /* noteq_token  */
    bind_token = 283,              /* bind_token  */
    round_token = 284,             /* round_token  */
    offset_token = 285,            /* offset_token  */
    abs_token = 286,               /* abs_token  */
    datatype_token = 287,          /* datatype_token  */
    values_token = 288,            /* values_token  */
    contains_token = 289,          /* contains_token  */
    lcase_token = 290,             /* lcase_token  */
    is_literal_token = 291,        /* is_literal_token  */
    is_uri_token = 292,            /* is_uri_token  */
    bound_token = 293,             /* bound_token  */
    var_token = 294,               /* var_token  */
    iri_token = 295,               /* iri_token  */
    str_token = 296,               /* str_token  */
    string_token = 297,            /* string_token  */
    blank_node_token = 298,        /* blank_node_token  */
    int_token = 299,               /* int_token  */
    geq_token = 300,               /* geq_token  */
    leq_token = 301                /* leq_token  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.ypp"

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

#line 129 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
