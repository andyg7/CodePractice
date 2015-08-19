#include<stdio.h>
#include<stdlib.h>
#include "MyQueue.h"
#include "MyHeap.h"

int main(int argc, char **argv) {

	struct HeapNode *root = NULL;
	addHeapNode(&root, 7);	
	addHeapNode(&root, 10);	
	addHeapNode(&root, 0);	
	addHeapNode(&root, 18);	
	addHeapNode(&root, 77);	
	addHeapNode(&root, 109);	
	addHeapNode(&root, 5);	
	addHeapNode(&root, 36);	
	addHeapNode(&root, 23);	
	addHeapNode(&root, 598);	
	addHeapNode(&root, 2);	
	addHeapNode(&root, 2);	
	bfs(&root);
	//sort(&root);
	printf("%s %d\n", "size of heap", sizeOfHeap(&root, 0));
	bfs(&root);
	freeHeap(&root);
	return 0;
}
