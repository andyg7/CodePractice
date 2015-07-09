#include <stdio.h>
#include <string.h>
int stringToInt(char s[]);
typedef int bool;
#define true 1
#define false 0

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

		const char delim[2] = " ";
		int arrayOfNums[1024];
		char *strNum = strtok(line, delim);
		int counter = 0;
		while(strNum != NULL) {
			int strinLen = strlen(strNum);
			if(strNum[strinLen - 1] == '\n') {
				//printf("%s %d\n", "size before", strinLen);
				strNum[strinLen - 1] = '\0';
				strinLen = strlen(strNum);
				//printf("%s %d\n", "size after", strinLen);
			}
			//printf("%s\n", strNum);
			arrayOfNums[counter] = stringToInt(strNum);
			//printf("%d\n", arrayOfNums[counter]);
			strNum = strtok(NULL, delim);
			counter++;	
		}

		int listSize = counter;
		bool foundLoop = false;
		//printf("%s %d\n", "list size " , listSize);
		for(int i = 0; i < listSize; i++) {
			//printf("%d %s", arrayOfNums[i], " ");
		}
		for(int i = 0; i < counter; i++) {
			for(int a = 0; a < i; a++) {
				if(arrayOfNums[a] == arrayOfNums[i]) {
					for(int b = a; b < i; b++) {
						if(b == (i - 1)) {
							printf("%d", arrayOfNums[b]);
						} else {
							printf("%d ", arrayOfNums[b]);
						}
					}
					foundLoop = true;
					a = i;
				}

			}
			if(foundLoop == true) {
				i = counter;
			}
		}	
	}
	return 0;
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
