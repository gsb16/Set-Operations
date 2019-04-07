CFLAGS = -Wall -O2

conjuntos: conjuntos.o funcconj.o
	gcc  -O2 conjuntos.o funcconj.o   -o conjuntos

conjuntos.o: conjuntos.c
funcconj.o: funcconj.c funcconj.h

clean:
	rm -f *.o

purge: clean
	rm -f conjuntos
