/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "hoc.y"

	#include "hoc.h"
	#define code2(c1,c2)		code(c1); code(c2);
	#define code3(c1 ,c2,c3)	code(c1); code(c2); code(c3);
	#define code4(C1, C2, C3, C4)	code3(C1, C2, C3); code(C4);

	int yylex();
	void fpecatch(int e);
	void yyerror(char *s);
	void warning(char *s, char *t);
	void execerror(char *s, char *t);
	extern void init();
	extern void initcode();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 15 "hoc.y"
typedef union
{
	Symbol *sym;   /* apuntador de la tabla de símbolos */ 
	Inst *inst;  /* instrucción de máquina */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUMBER 257
#define PRINT 258
#define VAR 259
#define BLTIN 260
#define UNDEF 261
#define WHILE 262
#define IF 263
#define ELSE 264
#define OR 265
#define AND 266
#define GT 267
#define GE 268
#define LT 269
#define LE 270
#define EQ 271
#define NE 272
#define UNARYMINUS 273
#define NOT 274
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    2,    9,    9,    9,
    9,    1,    1,    1,    1,    1,    1,    1,    5,    5,
    6,    7,    8,    4,    4,    4,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    3,    3,    3,    3,    1,    2,    4,
    4,    1,    2,    4,    4,    7,    3,    4,    4,    1,
    1,    1,    0,    0,    2,    2,    1,    1,    1,    1,
    4,    3,    3,    3,    3,    3,    3,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,   21,   22,    0,    8,
    0,    0,   24,    0,    0,    0,    0,    0,    0,   27,
    6,    0,    9,    0,   30,    0,    0,    0,    0,   24,
    0,    0,    0,    4,    3,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   26,    0,   32,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,   23,
   10,   11,   31,   18,    0,   14,    0,   19,    0,   23,
   16,
};
static const YYINT yydgoto[] = {                          1,
   61,   25,   62,   32,   52,   18,   19,   86,   20,
};
static const YYINT yysindex[] = {                         0,
  756,   -7,  -39,  -38,  -53,  -30,    0,    0,  -38,    0,
 -104,  -38,    0,  -38,   12,   17,  873,  -28,  -28,    0,
    0, -229,    0, -227,    0,  738,  -38,  -38,  -36,    0,
  -36,  763,  908,    0,    0,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  -38,    0,  -38,  -38,
  738,  833,  833,  -73,  -72,  738,  930,  776, -104,    0,
    0,  738,    0, 1010,  -29,  -22,  -22,  -22,  -22,  -22,
  -22,  -16,  -36,  -36,  -36,  738,  938, -104,    0,    0,
    0,    0,    0,    0,   24,    0, -228,    0,  833,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  131,    0,   14,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,  897,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  667,    0,    0,   33,    0,
   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  853,    0,    0,    0,    0,  577,    0,    0,  840,    0,
    0,  784,    0,  555,  505,  375,  399,  427,  446,  465,
  486,  164,   71,   93,  112,  737,    0,    0,    0,    0,
    0,    0,    0,    0,  863,    0,  812,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
   -1,   34, 1210,    7,   19,    0,    0,  -75,    0,
};
#define YYTABLESIZE 1282
static const YYINT yytable[] = {                         15,
    2,   14,   21,   22,   87,   24,   12,   27,   49,   28,
    2,   50,   45,   44,   91,   49,   12,   46,   30,   45,
   44,   34,   49,   29,   46,   45,   35,   54,   49,   55,
   46,   81,   82,   88,   16,   89,   58,   53,    0,    0,
    2,    0,   47,    0,    0,    2,    0,    0,    0,    0,
   79,   80,    0,   29,   29,   29,   29,   47,   29,    0,
   29,   38,    0,    0,   47,   23,   10,    0,    0,    0,
    0,   47,   47,   47,   47,   47,   10,   47,    0,   47,
   35,    0,    0,    0,    0,    0,    0,   90,    0,    0,
    0,   38,   38,   38,   38,    0,    0,    0,   38,    0,
    0,    0,   36,    0,    0,    2,    0,   29,    0,    0,
   35,   35,   35,   35,    0,    0,    0,   35,   29,    0,
    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   36,   36,   36,   36,   29,   47,   29,   36,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   37,   37,   37,   37,   47,   38,   47,   37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,   28,   28,   33,   38,   35,   38,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   35,    0,   35,    0,   36,    0,    0,
    0,    0,    0,   33,   33,    0,   33,    0,    0,    0,
    0,    0,    0,    0,    0,   36,   37,   36,    3,    0,
    5,    6,    0,    0,   28,    0,    0,    0,    3,    0,
    5,    6,    0,    0,   37,    9,   37,   38,   39,   40,
   41,   42,   43,    0,    0,    9,    0,    0,    0,    0,
    0,    0,    0,   28,    0,   28,    2,    2,    2,    2,
    2,    0,    2,    2,    0,    0,    0,    0,   33,    0,
   29,   29,   29,   29,    2,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   29,   29,   33,   29,   33,   47,
   47,   47,   47,    0,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,    0,   47,    0,   38,   38,
   38,   38,    0,   38,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,    0,   38,    0,   35,   35,   35,
   35,    0,   35,   35,   35,   35,   35,   35,   35,   35,
   35,   35,   35,    0,   35,    0,    0,    0,    0,   36,
   36,   36,   36,    0,   36,   36,   36,   36,   36,   36,
   36,   36,   36,   36,   36,    0,   36,    0,   37,   37,
   37,   37,    0,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   39,   37,    0,   28,   28,   28,
   28,    0,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,    0,   28,    0,    0,    0,   40,    0,
    0,    0,    0,    0,   39,   39,    0,    0,    0,    0,
   33,   33,   33,   33,    0,   33,   33,   33,   33,   33,
   33,   33,   33,   33,   33,   33,   41,   33,   40,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,   41,    0,    0,
    0,    0,    0,    0,   43,    0,    0,    0,    0,   39,
    0,    0,    0,    0,    0,   42,   42,    0,    0,    0,
    0,    0,    0,    0,    0,   44,    0,   39,    0,   39,
    0,    0,    0,   40,   43,   43,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,    0,    0,    0,    0,
    0,   40,    0,   40,    0,   44,   44,    0,    0,    0,
    0,   41,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,   45,    0,    0,    0,   41,
   42,   41,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,   42,   43,
   42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    7,   43,    0,   43,
   44,    0,    0,    0,   46,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   44,   45,
   44,    0,    0,    0,    0,    0,    7,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,    0,   45,
    0,   39,   39,   39,   39,    0,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,    0,   39,    0,
    0,    0,    0,    0,    0,   40,   40,   40,   40,   46,
   40,   40,   40,   40,   40,   40,   40,   40,   40,   40,
   40,    0,   40,    0,    0,    0,   13,   46,    0,   46,
    0,    7,    0,   41,   41,   41,   41,    0,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   41,   41,    7,
   41,    7,   42,   42,   42,   42,   13,   42,   42,   42,
   42,   42,   42,   42,   42,   42,   42,   42,    0,   42,
    0,   43,   43,   43,   43,    0,   43,   43,   43,   43,
   43,   43,   43,   43,   43,   43,   43,    0,   43,    0,
    0,    0,   44,   44,   44,   44,   34,   44,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   44,    0,   44,
    0,   45,   45,   45,   45,   11,   45,   45,   45,   45,
   45,   13,   59,    0,    0,    0,   34,   34,   45,   45,
   44,    0,   49,    0,   46,   59,    0,    0,    0,   13,
    0,   13,    0,   12,    0,   14,    0,    0,    0,    0,
   12,    0,   14,    0,    0,    0,    0,   12,    0,    0,
    0,   46,   46,   46,   46,   14,   46,   46,   46,   46,
   12,   15,    0,   12,    0,    0,    0,    0,   46,    0,
    0,   47,    0,    7,    7,    7,    7,    0,    7,    7,
    7,   34,   78,    0,    0,    0,    0,    0,    0,   25,
    7,   15,    0,    0,    0,    0,   15,    0,    0,   34,
   10,   34,   20,    0,    0,    0,    0,   10,    0,    0,
    0,    0,   14,    0,    0,    0,    0,   12,   13,   25,
   10,    0,   48,    0,   25,   13,    0,   60,   12,    0,
    0,    0,   20,    0,    0,    0,    0,    0,   13,    0,
   84,    0,   32,    0,   32,   32,   12,   32,   12,   32,
    0,    0,    0,    0,   45,   44,   15,   49,    0,   46,
    0,    0,    0,   13,   13,   13,   13,    0,   13,   13,
   13,    0,    0,    0,   15,    0,   15,   10,   30,   30,
   13,   30,    0,   30,   25,    0,    0,    0,   63,   45,
   44,    0,   49,    0,   46,   13,   32,   20,    0,    0,
    0,    0,    0,    0,   25,    0,   47,   32,    0,    0,
   83,   45,   44,    0,   49,   20,   46,    0,   85,   45,
   44,    0,   49,    0,   46,   32,    0,    0,    0,    0,
   30,    0,    0,   34,   34,   34,   34,    0,   34,   34,
   34,   47,   36,   37,   38,   39,   40,   41,   42,   43,
   34,    2,    3,    4,    5,    6,    0,    7,    8,    3,
    4,    5,    6,   47,    7,    8,    0,    0,    0,    9,
    0,   47,    3,    4,    5,    6,    9,    7,    8,    0,
   12,   12,   12,   12,    0,   12,   12,   12,    0,    9,
    0,   45,   44,    0,   49,    0,   46,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   15,   15,
   15,   15,    0,   15,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,    0,    0,    0,    3,
    4,    5,    6,    0,    7,    8,   25,   25,   25,   25,
    0,   25,   25,   47,    0,    0,    9,    0,    0,   20,
   20,   20,   20,   25,   20,   20,    0,    0,    0,   32,
   32,   32,   32,    0,   32,   32,   20,   32,   32,   32,
   32,   32,   32,   32,   32,    0,   32,   36,   37,   38,
   39,   40,   41,   42,   43,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   30,   30,   30,   30,   30,   30,   30,   30,    0,
    0,    0,   36,   37,   38,   39,   40,   41,   42,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   36,   37,   38,   39,   40,   41,
   42,   43,   36,   37,   38,   39,   40,   41,   42,   43,
   17,    0,    0,   26,    0,    0,    0,    0,   29,    0,
    0,   31,    0,   33,    0,    0,    0,   51,   51,    0,
    0,    0,    0,    0,    0,    0,   56,   57,    0,    0,
    0,    0,    0,    0,    0,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,    0,   76,   77,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,   38,   39,   40,   41,
   42,   43,
};
static const YYINT yycheck[] = {                          1,
    0,   40,   10,   43,   80,   45,   45,   61,   45,   40,
   10,   40,   42,   43,   90,   45,   45,   47,  123,   42,
   43,   10,   45,   10,   47,   42,   10,  257,   45,  257,
   47,  105,  105,   10,    1,  264,   30,   19,   -1,   -1,
   40,   -1,   10,   -1,   -1,   45,   -1,   -1,   -1,   -1,
   52,   53,   -1,   40,   41,   42,   43,   94,   45,   -1,
   47,   10,   -1,   -1,   94,  105,  105,   -1,   -1,   -1,
   -1,   94,   40,   41,   42,   43,  105,   94,   -1,   47,
   10,   -1,   -1,   -1,   -1,   -1,   -1,   89,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,   -1,   -1,   47,   -1,
   -1,   -1,   10,   -1,   -1,  105,   -1,   94,   -1,   -1,
   40,   41,   42,   43,   -1,   -1,   -1,   47,  105,   -1,
   -1,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   42,   43,  123,  105,  125,   47,
   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,  123,  105,  125,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   41,   42,   10,  123,  105,  125,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  125,   -1,  105,   -1,   -1,
   -1,   -1,   -1,   40,   41,   -1,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  123,  105,  125,  257,   -1,
  259,  260,   -1,   -1,   94,   -1,   -1,   -1,  257,   -1,
  259,  260,   -1,   -1,  123,  274,  125,  267,  268,  269,
  270,  271,  272,   -1,   -1,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  125,  256,  257,  258,  259,
  260,   -1,  262,  263,   -1,   -1,   -1,   -1,  105,   -1,
  257,  258,  259,  260,  274,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  123,  274,  125,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,   -1,  274,   -1,  257,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,  274,   -1,  257,  258,  259,
  260,   -1,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,   -1,  274,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,   -1,  274,   -1,  257,  258,
  259,  260,   -1,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,   10,  274,   -1,  257,  258,  259,
  260,   -1,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,   -1,  274,   -1,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,   10,  274,   40,   41,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,  105,
   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   10,   -1,  123,   -1,  125,
   -1,   -1,   -1,  105,   40,   41,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   40,   41,   -1,   -1,   -1,
   -1,  105,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,  123,
  105,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   10,   -1,   -1,   -1,  123,  105,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   10,  123,   -1,  125,
  105,   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,  105,
  125,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
   -1,  257,  258,  259,  260,   -1,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,   -1,  274,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  105,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,   -1,  274,   -1,   -1,   -1,   10,  123,   -1,  125,
   -1,  105,   -1,  257,  258,  259,  260,   -1,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  123,
  274,  125,  257,  258,  259,  260,   40,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,  274,
   -1,  257,  258,  259,  260,   -1,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,   -1,  274,   -1,
   -1,   -1,  257,  258,  259,  260,   10,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,   -1,  274,
   -1,  257,  258,  259,  260,   10,  262,  263,  264,  265,
  266,  105,   10,   -1,   -1,   -1,   40,   41,  274,   42,
   43,   -1,   45,   -1,   47,   10,   -1,   -1,   -1,  123,
   -1,  125,   -1,   10,   -1,   40,   -1,   -1,   -1,   -1,
   45,   -1,   40,   -1,   -1,   -1,   -1,   45,   -1,   -1,
   -1,  257,  258,  259,  260,   40,  262,  263,  264,  265,
   45,   10,   -1,   40,   -1,   -1,   -1,   -1,  274,   -1,
   -1,   94,   -1,  257,  258,  259,  260,   -1,  262,  263,
  264,  105,   10,   -1,   -1,   -1,   -1,   -1,   -1,   10,
  274,   40,   -1,   -1,   -1,   -1,   45,   -1,   -1,  123,
  105,  125,   10,   -1,   -1,   -1,   -1,  105,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   -1,   -1,   45,  123,   40,
  105,   -1,   10,   -1,   45,  123,   -1,  125,  105,   -1,
   -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,   40,   -1,   42,   43,  123,   45,  125,   47,
   -1,   -1,   -1,   -1,   42,   43,  105,   45,   -1,   47,
   -1,   -1,   -1,  257,  258,  259,  260,   -1,  262,  263,
  264,   -1,   -1,   -1,  123,   -1,  125,  105,   42,   43,
  274,   45,   -1,   47,  105,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,  123,   94,  105,   -1,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   94,  105,   -1,   -1,
   41,   42,   43,   -1,   45,  123,   47,   -1,   41,   42,
   43,   -1,   45,   -1,   47,  123,   -1,   -1,   -1,   -1,
   94,   -1,   -1,  257,  258,  259,  260,   -1,  262,  263,
  264,   94,  265,  266,  267,  268,  269,  270,  271,  272,
  274,  256,  257,  258,  259,  260,   -1,  262,  263,  257,
  258,  259,  260,   94,  262,  263,   -1,   -1,   -1,  274,
   -1,   94,  257,  258,  259,  260,  274,  262,  263,   -1,
  257,  258,  259,  260,   -1,  262,  263,  264,   -1,  274,
   -1,   42,   43,   -1,   45,   -1,   47,  274,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,  262,  263,  257,  258,  259,  260,
   -1,  262,  263,   94,   -1,   -1,  274,   -1,   -1,  257,
  258,  259,  260,  274,  262,  263,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,  262,  263,  274,  265,  266,  267,
  268,  269,  270,  271,  272,   -1,  274,  265,  266,  267,
  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
   -1,   -1,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  265,  266,  267,  268,  269,  270,
  271,  272,  265,  266,  267,  268,  269,  270,  271,  272,
    1,   -1,   -1,    4,   -1,   -1,   -1,   -1,    9,   -1,
   -1,   12,   -1,   14,   -1,   -1,   -1,   18,   19,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   27,   28,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,   -1,   49,   50,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  266,  267,  268,  269,  270,
  271,  272,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
"'_'",0,0,0,0,0,0,0,0,0,"'i'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"NUMBER","PRINT","VAR","BLTIN","UNDEF","WHILE","IF","ELSE",
"OR","AND","GT","GE","LT","LE","EQ","NE","UNARYMINUS","NOT",0,0,0,0,0,0,0,0,0,0,
0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list stmt '\\n'",
"list : list expr '\\n'",
"list : list error '\\n'",
"asgn : VAR '=' expr",
"complex : 'i'",
"complex : NUMBER 'i'",
"complex : NUMBER '+' NUMBER 'i'",
"complex : NUMBER '-' NUMBER 'i'",
"stmt : expr",
"stmt : PRINT expr",
"stmt : while cond stmt end",
"stmt : if cond stmt end",
"stmt : if cond stmt end ELSE stmt end",
"stmt : '{' stmtlist '}'",
"stmt : '\\n' '{' stmtlist '}'",
"cond : '(' expr ')' '\\n'",
"cond : expr",
"while : WHILE",
"if : IF",
"end :",
"stmtlist :",
"stmtlist : stmtlist '\\n'",
"stmtlist : stmtlist stmt",
"expr : complex",
"expr : NUMBER",
"expr : VAR",
"expr : asgn",
"expr : BLTIN '(' expr ')'",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '^' expr",
"expr : '-' expr",
"expr : expr GT expr",
"expr : expr GE expr",
"expr : expr LT expr",
"expr : expr LE expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 114 "hoc.y"

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf begin;

char *progname;
int lineno = 1;

int main(int argc, char **argv)
{
	/*int  fpecatch();*/
	progname  =  argv[0];
	init();
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode())
		execute(prog);
	return 0;
}

