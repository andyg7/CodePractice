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
	//printf("%s %d\n", "size of heap", sizeOfHeap(&root));
	bfs(&root);
	return 0;
}
