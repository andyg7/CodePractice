#ifndef _MYHEAP_H_
#define _MYHEAP_H_

typedef enum {
	left, right
} RelationToParent;

struct HeapNode {
	int data;
	struct HeapNode *rightChild;
	struct HeapNode *leftChild;
};
void addP();
void addHeapNode(struct HeapNode **element, int n);
void freeHeap(struct HeapNode *element);
int sizeOfHeap(struct HeapNode *element, int n);
void bfs(struct HeapNode **element);
void sort(struct HeapNode **element);

#endif
