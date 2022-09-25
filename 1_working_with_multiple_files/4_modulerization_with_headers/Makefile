install: date.o main.o
	gcc -o main date.o main.o date.h
build: main.c date.c
	gcc -c date.c main.c
clean:
	rm -f main *.o
