CC = gcc
INCLUDES =
CFLAGS = -g -Wall
LDFLAGS = -g 
LDLIBS = -lm  

main: main.o
	$(CC) $(LDFLAGS) main.o -o main $(LDLIBS)

main.o: main.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c


clean:
	rm -f *.o main

.PHONY: all
all: clean main
