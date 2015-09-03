/*
   Codeeval.com solution to "WHICH WAY IS FASTER?" problem.
 */

#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
bool validIndex(int x, int y, int dx, int dy);
int getXBFS(int counter, int dx, int dy);
int getYBFS(int counter, int dx, int dy);
int squareRootInt(int x);
static const int WIDTH = 4;
static const int HEIGHT = 4;

void printArray(char ar[WIDTH][HEIGHT]);
void processInput(const char * line, char ar[WIDTH][HEIGHT]);


int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line, 1024, file)) {
		// Do something with the line
		printf("%s", line);
		char inputMatrix[WIDTH][HEIGHT];
		processInput(line, inputMatrix);
		printArray(inputMatrix);
	}

	fclose(file);
	return 0;
}


bool validIndex(int x, int y, int dw, int dh) {

	if(x < 0) {
		return false;
	}

	if(y < 0) {
		return false;
	}

	if(x > (dw - 1)) {
		return false;
	}

	if(y > (dh - 1)) {
		return false;
	}

	return true;
}

int getXBFS(int counter, int dx, int dy) {

	int x;
	int sqr = squareRootInt(counter);
	int lowerRange = sqr * sqr;
	int upperRange = (((sqr + 1) * (sqr + 1)) - 1);
	int range = upperRange - lowerRange + 1;
	int midRange = (range / 2) + lowerRange;
	if(counter < midRange) {
		x =  counter - lowerRange;
	} else {
		x = sqr;
	}
	return x;
}

int getYBFS(int counter, int dx, int dy) {

	int y;
	int sqr = squareRootInt(counter);
	int lowerRange = sqr * sqr;
	int upperRange = (((sqr + 1) * (sqr + 1)) - 1);
	int range = upperRange - lowerRange + 1;
	int midRange = (range / 2) + lowerRange;
	if(counter > midRange) {
		y =  upperRange - counter;
	} else {
		y = sqr;
	}
	return y;
}

int squareRootInt(int x) {

	int counter = 0;
	int square = counter * counter;
	while(square <= x) {

		counter++;
		square = counter * counter;
	}

	counter--;
	square = counter * counter;
	return counter;
}

void processInput(const char * line, char ar[WIDTH][HEIGHT]) {
	int numOfElements = WIDTH * HEIGHT;

	for(int i = 0; i < 4; i++) {
		int counter = ((HEIGHT - 1) * (HEIGHT - 1));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
			}

	for(int i = 7; i < 11; i++) {
		int counter = ((HEIGHT - 2) * (HEIGHT - 2));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 7;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}

	for(int i = 14; i < 18; i++) {
		int counter = ((HEIGHT - 3) * (HEIGHT - 3));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 14;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}

	for(int i = 21; i < 25; i++) {
		int counter = ((HEIGHT - 4) * (HEIGHT - 4));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 21;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}
}

void printArray(char ar[WIDTH][HEIGHT]) {

	printf("%s\n", "Printing Array: ");

	for(int i = HEIGHT - 1; i >= 0; i--) { 

		for(int k = 0; k < WIDTH; k++) {
			printf("%c ", ar[k][i]);
		}
		printf("%c", '\n');
	}
}
