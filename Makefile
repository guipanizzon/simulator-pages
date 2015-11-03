PARAMS=-g -lm -c -Wall

all: pagesim

pagesim: main.o
	gcc main.o -o pagesim

main.o: main.c
	gcc $(PARAMS) main.c

clean:
	rm *~ *.o pagesim; clear;

god:
	make clean; make;