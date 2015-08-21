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
	addHeapNode(&root, 88);	
	addHeapNode(&root, 65);	
	addHeapNode(&root, 24);	
	addHeapNode(&root, 23);	
	addHeapNode(&root, 388);	
	addHeapNode(&root, 23);	
	addHeapNode(&root, 88);	
	addHeapNode(&root, 99);	
	addHeapNode(&root, 1);	
	addHeapNode(&root, 100000);	
	addHeapNode(&root, 598);	
	addHeapNode(&root, 2);	
	addHeapNode(&root, 2);	
	addHeapNode(&root, 2);	
	addHeapNode(&root, 2);	
	addHeapNode(&root, 89999999);	
	//bfs(&root);
	createHeap(&root);
	//bfs(&root);
	sort(&root);
	printf("%s %d\n", "size of heap", heapSize(&root));
	//bfs(&root);
	freeHeap(&root);
	return 0;
}
