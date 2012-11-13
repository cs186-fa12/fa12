
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     ABORT_P = 258,
     ABSOLUTE_P = 259,
     ACCESS = 260,
     ACTION = 261,
     ADD_P = 262,
     ADMIN = 263,
     AFTER = 264,
     AGGREGATE = 265,
     ALL = 266,
     ALSO = 267,
     ALTER = 268,
     ALWAYS = 269,
     ANALYSE = 270,
     ANALYZE = 271,
     AND = 272,
     ANY = 273,
     ARRAY = 274,
     AS = 275,
     ASC = 276,
     ASSERTION = 277,
     ASSIGNMENT = 278,
     ASYMMETRIC = 279,
     AT = 280,
     AUTHORIZATION = 281,
     BACKWARD = 282,
     BEFORE = 283,
     BEGIN_P = 284,
     BETWEEN = 285,
     BIGINT = 286,
     BINARY = 287,
     BIT = 288,
     BOOLEAN_P = 289,
     BOTH = 290,
     BY = 291,
     CACHE = 292,
     CALLED = 293,
     CASCADE = 294,
     CASCADED = 295,
     CASE = 296,
     CAST = 297,
     CATALOG_P = 298,
     CHAIN = 299,
     CHAR_P = 300,
     CHARACTER = 301,
     CHARACTERISTICS = 302,
     CHECK = 303,
     CHECKPOINT = 304,
     CLASS = 305,
     CLOSE = 306,
     CLUSTER = 307,
     COALESCE = 308,
     COLLATE = 309,
     COLUMN = 310,
     COMMENT = 311,
     COMMIT = 312,
     COMMITTED = 313,
     CONCURRENTLY = 314,
     CONFIGURATION = 315,
     CONNECTION = 316,
     CONSTRAINT = 317,
     CONSTRAINTS = 318,
     CONTENT_P = 319,
     CONTINUE_P = 320,
     CONVERSION_P = 321,
     COPY = 322,
     COST = 323,
     CREATE = 324,
     CREATEDB = 325,
     CREATEROLE = 326,
     CREATEUSER = 327,
     CROSS = 328,
     CSV = 329,
     CURRENT_P = 330,
     CURRENT_CATALOG = 331,
     CURRENT_DATE = 332,
     CURRENT_ROLE = 333,
     CURRENT_SCHEMA = 334,
     CURRENT_TIME = 335,
     CURRENT_TIMESTAMP = 336,
     CURRENT_USER = 337,
     CURSOR = 338,
     CYCLE = 339,
     DATA_P = 340,
     DATABASE = 341,
     DAY_P = 342,
     DEALLOCATE = 343,
     DEC = 344,
     DECIMAL_P = 345,
     DECLARE = 346,
     DEFAULT = 347,
     DEFAULTS = 348,
     DEFERRABLE = 349,
     DEFERRED = 350,
     DEFINER = 351,
     DELETE_P = 352,
     DELIMITER = 353,
     DELIMITERS = 354,
     DESC = 355,
     DICTIONARY = 356,
     DISABLE_P = 357,
     DISCARD = 358,
     DISTINCT = 359,
     DO = 360,
     DOCUMENT_P = 361,
     DOMAIN_P = 362,
     DOUBLE_P = 363,
     DROP = 364,
     EACH = 365,
     ELSE = 366,
     ENABLE_P = 367,
     ENCODING = 368,
     ENCRYPTED = 369,
     END_P = 370,
     ENUM_P = 371,
     ESCAPE = 372,
     EXCEPT = 373,
     EXCLUDING = 374,
     EXCLUSIVE = 375,
     EXECUTE = 376,
     EXISTS = 377,
     EXPLAIN = 378,
     EXTERNAL = 379,
     EXTRACT = 380,
     FALSE_P = 381,
     FAMILY = 382,
     FETCH = 383,
     FIRST_P = 384,
     FLOAT_P = 385,
     FOLLOWING = 386,
     FOR = 387,
     FORCE = 388,
     FOREIGN = 389,
     FORWARD = 390,
     FREEZE = 391,
     FROM = 392,
     FULL = 393,
     FUNCTION = 394,
     GLOBAL = 395,
     GRANT = 396,
     GRANTED = 397,
     GREATEST = 398,
     GROUP_P = 399,
     HANDLER = 400,
     HAVING = 401,
     HEADER_P = 402,
     HOLD = 403,
     HOUR_P = 404,
     IDENTITY_P = 405,
     IF_P = 406,
     ILIKE = 407,
     IMMEDIATE = 408,
     IMMUTABLE = 409,
     IMPLICIT_P = 410,
     IN_P = 411,
     INCLUDING = 412,
     INCREMENT = 413,
     INDEX = 414,
     INDEXES = 415,
     INHERIT = 416,
     INHERITS = 417,
     INITIALLY = 418,
     INNER_P = 419,
     INOUT = 420,
     INPUT_P = 421,
     INSENSITIVE = 422,
     INSERT = 423,
     INSTEAD = 424,
     INT_P = 425,
     INTEGER = 426,
     INTERSECT = 427,
     INTERVAL = 428,
     INTO = 429,
     INVOKER = 430,
     IS = 431,
     ISNULL = 432,
     ISOLATION = 433,
     JOIN = 434,
     KEY = 435,
     LANCOMPILER = 436,
     LANGUAGE = 437,
     LARGE_P = 438,
     LAST_P = 439,
     LC_COLLATE_P = 440,
     LC_CTYPE_P = 441,
     LEADING = 442,
     LEAST = 443,
     LEFT = 444,
     LEVEL = 445,
     LIKE = 446,
     LIMIT = 447,
     LISTEN = 448,
     LOAD = 449,
     LOCAL = 450,
     LOCALTIME = 451,
     LOCALTIMESTAMP = 452,
     LOCATION = 453,
     LOCK_P = 454,
     LOGIN_P = 455,
     MAPPING = 456,
     MATCH = 457,
     MAXVALUE = 458,
     MINUTE_P = 459,
     MINVALUE = 460,
     MODE = 461,
     MONTH_P = 462,
     MOVE = 463,
     NAME_P = 464,
     NAMES = 465,
     NATIONAL = 466,
     NATURAL = 467,
     NCHAR = 468,
     NEW = 469,
     NEXT = 470,
     NO = 471,
     NOCREATEDB = 472,
     NOCREATEROLE = 473,
     NOCREATEUSER = 474,
     NOINHERIT = 475,
     NOLOGIN_P = 476,
     NONE = 477,
     NOSUPERUSER = 478,
     NOT = 479,
     NOTHING = 480,
     NOTIFY = 481,
     NOTNULL = 482,
     NOWAIT = 483,
     NULL_P = 484,
     NULLIF = 485,
     NULLS_P = 486,
     NUMERIC = 487,
     OBJECT_P = 488,
     OF = 489,
     OFF = 490,
     OFFSET = 491,
     OIDS = 492,
     OLD = 493,
     ON = 494,
     ONLY = 495,
     OPERATOR = 496,
     OPTION = 497,
     OPTIONS = 498,
     OR = 499,
     ORDER = 500,
     OUT_P = 501,
     OUTER_P = 502,
     OVER = 503,
     OVERLAPS = 504,
     OVERLAY = 505,
     OWNED = 506,
     OWNER = 507,
     PARSER = 508,
     PARTIAL = 509,
     PARTITION = 510,
     PASSWORD = 511,
     PLACING = 512,
     PLANS = 513,
     POSITION = 514,
     PRECEDING = 515,
     PRECISION = 516,
     PRESERVE = 517,
     PREPARE = 518,
     PREPARED = 519,
     PRIMARY = 520,
     PRIOR = 521,
     PRIVILEGES = 522,
     PROCEDURAL = 523,
     PROCEDURE = 524,
     QUOTE = 525,
     RANGE = 526,
     READ = 527,
     REAL = 528,
     REASSIGN = 529,
     RECHECK = 530,
     RECURSIVE = 531,
     REFERENCES = 532,
     REINDEX = 533,
     RELATIVE_P = 534,
     RELEASE = 535,
     RENAME = 536,
     REPEATABLE = 537,
     REPLACE = 538,
     REPLICA = 539,
     RESET = 540,
     RESTART = 541,
     RESTRICT = 542,
     RETURNING = 543,
     RETURNS = 544,
     REVOKE = 545,
     RIGHT = 546,
     ROLE = 547,
     ROLLBACK = 548,
     ROW = 549,
     ROWS = 550,
     RULE = 551,
     SAVEPOINT = 552,
     SCHEMA = 553,
     SCROLL = 554,
     SEARCH = 555,
     SECOND_P = 556,
     SECURITY = 557,
     SELECT = 558,
     SEQUENCE = 559,
     SERIALIZABLE = 560,
     SERVER = 561,
     SESSION = 562,
     SESSION_USER = 563,
     SET = 564,
     SETOF = 565,
     SHARE = 566,
     SHOW = 567,
     SIMILAR = 568,
     SIMPLE = 569,
     SMALLINT = 570,
     SOME = 571,
     STABLE = 572,
     STANDALONE_P = 573,
     START = 574,
     STATEMENT = 575,
     STATISTICS = 576,
     STDIN = 577,
     STDOUT = 578,
     STORAGE = 579,
     STRICT_P = 580,
     STRIP_P = 581,
     SUBSTRING = 582,
     SUPERUSER_P = 583,
     SYMMETRIC = 584,
     SYSID = 585,
     SYSTEM_P = 586,
     TABLE = 587,
     TABLESPACE = 588,
     TEMP = 589,
     TEMPLATE = 590,
     TEMPORARY = 591,
     TEXT_P = 592,
     THEN = 593,
     TIME = 594,
     TIMESTAMP = 595,
     TO = 596,
     TRAILING = 597,
     TRANSACTION = 598,
     TREAT = 599,
     TRIGGER = 600,
     TRIM = 601,
     TRUE_P = 602,
     TRUNCATE = 603,
     TRUSTED = 604,
     TYPE_P = 605,
     UNBOUNDED = 606,
     UNCOMMITTED = 607,
     UNENCRYPTED = 608,
     UNION = 609,
     UNIQUE = 610,
     UNKNOWN = 611,
     UNLISTEN = 612,
     UNTIL = 613,
     UPDATE = 614,
     USER = 615,
     USING = 616,
     VACUUM = 617,
     VALID = 618,
     VALIDATOR = 619,
     VALUE_P = 620,
     VALUES = 621,
     VARCHAR = 622,
     VARIADIC = 623,
     VARYING = 624,
     VERBOSE = 625,
     VERSION_P = 626,
     VIEW = 627,
     VOLATILE = 628,
     WHEN = 629,
     WHERE = 630,
     WHITESPACE_P = 631,
     WINDOW = 632,
     WITH = 633,
     WITHOUT = 634,
     WORK = 635,
     WRAPPER = 636,
     WRITE = 637,
     XML_P = 638,
     XMLATTRIBUTES = 639,
     XMLCONCAT = 640,
     XMLELEMENT = 641,
     XMLFOREST = 642,
     XMLPARSE = 643,
     XMLPI = 644,
     XMLROOT = 645,
     XMLSERIALIZE = 646,
     YEAR_P = 647,
     YES_P = 648,
     ZONE = 649,
     NULLS_FIRST = 650,
     NULLS_LAST = 651,
     WITH_TIME = 652,
     IDENT = 653,
     FCONST = 654,
     SCONST = 655,
     BCONST = 656,
     XCONST = 657,
     Op = 658,
     ICONST = 659,
     PARAM = 660,
     POSTFIXOP = 661,
     UMINUS = 662,
     TYPECAST = 663
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 148 "gram.y"

	int					ival;
	char				chr;
	char				*str;
	const char			*keyword;
	bool				boolean;
	JoinType			jtype;
	DropBehavior		dbehavior;
	OnCommitAction		oncommit;
	List				*list;
	Node				*node;
	Value				*value;
	ObjectType			objtype;

	TypeName			*typnam;
	FunctionParameter   *fun_param;
	FunctionParameterMode fun_param_mode;
	FuncWithArgs		*funwithargs;
	DefElem				*defelt;
	SortBy				*sortby;
	WindowDef			*windef;
	JoinExpr			*jexpr;
	IndexElem			*ielem;
	Alias				*alias;
	RangeVar			*range;
	IntoClause			*into;
	WithClause			*with;
	A_Indices			*aind;
	ResTarget			*target;
	struct PrivTarget	*privtarget;
	AccessPriv			*accesspriv;

	InsertStmt			*istmt;
	VariableSetStmt		*vsetstmt;



/* Line 1676 of yacc.c  */
#line 498 "gram.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE base_yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE base_yylloc;