int yylex()
{
	int c;
	while  ((c = getchar()) ==  ' ' ||  c ==   '\t');
	if (c == EOF) return 0; 
	if (c == '.' || isdigit(c)) /*número*/
	{
		double d;
		ungetc(c, stdin); 
		scanf("%lf", &d);
		yylval.sym = install("", NUMBER, d, 0);
		return NUMBER; 
	}
	if (isalpha(c) && c != 105 || c == '_')
	{
		Symbol *s;
		char sbuf[100], *p = sbuf; 
		do
		{
			if (p >= sbuf + sizeof(sbuf) - 1)
			{
				*p = '\0'; 
				execerror("name too long", sbuf);
			}
			*p++ = c;
		} while ((c = getc(stdin)) != EOF && isalnum(c));
		ungetc(c, stdin); 
		*p = '\0'; 
		if ((s = lookup(sbuf)) == 0) s = install(sbuf, UNDEF, 0.0, 0); 
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
	}
	switch (c)
	{
		case '>':		return follow('=', GE, GT);
		case '<':		return follow('=', LE, LT);
		case '=':		return follow('=', EQ, '=');
		case '!':		return follow('=', NE, NOT);
		case '|':		return follow('|', OR, '|');
		case '&':		return follow('&', AND, '&');
		case '\n':		lineno++; return '\n';
		default:		return c; 
	}
}

