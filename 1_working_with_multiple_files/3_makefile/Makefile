build: main.o test.o
	gcc main.o test.o -o out

test: main.c test.c
	gcc -c test.c main.c test.h
clean: 
	rm -f out *.o
