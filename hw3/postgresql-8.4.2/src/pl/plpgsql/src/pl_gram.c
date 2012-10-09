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

/* Substitute the variable and function names.  */
#define yyparse plpgsql_yyparse
#define yylex   plpgsql_yylex
#define yyerror plpgsql_yyerror
#define yylval  plpgsql_yylval
#define yychar  plpgsql_yychar
#define yydebug plpgsql_yydebug
#define yynerrs plpgsql_yynerrs


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




/* Copy the first part of user declarations.  */
#line 1 "gram.y"

/*-------------------------------------------------------------------------
 *
 * gram.y				- Parser for the PL/pgSQL
 *						  procedural language
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $PostgreSQL: pgsql/src/pl/plpgsql/src/gram.y,v 1.125 2009/06/18 10:22:09 petere Exp $
 *
 *-------------------------------------------------------------------------
 */

#include "plpgsql.h"

#include "catalog/pg_type.h"
#include "parser/parser.h"


/*
 * Bison doesn't allocate anything that needs to live across parser calls,
 * so we can easily have it use palloc instead of malloc.  This prevents
 * memory leaks if we error out during parsing.  Note this only works with
 * bison >= 2.0.  However, in bison 1.875 the default is to use alloca()
 * if possible, so there's not really much problem anyhow, at least if
 * you're building with gcc.
 */
#define YYMALLOC palloc
#define YYFREE   pfree


static PLpgSQL_expr		*read_sql_construct(int until,
											int until2,
											int until3,
											const char *expected,
											const char *sqlstart,
											bool isexpression,
											bool valid_sql,
											int *endtoken);
static PLpgSQL_expr		*read_sql_expression2(int until, int until2,
											  const char *expected,
											  int *endtoken);
static	PLpgSQL_expr	*read_sql_stmt(const char *sqlstart);
static	PLpgSQL_type	*read_datatype(int tok);
static	PLpgSQL_stmt	*make_execsql_stmt(const char *sqlstart, int lineno);
static	PLpgSQL_stmt_fetch *read_fetch_direction(void);
static	PLpgSQL_stmt	*make_return_stmt(int lineno);
static	PLpgSQL_stmt	*make_return_next_stmt(int lineno);
static	PLpgSQL_stmt	*make_return_query_stmt(int lineno);
static  PLpgSQL_stmt 	*make_case(int lineno, PLpgSQL_expr *t_expr,
								   List *case_when_list, List *else_stmts);
static	void			 check_assignable(PLpgSQL_datum *datum);
static	void			 read_into_target(PLpgSQL_rec **rec, PLpgSQL_row **row,
										  bool *strict);
static	PLpgSQL_row		*read_into_scalar_list(const char *initial_name,
											   PLpgSQL_datum *initial_datum);
static PLpgSQL_row		*make_scalar_list1(const char *initial_name,
										   PLpgSQL_datum *initial_datum,
										   int lineno);
static	void			 check_sql_expr(const char *stmt);
static	void			 plpgsql_sql_error_callback(void *arg);
static	char			*parse_string_token(const char *token);
static	void			 plpgsql_string_error_callback(void *arg);
static	char			*check_label(const char *yytxt);
static	void			 check_labels(const char *start_label,
									  const char *end_label);
static PLpgSQL_expr 	*read_cursor_args(PLpgSQL_var *cursor,
										  int until, const char *expected);
static List				*read_raise_options(void);



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
/* Line 193 of yacc.c.  */
#line 350 "pl_gram.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 363 "pl_gram.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNRULES -- Number of states.  */
#define YYNSTATES  252

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      66,    67,     2,     2,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
      64,     2,    65,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    10,    13,    15,    18,    19,
      21,    29,    31,    34,    38,    40,    43,    45,    51,    53,
      55,    61,    67,    73,    74,    82,    83,    85,    87,    88,
      89,    93,    95,    99,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   119,   121,   122,   123,   126,   128,   130,
     132,   134,   135,   137,   140,   142,   145,   147,   149,   151,
     153,   155,   157,   159,   161,   163,   165,   167,   169,   171,
     173,   175,   177,   179,   181,   185,   190,   196,   200,   202,
     206,   208,   210,   212,   214,   216,   218,   220,   222,   224,
     228,   237,   238,   244,   247,   256,   257,   260,   262,   267,
     268,   271,   276,   282,   287,   291,   293,   295,   297,   299,
     304,   306,   308,   311,   314,   320,   323,   325,   327,   329,
     332,   336,   342,   348,   349,   354,   357,   359,   361,   363,
     365,   366,   367,   372,   375,   377,   383,   387,   389,   391,
     392,   393,   394,   395,   396,   402,   403,   405,   407,   410,
     412,   414,   416,   418,   420
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      71,     0,    -1,    72,    76,    75,    -1,    -1,    73,    -1,
      73,    74,    -1,    74,    -1,    61,    62,    -1,    -1,    63,
      -1,    77,     5,   150,    97,   135,    18,   146,    -1,   145,
      -1,   145,    78,    -1,   145,    78,    79,    -1,    12,    -1,
      79,    80,    -1,    80,    -1,    64,    64,   149,    65,    65,
      -1,    12,    -1,    81,    -1,    90,    92,    93,    94,    95,
      -1,    90,     3,    22,    89,    63,    -1,    41,    91,    48,
      91,    63,    -1,    -1,    90,    83,    11,    82,    85,    88,
      84,    -1,    -1,    33,    -1,    45,    -1,    -1,    -1,    66,
      86,    67,    -1,    87,    -1,    86,    68,    87,    -1,    90,
      93,    -1,    30,    -1,    22,    -1,   148,    -1,    59,    -1,
      55,    -1,    56,    -1,    57,    -1,    59,    -1,    -1,     9,
      -1,    -1,    -1,    34,    35,    -1,    63,    -1,    96,    -1,
       4,    -1,    13,    -1,    -1,    98,    -1,    98,    99,    -1,
      99,    -1,    76,    63,    -1,   101,    -1,   108,    -1,   110,
      -1,   115,    -1,   116,    -1,   117,    -1,   120,    -1,   122,
      -1,   123,    -1,   125,    -1,   127,    -1,   100,    -1,   102,
      -1,   128,    -1,   129,    -1,   130,    -1,   132,    -1,   133,
      -1,    38,   150,   141,    -1,   107,   150,     4,   141,    -1,
      25,    14,   150,   103,    63,    -1,   103,    68,   104,    -1,
     104,    -1,   106,     4,   105,    -1,    39,    -1,    42,    -1,
      55,    -1,    56,    -1,    57,    -1,    59,    -1,    55,    -1,
      56,    -1,    57,    -1,   107,    69,   142,    -1,    26,   150,
     143,    97,   109,    18,    26,    63,    -1,    -1,    17,   150,
     143,    97,   109,    -1,    16,    97,    -1,     7,   150,   111,
     112,   114,    18,     7,    63,    -1,    -1,   112,   113,    -1,
     113,    -1,    51,   150,   143,    97,    -1,    -1,    16,    97,
      -1,   145,    31,   150,   124,    -1,   145,    52,   150,   144,
     124,    -1,   145,    22,   118,   124,    -1,   150,   119,    27,
      -1,    55,    -1,    59,    -1,    57,    -1,    56,    -1,   121,
     150,   146,   147,    -1,    21,    -1,    10,    -1,    43,   150,
      -1,    40,   150,    -1,    97,    18,    31,   146,    63,    -1,
     126,   150,    -1,    28,    -1,    59,    -1,    60,    -1,    20,
     150,    -1,    36,   150,   134,    -1,    23,   150,   131,   134,
      29,    -1,    32,   150,   131,   134,    63,    -1,    -1,     8,
     150,   134,    63,    -1,    35,    63,    -1,    55,    -1,    56,
      -1,    57,    -1,    59,    -1,    -1,    -1,    19,   150,   136,
     137,    -1,   137,   138,    -1,   138,    -1,    51,   150,   139,
      47,    97,    -1,   139,    37,   140,    -1,   140,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    64,   149,    65,
      65,    -1,    -1,   148,    -1,    63,    -1,    51,   141,    -1,
      59,    -1,    55,    -1,    57,    -1,    56,    -1,   148,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   247,   247,   253,   254,   257,   258,   261,   267,   268,
     271,   293,   300,   307,   319,   328,   330,   334,   336,   338,
     342,   376,   381,   386,   385,   437,   440,   444,   451,   463,
     466,   495,   499,   505,   512,   513,   515,   544,   552,   562,
     566,   573,   584,   585,   590,   601,   602,   606,   608,   616,
     617,   621,   622,   626,   633,   642,   644,   646,   648,   650,
     652,   654,   656,   658,   660,   662,   664,   666,   668,   670,
     672,   674,   676,   678,   682,   695,   709,   722,   726,   732,
     744,   748,   754,   759,   763,   767,   774,   779,   784,   789,
     804,   820,   823,   852,   858,   865,   879,   883,   889,   901,
     904,   919,   936,   954,   987,  1241,  1256,  1277,  1285,  1295,
    1310,  1314,  1320,  1349,  1485,  1492,  1499,  1501,  1503,  1507,
    1555,  1612,  1634,  1647,  1652,  1665,  1672,  1687,  1691,  1695,
    1702,  1704,  1703,  1736,  1740,  1746,  1759,  1768,  1774,  1811,
    1815,  1819,  1823,  1827,  1831,  1839,  1842,  1848,  1850,  1857,
    1861,  1865,  1869,  1875,  1885
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_ALIAS", "K_ASSIGN", "K_BEGIN", "K_BY",
  "K_CASE", "K_CLOSE", "K_CONSTANT", "K_CONTINUE", "K_CURSOR", "K_DECLARE",
  "K_DEFAULT", "K_DIAGNOSTICS", "K_DOTDOT", "K_ELSE", "K_ELSIF", "K_END",
  "K_EXCEPTION", "K_EXECUTE", "K_EXIT", "K_FOR", "K_FETCH", "K_FROM",
  "K_GET", "K_IF", "K_IN", "K_INSERT", "K_INTO", "K_IS", "K_LOOP",
  "K_MOVE", "K_NOSCROLL", "K_NOT", "K_NULL", "K_OPEN", "K_OR", "K_PERFORM",
  "K_ROW_COUNT", "K_RAISE", "K_RENAME", "K_RESULT_OID", "K_RETURN",
  "K_REVERSE", "K_SCROLL", "K_STRICT", "K_THEN", "K_TO", "K_TYPE",
  "K_USING", "K_WHEN", "K_WHILE", "T_STRING", "T_NUMBER", "T_SCALAR",
  "T_ROW", "T_RECORD", "T_DTYPE", "T_WORD", "T_ERROR", "O_OPTION",
  "O_DUMP", "';'", "'<'", "'>'", "'('", "')'", "','", "'['", "$accept",
  "pl_function", "comp_optsect", "comp_options", "comp_option", "opt_semi",
  "pl_block", "decl_sect", "decl_start", "decl_stmts", "decl_stmt",
  "decl_statement", "@1", "opt_scrollable", "decl_cursor_query",
  "decl_cursor_args", "decl_cursor_arglist", "decl_cursor_arg",
  "decl_is_for", "decl_aliasitem", "decl_varname", "decl_renname",
  "decl_const", "decl_datatype", "decl_notnull", "decl_defval",
  "decl_defkey", "proc_sect", "proc_stmts", "proc_stmt", "stmt_perform",
  "stmt_assign", "stmt_getdiag", "getdiag_list", "getdiag_list_item",
  "getdiag_kind", "getdiag_target", "assign_var", "stmt_if", "stmt_else",
  "stmt_case", "opt_expr_until_when", "case_when_list", "case_when",
  "opt_case_else", "stmt_loop", "stmt_while", "stmt_for", "for_control",
  "for_variable", "stmt_exit", "exit_type", "stmt_return", "stmt_raise",
  "loop_body", "stmt_execsql", "execsql_start", "stmt_dynexecute",
  "stmt_open", "stmt_fetch", "stmt_move", "opt_fetch_direction",
  "stmt_close", "stmt_null", "cursor_variable", "exception_sect", "@2",
  "proc_exceptions", "proc_exception", "proc_conditions", "proc_condition",
  "expr_until_semi", "expr_until_rightbracket", "expr_until_then",
  "expr_until_loop", "opt_block_label", "opt_label", "opt_exitcond",
  "any_identifier", "any_name", "lno", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    59,    60,    62,    40,    41,    44,    91
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    75,    75,
      76,    77,    77,    77,    78,    79,    79,    80,    80,    80,
      81,    81,    81,    82,    81,    83,    83,    83,    84,    85,
      85,    86,    86,    87,    88,    88,    89,    90,    90,    90,
      90,    91,    92,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   101,   102,   103,   103,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   109,   109,   109,   110,   111,   112,   112,   113,   114,
     114,   115,   116,   117,   118,   119,   119,   119,   119,   120,
     121,   121,   122,   123,   124,   125,   126,   126,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   134,   134,   134,
     135,   136,   135,   137,   137,   138,   139,   139,   140,   141,
     142,   143,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148,   149,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     1,     2,     1,     2,     0,     1,
       7,     1,     2,     3,     1,     2,     1,     5,     1,     1,
       5,     5,     5,     0,     7,     0,     1,     1,     0,     0,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     0,     2,     1,     1,     1,
       1,     0,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     5,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       8,     0,     5,     2,     8,     0,     2,     1,     4,     0,
       2,     4,     5,     4,     3,     1,     1,     1,     1,     4,
       1,     1,     2,     2,     5,     2,     1,     1,     1,     2,
       3,     5,     5,     0,     4,     2,     1,     1,     1,     1,
       0,     0,     4,     2,     1,     5,     3,     1,     1,     0,
       0,     0,     0,     0,     5,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,   143,     4,     6,     7,     1,     0,     8,
       0,    11,     5,     0,     9,     2,   154,    14,    12,   150,
     152,   151,   149,   153,     0,   143,    18,     0,    38,    39,
      40,    37,     0,    13,    16,    19,    42,     0,   154,   154,
     111,   154,   110,   154,     0,   154,   116,   154,     0,   154,
     154,   154,   154,    86,    87,    88,   117,   118,     0,   130,
      52,    54,    67,    56,    68,   154,    57,    58,    59,    60,
      61,    62,   154,    63,    64,    65,   154,    66,    69,    70,
      71,    72,    73,    11,    41,     0,     0,    15,     0,    43,
      26,    27,     0,    44,   144,    95,     0,   119,   123,   154,
     141,   123,   125,     0,   139,   113,   112,    55,   154,     0,
      53,   140,     0,   145,   115,   154,   154,   154,     0,     0,
       0,    23,    45,     0,   126,   127,   128,   129,     0,     0,
       0,   143,     0,   120,    74,   131,   145,    89,   139,     0,
     146,   143,     0,   143,   142,     0,     0,     0,    36,    29,
       0,     0,   154,    99,    97,   124,     0,    82,    83,    84,
      85,     0,    78,     0,    91,     0,     0,    10,    75,   139,
     147,   109,     0,   103,   105,   108,   107,   106,     0,   101,
     143,    22,    17,    21,     0,     0,    46,    49,    50,    47,
      20,    48,   141,   143,    96,     0,   121,    76,     0,     0,
     143,   154,     0,   122,   154,   132,   134,   148,     0,   104,
     102,     0,    31,    44,    35,    34,    28,   143,   100,     0,
      77,    80,    81,    79,    93,   141,     0,     0,   133,   145,
      30,     0,    33,    24,    98,     0,   143,     0,     0,   137,
     138,     0,    32,    94,    91,    90,     0,   143,   114,    92,
     136,   135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    15,    58,    10,    18,    33,
      34,    35,   149,    92,   233,   185,   211,   212,   216,   147,
      36,    85,    93,   122,   151,   190,   191,   172,    60,    61,
      62,    63,    64,   161,   162,   223,   163,    65,    66,   202,
      67,   123,   153,   154,   195,    68,    69,    70,   141,   178,
      71,    72,    73,    74,   173,    75,    76,    77,    78,    79,
      80,   129,    81,    82,   128,   109,   166,   205,   206,   238,
     239,   134,   137,   131,   180,    83,   139,   171,    23,   240,
      25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
     -15,   -38,    65,     2,   -15,  -178,  -178,  -178,     4,     6,
      67,    58,  -178,    26,  -178,  -178,  -178,  -178,    -7,  -178,
    -178,  -178,  -178,  -178,     8,   280,  -178,    15,  -178,  -178,
    -178,  -178,    11,    -7,  -178,  -178,    18,    24,  -178,  -178,
    -178,  -178,  -178,  -178,    80,  -178,  -178,  -178,    37,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    39,    89,
     106,  -178,  -178,  -178,  -178,    40,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,    25,  -178,    62,    26,  -178,    90,  -178,
    -178,  -178,   108,  -178,  -178,  -178,    31,  -178,  -178,  -178,
    -178,  -178,  -178,    31,  -178,  -178,  -178,  -178,  -178,    99,
    -178,  -178,   116,    26,  -178,  -178,  -178,  -178,    15,    56,
      26,  -178,    88,    72,  -178,  -178,  -178,  -178,    61,    31,
      36,   170,    31,  -178,  -178,  -178,    26,  -178,  -178,   -32,
    -178,   390,    42,   390,  -178,    70,    71,    76,  -178,    64,
     100,    13,  -178,     7,  -178,  -178,   111,  -178,  -178,  -178,
    -178,   -23,  -178,   139,    43,    82,    96,  -178,  -178,  -178,
    -178,  -178,   130,  -178,  -178,  -178,  -178,  -178,   123,  -178,
     390,  -178,  -178,  -178,    48,    14,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   390,  -178,   133,  -178,  -178,    36,   -17,
     390,  -178,   134,  -178,  -178,    96,  -178,  -178,   122,  -178,
    -178,   -26,  -178,  -178,  -178,  -178,  -178,   225,  -178,   147,
    -178,  -178,  -178,  -178,  -178,  -178,   129,    26,  -178,    26,
    -178,    48,  -178,  -178,  -178,    93,   170,    94,    -4,  -178,
    -178,    97,  -178,  -178,    43,  -178,    26,   335,  -178,  -178,
    -178,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -178,   155,  -178,   166,  -178,  -178,  -178,
     138,  -178,  -178,  -178,  -178,  -178,  -178,   -59,  -178,  -178,
    -177,    55,  -178,   -39,  -178,  -178,  -178,   -25,  -178,   119,
    -178,  -178,  -178,  -178,   -22,  -178,  -178,  -178,  -178,   -63,
    -178,  -178,  -178,    29,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -125,  -178,  -178,  -178,  -178,  -178,
    -178,    83,  -178,  -178,   -65,  -178,  -178,  -178,   -20,  -178,
     -57,  -108,  -178,  -172,  -178,   180,  -133,  -178,  -104,    -2,
     -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -144
