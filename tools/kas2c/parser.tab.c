/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"


#ifdef _MACOSX
    #include <malloc/malloc.h>
#else
    #include <malloc.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined _MSC_VER
#include <strings.h>
#endif

#if defined (_WIN32) || defined (_WIN64) || defined(WIN32)
#	include <io.h>
#else
#	include <unistd.h>
#endif
	
#include "../../src/Game/Types.h"
#include "kas2c.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

// KAS defines its own values for TRUE/FALSE so we undef previous
// declarations here in order to prevent compiler warnings
#undef TRUE
#undef FALSE

int parseLevel = LEVEL_LEVEL;

int ifOnceIndex;  // up to 2^32 IFONCE statements per WATCH or INIT routine

extern FILE *yyout;
extern char *yytext;

extern int yylex (void);
extern int yyerror ( char* s );

extern int lineNum;
extern char curFilename[];


/* Line 371 of yacc.c  */
#line 117 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QSTRING = 258,
     ID = 259,
     COMMENT2 = 260,
     FSM = 261,
     ENDF = 262,
     STATES = 263,
     WATCH = 264,
     ENDW = 265,
     STATE = 266,
     ENDS = 267,
     INITIALIZE = 268,
     ENDI = 269,
     IF = 270,
     ELSEIF = 271,
     ELSE = 272,
     ENDIF = 273,
     IFONCE = 274,
     ENDIFONCE = 275,
     NUMBER = 276,
     AND = 277,
     OR = 278,
     NOT = 279,
     TEAM = 280,
     SHIPS = 281,
     TEAMSHIPS = 282,
     SHIPSPOINT = 283,
     TEAMSPOINT = 284,
     VOLUMEPOINT = 285,
     PATH = 286,
     POINT = 287,
     VOLUME = 288,
     THISTEAM = 289,
     THISTEAMSHIPS = 290,
     THISTEAMSPOINT = 291,
     JUMP = 292,
     KW_TRUE = 293,
     KW_FALSE = 294,
     LT = 295,
     LTE = 296,
     EQ = 297,
     NEQ = 298,
     GTE = 299,
     GT = 300,
     FSMCREATE = 301,
     LOCALIZATION = 302,
     ENDL = 303,
     LSTRING = 304,
     BANG = 305,
     UMINUS = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 50 "parser.y"

    char    *string;    /* string buffer */
    int     number;     /* numeric value */


