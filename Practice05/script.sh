yacc -d hoc.y
gcc y.tab.c init.c math.c symbol.c code.c complex.c -o cmplx -lm