int follow(int expect, int ifyes, int ifno)/*buscar  >=, etc.*/
{
	int c = getchar();
	if (c == expect) return ifyes;
	ungetc(c, stdin);
	return ifno;
}

void yyerror(char *s) /* comunicar errores de tiempo de compilación */
{
	warning(s, (char *)0);
} 

void execerror(char *s, char *t)
{
	warning(s, t);
	longjmp(begin, 0);
}

void fpecatch(int e) /* detectar errores por punto flotante */ 
{
	execerror("floating point exception", (char *) 0);
}	

void warning(char *s, char *t)
{
	fprintf (stderr, "%s: %s", progname, s);
	if(t) fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}
#line 626 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 3:
#line 37 "hoc.y"
	{code2(pop, STOP); return 1;}
break;
case 4:
#line 38 "hoc.y"
	{code(STOP); return 1;}
break;
case 5:
#line 39 "hoc.y"
	{code2(print, STOP); return 1;}
break;
case 6:
#line 40 "hoc.y"
	{yyerrok;}
break;
case 7:
#line 43 "hoc.y"
	{yyval.inst = yystack.l_mark[0].inst; code3(varpush, (Inst)yystack.l_mark[-2].sym, assign);}
break;
case 8:
#line 46 "hoc.y"
	{code2(cflag, imagipush);}
