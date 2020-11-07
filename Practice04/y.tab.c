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

#line 1 "complex.y"

	#include "hoc.h"
	#include <math.h>
	#define code2(C1, C2)			code(C1); code(C2);
	#define code3(C1, C2, C3)		code2(C1, C2); code(C3);
	#define code4(C1, C2, C3, C4)	code3(C1, C2, C3); code(C4);

	int yylex();
	void fpecatch(int e);
	void yyerror(char *s);
	void warning(char *s, char *t);
	void execerror(char *s, char *t);
	extern void code();
	extern void init();
	extern void execute();
	extern void initcode();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 19 "complex.y"
typedef union
{
	Symbol *sym;
	Inst *inst;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 51 "y.tab.c"

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
#define VAR 258
#define BLTIN 259
#define INDEF 260
#define UNARYMINUS 261
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    2,    3,    3,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const YYINT yylen[] = {                            2,
    0,    3,    3,    3,    3,    2,    3,    1,    2,    4,
    4,    1,    1,    1,    4,    3,    3,    3,    3,    3,
    2,    3,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    8,    6,    0,    0,
    0,    0,   12,    4,    0,    0,    9,    0,    0,   13,
    0,    5,    0,    0,    0,    0,    0,    0,    2,    3,
    0,    0,    0,    0,   22,    0,    0,    0,    0,    0,
   10,   11,   15,
};
static const YYINT yydgoto[] = {                          1,
   11,   12,   13,
};
static const YYINT yysindex[] = {                         0,
  -10,   -8,  -40,  -51,  -23,  -39,    0,    0,   15,  -39,
   -6,   19,    0,    0, -226, -224,    0,  -39,  -39,    0,
  -60,    0,  -34,  -39,  -39,  -39,  -39,  -39,    0,    0,
  -67,  -65,  -21,  -27,    0,  -15,  -15,  -60,  -60,  -60,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    9,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   33,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   32,    0,    0,   18,   72,   42,   59,   67,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  101,    0,    0,
};
#define YYTABLESIZE 249
static const YYINT yytable[] = {                          8,
   10,   14,   15,   29,   16,    6,   35,   26,   24,   18,
   25,   13,   27,   43,   26,   24,   19,   25,   14,   27,
   26,   24,    9,   25,   22,   27,   26,   16,   30,   10,
   31,   27,   32,   28,    6,   26,   24,   41,   25,   42,
   27,    7,   21,   13,   13,    0,   13,    0,   13,   14,
   14,   18,    0,    0,    0,   14,    0,    0,   16,   28,
   16,    0,   16,    0,   17,    7,   28,    0,   19,    0,
    0,    0,   28,   21,   21,   21,   20,   21,   28,   21,
    0,   17,   18,   18,   18,    0,   18,   28,   18,    0,
    0,    0,    0,    0,    7,   13,    0,    0,    0,   19,
   19,   19,   14,   19,    0,   19,   21,   20,   20,   20,
   23,   20,   17,   20,   17,    0,   17,    0,   33,   34,
    0,    0,    0,    0,   36,   37,   38,   39,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,   20,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    5,
};
static const YYINT yycheck[] = {                         10,
   40,   10,   43,   10,   45,   45,   41,   42,   43,   61,
   45,   10,   47,   41,   42,   43,   40,   45,   10,   47,
   42,   43,   33,   45,   10,   47,   42,   10,   10,   40,
  257,   47,  257,   94,   45,   42,   43,  105,   45,  105,
   47,   10,   10,   42,   43,   -1,   45,   -1,   47,   41,
   42,   10,   -1,   -1,   -1,   47,   -1,   -1,   41,   94,
   43,   -1,   45,   -1,  105,  105,   94,   -1,   10,   -1,
   -1,   -1,   94,   41,   42,   43,   10,   45,   94,   47,
   -1,   10,   41,   42,   43,   -1,   45,   94,   47,   -1,
   -1,   -1,   -1,   -1,  105,   94,   -1,   -1,   -1,   41,
   42,   43,   94,   45,   -1,   47,    6,   41,   42,   43,
   10,   45,   41,   47,   43,   -1,   45,   -1,   18,   19,
   -1,   -1,   -1,   -1,   24,   25,   26,   27,   28,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 261
#define YYUNDFTOKEN 267
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,"'i'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"NUMBER","VAR","BLTIN","INDEF","UNARYMINUS",0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : list",
"list :",
"list : list expr '\\n'",
"list : list asgn '\\n'",
"list : list error '\\n'",
"list : list '!' '\\n'",
"list : list '\\n'",
"asgn : VAR '=' expr",
"complex : 'i'",
"complex : NUMBER 'i'",
"complex : NUMBER '+' NUMBER 'i'",
"complex : NUMBER '-' NUMBER 'i'",
"expr : complex",
"expr : VAR",
"expr : NUMBER",
"expr : BLTIN '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '^' expr",
"expr : '-' expr",
"expr : '(' expr ')'",

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
#line 62 "complex.y"

	#include <stdio.h>
	#include <ctype.h>
	#include <signal.h>
	#include <setjmp.h>

	jmp_buf begin;

	char *progname;
	int lineno = 1;
	void main (int argc, char *argv[])
	{
		progname = argv[0];
		init();
		setjmp(begin);
		signal(SIGFPE, fpecatch);
		for(initcode(); yyparse (); initcode())
			execute(prog);
		return;
	}

	void execerror(char *s, char *t)
	{
		warning(s, t);
		longjmp(begin, 0);
	}

	void fpecatch(int e)
	{
		execerror("excepcion de punto flotante", (char *)0);
	}

	int yylex ()
	{
		int c;

		while ((c = getchar ()) == ' ' || c == '\t');
			if (c == EOF) return 0;
		if (c == '.' || isdigit (c))
		{
			double d;
			ungetc (c, stdin);
			scanf ("%lf", &d);
			yylval.sym = install("", NUMBER, d, 0);
			return NUMBER;
		}
		if(isalpha(c) && c != 105)
		{
			Symbol *s;
			char sbuf[200], *p = sbuf;
			do
			{*p++ = c;}
			while ((c = getchar()) != EOF && isalnum(c));
			ungetc(c, stdin);
			*p = '\0';
			if((s = lookup(sbuf)) == (Symbol *)NULL) s = install(sbuf, INDEF, 0.0, 0);
			yylval.sym=s;
			return s->type == INDEF ? VAR : s->type;
		}
  			if(c == '\n') lineno++;
  			return c;
	}

	void yyerror (char *s)  /*Llamada por yyparse ante un error*/
	{
		warning(s, (char *) 0);
	}

	void warning(char *s, char *t)
	{
		fprintf (stderr, "%s: %s", progname, s);
		if(t) fprintf (stderr, " %s", t);
		fprintf (stderr, " cerca de la linea %d\n", lineno);
	}
#line 339 "y.tab.c"

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
case 2:
#line 34 "complex.y"
	{code2(print, STOP); return 1;}
break;
case 3:
#line 35 "complex.y"
	{code2(pop, STOP); return 1;}
break;
case 4:
#line 36 "complex.y"
	{yyerrok;}
break;
case 5:
#line 37 "complex.y"
	{exit(0);}
break;
case 7:
#line 41 "complex.y"
	{code3(varpush, (Inst)yystack.l_mark[-2].sym, assign);}
break;
case 8:
#line 44 "complex.y"
	{code2(cflag, imagipush);}
break;
case 9:
#line 45 "complex.y"
	{code2(imagipush, (Inst)yystack.l_mark[-1].sym);}
break;
case 10:
#line 46 "complex.y"
	{code3(complexpush, (Inst)yystack.l_mark[-3].sym, (Inst)yystack.l_mark[-1].sym);}
break;
case 11:
#line 47 "complex.y"
	{code4(cflag, complexpush, (Inst)yystack.l_mark[-3].sym, (Inst)yystack.l_mark[-1].sym);}
break;
case 13:
#line 51 "complex.y"
	{code3(varpush, (Inst)yystack.l_mark[0].sym, eval);}
break;
case 14:
#line 52 "complex.y"
	{code2(constpush, (Inst)yystack.l_mark[0].sym);}
break;
case 15:
#line 53 "complex.y"
	{code2(bltin, (Inst)yystack.l_mark[-3].sym->u.ptr);}
break;
case 16:
#line 54 "complex.y"
	{code(ADD);}
break;
case 17:
#line 55 "complex.y"
	{code(SUB);}
break;
case 18:
#line 56 "complex.y"
	{code(MUL);}
break;
case 19:
#line 57 "complex.y"
	{code(DIV);}
break;
case 20:
#line 58 "complex.y"
	{code(power);}
break;
case 21:
#line 59 "complex.y"
	{code(negate);}
break;
#line 610 "y.tab.c"
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
