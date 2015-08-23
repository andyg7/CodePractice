CC=gcc
INCLUDES=
CFLAGS= -g -Wall
LDFLAGS= -g
LDLIBS= -lm

main: main.o
	$(CC) main.o -o main

main.o: main.c
	$(CC) -c main.c

.PHONY: clean
clean:
	rm -f *.o main

.PHONY: all
all: clean main