break;
case 9:
#line 47 "hoc.y"
	{code2(imagipush, (Inst)yystack.l_mark[-1].sym);}
break;
case 10:
#line 48 "hoc.y"
	{code3(complexpush, (Inst)yystack.l_mark[-3].sym, (Inst)yystack.l_mark[-1].sym);}
break;
case 11:
#line 49 "hoc.y"
	{code4(cflag, complexpush, (Inst)yystack.l_mark[-3].sym, (Inst)yystack.l_mark[-1].sym);}
break;
case 12:
#line 52 "hoc.y"
	{code(pop);}
break;
case 13:
#line 53 "hoc.y"
	{code(prexpr); yyval.inst = yystack.l_mark[0].inst;}
break;
case 14:
#line 55 "hoc.y"
	{
				(yystack.l_mark[-3].inst)[1] = (Inst)yystack.l_mark[-1].inst;	/* cuerpo de la iteración */ 
				(yystack.l_mark[-3].inst)[2] = (Inst)yystack.l_mark[0].inst;	/* terminar si la condición no se cumple */
			}
break;
case 15:
#line 60 "hoc.y"
	{
				(yystack.l_mark[-3].inst)[1] = (Inst)yystack.l_mark[-1].inst;	/* parte then */ 
				(yystack.l_mark[-3].inst)[3] = (Inst)yystack.l_mark[0].inst;	/* terminar si la condición no se cumple */ 
			}
