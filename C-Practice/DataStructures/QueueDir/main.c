#include<stdio.h>
#include "MyQueue.h"

int main(int argc, const char ** argv) {

	struct node *queue = NULL;
	int i0 = 5;
	int i1 = 7;
	int i2 = 8;
	int i3 = 9;
	int i4 = 10;
	int i5 = 0;

	/*insert(&queue, &i0, sizeof(int));
	insert(&queue, &i1, sizeof(int));
	insert(&queue, &i2, sizeof(int));
	deque(&queue);
	insert(&queue, &i3, sizeof(int));
	insert(&queue, &i4, sizeof(int));
	deque(&queue);
	insert(&queue, &i5, sizeof(int));
	printQueue(&queue);*/
	for(int i = 0; i < 10; i++) {
		insert(&queue, &i, sizeof(int)); 
	}
	printf("%s\n", "going on");
	printf("%s\n", "going on");
	printf("%s\n", "going on");
	printf("%s\n", "going on");
	printf("%s\n", "going on");
	printQueue(&queue);
	freeQueue(&queue);

	return 0;
}
