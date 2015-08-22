#include <stdio.h>
int createInt(char c[]);
int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while (fgets(line, 1024, file)) {
		// Do something with the line
		char binaryAnswer[1024];
		int x = createInt(line);	
		printf("%d\n", x);
	}
	return 0;
}

int createInt(char c[]) {
	int i = 0;
	int counter = 0;
	while(c[counter] != '\n' && c[counter] != '\0') {
		i = i * 10;
		i = i + (c[counter] - '0');;
		counter++;
	}
	return i;
}

