CC = gcc
INCLUDES =
CFLAGS = -g -WALL -I.
LDFLAGS = -g
LDLIBS = -lm

main: main.o MyLinkedList.o
	$(CC) -o main main.o MyLinkedList.o

main.o: main.c MyLinkedList.h
	$(CC) -c main.c

MyLinkedList.o: MyLinkedList.c MyLinkedList.h
	$(CC) -c MyLinkedList.c

.PHONY: clean
clean: 
	rm -f *.o main
.PHONY: all
all: clean main
	
