#include "complejo_cal.h"

typedef struct Symbol /*entrada de la tabla de s�mbolos*/
{
	char *name;
	short type;	/* VAR, BLTIN, UNDEF */
	union
	{
		Complejo * val;	/* si es VAR */
		Complejo * (*ptr)(Complejo *);	/* s� es BLTIN */
	} u;
	struct Symbol *next;	/* para ligarse a otro */ 
} Symbol;

Symbol *install(char *s, int t, Complejo * d), *lookup(char *s);
void init(void);