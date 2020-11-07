#include "complejo_cal.h"

Complejo *creaComplejo(double real, double img)
{
	Complejo *nvo = (Complejo*)malloc(sizeof(Complejo));
	nvo->real = real;
	nvo->img = img;
	return nvo;
}

Complejo *Complejo_add(Complejo *c1, Complejo *c2)
{
	return creaComplejo(c1->real + c2->real, c1->img + c2->img);
}

Complejo *Complejo_sub(Complejo *c1, Complejo *c2)
{
	return creaComplejo(c1->real - c2->real, c1->img - c2->img);
}

Complejo *Complejo_mul(Complejo *c1, Complejo *c2)
{
	return creaComplejo( c1->real*c2->real - c1->img*c2->img, c1->img*c2->real + c1->real*c2->img);
}

Complejo *Complejo_div(Complejo *c1, Complejo *c2)
{
	double d = c2->real * c2->real + c2->img * c2->img;
	return creaComplejo( (c1->real*c2->real + c1->img*c2->img) / d, (c1->img*c2->real - c1->real*c2->img) / d);
}

Complejo *Complejo_pot(Complejo *c, int pot)
{
	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < pot; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}
Complejo *Complejo_sin(Complejo *c)
{
	return creaComplejo(sin(c->real) * cosh(c->img), cos(c->real) * sinh(c->img));
}

Complejo *Complejo_cos(Complejo *c)
{
	return creaComplejo(cos(c->real) * cosh(c->img), -(sin(c->real) * sinh(c->img)));
}

Complejo *Complejo_tan(Complejo *c)
{
	if (Complejo_cos(c) == 0)
		return 0;

	return Complejo_div (Complejo_sin(c), Complejo_cos(c));
}

Complejo *Complejo_log(Complejo *c)
{
	if (c->real == 0)
		return 0; 	
	return creaComplejo(log(Complejo_fabs(c)->real), atan(c->img / c->real));
}

Complejo *Complejo_log10(Complejo *c)
{
	return Complejo_div(Complejo_log(c), creaComplejo(log(10), 0));
}

Complejo *Complejo_exp(Complejo *c)
{
	return creaComplejo(exp(c->real) * cos(c->img), exp(c->real) * sin(c->img));
}

Complejo *Complejo_sqrt(Complejo *c)
{
	if (c->img >= 0)
		return creaComplejo(sqrt((Complejo_add(Complejo_fabs(c), creaComplejo(c->real, 0)))->real / 2), sqrt((Complejo_sub(Complejo_fabs(c), creaComplejo(c->real, 0)))->real / 2));
	else
		return creaComplejo(sqrt((Complejo_add(Complejo_fabs(c), creaComplejo(c->real, 0)))->real / 2), -(sqrt((Complejo_sub(Complejo_fabs(c), creaComplejo(c->real, 0)))->real / 2)));
}

Complejo *Complejo_fabs(Complejo *c)
{
	return creaComplejo(sqrt((c->real * c->real) + (c->img * c->img)), 0);
}

void imprimirC(Complejo *c)
{
	if (c->real != 0 && c->img != 0)
	{
		if (c->img != 1 && c->img != -1)
			(c->img > 0) ? printf("%.6f + %.6fi\n", c->real, c->img) : printf("%.6f - %.6fi\n", c->real, -c->img);
		else
			(c->img == 1) ? printf("%.6f + i\n", c->real, c->img) :  printf("%.6f - i\n", c->real, c->img);
	}
	else
	{
		if (c->real == 0)
		{
			if (c->img != 1 && c->img != -1)
				printf("%.6fi\n", c->img);
			else
				(c->img == 1) ? printf("i\n") : printf("-i\n");
		}
		else
			printf("%.6f\n", c->real);
	}
}

