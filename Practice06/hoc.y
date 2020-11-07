%{
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
%}
%union
{
	Symbol *sym;   /* apuntador de la tabla de símbolos */ 
	Inst *inst;  /* instrucción de máquina */
}
%token <sym> NUMBER PRINT VAR BLTIN UNDEF WHILE IF ELSE FOR
%type <inst> stmt asgn expr stmtlist cond while if for end complex

%right '='
%left OR
%left AND
%left GT GE LT LE EQ NE
%left '+' '_'
%left '*' '/'
%left UNARYMINUS NOT
%right '^'
%left 'i'

%%

	list:     /* nada */ 
		|	list '\n'
		|	list asgn '\n'				{code2(pop, STOP); return 1;}
		|	list stmt '\n'				{code(STOP); return 1;}
		|	list expr '\n'				{code2(print, STOP); return 1;}
		|	list error '\n'				{yyerrok;}
		;
	asgn:
			VAR '=' expr				{$$ = $3; code3(varpush, (Inst)$1, assign);}
		;
 complex:
		 	'i'							{code2(cflag, imagipush);}
		|	NUMBER 'i'					{code2(imagipush, (Inst)$1);}
		|	NUMBER '+' NUMBER 'i'		{code3(complexpush, (Inst)$1, (Inst)$3);}
		|	NUMBER '-' NUMBER 'i'		{code4(cflag, complexpush, (Inst)$1, (Inst)$3);}
		;
	stmt:
			expr						{code(pop);}
		|	PRINT expr					{code(prexpr); $$ = $2;}
		|	while cond stmt end
			{
				($1)[1] = (Inst)$3;	/* cuerpo de la iteración */ 
				($1)[2] = (Inst)$4;	/* terminar si la condición no se cumple */
			}
		|	for '(' cond ';' cond ';' cond ')' stmt end
			{
				($1)[1] = (Inst)$5;	/* Condición */
				($1)[2] = (Inst)$7;	/* Despues de ciclo*/
				($1)[3] = (Inst)$9;	/* Cuerpo*/
				($1)[4] = (Inst)$10; /* Termina si no se cumple la condición*/
			}
		|	if cond stmt end /* proposición if que no emplea else */ 
			{
				($1)[1] = (Inst)$3;	/* parte then */ 
				($1)[3] = (Inst)$4;	/* terminar si la condición no se cumple */ 
			}   
		|	if cond stmt end ELSE stmt end /* proposición if con parte else */
			{
				($1)[1]   =   (Inst)$3;	/*parte then  */
				($1)[2]   =   (Inst)$6;	/*parte else   */
				($1)[3]   =   (Inst)$7; /*terminar si la condición no se cumple  */
			}
		|	'{'	stmtlist '}'			{$$ = $2;}
		|	'\n' '{' stmtlist '}'		{$$ = $3;}
        ;
	cond:
			'(' expr ')' '\n'			{code(STOP); $$ = $2;}
		|	expr						{code(STOP); $$ = $1;}
		;
   while:
			WHILE						{$$ = code3(whilecode, STOP, STOP);}
		;
	 for:
	 		FOR							{$$ = code(forcode); code3(STOP,STOP,STOP); code(STOP);}
		;
	  if:
			IF   						{$$ = code(ifcode); code3(STOP, STOP, STOP);}
		;
	 end:
	 		/* nada */					{code(STOP); $$ = progp;}
		;
stmtlist:
			/* nada */					{$$ = progp;}
		|	stmtlist '\n'
		|	stmtlist stmt
		;
	expr:
			complex						{$$ = $1;}
		|	NUMBER						{$$ = code2(constpush, (Inst)$1);}
		|	VAR							{$$ = code3(varpush, (Inst)$1, eval);}
		|	asgn
		|	BLTIN '(' expr ')'			{$$ = $3; code2(bltin, (Inst)$1->u.ptr);}
		|	'(' expr ')'				{$$ = $2;}
		|	expr '+' expr				{code(ADD);}
		|	expr '-' expr				{code(SUB);}
		|	expr '*' expr				{code(MUL);}
		|	expr '/' expr				{code(DIV);}
		|	expr '^' expr				{code(power);}
		|	'-' expr %prec UNARYMINUS	{$$ = $2; code(negate);}
		|	expr GT expr				{code(gt);}
		|	expr GE expr				{code(ge);}
		|	expr LT expr				{code(lt);}
		|	expr LE expr				{code(le);}
		|	expr EQ expr				{code(eq);}
		|	expr NE expr				{code(ne);}
		|	expr AND expr				{code(and);}
		|	expr OR expr				{code(or);}
		|	NOT expr					{$$ = $2; code(not);}
		;
%%
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