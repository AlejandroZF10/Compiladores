#include "complex.h"
#define NSTACK 256
#define NPROG 2000

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

extern Datum pop();

typedef int (*Inst)();  /* instrucción de maquina */ 

#define STOP    (Inst) 0

Inst prog[NPROG], *progp, *code();


extern void prexpr();
extern int follow(int, int, int);
extern void execerror(char *, char *);
extern void ifcode(), whilecode();
extern void init(), initcode(), execute(Inst *);
extern void eval(), ADD(), SUB(), MUL(), DIV(), negate(), power();
extern void gt(), lt(), eq(), ge(), le(), ne(), and() , or(), not(), quit();
extern void assign(), bltin(), varpush(), constpush(), print(), complexpush(), imagipush(), cflag();
