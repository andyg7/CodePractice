#include <stdlib.h>
#include <stdio.h>
#include "MyLinkedList.h"

int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line, 1024, file)) {
		//printf("%s", line);

	}
	struct node *aList = (struct node *)malloc(sizeof(struct node));
	initializeLinkedList(&aList);
	insertBack(9, &aList);
	insertBack(61, &aList);
	insertBack(1890, &aList);
	printf("%s\n", "printing list:");
	printLinkedList(&aList);
	destroyLinkedList(&aList);	

	return 0;

}
