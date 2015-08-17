CC=gcc
INCLUDES=
CFLAGS=-g -Wall
LDFLAGS= -g
LDLIBS= -lm

main: main.o MyQueue.o
	$(CC) main.o MyQueue.o  -o main
main.o: main.c MyQueue.h
	$(CC) -c main.c

MyQueue.o: MyQueue.c MyQueue.h
	$(CC) -c MyQueue.c

.PHONY: clean
clean:
	rm -f *.o main
.PHONY: all
all: clean main