static const yytype_int16 yytable[] =
{
      59,    95,    96,   167,    97,    26,    98,   213,   100,   140,
     101,    24,   103,   104,   105,   106,   148,   187,   179,   169,
     217,    88,   221,   193,     6,   222,   188,    89,   112,   -25,
     168,   170,   140,   246,    27,   113,   214,    17,   133,   114,
     197,   230,   231,   247,   215,   198,     1,   115,    28,    29,
      30,    90,    31,   236,   213,   210,   116,    32,   152,   200,
     201,   207,   130,    91,   156,     7,     8,   165,    13,    14,
      17,   135,    16,    37,    84,    86,   189,   117,   142,   143,
     144,    19,    20,    21,   119,    22,   124,   125,   126,    94,
     127,   157,   158,   159,    99,   160,   241,   174,   175,   176,
     102,   177,   107,    28,    29,    30,   164,    31,   108,   111,
     118,  -143,   120,    38,    39,   192,    40,   136,  -143,   121,
     138,   146,   150,   152,   155,   140,    41,    42,  -143,    43,
     184,    44,    45,   181,    46,   186,   182,  -143,    47,   183,
     196,    48,    49,   199,    50,   203,    51,   204,   208,    52,
     209,   219,   226,   229,   235,   237,   243,   245,  -143,    12,
     248,    53,    54,    55,   225,    56,    57,   227,   218,     9,
       8,    87,   242,   145,   232,   224,   220,    38,    39,   110,
      40,   249,   194,    11,   132,   228,   -51,   -51,   -51,   250,
      41,    42,   234,    43,     0,    44,    45,     0,    46,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,     0,
      51,   244,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,    53,    54,    55,     0,    56,
      57,     0,    38,    39,     8,    40,     0,     0,     0,     0,
       0,   -51,     0,   -51,     0,    41,    42,     0,    43,     0,
      44,    45,     0,    46,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,     0,    51,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,   -51,     0,     0,     0,
      53,    54,    55,     0,    56,    57,     0,    38,    39,     8,
      40,     0,     0,     0,     0,     0,     0,     0,   -51,   -51,
      41,    42,     0,    43,     0,    44,    45,     0,    46,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,     0,
      51,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,     0,    56,
      57,     0,    38,    39,     8,    40,     0,     0,     0,     0,
       0,     0,     0,   -51,     0,    41,    42,     0,    43,     0,
      44,    45,     0,    46,     0,     0,     0,    47,     0,     0,
      48,    49,     0,    50,     0,    51,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,   -51,     0,     0,     0,
      53,    54,    55,     0,    56,    57,     0,    38,    39,     8,
      40,     0,     0,     0,     0,     0,     0,     0,   -51,     0,
      41,    42,     0,    43,     0,    44,    45,     0,    46,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,     0,
      51,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,     0,    56,
      57,     0,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
      25,    38,    39,   136,    41,    12,    43,   184,    45,   113,
      47,    13,    49,    50,    51,    52,   120,     4,   143,    51,
     192,     3,    39,    16,    62,    42,    13,     9,    65,    11,
     138,    63,   136,    37,    41,    72,    22,    12,   103,    76,
      63,    67,    68,    47,    30,    68,    61,    22,    55,    56,
      57,    33,    59,   225,   231,   180,    31,    64,    51,    16,
      17,   169,    99,    45,   129,     0,    64,   132,    64,    63,
      12,   108,     5,    65,    59,    64,    63,    52,   115,   116,
     117,    55,    56,    57,    86,    59,    55,    56,    57,    65,
      59,    55,    56,    57,    14,    59,   229,    55,    56,    57,
      63,    59,    63,    55,    56,    57,   131,    59,    19,    69,
      48,     5,    22,     7,     8,   152,    10,    18,    12,    11,
       4,    65,    34,    51,    63,   229,    20,    21,    22,    23,
      66,    25,    26,    63,    28,    35,    65,    31,    32,    63,
      29,    35,    36,     4,    38,    63,    40,    51,    18,    43,
      27,    18,    18,    31,     7,    26,    63,    63,    52,     4,
      63,    55,    56,    57,   201,    59,    60,   204,   193,     3,
      64,    33,   231,   118,   213,   200,   198,     7,     8,    60,
      10,   244,   153,     3,   101,   205,    16,    17,    18,   246,
      20,    21,   217,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    -1,
      40,   236,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    -1,     7,     8,    64,    10,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    18,    -1,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    -1,     7,     8,    64,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    -1,     7,     8,    64,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    -1,     7,     8,    64,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    71,    72,    73,    74,    62,     0,    64,    76,
      77,   145,    74,    64,    63,    75,     5,    12,    78,    55,
      56,    57,    59,   148,   149,   150,    12,    41,    55,    56,
      57,    59,    64,    79,    80,    81,    90,    65,     7,     8,
      10,    20,    21,    23,    25,    26,    28,    32,    35,    36,
      38,    40,    43,    55,    56,    57,    59,    60,    76,    97,
      98,    99,   100,   101,   102,   107,   108,   110,   115,   116,
     117,   120,   121,   122,   123,   125,   126,   127,   128,   129,
     130,   132,   133,   145,    59,    91,    64,    80,     3,     9,
      33,    45,    83,    92,    65,   150,   150,   150,   150,    14,
     150,   150,    63,   150,   150,   150,   150,    63,    19,   135,
      99,    69,   150,   150,   150,    22,    31,    52,    48,   149,
      22,    11,    93,   111,    55,    56,    57,    59,   134,   131,
     150,   143,   131,   134,   141,   150,    18,   142,     4,   146,
     148,   118,   150,   150,   150,    91,    65,    89,   148,    82,
      34,    94,    51,   112,   113,    63,   134,    55,    56,    57,
      59,   103,   104,   106,    97,   134,   136,   146,   141,    51,
      63,   147,    97,   124,    55,    56,    57,    59,   119,   124,
     144,    63,    65,    63,    66,    85,    35,     4,    13,    63,
      95,    96,   150,    16,   113,   114,    29,    63,    68,     4,
      16,    17,   109,    63,    51,   137,   138,   141,    18,    27,
     124,    86,    87,    90,    22,    30,    88,   143,    97,    18,
     104,    39,    42,   105,    97,   150,    18,   150,   138,    31,
      67,    68,    93,    84,    97,     7,   143,    26,   139,   140,
     149,   146,    87,    63,    97,    63,    37,    47,    63,   109,
     140,    97
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
#line 248 "gram.y"
    {
						yylval.program = (PLpgSQL_stmt_block *) (yyvsp[(2) - (3)].stmt);
					;}
    break;

  case 7:
#line 262 "gram.y"
    {
						plpgsql_DumpExecTree = true;
					;}
    break;

  case 10:
#line 272 "gram.y"
    {
						PLpgSQL_stmt_block *new;

						new = palloc0(sizeof(PLpgSQL_stmt_block));

						new->cmd_type	= PLPGSQL_STMT_BLOCK;
						new->lineno		= (yyvsp[(3) - (7)].ival);
						new->label		= (yyvsp[(1) - (7)].declhdr).label;
						new->n_initvars = (yyvsp[(1) - (7)].declhdr).n_initvars;
						new->initvarnos = (yyvsp[(1) - (7)].declhdr).initvarnos;
						new->body		= (yyvsp[(4) - (7)].list);
						new->exceptions	= (yyvsp[(5) - (7)].exception_block);

						check_labels((yyvsp[(1) - (7)].declhdr).label, (yyvsp[(7) - (7)].str));
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 11:
#line 294 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.declhdr).label	  = (yyvsp[(1) - (1)].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					;}
    break;

  case 12:
#line 301 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.declhdr).label	  = (yyvsp[(1) - (2)].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					;}
    break;

  case 13:
#line 308 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						if ((yyvsp[(3) - (3)].str) != NULL)
							(yyval.declhdr).label = (yyvsp[(3) - (3)].str);
						else
							(yyval.declhdr).label = (yyvsp[(1) - (3)].str);
						/* Remember variables declared in decl_stmts */
						(yyval.declhdr).n_initvars = plpgsql_add_initdatums(&((yyval.declhdr).initvarnos));
					;}
    break;

  case 14:
#line 320 "gram.y"
    {
						/* Forget any variables created before block */
						plpgsql_add_initdatums(NULL);
						/* Make variable names be local to block */
						plpgsql_ns_setlocal(true);
					;}
    break;

  case 15:
#line 329 "gram.y"
    {	(yyval.str) = (yyvsp[(2) - (2)].str);	;}
    break;

  case 16:
#line 331 "gram.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	;}
    break;

  case 17:
#line 335 "gram.y"
    {	(yyval.str) = (yyvsp[(3) - (5)].str);	;}
    break;

  case 18:
#line 337 "gram.y"
    {	(yyval.str) = NULL;	;}
    break;

  case 19:
#line 339 "gram.y"
    {	(yyval.str) = NULL;	;}
    break;

  case 20:
#line 343 "gram.y"
    {
						PLpgSQL_variable	*var;

						var = plpgsql_build_variable((yyvsp[(1) - (5)].varname).name, (yyvsp[(1) - (5)].varname).lineno,
													 (yyvsp[(3) - (5)].dtype), true);
						if ((yyvsp[(2) - (5)].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->isconst = (yyvsp[(2) - (5)].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be CONSTANT")));
						}
						if ((yyvsp[(4) - (5)].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->notnull = (yyvsp[(4) - (5)].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be NOT NULL")));
						}
						if ((yyvsp[(5) - (5)].expr) != NULL)
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->default_val = (yyvsp[(5) - (5)].expr);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("default value for row or record variable is not supported")));
						}
					;}
    break;

  case 21:
#line 377 "gram.y"
    {
						plpgsql_ns_additem((yyvsp[(4) - (5)].nsitem)->itemtype,
										   (yyvsp[(4) - (5)].nsitem)->itemno, (yyvsp[(1) - (5)].varname).name);
					;}
    break;

  case 22:
#line 382 "gram.y"
    {
						plpgsql_ns_rename((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
					;}
    break;

  case 23:
#line 386 "gram.y"
    { plpgsql_ns_push((yyvsp[(1) - (3)].varname).name); ;}
    break;

  case 24:
#line 388 "gram.y"
    {
						PLpgSQL_var *new;
						PLpgSQL_expr *curname_def;
						char		buf[1024];
						char		*cp1;
						char		*cp2;

						/* pop local namespace for cursor args */
						plpgsql_ns_pop();

						new = (PLpgSQL_var *)
							plpgsql_build_variable((yyvsp[(1) - (7)].varname).name, (yyvsp[(1) - (7)].varname).lineno,
												   plpgsql_build_datatype(REFCURSOROID,
																		  -1),
												   true);

						curname_def = palloc0(sizeof(PLpgSQL_expr));

						curname_def->dtype = PLPGSQL_DTYPE_EXPR;
						strcpy(buf, "SELECT ");
						cp1 = new->refname;
						cp2 = buf + strlen(buf);
						/*
						 * Don't trust standard_conforming_strings here;
						 * it might change before we use the string.
						 */
						if (strchr(cp1, '\\') != NULL)
							*cp2++ = ESCAPE_STRING_SYNTAX;
						*cp2++ = '\'';
						while (*cp1)
						{
							if (SQL_STR_DOUBLE(*cp1, true))
								*cp2++ = *cp1;
							*cp2++ = *cp1++;
						}
						strcpy(cp2, "'::refcursor");
						curname_def->query = pstrdup(buf);
						new->default_val = curname_def;

						new->cursor_explicit_expr = (yyvsp[(7) - (7)].expr);
						if ((yyvsp[(5) - (7)].row) == NULL)
							new->cursor_explicit_argrow = -1;
						else
							new->cursor_explicit_argrow = (yyvsp[(5) - (7)].row)->dno;
						new->cursor_options = CURSOR_OPT_FAST_PLAN | (yyvsp[(2) - (7)].ival);
					;}
    break;

  case 25:
#line 437 "gram.y"
    {
						(yyval.ival) = 0;
					;}
    break;

  case 26:
#line 441 "gram.y"
    {
						(yyval.ival) = CURSOR_OPT_NO_SCROLL;
					;}
    break;

  case 27:
#line 445 "gram.y"
    {
						(yyval.ival) = CURSOR_OPT_SCROLL;
					;}
    break;

  case 28:
#line 451 "gram.y"
    {
						PLpgSQL_expr *query;

						plpgsql_ns_setlocal(false);
						query = read_sql_stmt("");
						plpgsql_ns_setlocal(true);

						(yyval.expr) = query;
					;}
    break;

  case 29:
#line 463 "gram.y"
    {
						(yyval.row) = NULL;
					;}
    break;

  case 30:
#line 467 "gram.y"
    {
						PLpgSQL_row *new;
						int i;
						ListCell *l;

						new = palloc0(sizeof(PLpgSQL_row));
						new->dtype = PLPGSQL_DTYPE_ROW;
						new->lineno = plpgsql_scanner_lineno();
						new->rowtupdesc = NULL;
						new->nfields = list_length((yyvsp[(2) - (3)].list));
						new->fieldnames = palloc(new->nfields * sizeof(char *));
						new->varnos = palloc(new->nfields * sizeof(int));

						i = 0;
						foreach (l, (yyvsp[(2) - (3)].list))
						{
							PLpgSQL_variable *arg = (PLpgSQL_variable *) lfirst(l);
							new->fieldnames[i] = arg->refname;
							new->varnos[i] = arg->dno;
							i++;
						}
						list_free((yyvsp[(2) - (3)].list));

						plpgsql_adddatum((PLpgSQL_datum *) new);
						(yyval.row) = new;
					;}
    break;

  case 31:
#line 496 "gram.y"
    {
						(yyval.list) = list_make1((yyvsp[(1) - (1)].variable));
					;}
    break;

  case 32:
#line 500 "gram.y"
    {
						(yyval.list) = lappend((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].variable));
					;}
    break;

  case 33:
#line 506 "gram.y"
    {
						(yyval.variable) = plpgsql_build_variable((yyvsp[(1) - (2)].varname).name, (yyvsp[(1) - (2)].varname).lineno,
													(yyvsp[(2) - (2)].dtype), true);
					;}
    break;

  case 36:
#line 516 "gram.y"
    {
						char	*name;
						PLpgSQL_nsitem *nsi;

						plpgsql_convert_ident((yyvsp[(1) - (1)].str), &name, 1);
						if (name[0] != '$')
							yyerror("only positional parameters can be aliased");

						plpgsql_ns_setlocal(false);

						nsi = plpgsql_ns_lookup(name, NULL, NULL, NULL);
						if (nsi == NULL)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_PARAMETER),
									 errmsg("function has no parameter \"%s\"",
											name)));
						}

						plpgsql_ns_setlocal(true);

						pfree(name);

						(yyval.nsitem) = nsi;
					;}
    break;

  case 37:
