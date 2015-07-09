CC = gcc
INCLUDES = -I../LinkedListDir/
CFLAGS = -g -Wall
LDFLAGS = -g 
LDLIBS = -lm  

main: main.o MyLinkedList.o myadd.o
	$(CC) $(LDFLAGS) main.o MyLinkedList.o myadd.o -o main $(LDLIBS)
main.o: main.c ../LinkedListDir/MyLinkedList.h myadd.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c
MyLinkedList.o: ../LinkedListDir/MyLinkedList.c ../LinkedListDir/MyLinkedList.h
	$(CC) $(CFLAGS) -c ../LinkedListDir/MyLinkedList.c
myadd.o: myadd.c myadd.h
	$(CC) -c myadd.c
.PHONY: clean
clean:
	rm -f *.o main
.PHONY: all
all: clean main
