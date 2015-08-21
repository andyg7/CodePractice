#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MyQueue.h"
#include "MyHeap.h"

bool validInput(const char * input);
int numOfElements(const char *input);
int stringToInt(const char * c);
int processInput(const char * input);
int sizeOfInput(const char * input);

int main(int argc, char **argv) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];

	bool firstRun = true;

	while(fgets(line, 1024, file)) {

		if(firstRun == true) {
			firstRun = false;
		} else {
			printf("%c", '\n');
		}

		int numOfNums = processInput(line);
		bool validInput = false;
		if(numOfNums == -1) {
			printf("%s\n", "Invalid input");
		} else {
			printf("%s %s", "Before sorting: ", line);
			validInput = true;
			struct HeapNode *heapRoot = NULL;
			int currentInt;
			char delim[2] = " ";
			char *token = strtok(line, delim);
			while(token != NULL) {
				currentInt = stringToInt(token);
				token = strtok(NULL, delim);
				addHeapNode(&heapRoot, currentInt);
			}
			printf("%s", "After sorting: ");
			sort(&heapRoot);
			freeHeap(&heapRoot);
		}

	}
	return 0;
}

int processInput(const char * input) {

	bool val = validInput(input);
	if(val == 1) {
		//printf("%s\n", "valid input");
	} else {
		//printf("%s\n", "invalid input");
	}

	if(val == 0) {
		return -1;
	} else {
		int elems = numOfElements(input);
		return elems;
	}
}

int sizeOfInput(const char * input) {

	int counter = 0;
	char currentChar = *input;
	while(currentChar != '\n' && currentChar != '\0') {

		counter++;
		currentChar = *(input + counter);
	}
	return counter;
}

bool validInput(const char * input) {

	bool prevSpace = true;
	bool valid = true;
	int length = sizeOfInput(input);

	for(int i = 0; i < length; i++) {

		char c = *(input + i);

		if(c == ' ') {
			if(prevSpace == true || i == length - 1) {
				valid = false;
				i = length;
			} else {
				prevSpace = true;
			}
		} else {
			prevSpace = false;
			int num = c - '0';
			if(num >9 || num < 0) {
				valid = false;
				i = length;
			}
		}
	}

	return valid;
}

int numOfElements(const char *input) {

	int length = sizeOfInput(input);
	int counter = 0;
	int numOfElems = 0;
	char currentChar = *(input);
	for(int i = 0; i < length; i++) {
		if(currentChar == ' ') {
			numOfElems++;
		}
		currentChar = *(input + counter);
		counter++;
	}

	numOfElems++;

	return numOfElems;
}

int stringToInt(const char * c) {

	int result = 0;

	int counter = 0;

	char currentChar = *(c);
	while(currentChar != '\n' && currentChar != '\0') {
		int num = currentChar - '0';
		result = result * 10;
		result = result + num;
		counter++;
		currentChar = *(c + counter);
	}

	return result;
}