#line 545 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident(yytext, &name, 1);
						(yyval.varname).name = name;
						(yyval.varname).lineno  = plpgsql_scanner_lineno();
					;}
    break;

  case 38:
#line 553 "gram.y"
    {
						/*
						 * Since the scanner is only searching the topmost
						 * namestack entry, getting T_SCALAR etc can only
						 * happen if the name is already declared in this
						 * block.
						 */
						yyerror("duplicate declaration");
					;}
    break;

  case 39:
#line 563 "gram.y"
    {
						yyerror("duplicate declaration");
					;}
    break;

  case 40:
#line 567 "gram.y"
    {
						yyerror("duplicate declaration");
					;}
    break;

  case 41:
#line 574 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident(yytext, &name, 1);
						/* the result must be palloc'd, see plpgsql_ns_rename */
						(yyval.str) = name;
					;}
    break;

  case 42:
#line 584 "gram.y"
    { (yyval.boolean) = false; ;}
    break;

  case 43:
#line 586 "gram.y"
    { (yyval.boolean) = true; ;}
    break;

  case 44:
#line 590 "gram.y"
    {
						/*
						 * If there's a lookahead token, read_datatype
						 * should consume it.
						 */
						(yyval.dtype) = read_datatype(yychar);
						yyclearin;
					;}
    break;

  case 45:
#line 601 "gram.y"
    { (yyval.boolean) = false; ;}
    break;

  case 46:
#line 603 "gram.y"
    { (yyval.boolean) = true; ;}
    break;

  case 47:
#line 607 "gram.y"
    { (yyval.expr) = NULL; ;}
    break;

  case 48:
#line 609 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.expr) = plpgsql_read_expression(';', ";");
						plpgsql_ns_setlocal(true);
					;}
    break;

  case 51:
#line 621 "gram.y"
    { (yyval.list) = NIL; ;}
    break;

  case 52:
#line 623 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); ;}
    break;

  case 53:
#line 627 "gram.y"
    {
							if ((yyvsp[(2) - (2)].stmt) == NULL)
								(yyval.list) = (yyvsp[(1) - (2)].list);
							else
								(yyval.list) = lappend((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].stmt));
						;}
    break;

  case 54:
#line 634 "gram.y"
    {
							if ((yyvsp[(1) - (1)].stmt) == NULL)
								(yyval.list) = NIL;
							else
								(yyval.list) = list_make1((yyvsp[(1) - (1)].stmt));
						;}
    break;

  case 55:
#line 643 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].stmt); ;}
    break;

  case 56:
