CC = gcc
INCLUDES = 
CFLAGS = 
LDFLAGS = 
LDLIBS = 

main: main.o MyString.o
	$(CC) main.o MyString.o -o main
main.o: main.c MyString.h
	$(CC) -c main.c
MyString.o: MyString.c MyString.h
	$(CC) -c MyString.c

.PHONY: clean
clean:
	rm -f *.o main
.PHONY: all
all: clean main
