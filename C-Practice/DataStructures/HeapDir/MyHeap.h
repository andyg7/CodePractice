#ifndef _MYHEAP_H_
#define _MYHEAP_H_

struct HeapNode {
	int data;
	struct HeapNode *parent;
	struct HeapNode *rightChild;
	struct HeapNode *leftChild;
};

void initialize(struct HeapNode **element);
void swapParent(struct HeapNode **parent, struct HeapNode **child); 
void addHeapNode(struct HeapNode **element, int n);
void freeHeap(struct HeapNode **element);
int sizeOfHeap(struct HeapNode **element, int n);
void bfs(struct HeapNode **element);
void freeHeap(struct HeapNode **element);
//struct HeapNode ** nextPosition(struct HeapNode **element);

#endif