#line 645 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 57:
#line 647 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 58:
#line 649 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 59:
#line 651 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 60:
#line 653 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 61:
#line 655 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 62:
#line 657 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 63:
#line 659 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 64:
#line 661 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 65:
#line 663 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 66:
#line 665 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 67:
#line 667 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 68:
#line 669 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 69:
#line 671 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 70:
#line 673 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 71:
#line 675 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 72:
#line 677 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 73:
#line 679 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 74:
#line 683 "gram.y"
    {
						PLpgSQL_stmt_perform *new;

						new = palloc0(sizeof(PLpgSQL_stmt_perform));
						new->cmd_type = PLPGSQL_STMT_PERFORM;
						new->lineno   = (yyvsp[(2) - (3)].ival);
						new->expr  = (yyvsp[(3) - (3)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 75:
#line 696 "gram.y"
    {
						PLpgSQL_stmt_assign *new;

						new = palloc0(sizeof(PLpgSQL_stmt_assign));
						new->cmd_type = PLPGSQL_STMT_ASSIGN;
						new->lineno   = (yyvsp[(2) - (4)].ival);
						new->varno = (yyvsp[(1) - (4)].ival);
						new->expr  = (yyvsp[(4) - (4)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 76:
#line 710 "gram.y"
    {
						PLpgSQL_stmt_getdiag	 *new;

						new = palloc0(sizeof(PLpgSQL_stmt_getdiag));
						new->cmd_type = PLPGSQL_STMT_GETDIAG;
						new->lineno   = (yyvsp[(3) - (5)].ival);
						new->diag_items  = (yyvsp[(4) - (5)].list);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 77:
#line 723 "gram.y"
    {
						(yyval.list) = lappend((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].diagitem));
					;}
    break;

  case 78:
#line 727 "gram.y"
    {
						(yyval.list) = list_make1((yyvsp[(1) - (1)].diagitem));
					;}
    break;

  case 79:
#line 733 "gram.y"
    {
						PLpgSQL_diag_item *new;

						new = palloc(sizeof(PLpgSQL_diag_item));
						new->target = (yyvsp[(1) - (3)].ival);
						new->kind = (yyvsp[(3) - (3)].ival);

						(yyval.diagitem) = new;
					;}
    break;

  case 80:
#line 745 "gram.y"
    {
						(yyval.ival) = PLPGSQL_GETDIAG_ROW_COUNT;
					;}
    break;

  case 81:
#line 749 "gram.y"
    {
						(yyval.ival) = PLPGSQL_GETDIAG_RESULT_OID;
					;}
    break;

  case 82:
#line 755 "gram.y"
    {
						check_assignable(yylval.scalar);
						(yyval.ival) = yylval.scalar->dno;
					;}
    break;

  case 83:
#line 760 "gram.y"
    {
						yyerror("expected an integer variable");
					;}
    break;

  case 84:
#line 764 "gram.y"
    {
						yyerror("expected an integer variable");
					;}
    break;

  case 85:
#line 768 "gram.y"
    {
						yyerror("expected an integer variable");
					;}
    break;

  case 86:
#line 775 "gram.y"
    {
						check_assignable(yylval.scalar);
						(yyval.ival) = yylval.scalar->dno;
					;}
    break;

  case 87:
#line 780 "gram.y"
    {
						check_assignable((PLpgSQL_datum *) yylval.row);
						(yyval.ival) = yylval.row->dno;
					;}
    break;

  case 88:
#line 785 "gram.y"
    {
						check_assignable((PLpgSQL_datum *) yylval.rec);
						(yyval.ival) = yylval.rec->dno;
					;}
    break;

  case 89:
#line 790 "gram.y"
    {
						PLpgSQL_arrayelem	*new;

						new = palloc0(sizeof(PLpgSQL_arrayelem));
						new->dtype		= PLPGSQL_DTYPE_ARRAYELEM;
						new->subscript	= (yyvsp[(3) - (3)].expr);
						new->arrayparentno = (yyvsp[(1) - (3)].ival);

						plpgsql_adddatum((PLpgSQL_datum *)new);

						(yyval.ival) = new->dno;
					;}
    break;

  case 90:
#line 805 "gram.y"
    {
						PLpgSQL_stmt_if *new;

						new = palloc0(sizeof(PLpgSQL_stmt_if));
						new->cmd_type	= PLPGSQL_STMT_IF;
						new->lineno		= (yyvsp[(2) - (8)].ival);
						new->cond		= (yyvsp[(3) - (8)].expr);
						new->true_body	= (yyvsp[(4) - (8)].list);
						new->false_body = (yyvsp[(5) - (8)].list);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 91:
#line 820 "gram.y"
    {
						(yyval.list) = NIL;
					;}
    break;

  case 92:
#line 824 "gram.y"
    {
						/*
						 * Translate the structure:	   into:
						 *
						 * IF c1 THEN				   IF c1 THEN
						 *	 ...						   ...
						 * ELSIF c2 THEN			   ELSE
						 *								   IF c2 THEN
						 *	 ...							   ...
						 * ELSE							   ELSE
						 *	 ...							   ...
						 * END IF						   END IF
						 *							   END IF
						 */
						PLpgSQL_stmt_if *new_if;

						/* first create a new if-statement */
						new_if = palloc0(sizeof(PLpgSQL_stmt_if));
						new_if->cmd_type	= PLPGSQL_STMT_IF;
						new_if->lineno		= (yyvsp[(2) - (5)].ival);
						new_if->cond		= (yyvsp[(3) - (5)].expr);
						new_if->true_body	= (yyvsp[(4) - (5)].list);
						new_if->false_body	= (yyvsp[(5) - (5)].list);

						/* wrap the if-statement in a "container" list */
						(yyval.list) = list_make1(new_if);
					;}
    break;

  case 93:
#line 853 "gram.y"
    {
						(yyval.list) = (yyvsp[(2) - (2)].list);
					;}
    break;

  case 94:
#line 859 "gram.y"
    {
						(yyval.stmt) = make_case((yyvsp[(2) - (8)].ival), (yyvsp[(3) - (8)].expr), (yyvsp[(4) - (8)].list), (yyvsp[(5) - (8)].list));
					;}
    break;

  case 95:
#line 865 "gram.y"
    {
						PLpgSQL_expr *expr = NULL;
						int	tok = yylex();

						if (tok != K_WHEN)
						{
							plpgsql_push_back_token(tok);
							expr = plpgsql_read_expression(K_WHEN, "WHEN");
						}
						plpgsql_push_back_token(K_WHEN);
						(yyval.expr) = expr;
					;}
    break;

  case 96:
#line 880 "gram.y"
    {
						(yyval.list) = lappend((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].casewhen));
					;}
    break;

  case 97:
#line 884 "gram.y"
    {
						(yyval.list) = list_make1((yyvsp[(1) - (1)].casewhen));
					;}
    break;

  case 98:
#line 890 "gram.y"
    {
						PLpgSQL_case_when *new = palloc(sizeof(PLpgSQL_case_when));

						new->lineno	= (yyvsp[(2) - (4)].ival);
						new->expr	= (yyvsp[(3) - (4)].expr);
						new->stmts	= (yyvsp[(4) - (4)].list);
						(yyval.casewhen) = new;
					;}
    break;

  case 99:
#line 901 "gram.y"
    {
						(yyval.list) = NIL;
					;}
    break;

  case 100:
#line 905 "gram.y"
    {
						/*
						 * proc_sect could return an empty list, but we
						 * must distinguish that from not having ELSE at all.
						 * Simplest fix is to return a list with one NULL
						 * pointer, which make_case() must take care of.
						 */
						if ((yyvsp[(2) - (2)].list) != NIL)
							(yyval.list) = (yyvsp[(2) - (2)].list);
						else
							(yyval.list) = list_make1(NULL);
					;}
    break;

  case 101:
#line 920 "gram.y"
    {
						PLpgSQL_stmt_loop *new;

						new = palloc0(sizeof(PLpgSQL_stmt_loop));
						new->cmd_type = PLPGSQL_STMT_LOOP;
						new->lineno   = (yyvsp[(3) - (4)].ival);
						new->label	  = (yyvsp[(1) - (4)].str);
						new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;

						check_labels((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].loop_body).end_label);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 102:
#line 937 "gram.y"
    {
						PLpgSQL_stmt_while *new;

						new = palloc0(sizeof(PLpgSQL_stmt_while));
						new->cmd_type = PLPGSQL_STMT_WHILE;
						new->lineno   = (yyvsp[(3) - (5)].ival);
						new->label	  = (yyvsp[(1) - (5)].str);
						new->cond	  = (yyvsp[(4) - (5)].expr);
						new->body	  = (yyvsp[(5) - (5)].loop_body).stmts;

						check_labels((yyvsp[(1) - (5)].str), (yyvsp[(5) - (5)].loop_body).end_label);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 103:
#line 955 "gram.y"
    {
						/* This runs after we've scanned the loop body */
						if ((yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_FORI)
						{
							PLpgSQL_stmt_fori		*new;

							new = (PLpgSQL_stmt_fori *) (yyvsp[(3) - (4)].stmt);
							new->label	  = (yyvsp[(1) - (4)].str);
							new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_stmt_forq		*new;

							Assert((yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_FORS ||
								   (yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_FORC ||
								   (yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_DYNFORS);
							/* forq is the common supertype of all three */
							new = (PLpgSQL_stmt_forq *) (yyvsp[(3) - (4)].stmt);
							new->label	  = (yyvsp[(1) - (4)].str);
							new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}

						check_labels((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].loop_body).end_label);
						/* close namespace started in opt_block_label */
						plpgsql_ns_pop();
					;}
    break;

  case 104:
#line 988 "gram.y"
    {
						int			tok = yylex();

						if (tok == K_EXECUTE)
						{
							/* EXECUTE means it's a dynamic FOR loop */
							PLpgSQL_stmt_dynfors	*new;
							PLpgSQL_expr			*expr;
							int						term;

							expr = read_sql_expression2(K_LOOP, K_USING,
														"LOOP or USING",
														&term);

							new = palloc0(sizeof(PLpgSQL_stmt_dynfors));
							new->cmd_type = PLPGSQL_STMT_DYNFORS;
							new->lineno   = (yyvsp[(1) - (3)].ival);
							if ((yyvsp[(2) - (3)].forvariable).rec)
							{
								new->rec = (yyvsp[(2) - (3)].forvariable).rec;
								check_assignable((PLpgSQL_datum *) new->rec);
							}
							else if ((yyvsp[(2) - (3)].forvariable).row)
							{
								new->row = (yyvsp[(2) - (3)].forvariable).row;
								check_assignable((PLpgSQL_datum *) new->row);
							}
							else if ((yyvsp[(2) - (3)].forvariable).scalar)
							{
								/* convert single scalar to list */
								new->row = make_scalar_list1((yyvsp[(2) - (3)].forvariable).name, (yyvsp[(2) - (3)].forvariable).scalar, (yyvsp[(2) - (3)].forvariable).lineno);
								/* no need for check_assignable */
							}
							else
							{
								plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
								yyerror("loop variable of loop over rows must be a record or row variable or list of scalar variables");
							}
							new->query = expr;

							if (term == K_USING)
							{
								do
								{
									expr = read_sql_expression2(',', K_LOOP,
																", or LOOP",
																&term);
									new->params = lappend(new->params, expr);
								} while (term == ',');
							}

							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else if (tok == T_SCALAR &&
								 yylval.scalar->dtype == PLPGSQL_DTYPE_VAR &&
								 ((PLpgSQL_var *) yylval.scalar)->datatype->typoid == REFCURSOROID)
						{
							/* It's FOR var IN cursor */
							PLpgSQL_stmt_forc	*new;
							PLpgSQL_var			*cursor = (PLpgSQL_var *) yylval.scalar;
							char				*varname;

							new = (PLpgSQL_stmt_forc *) palloc0(sizeof(PLpgSQL_stmt_forc));
							new->cmd_type = PLPGSQL_STMT_FORC;
							new->lineno = (yyvsp[(1) - (3)].ival);

							new->curvar = cursor->dno;

							/* Should have had a single variable name */
							plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
							if ((yyvsp[(2) - (3)].forvariable).scalar && (yyvsp[(2) - (3)].forvariable).row)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("cursor FOR loop must have only one target variable")));

							/* create loop's private RECORD variable */
							plpgsql_convert_ident((yyvsp[(2) - (3)].forvariable).name, &varname, 1);
							new->rec = plpgsql_build_record(varname,
															(yyvsp[(2) - (3)].forvariable).lineno,
															true);

							/* can't use an unbound cursor this way */
							if (cursor->cursor_explicit_expr == NULL)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("cursor FOR loop must use a bound cursor variable")));

							/* collect cursor's parameters if any */
							new->argquery = read_cursor_args(cursor,
															 K_LOOP,
															 "LOOP");

							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_expr	*expr1;
							bool			 reverse = false;

							/*
							 * We have to distinguish between two
							 * alternatives: FOR var IN a .. b and FOR
							 * var IN query. Unfortunately this is
							 * tricky, since the query in the second
							 * form needn't start with a SELECT
							 * keyword.  We use the ugly hack of
							 * looking for two periods after the first
							 * token. We also check for the REVERSE
							 * keyword, which means it must be an
							 * integer loop.
							 */
							if (tok == K_REVERSE)
								reverse = true;
							else
								plpgsql_push_back_token(tok);

							/*
							 * Read tokens until we see either a ".."
							 * or a LOOP. The text we read may not
							 * necessarily be a well-formed SQL
							 * statement, so we need to invoke
							 * read_sql_construct directly.
							 */
							expr1 = read_sql_construct(K_DOTDOT,
													   K_LOOP,
													   0,
													   "LOOP",
													   "SELECT ",
													   true,
													   false,
													   &tok);

							if (tok == K_DOTDOT)
							{
								/* Saw "..", so it must be an integer loop */
								PLpgSQL_expr		*expr2;
								PLpgSQL_expr		*expr_by;
								PLpgSQL_var			*fvar;
								PLpgSQL_stmt_fori	*new;
								char				*varname;

								/* Check first expression is well-formed */
								check_sql_expr(expr1->query);

								/* Read and check the second one */
								expr2 = read_sql_expression2(K_LOOP, K_BY,
															 "LOOP",
															 &tok);

								/* Get the BY clause if any */
								if (tok == K_BY)
									expr_by = plpgsql_read_expression(K_LOOP,
																	  "LOOP");
								else
									expr_by = NULL;

								/* Should have had a single variable name */
								plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
								if ((yyvsp[(2) - (3)].forvariable).scalar && (yyvsp[(2) - (3)].forvariable).row)
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("integer FOR loop must have only one target variable")));

								/* create loop's private variable */
								plpgsql_convert_ident((yyvsp[(2) - (3)].forvariable).name, &varname, 1);
								fvar = (PLpgSQL_var *)
									plpgsql_build_variable(varname,
														   (yyvsp[(2) - (3)].forvariable).lineno,
														   plpgsql_build_datatype(INT4OID,
																				  -1),
														   true);

								new = palloc0(sizeof(PLpgSQL_stmt_fori));
								new->cmd_type = PLPGSQL_STMT_FORI;
								new->lineno   = (yyvsp[(1) - (3)].ival);
								new->var	  = fvar;
								new->reverse  = reverse;
								new->lower	  = expr1;
								new->upper	  = expr2;
								new->step	  = expr_by;

								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
							else
							{
								/*
								 * No "..", so it must be a query loop. We've prefixed an
								 * extra SELECT to the query text, so we need to remove that
								 * before performing syntax checking.
								 */
								char				*tmp_query;
								PLpgSQL_stmt_fors	*new;

								if (reverse)
									yyerror("cannot specify REVERSE in query FOR loop");

								Assert(strncmp(expr1->query, "SELECT ", 7) == 0);
								tmp_query = pstrdup(expr1->query + 7);
								pfree(expr1->query);
								expr1->query = tmp_query;

								check_sql_expr(expr1->query);

								new = palloc0(sizeof(PLpgSQL_stmt_fors));
								new->cmd_type = PLPGSQL_STMT_FORS;
								new->lineno   = (yyvsp[(1) - (3)].ival);
								if ((yyvsp[(2) - (3)].forvariable).rec)
								{
									new->rec = (yyvsp[(2) - (3)].forvariable).rec;
									check_assignable((PLpgSQL_datum *) new->rec);
								}
								else if ((yyvsp[(2) - (3)].forvariable).row)
								{
									new->row = (yyvsp[(2) - (3)].forvariable).row;
									check_assignable((PLpgSQL_datum *) new->row);
								}
								else if ((yyvsp[(2) - (3)].forvariable).scalar)
								{
									/* convert single scalar to list */
									new->row = make_scalar_list1((yyvsp[(2) - (3)].forvariable).name, (yyvsp[(2) - (3)].forvariable).scalar, (yyvsp[(2) - (3)].forvariable).lineno);
									/* no need for check_assignable */
								}
								else
								{
									plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
									yyerror("loop variable of loop over rows must be a record or row variable or list of scalar variables");
								}

								new->query = expr1;
								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
						}
					;}
    break;

  case 105:
#line 1242 "gram.y"
    {
						int			tok;

						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = yylval.scalar;
						(yyval.forvariable).rec = NULL;
						(yyval.forvariable).row = NULL;
						/* check for comma-separated list */
						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == ',')
							(yyval.forvariable).row = read_into_scalar_list((yyval.forvariable).name, (yyval.forvariable).scalar);
					;}
    break;

  case 106:
#line 1257 "gram.y"
    {
						int			tok;

						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).rec = NULL;
						(yyval.forvariable).row = NULL;
						/* check for comma-separated list */
						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == ',')
						{
							plpgsql_error_lineno = (yyval.forvariable).lineno;
							ereport(ERROR,
									(errcode(ERRCODE_SYNTAX_ERROR),
									 errmsg("\"%s\" is not a scalar variable",
											(yyval.forvariable).name)));
						}
					;}
    break;

  case 107:
#line 1278 "gram.y"
    {
						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).rec = yylval.rec;
						(yyval.forvariable).row = NULL;
					;}
    break;

  case 108:
#line 1286 "gram.y"
    {
						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).row = yylval.row;
						(yyval.forvariable).rec = NULL;
					;}
    break;

  case 109:
#line 1296 "gram.y"
    {
						PLpgSQL_stmt_exit *new;

						new = palloc0(sizeof(PLpgSQL_stmt_exit));
						new->cmd_type = PLPGSQL_STMT_EXIT;
						new->is_exit  = (yyvsp[(1) - (4)].boolean);
						new->lineno	  = (yyvsp[(2) - (4)].ival);
						new->label	  = (yyvsp[(3) - (4)].str);
						new->cond	  = (yyvsp[(4) - (4)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 110:
#line 1311 "gram.y"
    {
						(yyval.boolean) = true;
					;}
    break;

  case 111:
#line 1315 "gram.y"
    {
						(yyval.boolean) = false;
					;}
    break;

  case 112:
#line 1321 "gram.y"
    {
						int	tok;

						tok = yylex();
						if (tok == 0)
							yyerror("unexpected end of function definition");

						/*
						 * To avoid making NEXT and QUERY effectively be
						 * reserved words within plpgsql, recognize them
						 * via yytext.
						 */
						if (pg_strcasecmp(yytext, "next") == 0)
						{
							(yyval.stmt) = make_return_next_stmt((yyvsp[(2) - (2)].ival));
						}
						else if (pg_strcasecmp(yytext, "query") == 0)
						{
							(yyval.stmt) = make_return_query_stmt((yyvsp[(2) - (2)].ival));
						}
						else
						{
							plpgsql_push_back_token(tok);
							(yyval.stmt) = make_return_stmt((yyvsp[(2) - (2)].ival));
						}
					;}
    break;

  case 113:
#line 1350 "gram.y"
    {
						PLpgSQL_stmt_raise		*new;
						int	tok;

						new = palloc(sizeof(PLpgSQL_stmt_raise));

						new->cmd_type	= PLPGSQL_STMT_RAISE;
						new->lineno		= (yyvsp[(2) - (2)].ival);
						new->elog_level = ERROR;	/* default */
						new->condname	= NULL;
						new->message	= NULL;
						new->params		= NIL;
						new->options	= NIL;

						tok = yylex();
						if (tok == 0)
							yyerror("unexpected end of function definition");

						/*
						 * We could have just RAISE, meaning to re-throw
						 * the current error.
						 */
						if (tok != ';')
						{
							/*
							 * First is an optional elog severity level.
							 * Most of these are not plpgsql keywords,
							 * so we rely on examining yytext.
							 */
							if (pg_strcasecmp(yytext, "exception") == 0)
							{
								new->elog_level = ERROR;
								tok = yylex();
							}
							else if (pg_strcasecmp(yytext, "warning") == 0)
							{
								new->elog_level = WARNING;
								tok = yylex();
							}
							else if (pg_strcasecmp(yytext, "notice") == 0)
							{
								new->elog_level = NOTICE;
								tok = yylex();
							}
							else if (pg_strcasecmp(yytext, "info") == 0)
							{
								new->elog_level = INFO;
								tok = yylex();
							}
							else if (pg_strcasecmp(yytext, "log") == 0)
							{
								new->elog_level = LOG;
								tok = yylex();
							}
							else if (pg_strcasecmp(yytext, "debug") == 0)
							{
								new->elog_level = DEBUG1;
								tok = yylex();
							}
							if (tok == 0)
								yyerror("unexpected end of function definition");

							/*
							 * Next we can have a condition name, or
							 * equivalently SQLSTATE 'xxxxx', or a string
							 * literal that is the old-style message format,
							 * or USING to start the option list immediately.
							 */
							if (tok == T_STRING)
							{
								/* old style message and parameters */
								new->message = parse_string_token(yytext);
								/*
								 * We expect either a semi-colon, which
								 * indicates no parameters, or a comma that
								 * begins the list of parameter expressions,
								 * or USING to begin the options list.
								 */
								tok = yylex();
								if (tok != ',' && tok != ';' && tok != K_USING)
									yyerror("syntax error");

								while (tok == ',')
								{
									PLpgSQL_expr *expr;

									expr = read_sql_construct(',', ';', K_USING,
															  ", or ; or USING",
															  "SELECT ",
															  true, true, &tok);
									new->params = lappend(new->params, expr);
								}
							}
							else if (tok != K_USING)
							{
								/* must be condition name or SQLSTATE */
								if (pg_strcasecmp(yytext, "sqlstate") == 0)
								{
									/* next token should be a string literal */
									char   *sqlstatestr;

									if (yylex() != T_STRING)
										yyerror("syntax error");
									sqlstatestr = parse_string_token(yytext);

									if (strlen(sqlstatestr) != 5)
										yyerror("invalid SQLSTATE code");
									if (strspn(sqlstatestr, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 5)
										yyerror("invalid SQLSTATE code");
									new->condname = sqlstatestr;
								}
								else
								{
									char   *cname;

									if (tok != T_WORD)
										yyerror("syntax error");
									plpgsql_convert_ident(yytext, &cname, 1);
									plpgsql_recognize_err_condition(cname,
																	false);
									new->condname = cname;
								}
								tok = yylex();
								if (tok != ';' && tok != K_USING)
									yyerror("syntax error");
							}

							if (tok == K_USING)
								new->options = read_raise_options();
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 114:
#line 1486 "gram.y"
    {
						(yyval.loop_body).stmts = (yyvsp[(1) - (5)].list);
						(yyval.loop_body).end_label = (yyvsp[(4) - (5)].str);
					;}
    break;

  case 115:
#line 1493 "gram.y"
    {
						(yyval.stmt) = make_execsql_stmt((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival));
					;}
    break;

  case 116:
#line 1500 "gram.y"
    { (yyval.str) = pstrdup(yytext); ;}
    break;

  case 117:
#line 1502 "gram.y"
    { (yyval.str) = pstrdup(yytext); ;}
    break;

  case 118:
#line 1504 "gram.y"
    { (yyval.str) = pstrdup(yytext); ;}
    break;

  case 119:
#line 1508 "gram.y"
    {
						PLpgSQL_stmt_dynexecute *new;
						PLpgSQL_expr *expr;
						int endtoken;

						expr = read_sql_construct(K_INTO, K_USING, ';',
												  "INTO or USING or ;",
												  "SELECT ",
												  true, true, &endtoken);

						new = palloc(sizeof(PLpgSQL_stmt_dynexecute));
						new->cmd_type = PLPGSQL_STMT_DYNEXECUTE;
						new->lineno = (yyvsp[(2) - (2)].ival);
						new->query = expr;
						new->into = false;
						new->strict = false;
						new->rec = NULL;
						new->row = NULL;
						new->params = NIL;

						/* If we found "INTO", collect the argument */
						if (endtoken == K_INTO)
						{
							new->into = true;
							read_into_target(&new->rec, &new->row, &new->strict);
							endtoken = yylex();
							if (endtoken != ';' && endtoken != K_USING)
								yyerror("syntax error");
						}

						/* If we found "USING", collect the argument(s) */
						if (endtoken == K_USING)
						{
							do
							{
								expr = read_sql_expression2(',', ';',
															", or ;",
															&endtoken);
								new->params = lappend(new->params, expr);
							} while (endtoken == ',');
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 120:
#line 1556 "gram.y"
    {
						PLpgSQL_stmt_open *new;
						int				  tok;

						new = palloc0(sizeof(PLpgSQL_stmt_open));
						new->cmd_type = PLPGSQL_STMT_OPEN;
						new->lineno = (yyvsp[(2) - (3)].ival);
						new->curvar = (yyvsp[(3) - (3)].var)->dno;
						new->cursor_options = CURSOR_OPT_FAST_PLAN;

						if ((yyvsp[(3) - (3)].var)->cursor_explicit_expr == NULL)
						{
							/* be nice if we could use opt_scrollable here */
						    tok = yylex();
							if (tok == K_NOSCROLL)
							{
								new->cursor_options |= CURSOR_OPT_NO_SCROLL;
								tok = yylex();
							}
							else if (tok == K_SCROLL)
							{
								new->cursor_options |= CURSOR_OPT_SCROLL;
								tok = yylex();
							}

							if (tok != K_FOR)
							{
								plpgsql_error_lineno = (yyvsp[(2) - (3)].ival);
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("syntax error at \"%s\"",
												yytext),
										 errdetail("Expected \"FOR\", to open a cursor for an unbound cursor variable.")));
							}

							tok = yylex();
							if (tok == K_EXECUTE)
							{
								new->dynquery = read_sql_stmt("SELECT ");
							}
							else
							{
								plpgsql_push_back_token(tok);
								new->query = read_sql_stmt("");
							}
						}
						else
						{
							/* predefined cursor query, so read args */
							new->argquery = read_cursor_args((yyvsp[(3) - (3)].var), ';', ";");
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 121:
#line 1613 "gram.y"
    {
						PLpgSQL_stmt_fetch *fetch = (yyvsp[(3) - (5)].fetch);
						PLpgSQL_rec	   *rec;
						PLpgSQL_row	   *row;

						/* We have already parsed everything through the INTO keyword */
						read_into_target(&rec, &row, NULL);

						if (yylex() != ';')
							yyerror("syntax error");

						fetch->lineno = (yyvsp[(2) - (5)].ival);
						fetch->rec		= rec;
						fetch->row		= row;
						fetch->curvar	= (yyvsp[(4) - (5)].var)->dno;
						fetch->is_move	= false;

						(yyval.stmt) = (PLpgSQL_stmt *)fetch;
					;}
    break;

  case 122:
#line 1635 "gram.y"
    {
						PLpgSQL_stmt_fetch *fetch = (yyvsp[(3) - (5)].fetch);

						fetch->lineno = (yyvsp[(2) - (5)].ival);
						fetch->curvar	= (yyvsp[(4) - (5)].var)->dno;
						fetch->is_move	= true;

						(yyval.stmt) = (PLpgSQL_stmt *)fetch;
					;}
    break;

  case 123:
#line 1647 "gram.y"
    {
						(yyval.fetch) = read_fetch_direction();
					;}
    break;

  case 124:
#line 1653 "gram.y"
    {
						PLpgSQL_stmt_close *new;

						new = palloc(sizeof(PLpgSQL_stmt_close));
						new->cmd_type = PLPGSQL_STMT_CLOSE;
						new->lineno = (yyvsp[(2) - (4)].ival);
						new->curvar = (yyvsp[(3) - (4)].var)->dno;

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					;}
    break;

  case 125:
#line 1666 "gram.y"
    {
						/* We do not bother building a node for NULL */
						(yyval.stmt) = NULL;
					;}
    break;

  case 126:
#line 1673 "gram.y"
    {
						if (yylval.scalar->dtype != PLPGSQL_DTYPE_VAR)
							yyerror("cursor variable must be a simple variable");

						if (((PLpgSQL_var *) yylval.scalar)->datatype->typoid != REFCURSOROID)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("variable \"%s\" must be of type cursor or refcursor",
											((PLpgSQL_var *) yylval.scalar)->refname)));
						}
						(yyval.var) = (PLpgSQL_var *) yylval.scalar;
					;}
    break;

  case 127:
#line 1688 "gram.y"
    {
						yyerror("expected a cursor or refcursor variable");
					;}
    break;

  case 128:
#line 1692 "gram.y"
    {
						yyerror("expected a cursor or refcursor variable");
					;}
    break;

  case 129:
#line 1696 "gram.y"
    {
						yyerror("expected a cursor or refcursor variable");
					;}
    break;

  case 130:
#line 1702 "gram.y"
    { (yyval.exception_block) = NULL; ;}
    break;

  case 131:
#line 1704 "gram.y"
    {
						/*
						 * We use a mid-rule action to add these
						 * special variables to the namespace before
						 * parsing the WHEN clauses themselves.
						 */
						PLpgSQL_exception_block *new = palloc(sizeof(PLpgSQL_exception_block));
						PLpgSQL_variable *var;

						var = plpgsql_build_variable("sqlstate", (yyvsp[(2) - (2)].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlstate_varno = var->dno;

						var = plpgsql_build_variable("sqlerrm", (yyvsp[(2) - (2)].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlerrm_varno = var->dno;

						(yyval.exception_block) = new;
					;}
    break;

  case 132:
#line 1728 "gram.y"
    {
						PLpgSQL_exception_block *new = (yyvsp[(3) - (4)].exception_block);
						new->exc_list = (yyvsp[(4) - (4)].list);

						(yyval.exception_block) = new;
					;}
    break;

  case 133:
#line 1737 "gram.y"
    {
							(yyval.list) = lappend((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].exception));
						;}
    break;

  case 134:
#line 1741 "gram.y"
    {
							(yyval.list) = list_make1((yyvsp[(1) - (1)].exception));
						;}
    break;

  case 135:
#line 1747 "gram.y"
    {
						PLpgSQL_exception *new;

						new = palloc0(sizeof(PLpgSQL_exception));
						new->lineno     = (yyvsp[(2) - (5)].ival);
						new->conditions = (yyvsp[(3) - (5)].condition);
						new->action	    = (yyvsp[(5) - (5)].list);

						(yyval.exception) = new;
					;}
    break;

  case 136:
#line 1760 "gram.y"
    {
							PLpgSQL_condition	*old;

							for (old = (yyvsp[(1) - (3)].condition); old->next != NULL; old = old->next)
								/* skip */ ;
							old->next = (yyvsp[(3) - (3)].condition);
							(yyval.condition) = (yyvsp[(1) - (3)].condition);
						;}
    break;

  case 137:
#line 1769 "gram.y"
    {
							(yyval.condition) = (yyvsp[(1) - (1)].condition);
						;}
    break;

  case 138:
#line 1775 "gram.y"
    {
							if (strcmp((yyvsp[(1) - (1)].str), "sqlstate") != 0)
							{
								(yyval.condition) = plpgsql_parse_err_condition((yyvsp[(1) - (1)].str));
							}
							else
							{
								PLpgSQL_condition *new;
								char   *sqlstatestr;

								/* next token should be a string literal */
								if (yylex() != T_STRING)
									yyerror("syntax error");
								sqlstatestr = parse_string_token(yytext);

								if (strlen(sqlstatestr) != 5)
									yyerror("invalid SQLSTATE code");
								if (strspn(sqlstatestr, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 5)
									yyerror("invalid SQLSTATE code");

								new = palloc(sizeof(PLpgSQL_condition));
								new->sqlerrstate =
									MAKE_SQLSTATE(sqlstatestr[0],
												  sqlstatestr[1],
												  sqlstatestr[2],
												  sqlstatestr[3],
												  sqlstatestr[4]);
								new->condname = sqlstatestr;
								new->next = NULL;

								(yyval.condition) = new;
							}
						;}
    break;

  case 139:
#line 1811 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(';', ";"); ;}
    break;

  case 140:
#line 1815 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(']', "]"); ;}
    break;

  case 141:
#line 1819 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(K_THEN, "THEN"); ;}
    break;

  case 142:
#line 1823 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(K_LOOP, "LOOP"); ;}
    break;

  case 143:
#line 1827 "gram.y"
    {
						plpgsql_ns_push(NULL);
						(yyval.str) = NULL;
					;}
    break;

  case 144:
#line 1832 "gram.y"
    {
						plpgsql_ns_push((yyvsp[(3) - (5)].str));
						(yyval.str) = (yyvsp[(3) - (5)].str);
					;}
    break;

  case 145:
#line 1839 "gram.y"
    {
						(yyval.str) = NULL;
					;}
    break;

  case 146:
#line 1843 "gram.y"
    {
						(yyval.str) = check_label((yyvsp[(1) - (1)].str));
					;}
    break;

  case 147:
#line 1849 "gram.y"
    { (yyval.expr) = NULL; ;}
    break;

  case 148:
#line 1851 "gram.y"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); ;}
    break;

  case 149:
#line 1858 "gram.y"
    {
						(yyval.str) = yytext;
					;}
    break;

  case 150:
#line 1862 "gram.y"
    {
						(yyval.str) = yytext;
					;}
    break;

  case 151:
#line 1866 "gram.y"
    {
						(yyval.str) = yytext;
					;}
    break;

  case 152:
#line 1870 "gram.y"
    {
						(yyval.str) = yytext;
					;}
    break;

  case 153:
#line 1876 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident((yyvsp[(1) - (1)].str), &name, 1);
						(yyval.str) = name;
					;}
    break;

  case 154:
#line 1885 "gram.y"
    {
						(yyval.ival) = plpgsql_error_lineno = plpgsql_scanner_lineno();
					;}
    break;


/* Line 1267 of yacc.c.  */
#line 3744 "pl_gram.c"
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


#line 1890 "gram.y"



#define MAX_EXPR_PARAMS  1024

/*
 * determine the expression parameter position to use for a plpgsql datum
 *
 * It is important that any given plpgsql datum map to just one parameter.
 * We used to be sloppy and assign a separate parameter for each occurrence
 * of a datum reference, but that fails for situations such as "select DATUM
 * from ... group by DATUM".
 *
 * The params[] array must be of size MAX_EXPR_PARAMS.
 */
static int
assign_expr_param(int dno, int *params, int *nparams)
{
	int		i;

	/* already have an instance of this dno? */
	for (i = 0; i < *nparams; i++)
	{
		if (params[i] == dno)
			return i+1;
	}
	/* check for array overflow */
	if (*nparams >= MAX_EXPR_PARAMS)
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		ereport(ERROR,
				(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
				 errmsg("too many variables specified in SQL statement")));
	}
	/* add new parameter dno to array */
	params[*nparams] = dno;
	(*nparams)++;
	return *nparams;
}


/* Convenience routine to read an expression with one possible terminator */
PLpgSQL_expr *
plpgsql_read_expression(int until, const char *expected)
{
	return read_sql_construct(until, 0, 0, expected,
							  "SELECT ", true, true, NULL);
}

/* Convenience routine to read an expression with two possible terminators */
static PLpgSQL_expr *
read_sql_expression2(int until, int until2, const char *expected,
					 int *endtoken)
{
	return read_sql_construct(until, until2, 0, expected,
							  "SELECT ", true, true, endtoken);
}

/* Convenience routine to read a SQL statement that must end with ';' */
static PLpgSQL_expr *
read_sql_stmt(const char *sqlstart)
{
	return read_sql_construct(';', 0, 0, ";",
							  sqlstart, false, true, NULL);
}

/*
 * Read a SQL construct and build a PLpgSQL_expr for it.
 *
 * until:		token code for expected terminator
 * until2:		token code for alternate terminator (pass 0 if none)
 * until3:		token code for another alternate terminator (pass 0 if none)
 * expected:	text to use in complaining that terminator was not found
 * sqlstart:	text to prefix to the accumulated SQL text
 * isexpression: whether to say we're reading an "expression" or a "statement"
 * valid_sql:   whether to check the syntax of the expr (prefixed with sqlstart)
 * endtoken:	if not NULL, ending token is stored at *endtoken
 *				(this is only interesting if until2 or until3 isn't zero)
 */
static PLpgSQL_expr *
read_sql_construct(int until,
				   int until2,
				   int until3,
				   const char *expected,
				   const char *sqlstart,
				   bool isexpression,
				   bool valid_sql,
				   int *endtoken)
{
	int					tok;
	int					lno;
	PLpgSQL_dstring		ds;
	int					parenlevel = 0;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_expr		*expr;

	lno = plpgsql_scanner_lineno();
	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, sqlstart);

	for (;;)
	{
		tok = yylex();
		if (tok == until && parenlevel == 0)
			break;
		if (tok == until2 && parenlevel == 0)
			break;
		if (tok == until3 && parenlevel == 0)
			break;
		if (tok == '(' || tok == '[')
			parenlevel++;
		else if (tok == ')' || tok == ']')
		{
			parenlevel--;
			if (parenlevel < 0)
				yyerror("mismatched parentheses");
		}
		/*
		 * End of function definition is an error, and we don't expect to
		 * hit a semicolon either (unless it's the until symbol, in which
		 * case we should have fallen out above).
		 */
		if (tok == 0 || tok == ';')
		{
			if (parenlevel != 0)
				yyerror("mismatched parentheses");
			plpgsql_error_lineno = lno;
			if (isexpression)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL expression",
								expected)));
			else
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL statement",
								expected)));
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.row->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.rec->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, yytext);
				break;
		}
	}

	if (endtoken)
		*endtoken = tok;

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	if (valid_sql)
		check_sql_expr(expr->query);

	return expr;
}

static PLpgSQL_type *
read_datatype(int tok)
{
	int					lno;
	PLpgSQL_dstring		ds;
	char			   *type_name;
	PLpgSQL_type		*result;
	bool				needspace = false;
	int					parenlevel = 0;

	lno = plpgsql_scanner_lineno();

	/* Often there will be a lookahead token, but if not, get one */
	if (tok == YYEMPTY)
		tok = yylex();

	if (tok == T_DTYPE)
	{
		/* lexer found word%TYPE and did its thing already */
		return yylval.dtype;
	}

	plpgsql_dstring_init(&ds);

	while (tok != ';')
	{
		if (tok == 0)
		{
			if (parenlevel != 0)
				yyerror("mismatched parentheses");
			else
				yyerror("incomplete data type declaration");
		}
		/* Possible followers for datatype in a declaration */
		if (tok == K_NOT || tok == K_ASSIGN || tok == K_DEFAULT)
			break;
		/* Possible followers for datatype in a cursor_arg list */
		if ((tok == ',' || tok == ')') && parenlevel == 0)
			break;
		if (tok == '(')
			parenlevel++;
		else if (tok == ')')
			parenlevel--;
		if (needspace)
			plpgsql_dstring_append(&ds, " ");
		needspace = true;
		plpgsql_dstring_append(&ds, yytext);

		tok = yylex();
	}

	plpgsql_push_back_token(tok);

	type_name = plpgsql_dstring_get(&ds);

	if (type_name[0] == '\0')
		yyerror("missing data type declaration");

	plpgsql_error_lineno = lno;	/* in case of error in parse_datatype */

	result = plpgsql_parse_datatype(type_name);

	plpgsql_dstring_free(&ds);

	return result;
}

static PLpgSQL_stmt *
make_execsql_stmt(const char *sqlstart, int lineno)
{
	PLpgSQL_dstring		ds;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_stmt_execsql *execsql;
	PLpgSQL_expr		*expr;
	PLpgSQL_row			*row = NULL;
	PLpgSQL_rec			*rec = NULL;
	int					tok;
	int					prev_tok;
	bool				have_into = false;
	bool				have_strict = false;

	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, sqlstart);

	/*
	 * We have to special-case the sequence INSERT INTO, because we don't want
	 * that to be taken as an INTO-variables clause.  Fortunately, this is the
	 * only valid use of INTO in a pl/pgsql SQL command, and INTO is already a
	 * fully reserved word in the main grammar.  We have to treat it that way
	 * anywhere in the string, not only at the start; consider CREATE RULE
	 * containing an INSERT statement.
	 */
	if (pg_strcasecmp(sqlstart, "insert") == 0)
		tok = K_INSERT;
	else
		tok = 0;

	for (;;)
	{
		prev_tok = tok;
		tok = yylex();
		if (tok == ';')
			break;
		if (tok == 0)
			yyerror("unexpected end of function definition");

		if (tok == K_INTO && prev_tok != K_INSERT)
		{
			if (have_into)
				yyerror("INTO specified more than once");
			have_into = true;
			read_into_target(&rec, &row, &have_strict);
			continue;
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.row->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.rec->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, yytext);
				break;
		}
	}

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	check_sql_expr(expr->query);

	execsql = palloc(sizeof(PLpgSQL_stmt_execsql));
	execsql->cmd_type = PLPGSQL_STMT_EXECSQL;
	execsql->lineno  = lineno;
	execsql->sqlstmt = expr;
	execsql->into	 = have_into;
	execsql->strict	 = have_strict;
	execsql->rec	 = rec;
	execsql->row	 = row;

	return (PLpgSQL_stmt *) execsql;
}


