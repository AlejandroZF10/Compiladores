%{
#include <stdio.h>
#include <stdlib.h>
#include "complejo_cal.h"

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
%}

%union
{
	ComplejoAP val;
	double num;
}

%token <num> NUMBER
%type <val> complejoNum complejo
%left '+' '-'
%left '*' '/'
%left '^'
%nonassoc '(' ')'

%%

       list:
           | list'\n'
           | list complejoNum '\n'  {imprimirC($2);}
      	   ;

   complejo:
             NUMBER '+' NUMBER 'i'          {;$$ = creaComplejo($1,$3);}
           | NUMBER '+''i'                  {;$$ = creaComplejo($1,1);}
           | NUMBER '-' 'i'                 {;$$ = creaComplejo($1,-1);}
   	       | NUMBER '-' NUMBER 'i'          {;$$ = creaComplejo($1,-$3);}
   	       | '-' NUMBER '+' NUMBER 'i'      {;$$ = creaComplejo(-$2,$4);}
   	       | '-' NUMBER '-' NUMBER 'i'      {;$$ = creaComplejo(-$2,-$4);}
           ;

complejoNum:
             complejo
	         | complejoNum '+' complejoNum    {$$ = Complejo_add($1,$3);}
           | complejoNum '-' complejoNum    {$$ = Complejo_sub($1,$3);}
           | complejoNum '*' complejoNum    {$$ = Complejo_mul($1,$3);}
	         | complejoNum '/' complejoNum    {$$ = Complejo_div($1,$3);}
           | complejoNum '^' NUMBER         {$$ = Complejo_pot($1,$3);}
	         | '(' complejoNum ')'            {$$ = $2;}
           ;
%%


#include <stdio.h>
#include <ctype.h>
char *progname;
int lineno = 1;

void main (int argc, char *argv[])
{
    progname = argv[0];
    yyparse ();
}

int yylex ()
{
    int c;
  	while ((c = getchar ()) == ' ' || c == '\t');
    if (c == EOF) return 0;
  	if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval.num);
      return NUMBER;
    }
    if(c == '\n')
      lineno++;
    return c;                                
}
void yyerror (char *s)
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

