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
     K_ALIAS = 258,
     K_ASSIGN = 259,
     K_BEGIN = 260,
     K_BY = 261,
     K_CASE = 262,
     K_CLOSE = 263,
     K_CONSTANT = 264,
     K_CONTINUE = 265,
     K_CURSOR = 266,
     K_DECLARE = 267,
     K_DEFAULT = 268,
     K_DIAGNOSTICS = 269,
     K_DOTDOT = 270,
     K_ELSE = 271,
     K_ELSIF = 272,
     K_END = 273,
     K_EXCEPTION = 274,
     K_EXECUTE = 275,
     K_EXIT = 276,
     K_FOR = 277,
     K_FETCH = 278,
     K_FROM = 279,
     K_GET = 280,
     K_IF = 281,
     K_IN = 282,
     K_INSERT = 283,
     K_INTO = 284,
     K_IS = 285,
     K_LOOP = 286,
     K_MOVE = 287,
     K_NOSCROLL = 288,
     K_NOT = 289,
     K_NULL = 290,
     K_OPEN = 291,
     K_OR = 292,
     K_PERFORM = 293,
     K_ROW_COUNT = 294,
     K_RAISE = 295,
     K_RENAME = 296,
     K_RESULT_OID = 297,
     K_RETURN = 298,
     K_REVERSE = 299,
     K_SCROLL = 300,
     K_STRICT = 301,
     K_THEN = 302,
     K_TO = 303,
     K_TYPE = 304,
     K_USING = 305,
     K_WHEN = 306,
     K_WHILE = 307,
     T_STRING = 308,
     T_NUMBER = 309,
     T_SCALAR = 310,
     T_ROW = 311,
     T_RECORD = 312,
     T_DTYPE = 313,
     T_WORD = 314,
     T_ERROR = 315,
     O_OPTION = 316,
     O_DUMP = 317
   };
#endif
/* Tokens.  */
#define K_ALIAS 258
#define K_ASSIGN 259
#define K_BEGIN 260
#define K_BY 261
#define K_CASE 262
#define K_CLOSE 263
#define K_CONSTANT 264
#define K_CONTINUE 265
#define K_CURSOR 266
#define K_DECLARE 267
#define K_DEFAULT 268
#define K_DIAGNOSTICS 269
#define K_DOTDOT 270
#define K_ELSE 271
#define K_ELSIF 272
#define K_END 273
#define K_EXCEPTION 274
#define K_EXECUTE 275
#define K_EXIT 276
#define K_FOR 277
#define K_FETCH 278
#define K_FROM 279
#define K_GET 280
#define K_IF 281
#define K_IN 282
#define K_INSERT 283
#define K_INTO 284
#define K_IS 285
#define K_LOOP 286
#define K_MOVE 287
#define K_NOSCROLL 288
#define K_NOT 289
#define K_NULL 290
#define K_OPEN 291
#define K_OR 292
#define K_PERFORM 293
#define K_ROW_COUNT 294
#define K_RAISE 295
#define K_RENAME 296
#define K_RESULT_OID 297
#define K_RETURN 298
#define K_REVERSE 299
#define K_SCROLL 300
#define K_STRICT 301
#define K_THEN 302
#define K_TO 303
#define K_TYPE 304
#define K_USING 305
#define K_WHEN 306
#define K_WHILE 307
#define T_STRING 308
#define T_NUMBER 309
#define T_SCALAR 310
#define T_ROW 311
#define T_RECORD 312
#define T_DTYPE 313
#define T_WORD 314
#define T_ERROR 315
#define O_OPTION 316
#define O_DUMP 317




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 79 "gram.y"
{
		int32					ival;
		bool					boolean;
		char					*str;
		struct
		{
			char *name;
			int  lineno;
		}						varname;
		struct
		{
			char *name;
			int  lineno;
			PLpgSQL_datum   *scalar;
			PLpgSQL_rec     *rec;
			PLpgSQL_row     *row;
		}						forvariable;
		struct
		{
			char *label;
			int  n_initvars;
			int  *initvarnos;
		}						declhdr;
		struct
		{
			char *end_label;
			List *stmts;
		}						loop_body;
		List					*list;
		PLpgSQL_type			*dtype;
		PLpgSQL_datum			*scalar;	/* a VAR, RECFIELD, or TRIGARG */
		PLpgSQL_variable		*variable;	/* a VAR, REC, or ROW */
		PLpgSQL_var				*var;
		PLpgSQL_row				*row;
		PLpgSQL_rec				*rec;
		PLpgSQL_expr			*expr;
		PLpgSQL_stmt			*stmt;
		PLpgSQL_stmt_block		*program;
		PLpgSQL_condition		*condition;
		PLpgSQL_exception		*exception;
		PLpgSQL_exception_block	*exception_block;
		PLpgSQL_nsitem			*nsitem;
		PLpgSQL_diag_item		*diagitem;
		PLpgSQL_stmt_fetch		*fetch;
		PLpgSQL_case_when		*casewhen;
}
/* Line 1529 of yacc.c.  */
#line 220 "pl_gram.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE plpgsql_yylval;