static PLpgSQL_stmt_fetch *
read_fetch_direction(void)
{
	PLpgSQL_stmt_fetch *fetch;
	int			tok;
	bool		check_FROM = true;

	/*
	 * We create the PLpgSQL_stmt_fetch struct here, but only fill in
	 * the fields arising from the optional direction clause
	 */
	fetch = (PLpgSQL_stmt_fetch *) palloc0(sizeof(PLpgSQL_stmt_fetch));
	fetch->cmd_type = PLPGSQL_STMT_FETCH;
	/* set direction defaults: */
	fetch->direction = FETCH_FORWARD;
	fetch->how_many  = 1;
	fetch->expr      = NULL;

	/*
	 * Most of the direction keywords are not plpgsql keywords, so we
	 * rely on examining yytext ...
	 */
	tok = yylex();
	if (tok == 0)
		yyerror("unexpected end of function definition");

	if (pg_strcasecmp(yytext, "next") == 0)
	{
		/* use defaults */
	}
	else if (pg_strcasecmp(yytext, "prior") == 0)
	{
		fetch->direction = FETCH_BACKWARD;
	}
	else if (pg_strcasecmp(yytext, "first") == 0)
	{
		fetch->direction = FETCH_ABSOLUTE;
	}
	else if (pg_strcasecmp(yytext, "last") == 0)
	{
		fetch->direction = FETCH_ABSOLUTE;
		fetch->how_many  = -1;
	}
	else if (pg_strcasecmp(yytext, "absolute") == 0)
	{
		fetch->direction = FETCH_ABSOLUTE;
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		check_FROM = false;
	}
	else if (pg_strcasecmp(yytext, "relative") == 0)
	{
		fetch->direction = FETCH_RELATIVE;
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		check_FROM = false;
	}
	else if (pg_strcasecmp(yytext, "forward") == 0)
	{
		/* use defaults */
	}
	else if (pg_strcasecmp(yytext, "backward") == 0)
	{
		fetch->direction = FETCH_BACKWARD;
	}
	else if (tok != T_SCALAR)
	{
		plpgsql_push_back_token(tok);
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		check_FROM = false;
	}
	else
	{
		/* Assume there's no direction clause */
		plpgsql_push_back_token(tok);
		check_FROM = false;
	}

	/* check FROM or IN keyword after direction's specification */
	if (check_FROM)
	{
		tok = yylex();
		if (tok != K_FROM && tok != K_IN)
			yyerror("expected FROM or IN");
	}

	return fetch;
}


