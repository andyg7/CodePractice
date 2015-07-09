#include "MyString.h"

int stringToInt(char s[]) {
	int a = 10;
	int b = 10;
	int len = getStringLength(s);
	int multiple = 1;
	int stringValue = 0;
	for(int i = 0; i < len; i++) {
		int temp = s[i] - '0';
		stringValue = (stringValue * 10) + temp;	
	}
	return stringValue;
}

int getStringLength(char s[]) {
	int counter = 0;

	while(s[counter] != '\0') {
		counter ++;
	}	

	return counter;
}

