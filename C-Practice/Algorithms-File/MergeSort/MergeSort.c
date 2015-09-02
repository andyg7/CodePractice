#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getNum(char* c);
int* mergeSort(int* a, int n, int b, int c);
void copyElements(int* firstList, int* secondList, int n, int e); 
void changeArr(int arr[]);

void changeArr(int arr[]) {

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

}

int main(int argc, char *argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line,1024,file)) {

		char* p = strtok(line," ");
		int numberOfElements = getNum(p);
		int input[numberOfElements];
		p = strtok(NULL, " ");
		int b = 0;
		while((p)!= NULL) {

			char* temp = p;
			int tempNum = getNum(temp);
			input[b] = tempNum;
			//printf("%d\n", tempNum);
			p = strtok(NULL, " ");
			b++;
		}
		printf("%s\n", "Elements to sort: ");
		for(int i = 0; i < numberOfElements; i++) {
			printf("%d\n", input[i]);
		}

		int* sortedList;

		if((numberOfElements%2)==0) {	
			int midIndex = numberOfElements / 2;
			sortedList = mergeSort(&input[0], numberOfElements, 0, midIndex );
		} else {
			int midIndex = (numberOfElements + 1) / 2;
			sortedList = mergeSort(&input[0], numberOfElements, 0, midIndex); 
		}

		printf("%s\n","Merge sorted list: ");
		for(int i = 0; i < numberOfElements; i++) {
			printf("%d %s %d\n", i, ": ", *(sortedList + i));
		} 
	}
	
	fclose(file);

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

	//printf("%s %d\n","numbers to sort: ", n);
	for(int i = 0; i < n; i++) {
		//printf("%d\n", *(nums + start +  i));
	}
	//printf("%s %d %d\n", "indxes: ", start, mid);

	for(int i = 0; i < n; i++) {
		//printf("%s %d\n", "coming in ",*(nums + i) );
	}

	if(n == 1) {
		return nums;
	}

	if(n == 2) {
		//printf("%s\n", "About to sort: ");
		//printf("%s %d\n","first", *(nums + start));
		//printf("%s %d\n","second", *(nums + start + 1));
		
		int* tmpNums = nums;
		tmpNums = tmpNums + start;
		if((*(nums + start)) > (*(nums + start + 1))) {
			int holder = *(nums + start);
			*(nums + start) = *(nums + 1 + start);
			*(nums + 1 + start) = holder;
			//printf("%d\n", *nums);
			//	printf("%d\n", *(nums + 1));
		}
		//printf("%s\n", "sorted now: ");
		//printf("%s %d\n","first", *(nums + start));
		//printf("%s %d\n","second", *(nums + start + 1));

		return nums;
	}

	//printf("%s %d\n", "list size is: ", n);

	int leftListSize = mid - start;
		//printf("%s %d\n", "left list size: " , leftListSize);
	int rightListSize = n - leftListSize; 
		//printf("%s %d\n", "right list size: ", rightListSize);

	int* sortedLeftSide;
	if((leftListSize%2)==0) {
		if(leftListSize == 2) {
			sortedLeftSide = mergeSort(nums, leftListSize, start, start + 1);
		} else {
			int subLeftStart = start;
			int subLeftMid = leftListSize / 2;
			//			printf("%s %d\n", "sub left start: ", subLeftStart);
			//			printf("%s %d\n", "sub left mid: ", subLeftMid);
			sortedLeftSide = mergeSort(nums, leftListSize, subLeftStart, subLeftMid);
		}
	} else {
		if(leftListSize == 1) {
			sortedLeftSide = mergeSort(nums, leftListSize, start, start);
		} else {
			int subLeftStart = start;
			int subLeftMid = (leftListSize + 1) / 2;	
			//			printf("%s %d\n", "sub left start: ", subLeftStart);
			//			printf("%s %d\n", "sub left mid: ", subLeftMid);

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
			//printf("%s %d\n", "sub right start: ", subRightStart);
			//	printf("%s %d\n", "sub right mid: ", subRightMid);
			sortedRightSide = mergeSort(nums, rightListSize, subRightStart, subRightMid);
		}
	} else {
		if(rightListSize == 1) {
			sortedRightSide = mergeSort(nums, rightListSize, mid, mid);
		} else {
			int subRightStart = mid;
			int subRightMid = ((rightListSize + 1) / 2) + leftListSize;
			//printf("%s %d\n", "sub right start: ", subRightStart);
			//printf("%s %d\n", "sub right mid: ", subRightMid);

			sortedRightSide = mergeSort(nums, rightListSize, subRightStart, subRightMid);
		}	
	}



	int *p = (int *) malloc(n * sizeof(int));

	int totalCounter = 0;
	int leftCounter = 0;
	int rightCounter = 0;

	//printf("%s\n", "left side sorted: ");
	for(int i = 0; i < leftListSize; i++) {
		//printf("%d\n", *(sortedLeftSide + start + i));
	}
	//printf("%s\n", "right side sorted: ");
	for(int i = 0; i < rightListSize; i++) {
		//printf("%d\n", *(sortedRightSide + mid + i));
	}
	while((leftCounter < leftListSize) || (rightCounter < rightListSize)) {

		if(leftCounter >= leftListSize) {
			int tv = *(sortedRightSide + mid + rightCounter);
			*(p + totalCounter) = tv;
			//printf("%s %d\n", "here: ", tv);
			totalCounter++;
			rightCounter++;

		} else if(rightCounter >= rightListSize) {
			int tv = *(sortedLeftSide +start+ leftCounter);
			*(p + totalCounter) = tv;
			//printf("%s %d\n", "here: ", tv);
			totalCounter++;
			leftCounter++;
		} else {

			if(*(sortedRightSide + mid + rightCounter) < *(sortedLeftSide + start + leftCounter)) {
				int tempE = *(sortedRightSide + mid+ rightCounter);
				*(p + totalCounter) = tempE; 
				//printf("%s %d\n","here" , tempE);
				rightCounter++;
			} else {

				int tempE = *(sortedLeftSide + start + leftCounter);
				*(p + totalCounter) = tempE;
				//printf("%s %d\n","here", tempE);
				leftCounter++;
			}
			totalCounter++;
		}
	}

	//printf("%d %d\n", start,n);
	copyElements(nums, p,n,start );
	//printf("%s\n", "merged sort: ");
	for(int i = 0; i < n; i++) {
	//printf("%d\n", *(nums + start + i));
}
	free(p);

	return nums;
}

void copyElements(int* firstList, int* secondList, int n, int e) {

	int counter = 0;

	while(counter < n) {

		*(firstList + counter + e) = *(secondList + counter);
		counter++;

	}
}

