#include "complex.h"

complex *cmalloc(double real, double imag)
{
	complex *tmp = (complex *)malloc(sizeof(complex));
	tmp->real = real;
	tmp->imag = imag;
	return tmp;
}

complex *complexAdd(complex *c1, complex *c2)
{
	return cmalloc(c1->real + c2->real, c1->imag + c2->imag);
}

complex *complexSub(complex *c1, complex *c2)
{
	return cmalloc(c1->real - c2->real, c1->imag - c2->imag);
}

complex *complexMul(complex *c1, complex *c2)
{
	return cmalloc( c1->real*c2->real - c1->imag*c2->imag, c1->imag*c2->real + c1->real*c2->imag);
}

complex *complexDiv(complex *c1, complex *c2)
{
	double d = c2->real * c2->real + c2->imag * c2->imag;
	return cmalloc( (c1->real*c2->real + c1->imag*c2->imag) / d, (c1->imag*c2->real - c1->real*c2->imag) / d);
}

complex *complexPow(complex *b, complex *exp)
{
	int i, pot = exp->real;

	complex *aux;
	aux = b;
	for (i = 1; i < pot; i++)
		aux = complexMul(b, aux);
	
	return aux;
}
complex *complexSin(complex *c)
{
	return cmalloc(sin(c->real) * cosh(c->imag), cos(c->real) * sinh(c->imag));
}

complex *complexCos(complex *c)
{
	return cmalloc(cos(c->real) * cosh(c->imag), -(sin(c->real) * sinh(c->imag)));
}

complex *complexTan(complex *c)
{
	if (complexCos(c) == 0)
		return 0;

	return complexDiv (complexSin(c), complexCos(c));
}

complex *complexLog(complex *c)
{
	if (c->real == 0) return 0;
	return cmalloc(log(complexAbs(c)->real), atan(c->imag / c->real));
}

complex *complexLog10(complex *c)
{
	return complexDiv(complexLog(c), cmalloc(log(10), 0));
}

complex *complexExp(complex *c)
{
	return cmalloc(exp(c->real) * cos(c->imag), exp(c->real) * sin(c->imag));
}

complex *complexSqrt(complex *c)
{
	if (c->imag >= 0)
		return cmalloc(sqrt((complexAdd(complexAbs(c), cmalloc(c->real, 0)))->real / 2), sqrt((complexSub(complexAbs(c), cmalloc(c->real, 0)))->real / 2));
	else
		return cmalloc(sqrt((complexAdd(complexAbs(c), cmalloc(c->real, 0)))->real / 2), -(sqrt((complexSub(complexAbs(c), cmalloc(c->real, 0)))->real / 2)));
}

complex *complexAbs(complex *c)
{
	return cmalloc(sqrt((c->real * c->real) + (c->imag * c->imag)), 0);
}

void printc(complex *c)
{
	if (c->real != 0 && c->imag != 0)
	{
		if (c->imag != 1 && c->imag != -1)
			(c->imag > 0) ? printf("%.6f + %.6fi\n", c->real, c->imag) : printf("%.6f - %.6fi\n", c->real, -c->imag);
		else
			(c->imag == 1) ? printf("%.6f + i\n", c->real) :  printf("%.6f - i\n", c->real);
	}
	else
	{
		if (c->real == 0 && c->imag == 0) printf("%.6f\n", c->real);
		else if (c->real == 0)
		{
			if (c->imag != 1 && c->imag != -1) printf("%.6fi\n", c->imag);
			else (c->imag == 1) ? printf("i\n") : printf("-i\n");
		}
		else printf("%.6f\n", c->real);
	}
}
