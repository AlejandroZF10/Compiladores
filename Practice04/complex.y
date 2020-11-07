%{
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
%}

%union
{
	Symbol *sym;
	Inst *inst;
}

%token <sym> NUMBER VAR BLTIN INDEF
%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS
%right '^' 'i'

%%
	list:
			|	list expr '\n'							{code2(print, STOP); return 1;}
			|	list asgn '\n'							{code2(pop, STOP); return 1;}
			|	list error '\n'							{yyerrok;}
			|	list '!' '\n'							{exit(0);}
			|	list'\n'
			;
	asgn:
				VAR '=' expr							{code3(varpush, (Inst)$1, assign);}
			;
 complex:
			 	'i'										{code2(cflag, imagipush);}
			|	NUMBER 'i'								{code2(imagipush, (Inst)$1);}
			|	NUMBER '+' NUMBER 'i'					{code3(complexpush, (Inst)$1, (Inst)$3);}
			|	NUMBER '-' NUMBER 'i'					{code4(cflag, complexpush, (Inst)$1, (Inst)$3);}
			;
	expr:
				complex
			|	VAR										{code3(varpush, (Inst)$1, eval);}
			|	NUMBER									{code2(constpush, (Inst)$1);}
			|	BLTIN '(' expr ')'						{code2(bltin, (Inst)$1->u.ptr);}
			|	expr '+' expr							{code(ADD);}
			|	expr '-' expr							{code(SUB);}
			|	expr '*' expr							{code(MUL);}
			|	expr '/' expr							{code(DIV);}
			|	expr '^' expr							{code(power);}
			|	'-' expr %prec UNARYMINUS				{code(negate);}
			|	'(' expr ')'
			;
%%
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