static PLpgSQL_stmt *
make_return_stmt(int lineno)
{
	PLpgSQL_stmt_return *new;

	new = palloc0(sizeof(PLpgSQL_stmt_return));
	new->cmd_type = PLPGSQL_STMT_RETURN;
	new->lineno   = lineno;
	new->expr	  = NULL;
	new->retvarno = -1;

	if (plpgsql_curr_compile->fn_retset)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function "
					"returning set; use RETURN NEXT or RETURN QUERY");
	}
	else if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function with OUT parameters");
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else if (plpgsql_curr_compile->fn_rettype == VOIDOID)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function returning void");
	}
	else if (plpgsql_curr_compile->fn_retistuple)
	{
		switch (yylex())
		{
			case K_NULL:
				/* we allow this to support RETURN NULL in triggers */
				break;

			case T_ROW:
				new->retvarno = yylval.row->dno;
				break;

			case T_RECORD:
				new->retvarno = yylval.rec->dno;
				break;

			default:
				yyerror("RETURN must specify a record or row variable in function returning row");
				break;
		}
		if (yylex() != ';')
			yyerror("RETURN must specify a record or row variable in function returning row");
	}
	else
	{
		/*
		 * Note that a well-formed expression is
		 * _required_ here; anything else is a
		 * compile-time error.
		 */
		new->expr = plpgsql_read_expression(';', ";");
	}

	return (PLpgSQL_stmt *) new;
}


