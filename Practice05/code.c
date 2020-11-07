#include "hoc.h" 
#include "y.tab.h"
static Datum stack[NSTACK];  /* la pila */
static Datum *stackp;       /* siguiente lugar libre en la pila */
Inst *pc;	/* contador de programa durante la ejecuci�n */

int flag;

void initcode() /*inicializaci�n para la generaci�n de c�digo */
{
	stackp = stack;
	progp = prog;
}

void push(Datum d)	/*meter d en la pila*/
{
	if(stackp >= &stack[NSTACK]) execerror("stack overflow", (char *) 0);
	*stackp++ = d;
}

Datum pop() /*sacar y retornar de la pila el elemento del tope*/
{
	if (stackp <= stack) execerror("stack underflow", (char *) 0);
	return  *--stackp;
}

void complexpush()
{
    double a, b;
    Datum d; 
    a = ((Symbol  *)*pc++)->u.num;
    b = ((Symbol  *)*pc++)->u.num;
    if(flag)
        d.val = cmalloc(a, -b);
    else
        d.val = cmalloc(a, b);
    flag = 0;
    push(d);
}

void constpush() /*meter una constante a la pila*/
{
    Datum d;
    double a;
    a = ((Symbol  *)*pc++)->u.num;
    d.val = cmalloc(a, 0);
    push(d);
}

void imagipush()
{
	Datum d;
    double a = 1.0;
    if (flag == 0)
    	a = ((Symbol  *)*pc++)->u.num;
    d.val = cmalloc(0, a);
    flag = 0;
    push(d);	
}

void varpush() /*meter una variable a la pila*/
{
    Datum d;
    d.sym = (Symbol *)(*pc++);
    push(d);
}
void whilecode()
{
	Datum d;
	Inst *savepc = pc; /*cuerpo de la iteraci�n*/
	execute(savepc + 2); /*condici�n*/	
	d = pop();
	while (d.val->real)
	{
		execute(*((Inst **)(savepc)));     /*cuerpo*/
		execute(savepc + 2);
		d = pop();
	} 
	pc = *((Inst  **)(savepc+1)); /*siguiente proposici�n*/
}

void ifcode()
{
	Datum d;
	Inst *savepc = pc; /*parte then*/
	execute(savepc + 3); /* condici�n */
	d = pop();
	if(d.val->real) execute(*((Inst **)(savepc)));
	else if (*((Inst **)(savepc + 1))) /*�parte else?*/
	execute(*(( Inst **) (savepc + 1)));
	pc = *((Inst **)(savepc + 2));	/*siguiente proposici�n*/
}

void eval() /*evaluar una variable en la pila*/
{
	Datum d;
	d = pop();
	if (d.sym->type == UNDEF) execerror("undefined variable", d.sym->name);
	d.val = d.sym->u.val;
	push(d);
}

void ADD() /*sumar los dos elementos superiores de la pila*/
{
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = complexAdd(d1.val, d2.val);
    push(d1);
}

void SUB()
{
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = complexSub(d1.val, d2.val);
    push(d1);
}

void MUL()
{
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = complexMul(d1.val, d2.val);
    push(d1);
}


void DIV() //Division
{
    Datum d1, d2;
    d2 = pop();
    if (d2.val->real == 0.0 && d2.val->imag == 0.0)
        execerror("division by zero", (char *)0);
    d1 = pop();
    d1.val = complexDiv(d1.val, d2.val);
    push(d1);
}

void negate()
{
    Datum d;
    d = pop();
    d.val = cmalloc(-d.val->real, -d.val->imag);
    push(d);
}

void cflag()
{
    flag = 1;
}

void power()
{
    Datum d1, d2;
    d2 = pop();
    d1 = pop();
    d1.val = complexPow(d1.val, d2.val);
    push(d1);
}

void gt()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real > d2.val->real);
	push(d1);
}

void lt()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real < d2.val->real);
	push(d1);
}

void ge()
{
	Datum d1, d2;
	d2  = pop();
	d1  = pop();
	d1.val->real = (double)(d1.val->real >= d2.val->real);
	push(d1) ;
}

void le()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real <= d2.val->real);
	push(d1);
}

void eq()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real == d2.val->real);
	push(d1);
}

void ne()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real != d2.val->real);
	push(d1);
}

void and()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real != 0.0 && d2.val->real != 0.0);
	push(d1);
}

void or()
{
	Datum d1, d2;
	d2 = pop();
	d1 = pop();
	d1.val->real = (double)(d1.val->real != 0.0 || d2.val->real != 0.0);
	push(d1);
}

void not()
{
	Datum d;
	d = pop();
	d.val->real = (double)(d.val->real == 0.0);
	push(d);
}

void assign()        /* asignar el valor superior al siguientevalor */ 
{
	Datum d1, d2;
	d1 = pop();
	d2 = pop();
	if (d1.sym->type != VAR && d1.sym->type != UNDEF) 
		execerror("assignment to non-variable", d1.sym->name);
	d1.sym->u.val = d2.val;
	d1.sym->type = VAR;
	push(d2); 
} 

void print() /*sacar el valor superior de la pila e imprimirlo */
{
    Datum d;
    d = pop();
    printc(d.val);
}

void prexpr() /*sacar el valor superior de la pila e imprimirlo */
{
    Datum d;
    d = pop();
    printc(d.val);
}


void bltin() /*evaluar un predefinido en el tope de la pila*/
{
    Datum d;
    d = pop();
    d.val = (*(complex *(*)())(*pc++))(d.val);
    push(d);
}
 
Inst *code(Inst f) /*instalar una instrucci�n u operando*/
{
	Inst *oprogp = progp;
	if (progp >= &prog[NPROG])
		execerror("program too big", (char *) 0);
	*progp++ = f;
	return oprogp;
}

void execute(Inst *p) /*ejecuci�n con la m�quina*/
{
	for  (pc = p; *pc != STOP;)
		(*(*pc++))();
}

