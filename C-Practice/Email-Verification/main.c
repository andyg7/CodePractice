#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
int getStringLength(const char * c);
bool contains(const char * str, char c);
void alterString(char * c);
bool validEmailChar(char c);

int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	bool firstRun = true;
	while(fgets(line, 1024, file)) {
		//printf("\n%s %s", "line: " , line);
		//printf("%d\n", getStringLength(line));
		if(getStringLength(line) == 0) {

		} else {

			if(firstRun == true) {
				firstRun = false;
			} else {
				printf("%c", '\n');
			}

			bool validEmail = true;
			int stringLen = getStringLength(line);
			char *firstWord = (char *)malloc(stringLen * sizeof(char));
			char *secondWord = (char *)malloc(stringLen * sizeof(char));
			bool atFound = false;
			int secondStart = 0;
			int firstWordLen = 0;
			int secondWordLen = 0;
			for(int i = 0; i < stringLen; i++) {
				if(atFound == false) {
					if(line[i] == '@') {
						atFound = true;
						secondStart = i + 1;
						*(firstWord + i) = '\0';
						if( i == stringLen - 1) {
							atFound = false;
						}
						if(i == 0) {
							atFound = false;
							i = stringLen;
						}
					} else {
						*(firstWord + i) = line[i];
						firstWordLen++;
					}
				} else {

					*(secondWord + i - secondStart) = line[i];
					if(i == (stringLen - 1)) {
						*(secondWord + i + 1 - secondStart) = '\0';
					}
				}
			}
			//printf("%s %d\n", "1st word len : ", firstWordLen);
			secondWordLen = stringLen - firstWordLen - 1;
			//printf("%s %d\n", "2nd word len : ", secondWordLen);
			if(atFound == false) {
				printf("%s", "false");
			} else {

				if((contains(firstWord, ' ') == true) || (contains(secondWord,
								' ') == true) || (contains(secondWord,
									'@') == true)) {
					printf("%s", "false");
				} else if(getStringLength(secondWord) < 5 ) {
					printf("%s", "false");
				} else {
					bool valid = true;
					for(int i = 0; i < firstWordLen; i++) {
						char tempChar = *(firstWord + i);
						if(validEmailChar(tempChar) ==
								false) {
							valid = false;
						}

					}
					
					for(int i = 0; i < secondWordLen - 4; i++) {
						char tempChar = *(secondWord + i);
						if(validEmailChar(tempChar) ==
								false) {
							valid = false;
						}

					}
					int len = getStringLength(secondWord);
					char a = *(secondWord + len - 1 - 3);
					char b = *(secondWord + len - 1 - 2);
					char c = *(secondWord + len - 1 - 1);
					char d = *(secondWord + len - 1);
					if(a != '.') {
						valid = false;
					}
					if(b != 'c') {
						valid = false;
					}
					if(c != 'o') {
						valid = false;
					}
					if(d != 'm') {
						valid = false;
					}
					if(valid == false) {
						printf("%s", "false");
					} else {
						printf("%s", "true");
					}
				}

			}
			free(firstWord);
			free(secondWord);

		}
	}
	return 0;
}


bool contains(const char * str, char c) {
	int len = getStringLength(str);
	for(int i = 0; i < len; i++) {
		if(*(str + i) == c) {
			return true;
		}
	}
	return false;
}

/*

   Returns length of string. Not including '\n', or the terminating '\0' character.

 */

void alterString(char * c) {
	*(c) = 'a';
}

int getStringLength(const char * string) {


	int counter = 0;
	while(*(string + counter) != '\0' && *(string + counter) != '\n') {
		counter ++;
	}
	return counter;
}

bool validEmailChar(char c) {

	if(97 <= c && c <= 122) {
		return true;
	}

	if(65 <= c && c <=90) {
		return true;
	}

	if(48 <= c && c <=57) {
		return true;
	}

	return false;
}
