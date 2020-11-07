yacc -d complex.y
gcc y.tab.c init.c math.c symbol.c code.c complex.c -o cmplx -lm
./cmplx