static PLpgSQL_stmt *
make_return_next_stmt(int lineno)
{
	PLpgSQL_stmt_return_next *new;

	if (!plpgsql_curr_compile->fn_retset)
		yyerror("cannot use RETURN NEXT in a non-SETOF function");

	new = palloc0(sizeof(PLpgSQL_stmt_return_next));
	new->cmd_type	= PLPGSQL_STMT_RETURN_NEXT;
	new->lineno		= lineno;
	new->expr		= NULL;
	new->retvarno	= -1;

	if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			yyerror("RETURN NEXT cannot have a parameter in function with OUT parameters");
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else if (plpgsql_curr_compile->fn_retistuple)
	{
		switch (yylex())
		{
			case T_ROW:
				new->retvarno = yylval.row->dno;
				break;

			case T_RECORD:
				new->retvarno = yylval.rec->dno;
				break;

			default:
				yyerror("RETURN NEXT must specify a record or row variable in function returning row");
				break;
		}
		if (yylex() != ';')
			yyerror("RETURN NEXT must specify a record or row variable in function returning row");
	}
	else
		new->expr = plpgsql_read_expression(';', ";");

	return (PLpgSQL_stmt *) new;
}


static PLpgSQL_stmt *
make_return_query_stmt(int lineno)
{
	PLpgSQL_stmt_return_query *new;
	int			tok;

	if (!plpgsql_curr_compile->fn_retset)
		yyerror("cannot use RETURN QUERY in a non-SETOF function");

	new = palloc0(sizeof(PLpgSQL_stmt_return_query));
	new->cmd_type = PLPGSQL_STMT_RETURN_QUERY;
	new->lineno = lineno;

	/* check for RETURN QUERY EXECUTE */
	if ((tok = yylex()) != K_EXECUTE)
	{
		/* ordinary static query */
		plpgsql_push_back_token(tok);
		new->query = read_sql_stmt("");
	}
	else
	{
		/* dynamic SQL */
		int		term;

		new->dynquery = read_sql_expression2(';', K_USING, "; or USING",
											 &term);
		if (term == K_USING)
		{
			do
			{
				PLpgSQL_expr *expr;

				expr = read_sql_expression2(',', ';', ", or ;", &term);
				new->params = lappend(new->params, expr);
			} while (term == ',');
		}
	}

	return (PLpgSQL_stmt *) new;
}


static void
check_assignable(PLpgSQL_datum *datum)
{
	switch (datum->dtype)
	{
		case PLPGSQL_DTYPE_VAR:
			if (((PLpgSQL_var *) datum)->isconst)
			{
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_ERROR_IN_ASSIGNMENT),
						 errmsg("\"%s\" is declared CONSTANT",
								((PLpgSQL_var *) datum)->refname)));
			}
			break;
		case PLPGSQL_DTYPE_ROW:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_REC:
			/* always assignable?  What about NEW/OLD? */
			break;
		case PLPGSQL_DTYPE_RECFIELD:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_ARRAYELEM:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_TRIGARG:
			yyerror("cannot assign to tg_argv");
			break;
		default:
			elog(ERROR, "unrecognized dtype: %d", datum->dtype);
			break;
	}
}

/*
 * Read the argument of an INTO clause.  On entry, we have just read the
 * INTO keyword.
 */
static void
read_into_target(PLpgSQL_rec **rec, PLpgSQL_row **row, bool *strict)
{
	int			tok;

	/* Set default results */
	*rec = NULL;
	*row = NULL;
	if (strict)
		*strict = false;

	tok = yylex();
	if (strict && tok == K_STRICT)
	{
		*strict = true;
		tok = yylex();
	}

	switch (tok)
	{
		case T_ROW:
			*row = yylval.row;
			check_assignable((PLpgSQL_datum *) *row);
			break;

		case T_RECORD:
			*rec = yylval.rec;
			check_assignable((PLpgSQL_datum *) *rec);
			break;

		case T_SCALAR:
			*row = read_into_scalar_list(yytext, yylval.scalar);
			break;

		default:
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("syntax error at \"%s\"", yytext),
					 errdetail("Expected record variable, row variable, "
							   "or list of scalar variables following INTO.")));
	}
}

/*
 * Given the first datum and name in the INTO list, continue to read
 * comma-separated scalar variables until we run out. Then construct
 * and return a fake "row" variable that represents the list of
 * scalars.
 */
