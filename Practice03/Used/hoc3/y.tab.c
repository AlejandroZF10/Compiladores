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

#line 1 "hoc3.y"

	#include "hoc.h"
	#include <math.h>
	#define MSDOS

	void yyerror (char *s);
	int yylex ();
	void warning(char *s, char *t);
	void execerror(char *s, char *t);
	void fpecatch();
	extern double Pow(double, double);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 14 "hoc3.y"
typedef union
{
	double val;
	Symbol *sym;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

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
    0,    0,    0,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    3,    3,    1,    1,    4,    3,    3,
    3,    3,    3,    3,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    6,    0,    0,    0,    2,    0,    0,    0,    0,
    0,    7,    0,    0,    0,    0,    0,    0,    0,    4,
    3,    0,    0,   14,    0,    0,    0,    0,    0,    8,
};
static const YYINT yydgoto[] = {                          1,
    8,    9,
};
static const YYINT yysindex[] = {                         0,
  -10,    0,  -38,  -18,  -39,    0,  -39,   -6,   14,  -39,
  -39,    0,  -69,  -33,  -39,  -39,  -39,  -39,  -39,    0,
    0,  -40,  -26,    0,  -29,  -29,  -69,  -69,  -69,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   10,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    0,    0,   40,   46,   17,   28,   35,    0,
};
static const YYINT yygindex[] = {                         0,
   87,    0,
};
#define YYTABLESIZE 249
static const YYINT yytable[] = {                          6,
    7,   17,   15,   20,   16,    5,   18,   24,   17,   15,
    7,   16,   17,   18,   30,   17,   15,   18,   16,   15,
   18,   11,   10,   21,   19,    5,   11,    0,    0,    7,
    0,    0,    0,    0,    5,   17,   15,   12,   16,    0,
   18,    0,    7,    7,   13,    7,    0,    7,    0,    9,
   15,   15,   15,   19,   15,   10,   15,   11,   11,   11,
   19,   11,    0,   11,   19,    0,    0,   19,   12,   12,
   12,    0,   12,    0,   12,   13,   13,   13,    0,   13,
    9,   13,    9,    0,    9,    0,   10,   19,   10,    0,
   10,   13,    0,   14,    7,    0,   22,   23,    0,    0,
    0,   25,   26,   27,   28,   29,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,   12,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    3,    4,
};
static const YYINT yycheck[] = {                         10,
   40,   42,   43,   10,   45,   45,   47,   41,   42,   43,
   10,   45,   42,   47,   41,   42,   43,   47,   45,   10,
   47,   40,   61,   10,   94,   10,   10,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   45,   42,   43,   10,   45,   -1,
   47,   -1,   42,   43,   10,   45,   -1,   47,   -1,   10,
   41,   42,   43,   94,   45,   10,   47,   41,   42,   43,
   94,   45,   -1,   47,   94,   -1,   -1,   94,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   -1,   45,
   41,   47,   43,   -1,   45,   -1,   41,   94,   43,   -1,
   45,    5,   -1,    7,   94,   -1,   10,   11,   -1,   -1,
   -1,   15,   16,   17,   18,   19,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 261
#define YYUNDFTOKEN 266
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"NUMBER","VAR","BLTIN","INDEF","UNARYMINUS",0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : list",
"list :",
"list : list '\\n'",
"list : list asgn '\\n'",
"list : list expr '\\n'",
"asgn : VAR '=' expr",
"expr : NUMBER",
"expr : VAR",
"expr : BLTIN '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '^' expr",
"expr : '(' expr ')'",
"expr : '-' expr",

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
#line 61 "hoc3.y"


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
  	yyparse();
}

void execerror(char *s, char *t)
{
	warning(s, t);
	longjmp(begin, 0);
}

void fpecatch()
{
	execerror("excepcion de punto flotante", (char *)0);
}

int yylex ()
{	
	int c;
  	while ((c = getchar ()) == ' ' || c == '\t');
 	if (c == EOF)
 		return 0;
  	if (c == '.' || isdigit (c))             
    {
    	ungetc (c, stdin);
    	scanf ("%lf", &yylval.val);
    	return NUMBER;
    }
	if(isalpha(c))
	{
		Symbol *s;
		char sbuf[200], *p = sbuf;
		do
		{
			*p++=c;
		} while ((c = getchar()) != EOF && isalnum(c));
		ungetc(c, stdin);
		*p = '\0';
		if((s=lookup(sbuf)) == (Symbol *)NULL)
			s = install(sbuf, INDEF, 0.0);
		yylval.sym = s;   
		if(s->type == INDEF)
		{
			return VAR;
		}
		else
		{
			return s->type;
		}
	}
  	if(c == '\n'){
                //puts("enter");
		lineno++;
        }
        /*if( c== '(')
		puts("(");
        if( c== ')')
		puts(")");*/
  	return c;                                
}

void yyerror (char *s)  /* Llamada por yyparse ante un error */
{
	warning(s, (char *) 0);
}

void warning(char *s, char *t)
{
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}
#line 333 "y.tab.c"

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
case 4:
#line 34 "hoc3.y"
	{printf("\t%.8g\n", yystack.l_mark[-1].val);}
break;
case 5:
#line 37 "hoc3.y"
	{yyval.val = yystack.l_mark[-2].sym->u.val = yystack.l_mark[0].val; yystack.l_mark[-2].sym->type = VAR;}
break;
case 6:
#line 40 "hoc3.y"
	{yyval.val = yystack.l_mark[0].val;}
break;
case 7:
#line 42 "hoc3.y"
	{
				if(yystack.l_mark[0].sym->type == INDEF)
					execerror("variable no definida",yystack.l_mark[0].sym->name);
				yyval.val=yystack.l_mark[0].sym->u.val;
			}
break;
case 8:
#line 47 "hoc3.y"
	{yyval.val=(*(yystack.l_mark[-3].sym->u.ptr))(yystack.l_mark[-1].val);}
break;
case 9:
#line 48 "hoc3.y"
	{yyval.val = yystack.l_mark[-2].val+yystack.l_mark[0].val;}
break;
case 10:
#line 49 "hoc3.y"
	{yyval.val = yystack.l_mark[-2].val-yystack.l_mark[0].val;}
break;
case 11:
#line 50 "hoc3.y"
	{yyval.val = yystack.l_mark[-2].val*yystack.l_mark[0].val;}
break;
case 12:
#line 52 "hoc3.y"
	{
						if(yystack.l_mark[0].val == 0.0)
							execerror("division por cero", "");
						yyval.val = yystack.l_mark[-2].val/yystack.l_mark[0].val;
					}
break;
case 13:
#line 57 "hoc3.y"
	{yyval.val = Pow(yystack.l_mark[-2].val, yystack.l_mark[0].val);}
break;
case 14:
#line 58 "hoc3.y"
	{yyval.val = yystack.l_mark[-1].val;}
break;
case 15:
#line 59 "hoc3.y"
	{yyval.val = -yystack.l_mark[0].val;}
break;
#line 588 "y.tab.c"
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
