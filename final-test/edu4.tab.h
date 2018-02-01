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
     IDEN = 258,
     NUMBER = 259,
     array = 260,
     define = 261,
     ELSE = 262,
     IF = 263,
     WHILE = 264,
     add = 265,
     sub = 266,
     mul = 267,
     divi = 268,
     eq = 269,
     deq = 270,
     lt = 271,
     gt = 272,
     le = 273,
     ge = 274,
     incri = 275,
     decri = 276,
     FOR = 277
   };
#endif
/* Tokens.  */
#define IDEN 258
#define NUMBER 259
#define array 260
#define define 261
#define ELSE 262
#define IF 263
#define WHILE 264
#define add 265
#define sub 266
#define mul 267
#define divi 268
#define eq 269
#define deq 270
#define lt 271
#define gt 272
#define le 273
#define ge 274
#define incri 275
#define decri 276
#define FOR 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "edu4.y"
{
  struct node *node;
  int ival;
  char *sval;
  int *dummy;
  double dval;
 }
/* Line 1529 of yacc.c.  */
#line 101 "edu4.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

