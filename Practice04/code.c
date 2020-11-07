#include "hoc.h"
#include "y.tab.h"
#define NSTACK 256
#define NPROG 2000

int flag;

static Datum *stackp;         /*siguiente lugar libre en la pila */
static Datum stack[NSTACK];   /*la pila */
Inst prog[NPROG];             /*la maquina */
Inst *progp;                  /*siguiente lugar libre para la generacion de codigo */
Inst *pc;	                  /*contador de programa durante la ejecucion */

void initcode() /*inicializacion para la generacion de codigo */
{
    stackp = stack;
    progp = prog;
}

void push(Datum d)	/*meter d en la pila*/
{
    if (stackp >= &stack[NSTACK]) execerror("stack overflow", (char *) 0);
    *stackp++ = d;
}

Datum pop()/*sacar y retornar de la pila el elemento del tope*/
{
    if (stackp <= stack) execerror("stack underflow", (char *)0);
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

void eval()	/*evaluar una variable en la pila*/
{
    Datum d;
    d = pop();
    if (d.sym->type == INDEF)
        execerror("undefined variable", d.sym->name);
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


void assign() /*asignar el valor superior al siguientevalor*/
{
    Datum d1, d2;
    d1 = pop();
    d2 = pop();
    if (d1.sym->type != VAR && d1.sym->type != INDEF)
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

void bltin() /*evaluar un predefinido en el tope de la pila*/
{
    Datum d;
    d = pop();
    d.val = (*(complex *(*)())(*pc++))(d.val);
    push(d);
}

Inst *code(Inst f) /*instalar una instruccion u operando*/
{
    Inst *oprogp = progp;
    if (progp >= &prog [NPROG])
		    execerror("program too big", (char *) 0);
    *progp++ = f;
    return oprogp;
}

void execute(Inst *p) /*ejecucion con la maquina*/
{
    for (pc = p; *pc != STOP; )
	     (*(*pc++))();
}
