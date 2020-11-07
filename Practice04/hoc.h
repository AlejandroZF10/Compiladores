#include "complex.h"
#define STOP (Inst)0

typedef struct Symbol /*entrada de la tabla de simbolos*/
{
	char *name;
	short type; /*VAR, BLTIN, UNDEF*/
	union
	{
		double num;   /*Si es numero double*/
		complex *val; /*si es VAR*/
		complex *(*ptr)(); /*si es BLTIN*/
	} u;
	struct Symbol *next; /*para ligarse a otro*/
} Symbol;

Symbol *install(char *s, int t, double d, int f), *lookup(char *s);

typedef union Datum /*tipo de la pila del interprete*/
{
	complex *val;
	Symbol *sym;
} Datum;

typedef int (*Inst)();  /* instrucci�n de m�quina */

extern Inst prog[];
extern Datum pop();
extern void execerror(char *, char *);
extern void eval(), ADD(), SUB(), MUL(), DIV(), negate(), power();
extern void assign(), bltin(), varpush(), constpush(), print(), complexpush(), imagipush(), cflag();
