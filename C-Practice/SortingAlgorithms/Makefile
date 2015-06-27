CC=gcc

main: Mergesort.o
	$(CC) -o main Mergesort.o
Mergesort.o: Mergesort.c
	$(CC) -c Mergesort.c
.PHONY: clean
clean:
	rm -f *.o main
.PHONY: all
all: clean main