break;
case 16:
#line 65 "hoc.y"
	{
				(yystack.l_mark[-6].inst)[1]   =   (Inst)yystack.l_mark[-4].inst;	/*parte then  */
				(yystack.l_mark[-6].inst)[2]   =   (Inst)yystack.l_mark[-1].inst;	/*parte else   */
				(yystack.l_mark[-6].inst)[3]   =   (Inst)yystack.l_mark[0].inst; /*terminar si la condición no se cumple  */
			}
break;
case 17:
#line 70 "hoc.y"
	{yyval.inst = yystack.l_mark[-1].inst;}
break;
case 18:
#line 71 "hoc.y"
	{yyval.inst = yystack.l_mark[-1].inst;}
break;
case 19:
#line 74 "hoc.y"
	{code(STOP); yyval.inst = yystack.l_mark[-2].inst;}
break;
case 20:
#line 75 "hoc.y"
	{code(STOP); yyval.inst = yystack.l_mark[0].inst;}
break;
case 21:
#line 78 "hoc.y"
	{yyval.inst = code3(whilecode, STOP, STOP);}
break;
case 22:
#line 81 "hoc.y"
	{yyval.inst = code(ifcode); code3(STOP, STOP, STOP);}
break;
case 23:
#line 84 "hoc.y"
	{code(STOP); yyval.inst = progp;}
