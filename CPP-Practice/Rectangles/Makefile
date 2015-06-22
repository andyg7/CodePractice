CC=g++

main: Rectangle.o
	$(CC) Rectangle.o -o main
Rectangle.o: Rectangle.cpp
	$(CC) -c Rectangle.cpp
.PHONY: clean
clean:
	rm -f *.o *~ a.out core hello
.PHONY: all
all: clean main
