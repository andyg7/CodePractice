main: main.o
	g++ main.o -o main
main.o: main.cpp
	g++ -c main.cpp
.PHONY: clean
clean:
	rm -f *.o a.out core hello
.PHONY: all
all: clean main
