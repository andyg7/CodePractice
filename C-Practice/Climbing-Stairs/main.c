#include <stdio.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0

int *testC(int c[]);

int stringToInt(char s[]);
void getRoutes(int b);
double routesToTop = 0;
int numStairs;
int *addArrays(int a[], int b[], int s[]);
int getArraySize(int a[]);
void initializeArray(int a[], int size);

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	bool firstRun = true;
	while (fgets(line, 1024, file)) {
		// Do something with the line

		if(firstRun == false) {
			printf("%c", '\n');
		} else {
			firstRun = false;
	}
		routesToTop = 0;
		int inputLen = strlen(line);
		if(line[inputLen - 1] == '\n') {
			line[inputLen - 1] = '\0';
		}	
		numStairs = stringToInt(line);

		int firstNums[10000];
		initializeArray(firstNums, 10000);
		firstNums[0] = 1;
		firstNums[1] = 2;
		firstNums[2] = 9;
		for(int i = 0; i < getArraySize(firstNums); i++) {
			//printf("%d", firstNums[i]);
		}//printf("%s %d\n", "first array size", getArraySize(firstNums));
		int secondNums[10000];
		initializeArray(secondNums, 10000);
		secondNums[0] = 1;
		secondNums[1] = 8;
		secondNums[2] = 1;
		for(int i = 0; i < getArraySize(secondNums); i++) {
			//printf("%d", secondNums[i]);
		}//printf("%s %d", "second size" ,getArraySize(secondNums));	
	
		int sum[10000];
		initializeArray(sum, 10000);


		addArrays(firstNums, secondNums, sum);

		for(int i = getArraySize(sum) - 1; i >= 0; i--) {
			//printf("%d", sum[i]);
		}

		int smallArry[10000];
		initializeArray(smallArry, 10000);
		smallArry[0] = 0;
		int bigArry[10000];
		initializeArray(bigArry, 10000);
		bigArry[0] = 1;
		int answerArry[10000];
		initializeArray(answerArry, 10000);
		if(numStairs == 0) {
			printf("%d", 0); 
		} else {
			if(numStairs == 1) {
				printf("%d", 1);
			} else {
				for(int i = 0; i < numStairs; i++) {
					addArrays(bigArry, smallArry, answerArry);
					for(int a = 0; a < 10000; a++) {
						smallArry[a] = bigArry[a];
						bigArry[a] = answerArry[a];
					}
				}
				//printf("%.0lf",routesToTop);
			}
		}
		for(int i = getArraySize(answerArry) - 1; i >= 0; i--) {
			printf("%d", answerArry[i]);
		}

	}
	return 0;
} 

void getRoutes(int stairsTaken) {

	int stairsLeft = numStairs - stairsTaken;
	if(stairsLeft > 2) {
		getRoutes(stairsTaken + 2);
		getRoutes(stairsTaken + 1);
	} else {
		switch(stairsLeft) {

			case 1:
				routesToTop = routesToTop + 1;
				break;
			case 2:
				routesToTop = routesToTop + 2;
				break;

		}
	}
}

int stringToInt(char s[]) {

	int len = strlen(s);
	int multiple = 1;
	int stringValue = 0;
	for(int i = 0; i < len; i++) {
		int temp = s[i] - '0';
		stringValue = (stringValue * 10) + temp;
	}
	return stringValue;
}

int *addArrays(int a[], int b[], int s[])  {

	int sizeA = getArraySize(a);
	int sizeB = getArraySize(b);
	int carry = 0;	
	int counter = 0;
	while((a[counter] != -1) || (b[counter] != -1)) {
		if((a[counter] == -1) && (b[counter] == -1)) {

		} else if(a[counter] == -1) {
			int currentB = b[counter];
			int sum = currentB + carry;
			//printf("%s %d\n", "sum here 1", sum);
			if(sum >= 10) {
				carry = 1;	
				s[counter] = sum - 10;
			} else {
				s[counter] = sum;
				carry = 0;
			}
		} else if(b[counter] == -1) {
			int currentA = a[counter];
			//printf("%s %d\n", "a here", currentA);

			int sum = currentA + carry;
			//printf("%s %d\n", "sum here 2", sum);
			if(sum >= 10) {
				carry = 1;	
				s[counter] = sum - 10;
			} else {
				s[counter] = sum;
				carry = 0;
			}
		} else { 
			int currentA = a[counter];
			int currentB = b[counter];
			int sum = currentA + currentB + carry;
			//printf("%s %d\n", "sum here 3", sum);
			if(sum >= 10) {
				carry = 1;	
				s[counter] = sum - 10;
			} else {
				s[counter] = sum;
				carry = 0;
			}
		}
		counter++;
	}
	if(carry != 0) {
		s[counter] = 1;
		}
	return s;
}

int getArraySize(int a[]) {

	int counter = 0;
	while(a[counter] != -1) {
		counter++;
	}
	return counter;
}
void initializeArray(int a[], int size) {

	for(int i = 0; i < size; i++) {
		a[i] = -1;
	}

}


int *testC(int a[]) {

	static int c[10];
	for(int i = 0; i < 10; i++) {
		a[i] = i;
	}
	return a;
}