static PLpgSQL_row *
read_into_scalar_list(const char *initial_name,
					  PLpgSQL_datum *initial_datum)
{
	int				 nfields;
	char			*fieldnames[1024];
	int				 varnos[1024];
	PLpgSQL_row		*row;
	int				 tok;

	check_assignable(initial_datum);
	fieldnames[0] = pstrdup(initial_name);
	varnos[0]	  = initial_datum->dno;
	nfields		  = 1;

	while ((tok = yylex()) == ',')
	{
		/* Check for array overflow */
		if (nfields >= 1024)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
					 errmsg("too many INTO variables specified")));
		}

		tok = yylex();
		switch(tok)
		{
			case T_SCALAR:
				check_assignable(yylval.scalar);
				fieldnames[nfields] = pstrdup(yytext);
				varnos[nfields++]	= yylval.scalar->dno;
				break;

			default:
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("\"%s\" is not a scalar variable",
								yytext)));
		}
	}

	/*
	 * We read an extra, non-comma token from yylex(), so push it
	 * back onto the input stream
	 */
	plpgsql_push_back_token(tok);

	row = palloc(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = pstrdup("*internal*");
	row->lineno = plpgsql_scanner_lineno();
	row->rowtupdesc = NULL;
	row->nfields = nfields;
	row->fieldnames = palloc(sizeof(char *) * nfields);
	row->varnos = palloc(sizeof(int) * nfields);
	while (--nfields >= 0)
	{
		row->fieldnames[nfields] = fieldnames[nfields];
		row->varnos[nfields] = varnos[nfields];
	}

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * Convert a single scalar into a "row" list.  This is exactly
 * like read_into_scalar_list except we never consume any input.
 * In fact, since this can be invoked long after the source
 * input was actually read, the lineno has to be passed in.
 */
static PLpgSQL_row *
make_scalar_list1(const char *initial_name,
				  PLpgSQL_datum *initial_datum,
				  int lineno)
{
	PLpgSQL_row		*row;

	check_assignable(initial_datum);

	row = palloc(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = pstrdup("*internal*");
	row->lineno = lineno;
	row->rowtupdesc = NULL;
	row->nfields = 1;
	row->fieldnames = palloc(sizeof(char *));
	row->varnos = palloc(sizeof(int));
	row->fieldnames[0] = pstrdup(initial_name);
	row->varnos[0] = initial_datum->dno;

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * When the PL/PgSQL parser expects to see a SQL statement, it is very
 * liberal in what it accepts; for example, we often assume an
 * unrecognized keyword is the beginning of a SQL statement. This
 * avoids the need to duplicate parts of the SQL grammar in the
 * PL/PgSQL grammar, but it means we can accept wildly malformed
 * input. To try and catch some of the more obviously invalid input,
 * we run the strings we expect to be SQL statements through the main
 * SQL parser.
 *
 * We only invoke the raw parser (not the analyzer); this doesn't do
 * any database access and does not check any semantic rules, it just
 * checks for basic syntactic correctness. We do this here, rather
 * than after parsing has finished, because a malformed SQL statement
 * may cause the PL/PgSQL parser to become confused about statement
 * borders. So it is best to bail out as early as we can.
 */
static void
check_sql_expr(const char *stmt)
{
	ErrorContextCallback  syntax_errcontext;
	ErrorContextCallback *previous_errcontext;
	MemoryContext oldCxt;

	if (!plpgsql_check_syntax)
		return;

	/*
	 * Setup error traceback support for ereport(). The previous
	 * ereport callback is installed by pl_comp.c, but we don't want
	 * that to be invoked (since it will try to transpose the syntax
	 * error to be relative to the CREATE FUNCTION), so temporarily
	 * remove it from the list of callbacks.
	 */
	Assert(error_context_stack->callback == plpgsql_compile_error_callback);

	previous_errcontext = error_context_stack;
	syntax_errcontext.callback = plpgsql_sql_error_callback;
	syntax_errcontext.arg = (char *) stmt;
	syntax_errcontext.previous = error_context_stack->previous;
	error_context_stack = &syntax_errcontext;

	oldCxt = MemoryContextSwitchTo(compile_tmp_cxt);
	(void) raw_parser(stmt);
	MemoryContextSwitchTo(oldCxt);

	/* Restore former ereport callback */
	error_context_stack = previous_errcontext;
}

static void
plpgsql_sql_error_callback(void *arg)
{
	char *sql_stmt = (char *) arg;

	Assert(plpgsql_error_funcname);

	errcontext("SQL statement in PL/PgSQL function \"%s\" near line %d",
			   plpgsql_error_funcname, plpgsql_error_lineno);
	internalerrquery(sql_stmt);
	internalerrposition(geterrposition());
	errposition(0);
}

/*
 * Convert a string-literal token to the represented string value.
 *
 * To do this, we need to invoke the core lexer.  Here we are only concerned
 * with setting up the right errcontext state, which is handled the same as
 * in check_sql_expr().
 */
static char *
parse_string_token(const char *token)
{
	char	   *result;
	ErrorContextCallback  syntax_errcontext;
	ErrorContextCallback *previous_errcontext;

	/* See comments in check_sql_expr() */
	Assert(error_context_stack->callback == plpgsql_compile_error_callback);

	previous_errcontext = error_context_stack;
	syntax_errcontext.callback = plpgsql_string_error_callback;
	syntax_errcontext.arg = (char *) token;
	syntax_errcontext.previous = error_context_stack->previous;
	error_context_stack = &syntax_errcontext;

	result = pg_parse_string_token(token);

	/* Restore former ereport callback */
	error_context_stack = previous_errcontext;

	return result;
}

static void
plpgsql_string_error_callback(void *arg)
{
	Assert(plpgsql_error_funcname);

	errcontext("string literal in PL/PgSQL function \"%s\" near line %d",
			   plpgsql_error_funcname, plpgsql_error_lineno);
	/* representing the string literal as internalquery seems overkill */
	errposition(0);
}

static char *
check_label(const char *yytxt)
{
	char	   *label_name;

	plpgsql_convert_ident(yytxt, &label_name, 1);
	if (plpgsql_ns_lookup_label(label_name) == NULL)
		yyerror("label does not exist");
	return label_name;
}

static void
check_labels(const char *start_label, const char *end_label)
{
	if (end_label)
	{
		if (!start_label)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" specified for unlabelled block",
							end_label)));
		}

		if (strcmp(start_label, end_label) != 0)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" differs from block's label \"%s\"",
							end_label, start_label)));
		}
	}
}

/*
 * Read the arguments (if any) for a cursor, followed by the until token
 *
 * If cursor has no args, just swallow the until token and return NULL.
 * If it does have args, we expect to see "( expr [, expr ...] )" followed
 * by the until token.  Consume all that and return a SELECT query that
 * evaluates the expression(s) (without the outer parens).
 */
static PLpgSQL_expr *
read_cursor_args(PLpgSQL_var *cursor, int until, const char *expected)
{
	PLpgSQL_expr *expr;
	int			tok;
	char	   *cp;

	tok = yylex();
	if (cursor->cursor_explicit_argrow < 0)
	{
		/* No arguments expected */
		if (tok == '(')
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("cursor \"%s\" has no arguments",
							cursor->refname)));
		}

		if (tok != until)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("syntax error at \"%s\"",
							yytext)));
		}

		return NULL;
	}

	/* Else better provide arguments */
	if (tok != '(')
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		ereport(ERROR,
				(errcode(ERRCODE_SYNTAX_ERROR),
				 errmsg("cursor \"%s\" has arguments",
						cursor->refname)));
	}

	/*
	 * Push back the '(', else plpgsql_read_expression
	 * will complain about unbalanced parens.
	 */
	plpgsql_push_back_token(tok);

	expr = plpgsql_read_expression(until, expected);

	/*
	 * Now remove the leading and trailing parens,
	 * because we want "SELECT 1, 2", not "SELECT (1, 2)".
	 */
	cp = expr->query;

	if (strncmp(cp, "SELECT", 6) != 0)
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		/* internal error */
		elog(ERROR, "expected \"SELECT (\", got \"%s\"", expr->query);
	}
	cp += 6;
	while (*cp == ' ')			/* could be more than 1 space here */
		cp++;
	if (*cp != '(')
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		/* internal error */
		elog(ERROR, "expected \"SELECT (\", got \"%s\"", expr->query);
	}
	*cp = ' ';

	cp += strlen(cp) - 1;

	if (*cp != ')')
		yyerror("expected \")\"");
	*cp = '\0';

	return expr;
}

/*
 * Parse RAISE ... USING options
 */
static List *
read_raise_options(void)
{
	List	   *result = NIL;

	for (;;)
	{
		PLpgSQL_raise_option *opt;
		int		tok;

		if ((tok = yylex()) == 0)
			yyerror("unexpected end of function definition");

		opt = (PLpgSQL_raise_option *) palloc(sizeof(PLpgSQL_raise_option));

		if (pg_strcasecmp(yytext, "errcode") == 0)
			opt->opt_type = PLPGSQL_RAISEOPTION_ERRCODE;
		else if (pg_strcasecmp(yytext, "message") == 0)
			opt->opt_type = PLPGSQL_RAISEOPTION_MESSAGE;
		else if (pg_strcasecmp(yytext, "detail") == 0)
			opt->opt_type = PLPGSQL_RAISEOPTION_DETAIL;
		else if (pg_strcasecmp(yytext, "hint") == 0)
			opt->opt_type = PLPGSQL_RAISEOPTION_HINT;
		else
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("unrecognized RAISE statement option \"%s\"",
							yytext)));
		}

		if (yylex() != K_ASSIGN)
			yyerror("syntax error, expected \"=\"");

		opt->expr = read_sql_expression2(',', ';', ", or ;", &tok);

		result = lappend(result, opt);

		if (tok == ';')
			break;
	}

	return result;
}

/*
 * Fix up CASE statement
 */
static PLpgSQL_stmt *
make_case(int lineno, PLpgSQL_expr *t_expr,
		  List *case_when_list, List *else_stmts)
{
	PLpgSQL_stmt_case 	*new;

	new = palloc(sizeof(PLpgSQL_stmt_case));
	new->cmd_type = PLPGSQL_STMT_CASE;
	new->lineno = lineno;
	new->t_expr = t_expr;
	new->t_varno = 0;
	new->case_when_list = case_when_list;
	new->have_else = (else_stmts != NIL);
	/* Get rid of list-with-NULL hack */
	if (list_length(else_stmts) == 1 && linitial(else_stmts) == NULL)
		new->else_stmts = NIL;
	else
		new->else_stmts = else_stmts;

	/*
	 * When test expression is present, we create a var for it and then
	 * convert all the WHEN expressions to "VAR IN (original_expression)".
	 * This is a bit klugy, but okay since we haven't yet done more than
	 * read the expressions as text.  (Note that previous parsing won't
	 * have complained if the WHEN ... THEN expression contained multiple
	 * comma-separated values.)
	 */
	if (t_expr)
	{
		ListCell *l;
		PLpgSQL_var *t_var;
		int		t_varno;

		/*
		 * We don't yet know the result datatype of t_expr.  Build the
		 * variable as if it were INT4; we'll fix this at runtime if needed.
		 */
		t_var = (PLpgSQL_var *)
			plpgsql_build_variable("*case*", lineno,
								   plpgsql_build_datatype(INT4OID, -1),
								   false);
		t_varno = t_var->dno;
		new->t_varno = t_varno;

		foreach(l, case_when_list)
		{
			PLpgSQL_case_when *cwt = (PLpgSQL_case_when *) lfirst(l);
			PLpgSQL_expr *expr = cwt->expr;
			int		nparams = expr->nparams;
			PLpgSQL_expr *new_expr;
			PLpgSQL_dstring ds;
			char	buff[32];

			/* Must add the CASE variable as an extra param to expression */
			if (nparams >= MAX_EXPR_PARAMS)
			{
				plpgsql_error_lineno = cwt->lineno;
				ereport(ERROR,
					    (errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
					     errmsg("too many variables specified in SQL statement")));
			}

			new_expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * (nparams + 1) - sizeof(int));
			memcpy(new_expr, expr,
				   sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
			new_expr->nparams = nparams + 1;
			new_expr->params[nparams] = t_varno;

			/* And do the string hacking */
			plpgsql_dstring_init(&ds);

			plpgsql_dstring_append(&ds, "SELECT $");
			snprintf(buff, sizeof(buff), "%d", nparams + 1);
			plpgsql_dstring_append(&ds, buff);
			plpgsql_dstring_append(&ds, " IN (");

			/* copy expression query without SELECT keyword */
			Assert(strncmp(expr->query, "SELECT ", 7) == 0);
			plpgsql_dstring_append(&ds, expr->query + 7);
			plpgsql_dstring_append_char(&ds, ')');

			new_expr->query = pstrdup(plpgsql_dstring_get(&ds));

			plpgsql_dstring_free(&ds);
			pfree(expr->query);
			pfree(expr);

			cwt->expr = new_expr;
		}
	}

	return (PLpgSQL_stmt *) new;
}


/* Needed to avoid conflict between different prefix settings: */
#undef yylex

#include "pl_scan.c"

