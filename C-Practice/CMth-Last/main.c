#include <stdio.h>
#include <stdlib.h>
int getStringLength(char * c);
int convertStringToInt(char *c);
int getIndex(char *c);
int getNumberOfInts(char * c);
int main(int argc, const char * argv[]) {
typedef int bool;
#define true 1
#define false 0

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	bool firstRun = true;
	while (fgets(line, 1024, file)) {

		//printf("%s\n", line);
		int elementToPrint = getIndex(line);
		int numOfChars = getNumberOfInts(line);
		//printf("%d %d\n", numOfChars, elementToPrint);
		int stringLen = getStringLength(line);
		if(line[stringLen - 1] == '\n') {
			stringLen--;
		}
		if(elementToPrint <= numOfChars) {
			if(firstRun == false) {
				printf("%c", '\n');
			} else {
				firstRun = false;
			}		//printf("%s\n", "here");
			int lineIndex = numOfChars - elementToPrint;
			lineIndex = lineIndex * 2;
			char charToPrint = line[lineIndex];
			printf("%c", charToPrint);
		} else {
			//firstRun = true;
		}

	}
	fclose(file);
	return 0;
} 

int getNumberOfInts(char * c) {

	int len = getStringLength(c);

	int currentIndex = len - 1;
	int counter = 0;
	while(*(c + currentIndex) != ' ') {
		counter++;
		currentIndex--;
	}
	counter++;

	int num = (len - counter + 1) / 2;
	//printf("%s %d\n", "num of words",  num);

	return num;
}
int getIndex(char *c) {

	int len = getStringLength(c);
	//printf("%s %s\n", "string ", c);
	if(*(c + len - 1) =='\n') {
		len--;
	}
	int counter = 0;
	int currentIndex = len - 1;

	while(*(c + currentIndex) != ' ') {
		currentIndex--;
		counter++;
	}
	currentIndex++;
	//printf("%s %d\n", "size of countr ", counter);
	char *substring = (char *)malloc((counter + 1) * sizeof(char));

	for(int i = 0; i < counter; i++) {
		*(substring + i) =  *(c + currentIndex + i); 
	}
	*(substring + counter) = '\0';

	//printf("%s %s\n", "substring", substring);
	int resultIndex = convertStringToInt(substring);
	//printf("%d\n", resultIndex);


	free(substring);
	return resultIndex;
}

int convertStringToInt(char *c) {
	
	int len = getStringLength(c);
	int result = 0;
	for(int i = 0; i < len; i++) {
		 char tempChar = *(c + i);
		int tempNum = tempChar - '0';
		result = result * 10;
		result = result + tempNum;
	}

	return result;
}

int getStringLength(char * c) {

	int counter = 0;
	while(*(c + counter) != '\0') {
		counter++;
		//printf("%c\n", *(c + counter));
	}
	return counter;
}
