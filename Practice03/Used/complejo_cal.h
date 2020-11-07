#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct complex {
  double real, img;
};
typedef struct complex Complejo;
typedef struct complex *ComplejoAP;
Complejo *creaComplejo(int real, int img);
Complejo *Complejo_add(Complejo *, Complejo *);
Complejo *Complejo_sub(Complejo *, Complejo *);
Complejo *Complejo_mul(Complejo *, Complejo *);
Complejo *Complejo_div(Complejo *, Complejo *);
Complejo *Complejo_pot(Complejo *, int);
Complejo *Complejo_sin(Complejo *);
Complejo *Complejo_cos(Complejo *);
Complejo *Complejo_tan(Complejo *);
Complejo *Complejo_log(Complejo *);
Complejo *Complejo_log10(Complejo *);
Complejo *Complejo_exp(Complejo *);
Complejo *Complejo_sqrt(Complejo *);
Complejo *Complejo_fabs(Complejo *);
void imprimirC(Complejo *c);