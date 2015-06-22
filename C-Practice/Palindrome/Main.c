#include <stdio.h>

typedef int bool;
#define true 1
#define false 0


int stringLength(char s[]);

int createInt(int i[], int s);

int isPalindrome(int i);


int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	int firstRun = 1;
	while (fgets(line, 1024, file)) {
		// Do something with the line
		if(firstRun == 0)
		{
			printf("%c",'\n');
		}
		firstRun = 0;
		int length = stringLength(line);
		if(line[length -1] == '\n')
		{
			line[length -1] = '\0';
			length = length - 1;
		}
		int numSize = 0;
		int revNumSize = 0;
		int num[length];
		int revNum[length];
		for(int i = 0; i < length;i++) {
			num[i] = line[i] - '0';	
		}
		numSize = sizeof(num)/sizeof(int);
		
		for(int i = 0; i < numSize;i++) {
			revNum[i] = num[numSize - 1 - i];	
		}
		revNumSize = sizeof(revNum)/sizeof(int);
		
		int x = createInt(num, numSize);
		int sum = x;
		int counter = 0;
		
		bool palindromeFound = false;
		while(palindromeFound == false) {
			if(isPalindrome(sum) == 1) {
				palindromeFound = true;
				printf("%d %d",counter, sum);
			} else {
				counter++;
				int tempSum = sum;
				int revSum = 0;
				while(tempSum != 0) {
					revSum = revSum * 10;
					revSum = revSum + tempSum%10;
					tempSum = tempSum/10;
				}
				sum = sum + revSum;
			}		
			
		}
	//	fclose(file);
	}
	return 0;
} 

int stringLength(char s[]) {
	int l = 0;
	
	while(s[l] != '\0' && s[l] != '\n') {
		l++;
	}
	return l;
}

int isPalindrome(int i) {
	
	int temp = i;
	int size = 0;
	while(temp > 0)
	{
		size++;
		temp = temp/10;
	}
	
	int c[size];
	int num = i;
	for(int a = 0; a < size; a++) {
		c[size-a-1] = num % 10;
		num = num / 10;  
	}
	for(int a = 0; a < size; a++){
			//	printf("%d",c[b]);
	}
	
	for(int a = 0; a < size;a++) {
		if(c[a] != c[size - a - 1])
		{
			return 0;
		}
	}
	
	return 1;
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