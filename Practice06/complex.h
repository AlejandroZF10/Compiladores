#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct complex
{
	double real, imag;
} complex;

void printc(complex *c);
complex *complexSin(complex *);
complex *complexCos(complex *);
complex *complexTan(complex *);
complex *complexLog(complex *);
complex *complexExp(complex *);
complex *complexAbs(complex *);
complex *complexQuit(complex *);
complex *complexSqrt(complex *);
complex *complexLog10(complex *);
complex *complexAdd(complex *, complex *);
complex *complexSub(complex *, complex *);
complex *complexMul(complex *, complex *);
complex *complexDiv(complex *, complex *);
complex *complexPow(complex *, complex *);
complex *cmalloc(double real, double imag);
