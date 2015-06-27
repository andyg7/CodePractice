#include <stdio.h>
#include <string.h>
int getNum(char* c);

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
	int input[numberOfElements];	
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
