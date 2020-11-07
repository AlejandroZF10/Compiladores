#include "complejo_cal.h"

Complejo *creaComplejo(int real, int img)
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

	int i;
	Complejo *aux;
	imprimirC(c);
	aux = creaComplejo(1, 4);
	return aux;
}

Complejo *Complejo_cos(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 7; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_tan(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 6; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_log(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 5; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_log10(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 4; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_exp(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 3; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_sqrt(Complejo *c)
{

	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 2; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}

Complejo *Complejo_fabs(Complejo *c)
{
	int i;
	Complejo *aux;
	aux = c;
	for (i = 1; i < 1; i++)
	{
		aux = Complejo_mul(c, aux);
	}
	return aux;
}
void imprimirC(Complejo *c)
{
	if(c->img != 0)
		printf("%.2f% + .2fi\n", c->real, c->img);
   else
		printf("%.2f\n", c->real);
}

