%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "hoc.h"
  #define MSDOS

  void yyerror (char *s);
  int yylex ();
  void warning(char *s, char *t);
  void execerror(char *s, char *t);
  void fpecatch();
%}

%union
{
	ComplejoAP val;
  Symbol *sym;
	double num;
}

%token <num> NUMBER
%token <sym> VAR BLTIN INDEF
%type <val> expr complejo asgn
%left '+' '-'
%left '*' '/'
%left '^'
%left USIGNE
%nonassoc '(' ')'

%%
       list:
           | list'\n'
           | list asgn '\n'
           | list expr '\n'                                        {imprimirC($2);}
      	   ;

       asgn:
             VAR '=' expr                                          {$$ = $1->u.val = $3; $1->type = VAR;}
           ;

   complejo:
             NUMBER '+' NUMBER 'i'                                 {$$ = creaComplejo($1, $3);}
           | NUMBER '+''i'                                         {$$ = creaComplejo($1, 1);}
           | NUMBER '-' 'i'                                        {$$ = creaComplejo($1, -1);}
   	       | NUMBER '-' NUMBER 'i'                                 {$$ = creaComplejo($1, -$3);}

   	       | '-' NUMBER %prec USIGNE '+' NUMBER %prec USIGNE 'i'   {$$ = creaComplejo(-$2, $4);}
           | '-' NUMBER %prec USIGNE '-' NUMBER %prec USIGNE 'i'   {$$ = creaComplejo(-$2, -$4);}
           | '-' NUMBER %prec USIGNE '+' %prec USIGNE 'i'          {$$ = creaComplejo(-$2, 1);}
           | '-' NUMBER %prec USIGNE '-' %prec USIGNE 'i'          {$$ = creaComplejo(-$2, -1);}
           ;

       expr:
              complejo{$$ = $1;}
            | VAR
                {
                  if($1->type == INDEF)
                    execerror("variable no definida", $1->name);
                  $$ = $1->u.val;
                }
           | BLTIN  '(' expr ')'                                   {$$ = (*($1->u.ptr))($3);}
	         | expr '+' expr                                         {$$ = Complejo_add($1,$3);}
           | expr '-' expr                                         {$$ = Complejo_sub($1,$3);}
           | expr '*' expr                                         {$$ = Complejo_mul($1,$3);}
	         | expr '/' expr
                          {
                            if($3->real == 0.0 && $3->img == 0.0)
                              execerror("division por cero", "");
                            $$ = Complejo_div($1,$3);
                          }
           | expr '^' NUMBER                                       {$$ = Complejo_pot($1,$3);}
	         | '(' expr ')'                                          {$$ = $2;}
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
  if (c == EOF) return 0;
  if (c == '.' || isdigit (c))             
  {
    ungetc (c, stdin);
    scanf ("%lf", &yylval.num);
    return NUMBER;
  }
  if(isalpha(c) && c != 105)
  {
    Symbol *s;
    char sbuf[200], *p = sbuf;

    do
    {
      *p++ = c;
    } while ((c = getchar()) != EOF && isalnum(c));

    ungetc(c, stdin);
    *p = '\0';

    if((s = lookup(sbuf)) == (Symbol *)NULL)
      s = install(sbuf, INDEF, 0);

    yylval.sym = s;

    if(s->type == INDEF)
      return VAR;
    else
      return s->type;
  }

  if(c == '\n') lineno++;
  
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
