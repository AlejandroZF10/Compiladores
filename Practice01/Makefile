Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o comp y.tab.c  
	@echo Compiled

$(Gram): complejo_cal.y
	@yacc -d complejo_cal.y

clean:
	@rm -f *.out  *.tab.* comp
	@echo Clean
