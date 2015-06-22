#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int createInt(int n[], int s);

int stringLength(char s[]);

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	fgets(line, 1024, file);
	int counter = 0;
	int length = stringLength(line);
	if(line[length -1] == '\n')
	{
		//line[length -1] = '\0';
		length = length - 1;
	}
	int numberArry[length];
	while(line[counter] != '\n') {
		numberArry[counter] = line[counter] - '0';
		counter++;
	}
	int number = createInt(numberArry,counter);
	//	printf("%d\n",number);
	
	char *arry[number];
	int sizeArry[number];
	for(int i = 0; i< number; i++){
		arry[i] = (char *)malloc(1024);
		sizeArry[i] = -1;
	}
	int count = 0;
	while (fgets(line, 1024, file)) {
		// Do something with the line
		int tempLength = strlen(line);
		if(line[tempLength - 1] == '\n'){
			line[tempLength - 1] = '\0';
			tempLength = tempLength - 1;
		}
		for(int i = 0;i < number;i++){
			if(tempLength > sizeArry[i] || sizeArry[i] == -1){
				for(int a = number - 2; a >= i;a--){
						strcpy(arry[a+1], arry[a]);
						sizeArry[a+1] = sizeArry[a];
				}
				strcpy(arry[i], line);
				sizeArry[i] = tempLength;
				
				i = number;
			} 
		}
	} 
	
	
	for(int i = 0; i < number;i++){
		printf("%s", arry[i]);
		if(i != number - 1){
			printf("%c",'\n');
		}
		free(arry[i]);
	}
	
	fclose(file);
	return 0;
} 

int createInt(int n[], int s) {
	
	int len = s;
	int multiple = 1;
	for(int a = 0; a < (len - 1) ;a++){
		multiple = multiple * 10;
	}
	int number = 0;
	
	for(int i = 0; i < len; i++) {
		number = number + (multiple * n[i]);
		multiple = multiple / 10;
	}
	
	return number;
}

int stringLength(char s[]) {
	int l = 0;
	
	while(s[l] != '\0') {
		l++;
	}
	return l;
}
