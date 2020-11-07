yacc -d hoc.y
gcc y.tab.c init.c math.c symbol.c Code.c complex.c -o cmplx -lm