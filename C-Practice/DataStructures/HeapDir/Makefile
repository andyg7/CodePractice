CC=gcc
INCLUDES= -I/Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/QueueDir
CFLAGS= -g -Wall
LDFLAGS= -g
LDLIBS= -lm

main: main.o MyHeap.o  /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/QueueDir/MyQueue.o
	$(CC) $(LDFLAGS) main.o MyHeap.o /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/QueueDir/MyQueue.o -o main $(LDLIBS)

main.o: main.c /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/QueueDir/MyQueue.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c

MyHeap.o: MyHeap.c MyHeap.h /Users/andrewgrant/Desktop/Coding-Practice/C-Practice/DataStructures/QueueDir/MyQueue.h
	$(CC) $(CFLAGS) $(INCLUDES) -c MyHeap.c

.PHONY: clean
clean:
	rm -f *.o main

.PHONY: all
all: clean main 
