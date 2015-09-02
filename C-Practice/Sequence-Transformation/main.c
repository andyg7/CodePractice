#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int lengthOfString(const char * s);

int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line, 1024, file)) {
		//Process line here
		char delim[2] = " ";
		char * token = strtok(line, delim);
		char *firstString;
		char *secondString;
		int inputCounter = 0;
		while(token != NULL) {
			inputCounter++;
			printf("%s\n", token);
			int currentStringLen = lengthOfString(token);
			printf("%d\n", currentStringLen);
			token = strtok(NULL, delim);
			if(inputCounter == 1) {
				firstString = (char *)malloc((currentStringLen + 1) * sizeof(char));
			} else {
				secondString = (char *)malloc((currentStringLen + 1) * sizeof(char));
			}
		}	
		assert(inputCounter == 2);
		free(firstString);
		free(secondString);
	}

	fclose(file);	
	
	return 0;
}

/*
   Length doesn't include \n char
 */

int lengthOfString(const char * s) {

	int counter = 0;
	while(*(s + counter) != '\n' && *(s + counter) != '\0') {
		counter++;
	}

	//printf("%s%s%d\n", s , "length is ", counter);

	return counter;
}
