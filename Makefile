CC = gcc
CHECKFLAGS = -lcheck -lm -lsubunit

.PHONY: all run test clean leaks

all: calc_path run

calc_path: main.o logic.o
	$(CC) main.o logic.o -o calc_path

main.o: main.c logic.h
	$(CC) -c main.c

logic.o: logic.c logic.h
	$(CC) -c logic.c

run:
	./calc_path 

test: tests.o logic.o logic.h
	rm -f tests
	$(CC) tests.o logic.o -o tests $(CHECKFLAGS)
	./tests

tests.o: tests.c
	$(CC) -c tests.c


clean:
	rm -f *.o calc_path tests

leaks: 
	valgrind --tool=memcheck --leak-check=yes ./calc_path
