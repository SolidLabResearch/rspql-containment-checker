/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 160 "parser.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

