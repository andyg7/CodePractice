CC=g++

hello: hello.o MyBike.o
	$(CC) hello.o MyBike.o -o hello
hello.o: hello.cpp MyBike.h
	$(CC) -c hello.cpp
MyBike.o: MyBike.cpp MyBike.h
	$(CC) -c MyBike.cpp
.PHONY: clean
clean:
	rm -f *.o *~ a.out core hello
.PHONY: all
all: clean main