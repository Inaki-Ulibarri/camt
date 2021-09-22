camt: camt.o camt.h
	gcc -Wall -Wextra -pedantic camt.c camt.h -o camt
	
camt.o: camt.c
	gcc -Wall -Wextra -pedantic camt.c
	