break;
case 24:
#line 87 "hoc.y"
	{yyval.inst = progp;}
break;
case 27:
#line 92 "hoc.y"
	{yyval.inst = yystack.l_mark[0].inst;}
break;
case 28:
#line 93 "hoc.y"
	{yyval.inst = code2(constpush, (Inst)yystack.l_mark[0].sym);}
break;
case 29:
#line 94 "hoc.y"
	{yyval.inst = code3(varpush, (Inst)yystack.l_mark[0].sym, eval);}
break;
case 31:
#line 96 "hoc.y"
	{yyval.inst = yystack.l_mark[-1].inst; code2(bltin, (Inst)yystack.l_mark[-3].sym->u.ptr);}
break;
case 32:
#line 97 "hoc.y"
	{yyval.inst = yystack.l_mark[-1].inst;}
break;
case 33:
#line 98 "hoc.y"
	{code(ADD);}
break;
case 34:
#line 99 "hoc.y"
	{code(SUB);}
break;
case 35:
#line 100 "hoc.y"
	{code(MUL);}
break;
case 36:
#line 101 "hoc.y"
	{code(DIV);}
break;
case 37:
#line 102 "hoc.y"
	{code(power);}
break;
case 38:
#line 103 "hoc.y"
	{yyval.inst = yystack.l_mark[0].inst; code(negate);}
break;
case 39:
#line 104 "hoc.y"
	{code(gt);}
break;
case 40:
#line 105 "hoc.y"
	{code(ge);}
break;
case 41:
#line 106 "hoc.y"
	{code(lt);}
break;
case 42:
#line 107 "hoc.y"
	{code(le);}
break;
case 43:
#line 108 "hoc.y"
	{code(eq);}
break;
case 44:
#line 109 "hoc.y"
	{code(ne);}
break;
case 45:
#line 110 "hoc.y"
	{code(and);}
break;
case 46:
#line 111 "hoc.y"
	{code(or);}
break;
case 47:
#line 112 "hoc.y"
	{yyval.inst = yystack.l_mark[0].inst; code(not);}
break;
#line 1003 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
