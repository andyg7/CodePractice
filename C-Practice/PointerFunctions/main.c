#include<stdio.h>
#include<stdlib.h>

int compareInts(const void * v1, const void * v2);

int main(int argc, const char ** argv) {

	int ints[] = {10, 3, 17, 20, 9};

	int numOfElements = 5;
	int sizeOfElements = sizeof(ints[0]);
	//qsort(ints, numOfElements, sizeOfElements, &compareInts);

/*
	for(int i = 0; i < numOfElements; i++) {
		printf("%d\n", ints[i]);
	}
*/

	int (*func1)(const void *v1, const void *v2);
	func1 = &compareInts;
	
	qsort(ints, numOfElements, sizeOfElements, func1);

	for(int i = 0; i < numOfElements; i++) {
		printf("%d\n", ints[i]);
	}

	return 0;
}

int compareInts(const void * v1, const void * v2) {

	int x = *(int *)v1;
	int y = *(int *)v2;

	if(x > y) {
		return 1;
	}
	 
	if(x < y) {
		return -1;
	}

	return 0;
}