/* Line 387 of yacc.c  */
#line 217 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 245 "parser.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,     2,     2,     2,
      59,    60,    52,    51,    58,    50,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    54,    55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    13,    15,    17,    18,    21,
      24,    28,    30,    33,    34,    37,    44,    47,    49,    52,
      53,    54,    59,    61,    65,    66,    70,    72,    74,    75,
      79,    81,    83,    84,    87,    89,    92,    96,    98,   100,
     102,   103,   112,   117,   118,   119,   123,   124,   125,   126,
     135,   136,   137,   145,   148,   149,   150,   158,   159,   164,
     165,   170,   171,   176,   177,   182,   183,   188,   189,   194,
     195,   200,   201,   206,   207,   212,   213,   218,   219,   224,
     225,   230,   231,   235,   236,   240,   241,   245,   246,   251,
     253,   254,   260,   262,   264,   265,   267,   268,   273,   275,
     277,   281,   283,   287,   291,   295,   299,   303,   307,   311,
     315,   317,   319,   323,   325,   326,   329,   334,   337,   339
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    71,    78,    81,    -1,    -1,    65,
      67,    66,    -1,    47,    -1,    48,    -1,    -1,    67,    68,
      -1,    69,    70,    -1,    49,    56,     4,    -1,     3,    -1,
      70,     3,    -1,    -1,    71,    72,    -1,    73,    75,    78,
      81,   123,    74,    -1,     6,     4,    -1,     7,    -1,     7,
       4,    -1,    -1,    -1,     8,    76,    77,    57,    -1,     4,
      -1,    77,    58,     4,    -1,    -1,    79,    84,    80,    -1,
      13,    -1,    14,    -1,    -1,    82,    84,    83,    -1,     9,
      -1,    10,    -1,    -1,    84,    85,    -1,    57,    -1,   101,
      57,    -1,    37,     4,    57,    -1,    88,    -1,    97,    -1,
      86,    -1,    -1,    46,    59,     4,    87,    58,   122,    60,
      57,    -1,    94,    91,    89,    18,    -1,    -1,    -1,    17,
      90,    84,    -1,    -1,    -1,    -1,    91,    16,    59,    92,
     101,    60,    93,    84,    -1,    -1,    -1,    15,    59,    95,
     101,    60,    96,    84,    -1,    98,    20,    -1,    -1,    -1,
      19,    59,    99,   101,    60,   100,    84,    -1,    -1,   101,
      51,   102,   101,    -1,    -1,   101,    50,   103,   101,    -1,
      -1,   101,    52,   104,   101,    -1,    -1,   101,    53,   105,
     101,    -1,    -1,   101,    22,   106,   101,    -1,    -1,   101,
      23,   107,   101,    -1,    -1,   101,    42,   108,   101,    -1,
      -1,   101,    43,   109,   101,    -1,    -1,   101,    45,   110,
     101,    -1,    -1,   101,    44,   111,   101,    -1,    -1,   101,
      40,   112,   101,    -1,    -1,   101,    41,   113,   101,    -1,
      -1,    50,   114,   101,    -1,    -1,    61,   115,   101,    -1,
      -1,    24,   116,   101,    -1,    -1,    59,   117,   101,    60,
      -1,    21,    -1,    -1,     4,   118,    59,   119,    60,    -1,
      38,    -1,    39,    -1,    -1,   121,    -1,    -1,   119,    58,
     120,   121,    -1,   101,    -1,     3,    -1,    49,    56,     4,
      -1,   122,    -1,    26,    56,     4,    -1,    31,    56,     4,
      -1,    32,    56,     4,    -1,    33,    56,     4,    -1,    27,
      56,     4,    -1,    28,    56,     4,    -1,    29,    56,     4,
      -1,    30,    56,     4,    -1,    35,    -1,    36,    -1,    25,
      56,     4,    -1,    34,    -1,    -1,   123,   124,    -1,   125,
      78,    81,   126,    -1,    11,     4,    -1,    12,    -1,    12,
       4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    73,    74,    77,    80,    83,    84,    91,
      94,    97,    98,   101,   102,   105,   108,   111,   112,   115,
     116,   116,   119,   120,   123,   124,   127,   130,   133,   134,
     137,   140,   148,   149,   152,   153,   154,   155,   156,   158,
     162,   162,   169,   172,   173,   173,   176,   177,   177,   177,
     180,   180,   180,   183,   186,   186,   186,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   197,   197,   198,   198,   199,   199,   200,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   205,   205,   206,
     207,   207,   208,   209,   212,   213,   214,   214,   217,   218,
     220,   222,   227,   229,   231,   233,   235,   237,   239,   241,
     243,   245,   249,   251,   255,   256,   259,   262,   265,   266
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QSTRING", "ID", "COMMENT2", "FSM",
  "ENDF", "STATES", "WATCH", "ENDW", "STATE", "ENDS", "INITIALIZE", "ENDI",
  "IF", "ELSEIF", "ELSE", "ENDIF", "IFONCE", "ENDIFONCE", "NUMBER", "AND",
  "OR", "NOT", "TEAM", "SHIPS", "TEAMSHIPS", "SHIPSPOINT", "TEAMSPOINT",
  "VOLUMEPOINT", "PATH", "POINT", "VOLUME", "THISTEAM", "THISTEAMSHIPS",
  "THISTEAMSPOINT", "JUMP", "KW_TRUE", "KW_FALSE", "LT", "LTE", "EQ",
  "NEQ", "GTE", "GT", "FSMCREATE", "LOCALIZATION", "ENDL", "LSTRING",
  "'-'", "'+'", "'*'", "'/'", "BANG", "UMINUS", "'_'", "';'", "','", "'('",
  "')'", "'!'", "$accept", "level", "localization", "localization_start",
  "localization_end", "lstring_defs", "lstring_def", "lstring_def_name",
  "lstring_value_list", "fsms", "fsm", "fsm_start", "fsm_end",
  "state_list", "$@1", "state_id_list", "initialize_block",
  "initialize_start", "initialize_end", "watch_block", "watch_start",
  "watch_end", "statements", "statement", "fsmcreate", "$@2",
  "ifstatement", "else", "$@3", "elseif", "$@4", "$@5", "ifcondition",
  "$@6", "$@7", "ifoncestatement", "ifoncecondition", "$@8", "$@9",
  "expression", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25",
  "$@26", "param_list", "$@27", "param", "paramteam", "states", "state",
  "state_start", "state_end", YY_NULL
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
      45,    43,    42,    47,   305,   306,    95,    59,    44,    40,
      41,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    66,    67,    67,    68,
      69,    70,    70,    71,    71,    72,    73,    74,    74,    75,
      76,    75,    77,    77,    78,    78,    79,    80,    81,    81,
      82,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      87,    86,    88,    89,    90,    89,    91,    92,    93,    91,
      95,    96,    94,    97,    99,   100,    98,   102,   101,   103,
     101,   104,   101,   105,   101,   106,   101,   107,   101,   108,
     101,   109,   101,   110,   101,   111,   101,   112,   101,   113,
     101,   114,   101,   115,   101,   116,   101,   117,   101,   101,
     118,   101,   101,   101,   119,   119,   120,   119,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   124,   125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     3,     1,     1,     0,     2,     2,
       3,     1,     2,     0,     2,     6,     2,     1,     2,     0,
       0,     4,     1,     3,     0,     3,     1,     1,     0,     3,
       1,     1,     0,     2,     1,     2,     3,     1,     1,     1,
       0,     8,     4,     0,     0,     3,     0,     0,     0,     8,
       0,     0,     7,     2,     0,     0,     7,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     3,     0,     4,     1,
       0,     5,     1,     1,     0,     1,     0,     4,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     1,     0,     2,     4,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     5,     0,    13,     7,     1,    24,     0,     0,    26,
      14,    19,    28,    32,     6,     0,     4,     8,     0,    16,
      20,    24,    30,     2,    32,     0,     0,    11,     9,     0,
      28,     0,    90,    27,     0,     0,    89,    85,     0,    92,
      93,     0,    81,    34,    87,    83,    25,    33,    39,    37,
      46,    38,     0,     0,    10,    12,    22,     0,   114,    31,
      29,     0,    50,    54,     0,     0,     0,     0,     0,     0,
      43,    53,    65,    67,    77,    79,    69,    71,    75,    73,
      59,    57,    61,    63,    35,    21,     0,     0,    94,     0,
       0,    86,    36,    40,    82,     0,    84,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    17,     0,    15,   115,    24,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   110,
     111,     0,    98,     0,    95,   101,     0,     0,     0,    88,
      47,    32,    42,    66,    68,    78,    80,    70,    72,    76,
      74,    60,    58,    62,    64,    18,   117,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    91,
      51,    55,     0,     0,    45,     0,   112,   102,   106,   107,
     108,   109,   103,   104,   105,   100,     0,    32,    32,     0,
       0,   118,   116,    97,    52,    56,     0,    48,   119,    41,
      32,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    16,     7,    17,    18,    28,     6,
      10,    11,   115,    21,    29,    57,    12,    13,    46,    23,
      24,    60,    25,    47,    48,   138,    49,    99,   141,    70,
     173,   200,    50,    89,   187,    51,    52,    90,   188,    53,
     109,   108,   110,   111,   100,   101,   104,   105,   107,   106,
     102,   103,    67,    69,    64,    68,    61,   133,   186,   134,
     135,    87,   116,   117,   192
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
     -43,   -63,    24,   -63,   -63,   -63,     9,     3,    62,   -63,
     -63,    67,    61,   -63,   -63,    20,   -63,   -63,    74,   -63,
     -63,    71,   -63,   -63,   -63,    68,    76,   -63,    78,    81,
      61,   111,   -63,   -63,    27,    32,   -63,   -63,    89,   -63,
     -63,    35,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,    75,   259,   -63,   -63,   -63,   -41,   -63,   -63,
     -63,    37,   -63,   -63,   116,    40,    94,   116,   116,   116,
      14,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,    96,    18,    29,   116,
     116,   -63,   -63,   -63,   -63,   163,   -63,    42,   -63,    84,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   -63,    99,   100,   -63,   -63,    71,   -63,    52,
      53,    54,    56,    57,    60,    63,    66,    77,   -63,   -63,
     -63,    80,   283,    11,   -63,   -63,   187,   211,    65,   -63,
     -63,   -63,   -63,   -32,   -32,   -16,   -16,   -16,   -16,   -16,
     -16,    21,    21,   -63,   -63,   -63,   -63,    61,   127,   130,
     134,   135,   137,   138,   139,   140,   142,   143,   -63,   -63,
     -63,   -63,   -11,   116,   141,   146,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,    29,   -63,   -63,    91,
     235,   148,   -63,   -63,   141,   141,   102,   -63,   -63,   -63,
     -63,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -18,   -63,   -63,   -29,
     -63,   -63,   -24,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -62,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -33,
      -5,   -63,   -63,   -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    58,    91,    30,     1,    94,    95,    96,    74,    75,
      76,    77,    78,    79,   119,     8,    85,    86,    80,    81,
      82,    83,     9,   128,     5,   113,   132,   136,   137,   114,
      97,    98,   118,    32,    80,    81,    82,    83,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      36,    14,    15,    37,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    19,    39,    40,   168,
      22,   169,    32,    82,    83,    20,    26,    27,   131,    42,
      54,    55,    33,    34,     9,    56,    62,    35,    44,    36,
      45,    63,    37,    65,    66,    71,    88,    92,    93,   157,
     112,   140,   142,   155,   156,    38,    39,    40,   158,   159,
     160,   190,   161,   162,    41,    32,   163,   174,    42,   164,
      32,    59,   165,   172,   132,    43,    34,    44,   175,    45,
      35,   176,    36,   166,   177,    37,   167,    36,   178,   179,
      37,   180,   181,   182,   183,    32,   184,   185,    38,    39,
      40,   196,   198,   193,    39,    40,    34,    41,   191,   199,
      35,    42,    36,   194,   195,    37,    42,   189,    43,     0,
      44,     0,    45,     0,     0,    44,   201,    45,    38,    39,
      40,     0,     0,     0,     0,    72,    73,    41,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,    43,     0,
      44,     0,    45,    74,    75,    76,    77,    78,    79,    72,
      73,     0,     0,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    72,    73,     0,     0,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    72,    73,     0,
       0,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,   171,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    72,    73,     0,     0,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    72,    73,     0,     0,    80,
      81,    82,    83,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,    80,    81,    82,    83
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      24,    30,    64,    21,    47,    67,    68,    69,    40,    41,
      42,    43,    44,    45,    25,     6,    57,    58,    50,    51,
      52,    53,    13,    34,     0,     7,    88,    89,    90,    11,
      16,    17,     3,     4,    50,    51,    52,    53,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      21,    48,    49,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     4,    38,    39,    58,
       9,    60,     4,    52,    53,     8,    56,     3,    49,    50,
       4,     3,    14,    15,    13,     4,    59,    19,    59,    21,
      61,    59,    24,     4,    59,    20,    59,    57,     4,   117,
       4,    59,    18,     4,     4,    37,    38,    39,    56,    56,
      56,   173,    56,    56,    46,     4,    56,   141,    50,    56,
       4,    10,    56,    58,   186,    57,    15,    59,   157,    61,
      19,     4,    21,    56,     4,    24,    56,    21,     4,     4,
      24,     4,     4,     4,     4,     4,     4,     4,    37,    38,
      39,    60,     4,   186,    38,    39,    15,    46,    12,    57,
      19,    50,    21,   187,   188,    24,    50,   172,    57,    -1,
      59,    -1,    61,    -1,    -1,    59,   200,    61,    37,    38,
      39,    -1,    -1,    -1,    -1,    22,    23,    46,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    61,    40,    41,    42,    43,    44,    45,    22,
      23,    -1,    -1,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    22,    23,    -1,    -1,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    22,    23,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    22,    23,    -1,    -1,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    22,    23,    -1,    -1,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    63,    64,    65,     0,    71,    67,     6,    13,
      72,    73,    78,    79,    48,    49,    66,    68,    69,     4,
       8,    75,     9,    81,    82,    84,    56,     3,    70,    76,
      78,    84,     4,    14,    15,    19,    21,    24,    37,    38,
      39,    46,    50,    57,    59,    61,    80,    85,    86,    88,
      94,    97,    98,   101,     4,     3,     4,    77,    81,    10,
      83,   118,    59,    59,   116,     4,    59,   114,   117,   115,
      91,    20,    22,    23,    40,    41,    42,    43,    44,    45,
      50,    51,    52,    53,    57,    57,    58,   123,    59,    95,
      99,   101,    57,     4,   101,   101,   101,    16,    17,    89,
     106,   107,   112,   113,   108,   109,   111,   110,   103,   102,
     104,   105,     4,     7,    11,    74,   124,   125,     3,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    49,   101,   119,   121,   122,   101,   101,    87,    60,
      59,    90,    18,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,     4,     4,    78,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    58,    60,
      60,    60,    58,    92,    84,    81,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   120,    96,   100,   122,
     101,    12,   126,   121,    84,    84,    60,    60,     4,    57,
      93,    84
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 5:
/* Line 1792 of yacc.c  */
#line 77 "parser.y"
    { kasLocalizationStart(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    { kasLocalizationEnd(); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { kasLStringDefineEnd(); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    { kasLStringDefineStart((yyvsp[(3) - (3)].string)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    { kasLStringValue((yyvsp[(1) - (1)].string)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 98 "parser.y"
    { kasLStringValue((yyvsp[(2) - (2)].string)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    { kasFSMStart((yyvsp[(2) - (2)].string)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    { kasFSMEnd(""); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { kasFSMEnd((yyvsp[(2) - (2)].string)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 115 "parser.y"
    { kasStateListClear(); kasStateListEnd(); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { kasStateListClear(); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { kasStateListEnd(); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    { kasStateListAdd((yyvsp[(1) - (1)].string)); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    { kasStateListAdd((yyvsp[(3) - (3)].string)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    { kasInitializeStart(); kasInitializeEnd(); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { kasInitializeStart(); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    { kasInitializeEnd(); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    { kasWatchStart(); kasWatchEnd(); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    { kasWatchStart(); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    { kasWatchEnd(); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { fprintf(yyout, ";\n\t"); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    { fprintf(yyout, ";\n\t"); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    { kasJump((yyvsp[(2) - (3)].string)); fprintf(yyout, ";\n\treturn;\n\t"); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    { kasFSMCreateStart((yyvsp[(3) - (3)].string)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    { kasFSMCreateEnd(); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { fprintf(yyout, "else\n\t{\n\t"); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { fprintf(yyout, "}\n\t"); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { fprintf(yyout, "else if ("); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { fprintf(yyout, ")\n\t{\n\t"); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { fprintf(yyout, "}\n\t"); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { fprintf(yyout, "if ("); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { fprintf(yyout, ")\n\t{\n\t"); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { fprintf(yyout, "}\n\t"); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { fprintf(yyout, "if (!kasfVarValueGet(\"_VIFONCE%03d\") && (", ifOnceIndex+1); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { fprintf(yyout, ")) // \"ifonce\" #%d\n\t{\n\tkasfVarCreateSet(\"_VIFONCE%03d\", 1);\n\t", ifOnceIndex+1, ifOnceIndex+1); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { fprintf(yyout, "}\n\t"); ++ifOnceIndex; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { fprintf(yyout, " + "); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    { fprintf(yyout, " - "); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    { fprintf(yyout, " * "); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 193 "parser.y"
    { fprintf(yyout, " / "); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    { fprintf(yyout, " && "); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    { fprintf(yyout, " || "); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    { fprintf(yyout, " == "); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    { fprintf(yyout, " != "); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    { fprintf(yyout, " > "); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    { fprintf(yyout, " >= "); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 200 "parser.y"
    { fprintf(yyout, " < "); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 201 "parser.y"
    { fprintf(yyout, " <= "); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    { fprintf(yyout, "-"); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    { fprintf(yyout, "!"); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    { fprintf(yyout, "!"); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    { fprintf(yyout, "("); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    { fprintf(yyout, ")"); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 206 "parser.y"
    { fprintf(yyout, "%d", (yyvsp[(1) - (1)].number)); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { kasFunctionStart((yyvsp[(1) - (1)].string)); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { kasFunctionEnd(); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    { fprintf(yyout, "1"); }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    { fprintf(yyout, "0"); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 214 "parser.y"
    { fprintf(yyout, ", "); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    { kasFunctionParamNumber(); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    { fprintf(yyout, "\"%s\"", (yyvsp[(1) - (1)].string));
                         kasFunctionParamCharPtr(); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    { kasLStringReference((yyvsp[(3) - (3)].string));
                              kasFunctionParamCharPtr(); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    { fprintf(yyout, "kasGrowSelectionPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                             kasFunctionParamSelectCommandPtr(); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { fprintf(yyout, "kasPathPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                             kasFunctionParamPathPtr(); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    { fprintf(yyout, "kasVectorPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                              kasFunctionParamVectorPtr(); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    { fprintf(yyout, "kasVolumePtr(\"%s\")", (yyvsp[(3) - (3)].string));
                              kasFunctionParamVolumePtr(); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 235 "parser.y"
    { fprintf(yyout, "kasAITeamShipsPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                                  kasFunctionParamSelectCommandPtr(); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 237 "parser.y"
    { fprintf(yyout, "kasShipsVectorPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                                   kasFunctionParamVectorPtr(); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    { fprintf(yyout, "kasTeamsVectorPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                                   kasFunctionParamVectorPtr(); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    { fprintf(yyout, "kasVolumeVectorPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                                   kasFunctionParamVectorPtr(); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 243 "parser.y"
    { fprintf(yyout, "(&kasThisTeamPtr->shipList)");
                        kasFunctionParamSelectCommandPtr(); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 245 "parser.y"
    { fprintf(yyout, "kasThisTeamsVectorPtr()");
                                kasFunctionParamVectorPtr();  }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 249 "parser.y"
    { fprintf(yyout, "kasAITeamPtr(\"%s\")", (yyvsp[(3) - (3)].string));
                             kasFunctionParamAITeamPtr(); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 251 "parser.y"
    { fprintf(yyout, "kasThisTeamPtr");
                        kasFunctionParamAITeamPtr(); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 262 "parser.y"
    { kasStateStart((yyvsp[(2) - (2)].string)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 265 "parser.y"
    { kasStateEnd(""); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 266 "parser.y"
    { kasStateEnd((yyvsp[(2) - (2)].string)); }
    break;


/* Line 1792 of yacc.c  */
#line 2141 "parser.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 269 "parser.y"


int lineNum = 1;
char curFilename[256]; // current input filename
char levelName[MAX_LEVEL_NAME_LENGTH+1]; // current input filename
FILE *yyhout, *yyfout;
unsigned int functionCount;  // number of FSM functions

int yyerror (char *s)
{
    if (!strcasecmp(s, "parse error"))
        fprintf(stderr, "%s(%d) error : at '%s', %s\n", curFilename, lineNum, yytext, stateHelpGet());
    else
        fprintf(stderr, "%s(%d) error : at '%s', %s (%s)\n", curFilename, lineNum, yytext, stateHelpGet(), s);
    return 99;
}

char *levelNameGet(void)
{
    return levelName;
}

int lineNumGet(void)
{
    return lineNum;
}

char *curFilenameGet()
{
    return curFilename;
}

int main(int argc, char **argv)
{
    char infilename[256], outfilename[256], houtfilename[256], foutfilename[256];
    char *shortinfilename, tempfilename[256];
    extern FILE *yyin, *yyout;
    int i;

    if (argc >= 2 && !strcasecmp(argv[1], "-F"))
    {
        kasHeaders(0);
        exit(1);
    }
    else if (argc >= 2 && !strcasecmp(argv[1], "-FC"))
    {
        kasHeaders(1);
        exit(1);
    }
    else if (argc != 4 && argc != 5)
    {
        fprintf(stderr, "\nKAS2C Version %s\n", KAS2C_VERSION);
        fprintf(stderr, "Copyright (C) 1998 Relic Entertainment Inc.  All rights reserved.\n");
        fprintf(stderr, "Modifications for Homeworld SDL by Ted Cipicchio <ted@thereisnospork.com>\n");
        fprintf(stderr, "\n Usage:\n\n");
        fprintf(stderr, " KAS2C mission.kas mission.c mission.h [func.c]\n");
        fprintf(stderr, " - generate mission.c and mission.h (and, optionally, func.c)\n");
        fprintf(stderr, " KAS2C -f\n");
        fprintf(stderr, " - list function headers (english style)\n");
        fprintf(stderr, " KAS2C -fc\n");
        fprintf(stderr, " - list function headers (C-style)\n");
        exit(1);
    }

    strcpy(infilename, argv[1]);

    strcpy(outfilename, argv[2]);

    strcpy(houtfilename, argv[3]);

    strcpy(foutfilename, (argc == 5 ? argv[4] : ""));

    if (!(yyin = fopen(infilename, "r")))
    {
        fprintf(stderr, "%s: can't open\n", infilename);
        exit(1);
    }

    if (!(yyout = fopen(outfilename, "w")))
    {
        fprintf(stderr, "%s: can't open\n", outfilename);
        exit(1);
    }

    if (!(yyhout = fopen(houtfilename, "w")))
    {
        fprintf(stderr, "%s: can't open\n", houtfilename);
        exit(1);
    }

    if (argc == 5 && !(yyfout = fopen(foutfilename, "w")))
    {
        fprintf(stderr, "%s: can't open\n", foutfilename);
        exit(1);
    }

    // hack off leading paths for display of infilename
    shortinfilename = infilename+strlen(infilename);
    while (shortinfilename > infilename)
    {
        --shortinfilename;
        if (*shortinfilename == '\\' || *shortinfilename == '/')
        {
            ++shortinfilename;
            break;
        }
    }
    fprintf(stderr, "%s\n", shortinfilename);

    strcpy(tempfilename, shortinfilename);
    strcpy(infilename, tempfilename);

    strcpy(levelName, shortinfilename);
    i = 0;
    while (i < strlen(levelName) && levelName[i] != '.')
        ++i;
    if (i < strlen(levelName))
        levelName[i] = 0;  // knock off extension

    strcpy(curFilename, infilename);

    fprintf(yyout, "//\n");
    fprintf(yyout, "//  %s\n", outfilename);
    fprintf(yyout, "//\n");
    fprintf(yyout, "//  Finite state machine routines for \"%s\" mission\n", levelName);
    fprintf(yyout, "//\n");
    fprintf(yyout, "//  Copyright (C) 1998 Relic Entertainment Inc.\n");
    fprintf(yyout, "//  All rights reserved\n");
    fprintf(yyout, "//\n");
    fprintf(yyout, "//  This code was autogenerated from %s by KAS2C Version %s\n",
        infilename, KAS2C_VERSION);
    fprintf(yyout, "//\n\n\n");
    fprintf(yyout, "#include \"%s\"  // prototypes and #includes for exposed game functions\n", houtfilename);
    fprintf(yyout, "\n");
    fprintf(yyout, "extern AITeam *CurrentTeamP;\n");
    fprintf(yyout, "#define kasThisTeamPtr CurrentTeamP\n");
    fprintf(yyout, "\n");
    fprintf(yyout, "//  for run-time scoping of symbols (variables, timers, etc.)\n");
    fprintf(yyout, "extern sdword CurrentMissionScope;\n");
    fprintf(yyout, "extern char CurrentMissionScopeName[];\n");
    fprintf(yyout, "\n");

    fprintf(yyout, "//  for displaying localized strings\n");
    fprintf(yyout, "extern udword strCurLanguage;\n");
    fprintf(yyout, "\n");

    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  %s\n", houtfilename);
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  Finite state machine for \"%s\" mission\n", levelName);
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  Copyright (C) 1998 Relic Entertainment Inc.\n");
    fprintf(yyhout, "//  All rights reserved\n");
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  This code was autogenerated from %s by KAS2C Version %s\n",
        infilename, KAS2C_VERSION);
    fprintf(yyhout, "//\n\n\n");
    fprintf(yyhout, "#ifndef __%s_H\n", levelName);
    fprintf(yyhout, "#define __%s_H\n\n\n", levelName);

    // add any other required #includes here
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  types and exposed game functions\n");
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "#include <string.h>\n");
    fprintf(yyhout, "#include \"AIMoves.h\"\n");
    fprintf(yyhout, "#include \"AITeam.h\"\n");
    fprintf(yyhout, "#include \"Attributes.h\"\n");
    fprintf(yyhout, "#include \"CommandWrap.h\"\n");
    fprintf(yyhout, "#include \"KASFunc.h\"\n");
    fprintf(yyhout, "#include \"Objectives.h\"\n");
    fprintf(yyhout, "#include \"Timer.h\"\n");
    fprintf(yyhout, "#include \"TradeMgr.h\"\n");
    fprintf(yyhout, "#include \"Types.h\"\n");
    fprintf(yyhout, "#include \"Vector.h\"\n");
    fprintf(yyhout, "#include \"Volume.h\"\n");

    // declarations of function list information
    if (yyfout)
    {
        fprintf(yyhout, "\n\n");
        fprintf(yyhout, "//\n");
        fprintf(yyhout, "//  level function pointer list\n");
        fprintf(yyhout, "//\n");
        fprintf(yyhout, "extern const void* %s_FunctionPointers[];\n", levelName);
        fprintf(yyhout, "extern const unsigned int %s_FunctionPointerCount;\n", levelName);
    }

    fprintf(yyhout, "\n\n");
    fprintf(yyhout, "//\n");
    fprintf(yyhout, "//  FSM prototypes\n");
    fprintf(yyhout, "//\n");

    if (yyfout)
    {
        fprintf(yyfout, "//\n");
        fprintf(yyfout, "//  %s\n", foutfilename);
        fprintf(yyfout, "//\n");
        fprintf(yyfout, "//  Finite state machine function pointers for \"%s\" mission\n", levelName);
        fprintf(yyfout, "//\n");
        fprintf(yyfout, "//  This code was autogenerated from %s by KAS2C Version %s\n",
            infilename, KAS2C_VERSION);
        fprintf(yyfout, "//\n\n\n");
        fprintf(yyfout, "#include \"%s\"  // prototypes and #includes for exposed game functions\n", houtfilename);
        fprintf(yyfout, "\n");
        fprintf(yyfout, "// FSM init/watch function pointers.\n");
        fprintf(yyfout, "const void* %s_FunctionPointers[] =\n", levelName);
        fprintf(yyfout, "{\n");
    }

    ifOnceIndex = 0;  // reset counter for each source file parsed

    functionCount = 0;  // number of FSM init/watch functions created

    // normal yyin and yyout interaction
    yyparse();

    fprintf(yyhout, "\n\n#endif\n");

    if (yyfout)
    {
        fprintf(yyfout, "};\n");
        fprintf(yyfout, "\n");
        fprintf(yyfout, "// Number of FSM init/watch function pointers.\n");
        fprintf(yyfout, "const unsigned int %s_FunctionPointerCount = %u;\n", levelName, functionCount);
    }

    fclose(yyin);
    fclose(yyout);
    fclose(yyhout);
    if (yyfout)
        fclose(yyfout);

    // to be done: unlink output files on error?
    if (yynerrs)
    {
        unlink(outfilename);
        unlink(houtfilename);
        if (foutfilename[0]);
            unlink(foutfilename);
    }
    return 0;
}
