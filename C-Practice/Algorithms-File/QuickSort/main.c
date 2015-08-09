#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int processInput(const char * input);
int sizeOfInput(const char * input);
typedef int bool;
#define true 1
#define false 0
bool validInput(const char * input);
int numOfElements(const char *input);
void createArray(int * ar, char * input, int size);
int stringToInt(const char * c);
void printArray(const int * ar, int size);
int getPivot(const int * ar, int a, int b);
int processInput(const char * input);
void sort(int * ar, int i0, int i1, int size);
void swap(int * ar, int i0, int i1);

int main(int argc, char ** argv) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];

	while(fgets(line, 1024, file)) {

		int arraySize = processInput(line);	
		int *array;
		bool validInput = false;
		if(arraySize == -1) {
			printf("%s\n", "invalid input");
		} else {
			validInput = true;
		}

		if(validInput == true) {
			array = (int *) malloc(arraySize * sizeof(int));
			if(array == NULL) {
				perror("malloc failed");
				exit(1);
			}
			createArray(array, line, arraySize);
			printf("%s\n", "before sorting");
			printArray(array, arraySize);
			int lastIndex = arraySize - 1;
			int firstPivot = getPivot(array, 0, lastIndex);
			sort(array, 0, lastIndex, arraySize);
			printf("%s\n", "after sorting");
			printArray(array, arraySize);

		}

		if(validInput == true) {
			free(array);
		}	

	}

	return 0;
}

void sort(int * ar, int i0, int i1, int s) {

	int size = s;
	int x0;
	int x1;
	int lowOpen;
	int upOpen;
	int counter;
	int inPlaceIndex;

	bool keepSorting = true;

	if(i0 == i1) {
		keepSorting = false;
	}

	if(keepSorting == true) {
		x0 = *(ar + i0);
		x1 = *(ar + i1);

		if(i0 + 1 == i1) {
			if(x0 > x1) {
				swap(ar, i0, i1);
			}
			keepSorting = false;
		}

		lowOpen = i0;
		upOpen = i1 - 1;
		counter = i0;

	}

	if(keepSorting == true) {
		int pivotIndex = getPivot(ar, i0, i1);
		int pivot = *(ar + pivotIndex);
		swap(ar, pivotIndex, i1);
		while(lowOpen != upOpen) {
			int currentInt = *(ar + counter);
			if(currentInt > pivot) {
				swap(ar, counter, upOpen);
				upOpen--;
			} else {
				counter++;
				lowOpen++;
			}

		}
		int midIndex = lowOpen;
		int mid = *(ar + midIndex);
		if(mid > pivot) {
			swap(ar, i1, midIndex);
			inPlaceIndex = midIndex;
		} else {
			swap(ar, i1, midIndex + 1);
			inPlaceIndex = midIndex + 1;
		}

		int leftListIndex = inPlaceIndex - 1;
		int rightListIndex = inPlaceIndex + 1;

		if(i0 <= leftListIndex) {
			sort(ar, i0, leftListIndex, size);
		}
		if(i1 >= rightListIndex) {
			sort(ar, rightListIndex, i1, size);
		}

	}

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

void createArray(int * ar, char * input, int size) {

	int counter = 0;
	char currentChar;
	char delim[2] = " ";
	char *token;

	token = strtok(input, delim);

	while(token != NULL) {
		int num = stringToInt(token);
		*(ar + counter) = num;
		counter++;
		token = strtok(NULL, delim);
	}

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

void printArray(const int * ar, int size) {

	for(int i = 0; i < size; i++) {
		printf("%d ", *(ar + i));
	}
	printf("%c", '\n');

}


int getPivot(const int * ar, int a, int b) {

	int midIndex = (a + b) / 2;
	int x0 = *(ar + a);
	int x1 = *(ar + midIndex);
	int x2 = *(ar + b);

	int pivot;
	if(x0 >= x1) {
		if(x2 >= x0) {
			pivot = a;	
		} else if(x2 <= x1) {
			pivot = midIndex;
		} else {
			pivot = b;
		}
	} else if(x2 >= x1){
		pivot = midIndex;
	} else if(x2 <= x0) {
		pivot = a;
	} else {
		pivot = b;
	}

	return pivot;
}



void swap(int * ar, int i0, int i1) {

	int x0 = *(ar + i0);
	int x1 = *(ar + i1);

	*(ar + i0) = x1;
	*(ar + i1) = x0;

}
