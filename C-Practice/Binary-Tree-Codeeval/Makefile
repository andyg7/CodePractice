CC=gcc

main: main.o
	$(CC) -o main main.o
main.o: main.c
	$(CC) -c main.c
.PHONY: clean
clean:
	rm -f *.o *~ core main
.PHONY: all
all: clean main
