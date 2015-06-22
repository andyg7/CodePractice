CC=g++
main: main.o
	$(CC) main.o -o main
main.o: main.cpp
	$(CC) -c main.cpp
.PHONY: clean
clean:
	rm -f *.o *~ a.out core main
.PHONY: all
all: clean main
