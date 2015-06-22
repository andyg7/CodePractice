main: main.o myadd.o
	gcc -o main main.o myadd.o
main.o: main.c
	gcc -c main.c
myadd.o: myadd.c myadd.h
	gcc -c myadd.c
.PHONY: clean
clean:
	rm -f *.o *~ a.out core main
.PHONY: all
all: clean main