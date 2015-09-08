#include <stdio.h>
#include "MyLinkedList.h"

int main(int argc, const char ** argv) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line, 1024, file)) {
		//Do something with the line
		printf("%s", line);
	}

	return 0;
}
