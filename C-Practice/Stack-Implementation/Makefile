main: main.o
	gcc -o main main.o
main.o: main.c
	gcc -c main.c
.PHONY: clean
clean:
	rm -f *.o *~ a.out core main
.PHONY: all
all: clean main