#include<stdio.h>

int main(int argc, char ** argv) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fget(line, 1024, file)) {
		// Do something with the line
		printf("%s", line);
	}

	return 0;
}
