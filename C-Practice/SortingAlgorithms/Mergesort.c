#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getNum(char* c);
int* mergeSort(int* a, int n, int b, int c);

int main(int argc, char *argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line,1024,file)) {
		int numberOfElements = 1;
		char* p = strtok(line," ");
		//printf("%s\n", p);
		//	p = strtok(NULL, " ");
		while((p)!= NULL) {

			char* temp = p;
			int tempNum = getNum(temp);
			printf("%d\n", tempNum);
			p = strtok(NULL, " ");
			if(p == NULL) {
				//	printf("%s", temp);
				//printf("%s", "kokoko");
			} else {
				//	printf("%s\n", temp);
			}	
			numberOfElements++;
		}
		numberOfElements--;
		int input[numberOfElements];	
		if((numberOfElements%2)==0) {	
			int midIndex = numberOfElements / 2;
			mergeSort(input, numberOfElements, 0, midIndex );
		} else {
			int midIndex = (numberOfElements + 1) / 2;
			mergeSort(input, numberOfElements, 0, midIndex); 
		}
	}

	return 0;
}

int getNum(char* c) {

	int number = 0;

	while((*c)!='\0' && ((*c) != '\n')) {
		number = (number * 10) + (*c - '0');
		c++;
	}

	return number;
}

int*  mergeSort(int* nums, int n, int start, int mid) {

	if(n == 1) {
		return nums;
	}

	if(n == 2) {
		nums = nums + start;
		if((*nums) > (*(nums + 1))) {
			int holder = *nums;
			*nums = *(nums + 1);
			*(nums + 1) = holder;
		}
		return nums;
	}

	printf("%s %d\n", "list size is: ", n);

	int leftListSize = mid - start;
	printf("%s %d\n", "left list size: " , leftListSize);
	int rightListSize = n - leftListSize; 
	printf("%s %d\n", "right list size: ", rightListSize);

	int* sortedLeftSide;
	if((leftListSize%2)==0) {
		if(leftListSize == 2) {
			sortedLeftSide = mergeSort(nums, leftListSize, start, start + 1);
		} else {
			int subLeftStart = start;
			int subLeftMid = leftListSize / 2;
			printf("%s %d\n", "sub left start: ", subLeftStart);
			printf("%s %d\n", "sub left mid: ", subLeftMid);
			sortedLeftSide = mergeSort(nums, leftListSize, subLeftStart, subLeftMid);
		}
	} else {
		if(leftListSize == 1) {
			sortedLeftSide = mergeSort(nums, leftListSize, start, start);
		} else {
			int subLeftStart = start;
			int subLeftMid = (leftListSize + 1) / 2;	
			printf("%s %d\n", "sub left start: ", subLeftStart);
			printf("%s %d\n", "sub left mid: ", subLeftMid);

			sortedLeftSide = mergeSort(nums, leftListSize, subLeftStart, subLeftMid);
		}
	}

	int* sortedRightSide;
	if((rightListSize%2)==0) {
		if(rightListSize == 2) {
			sortedRightSide = mergeSort(nums, rightListSize, mid, mid+1);
		} else {
			int subRightStart = mid;
			int subRightMid = (rightListSize / 2) + leftListSize;
			printf("%s %d\n", "sub right start: ", subRightStart);
			printf("%s %d\n", "sub right mid: ", subRightMid);
			sortedRightSide = mergeSort(nums, rightListSize, subRightStart, subRightMid);
		}
	} else {
		if(rightListSize == 1) {
			sortedRightSide = mergeSort(nums, rightListSize, mid, mid);
		} else {
			int subRightStart = mid;
			int subRightMid = ((rightListSize + 1) / 2) + leftListSize;
			printf("%s %d\n", "sub right start: ", subRightStart);
			printf("%s %d\n", "sub right mid: ", subRightMid);

			sortedRightSide = mergeSort(nums, rightListSize, subRightStart, subRightMid);
		}	
	}

	int *p = (int *) malloc(n * sizeof(int));

	int leftCounter = 0;
	int rightCounter = 0;
	free(p);
	return nums;
}

void copyElements(int* firstList, int* secondList, int n) {

	int counter = 0;

	while(counter < n) {

		*firstList = *secondList;
		firstList++;
		secondList++;
		counter++;

	}
}

