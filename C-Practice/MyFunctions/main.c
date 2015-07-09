#include <stdio.h>
#include <stdlib.h>
#include "MyString.h"


int main(int argc, char ** argv) {

	int x = 0;
	int y = 1;
	char str[] = "927";
	int aInt = stringToInt(str);
	/*printf("%d\n", aInt);
	printf("%s\n", str);
	printf("%d\n", getStringLength(str));*/
	printf("%d\n", stringToInt(str));

	for(int i = 0; i < 10; i++) {
		printf("%s\n", "dude");	
}	

	return 0;
}
