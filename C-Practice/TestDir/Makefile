CC = gcc
INCLUDES = -I /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir
CFLAGS = -g -Wall
LDFLAGS = -g 
LDLIBS = -lm  

main: main.o MyLinkedList.o
	$(CC) $(LDFLAGS) main.o MyLinkedList.o -o main $(LDLIBS)

main.o: main.c /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

MyLinkedList.o: /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.c  /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.h
	$(CC) $(CFLAGS) -c /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.c

.PHONY: clean
clean:
	rm -f *.o main

.PHONY: all
all: clean main
