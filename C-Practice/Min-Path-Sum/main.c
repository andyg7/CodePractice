/*

   Codeeval Mininmun Path Sum
   Andrew Grant

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef int bool;
void makeArray(int * pt, char * c, int index, int r);
int stringToInt(char * c);
void printMatrix(int * pt, int r, int c);
int getElement(int * pt, int r, int c, int x, int y);
bool validIndex(int r, int c, int x, int y);
bool foundPath(int * pt, int r, int c);
int getX(int r, int c, int i);
int getY(int r, int c, int i);
int findMinPath(int * matrix,int * minPaths, int r, int c);
void initializeMinPaths(int * pt, int r, int c);
int getIndex(int r, int c, int x, int y);
/*

   Finds the minimum sum path from the top left of the matrix to the bottom right of the
   matrix


 */
int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	bool firstRun = true;
	while (fgets(line, 1024, file)) {
		// Do something with the line
		if(firstRun == true) {
			firstRun = false;
		} else {
			printf("%c", '\n');
		}
		int matrixSize = stringToInt(line);
		int numOfElements = matrixSize * matrixSize;
		/*

		   Pointer used to represent 2D Array
		   @arr the 2D array input
		   @minPaths the minimum path to each element in the matrix

		 */

		int * arr = (int *)malloc(numOfElements * sizeof(int));
		int * minPaths = (int *)malloc(numOfElements * sizeof(int));
		if(arr == NULL || minPaths == NULL) {
			perror("malloc failed");
			exit(1);
		}

		initializeMinPaths(minPaths, matrixSize, matrixSize);

		for(int i = 0; i < matrixSize; i++) {
			if(fgets(line, 1024, file) != NULL) {
				makeArray(arr, line, i, matrixSize);
			}
		}

		
		int minPathCost = findMinPath(arr, minPaths, matrixSize, matrixSize); 
		printf("%d", minPathCost);

		free(arr);
		free(minPaths);
	}
	return 0;
} 

int findMinPath(int * matrix,int * minPaths, int r, int c) {

	int firstElement = *(matrix);
	int rows = r;
	int columns = c;
	int numOfElems = rows * columns;

	*(minPaths) = firstElement;

	int tempCounter = 0;
	bool foundMinPath = false;

	while(foundMinPath == false) {

		int currentMin = -1;
		int currentIndex = -1;

		for(int i = 0; i < numOfElems; i++) {

			if(*(minPaths + i) != -1) {
				int currentX = getX(rows, columns, i);
				int currentY = getY(rows, columns, i);
				int currentSum = *(minPaths + i); 

				int rightX = currentX + 1;
				int rightY = currentY;
				if(validIndex(rows, columns, rightX, rightY) == true) {
					int rightIndex = getIndex(rows, columns, rightX, rightY);
					if(*(minPaths + rightIndex) == -1 ) {
						int rightCost = getElement(matrix, rows, columns, rightX, rightY);
						int tempSum = currentSum + rightCost;
						if(currentMin == -1 || tempSum < currentMin) {
							currentMin = tempSum;
							currentIndex = rightIndex;	
						}
					}

				}

				int downX = currentX;
				int downY = currentY + 1;
				if(validIndex(rows, columns, downX, downY) == true) {
					int downIndex = getIndex(rows, columns, downX, downY);
					if(*(minPaths + downIndex) == -1 ) {
						int downCost = getElement(matrix, rows, columns, downX, downY);
						int tempSum = currentSum + downCost;
						if(currentMin == -1 || tempSum <
								currentMin) {
							currentMin = tempSum;
							currentIndex = getIndex(rows, columns, downX, downY);
						}


					}
				}
			}

		}

		*(minPaths + currentIndex) = currentMin;	

		foundMinPath = foundPath(minPaths, rows, columns);
		if(foundMinPath == false) {
			//printf("%s\n", "still looking");
		}
	}

	int result = *(minPaths + numOfElems - 1);

	return result;
}

void makeArray(int * pt, char * c, int index, int r) {

	int column = 0;
	char delim[2] =",";
	char *seg= strtok(c, delim);
	while(seg != NULL) {
		int firstNum = stringToInt(seg);
		*(pt + (index * r) + column) = firstNum;
		column++;	
		seg = strtok(NULL, delim);

	}
}

void initializeMinPaths(int * pt, int r, int c) {

	int numOfElements = r * c;
	for(int i = 0; i < numOfElements; i++) {
		*(pt + i) = -1; 
	}

}

int stringToInt(char * c) {

	int result = 0;
	int counter = 0;
	while(*(c + counter) != '\n' && *(c + counter) != '\0') {
		char tempChar = *(c + counter);
		int tempInt = tempChar - '0';
		result = result * 10;
		result = result + tempInt;
		counter++;
	}

	return result;
}

void printMatrix(int * pt, int r, int c) {

	for(int i = 0; i < r; i++) {
		for(int a = 0; a < c; a++) {
			int element = *(pt + (i*c) + a);
			printf("%d %s", element, " ");
		}
		printf("%c", '\n');
	}
}

int getElement(int * pt, int r, int c, int x, int y) {

	int element = *(pt + (y*c) + x);	
	return element;
}

bool validIndex(int r, int c, int x, int y) {

	if(x < 0) {
		return false;
	}

	if(x >= c) {
		return false;
	}

	if(y < 0) {
		return false;
	}

	if(y >= r) {
		return false;
	}

	return true;
}

bool foundPath(int * pt, int r, int c) {

	int maxIndex = (r * c) - 1;
	if(*(pt + maxIndex) == -1) {
		return false;
	}

	return true;
}

int getX(int r, int c, int i) {

	int x = i % c;

	return x;
}


int getY(int r, int c, int i) {

	int y = i / c;
	return y;
}

int getIndex(int r, int c, int x, int y) {

	int index = y * c;
	index = index + x;

	return index;
}
