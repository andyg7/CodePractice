CC=gcc
INCLUDES= -I/Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir
CFLAGS= -g -Wall
LDFLAGS= -g
LDLIBS= -lm

main: main.o /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.o
	$(CC) $(LDFLAGS) main.o /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.o -o main $(LDLIBS)

main.o: main.c /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

MyHeap.o: MyHeap.c MyHeap.h /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/LinkedListDir/MyLinkedList.h
	$(CC) $(CFLAGS) $(INCLUDES) -c MyHeap.c

.PHONY: clean
clean:
	rm -f *.o main

.PHONY: all
all: clean main 
