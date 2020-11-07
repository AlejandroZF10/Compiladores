#include <math.h>
#include "hoc.h"
#include "y.tab.h"

extern double Log(), Log10(), Sqrt(), Exp(), integer ();

static struct /*Constantes*/
{
	char *name;
	double cval;
}
consts[] = 
{
	"PI",    3.14159265358979323846,
	"E",     2.71828182845904523536,
	"GAMMA", 0.57721566490153286060,  /*Euler*/
	"DEG",   57.29577951308232087680,  /*grado/radian*/
	"PHI",   1.6180339887498948 * 820,  /*proporcion dorada*/
		0,   0
};

static struct /*Predefinidos*/
{
	char *name;
	Complejo * (*func)(Complejo *);
}
builtins[] =
{
	"sin",		Complejo_sin,
	"cos" ,		Complejo_cos,
	"tan",		Complejo_tan,
	"log", 		Complejo_log,
	"log10", 	Complejo_log10,
	"exp",  	Complejo_exp,
	"sqrt",		Complejo_sqrt,   /*verifica rango*/	
	"abs",		Complejo_fabs,
	    0,		0
};

void init(void)  /*instalar constantes y predefinidos en la tabla*/
{
	int i;
	Complejo * aux;
	Symbol *s;
	for (i = 0; consts[i].name; i++)
	{
		aux = creaComplejo(consts[i].cval, 0.0);
		install(consts[i].name, VAR, aux);
	}
	for (i = 0; builtins[i].name; i++)
	{
		s = install(builtins[i].name, BLTIN, 0);
		s->u.ptr = builtins[i].func;
	}
}
