#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "MyHeap.h"
#include "MyQueue.h"

static struct HeapNode **nextPosition(struct HeapNode **element);
static int getRow(int n);

static struct HeapNode ** nextPosition(struct HeapNode **element) {

	if((*element) == NULL) {
		return element;
	}

	bool foundPos = false;
	struct HeapNode ** nodeToReturn = NULL;
	struct HeapNode ** iterator = element;
	struct node *queue = NULL;
	int sizeOfIterator = sizeof(iterator);
	insert(&queue, &(iterator), sizeOfIterator);
	//printf("%s %d\n","len of q", lengthOfQueue(&queue));

	while(foundPos == false) {
		iterator = *(struct HeapNode ***)frontElement(&queue);	
		if((*iterator)->leftChild == NULL) {
			foundPos = true;
			nodeToReturn = iterator;
		}
		if((*iterator)->rightChild == NULL) {
			foundPos = true;
			nodeToReturn = iterator;
		}
		if(foundPos == false) {
			struct HeapNode ** leftChild = &(*iterator)->leftChild;
			struct HeapNode ** rightChild = &(*iterator)->rightChild;
			int sizeOfLeft = sizeof(leftChild);
			int sizeOfRight = sizeof(rightChild);
			insert(&queue, &leftChild, sizeOfLeft);
			insert(&queue, &rightChild, sizeOfRight);
			deque(&queue);
		}
	} 

	freeQueue(&queue);
	//printf("%s %d\n", "printing queue len", lengthOfQueue(&queue));
	//printf("%s %d\n", "returning ", (*nodeToReturn)->data); 
	return nodeToReturn;
}

void addHeapNode(struct HeapNode **element, int n) {

	struct HeapNode *nodeToAdd = (struct HeapNode *)malloc(sizeof(struct HeapNode));	
	if(nodeToAdd == NULL) {
		printf("%s\n", "malloc failed");	
		exit(1);
	}
	(nodeToAdd)->data = n;
	(nodeToAdd)->parent = NULL;
	(nodeToAdd)->leftChild = NULL;
	(nodeToAdd)->rightChild = NULL;
	//printf("%s %d\n","adding ", n);
	if(*element == NULL) {
		(*element) = nodeToAdd;
	} else {
		struct HeapNode **prtNode = nextPosition(element);
		if((*prtNode) == NULL) {
		}
		if((*prtNode)->leftChild == NULL) {
			nodeToAdd->parent = *prtNode;
			(*prtNode)->leftChild = nodeToAdd;
			//printf("%s\n","okok");
		} else {
			nodeToAdd->parent = *prtNode;
			(*prtNode)->rightChild = nodeToAdd;
			//printf("%s\n","okokhhh");
		} 
	}
}

int sizeOfHeap(struct HeapNode **element, int n) {
	int counter = n;
	if(*element != NULL) {
		counter++;
	}
	if((*element)->leftChild != NULL) {
		counter = sizeOfHeap(&(*element)->leftChild, counter);
	}
	if((*element)->rightChild != NULL) {
		counter = sizeOfHeap(&(*element)->rightChild, counter);
	}

	return counter;
}

void bfs(struct HeapNode **element) {
	int heapSize = sizeOfHeap(element, 0);
	int nodeCounter = 0;
	int currentRow = 0;

	if(heapSize == 0) {
		printf("%s\n", "heap is empty");
	} else {
		struct HeapNode **iterator = element;
		struct node *queue = NULL;
		insert(&queue, &iterator, sizeof(iterator));

		while(isEmpty(&queue) == false ) {
			iterator = *(struct HeapNode ***)frontElement(&queue);	
			if((*iterator)->leftChild != NULL) {
				struct HeapNode ** leftChild = &(*iterator)->leftChild;
				insert(&queue, &leftChild, sizeof(leftChild));
			}
			if((*iterator)->rightChild != NULL) {
				struct HeapNode ** rightChild = &(*iterator)->rightChild;
				insert(&queue, &rightChild, sizeof(rightChild));
			}
			int row = getRow(nodeCounter);
			if(row == currentRow) {
				printf("%d ", (*iterator)->data);
			} else {
				printf("\n%s %d\n", "row", row);
				printf("%d ", (*iterator)->data);
				currentRow = row;
			}
			nodeCounter++;
			deque(&queue);
		}
		freeQueue(&queue);
	}

}

//Depth first search and deallocation

void freeHeap(struct HeapNode **element) {
	assert(*element != NULL);
	if((*element)->leftChild != NULL) {
		freeHeap(&(*element)->leftChild);
	}
	if((*element)->rightChild != NULL) {
		freeHeap(&(*element)->rightChild);
	}
	free(*element);
}

static int getRow(int n) {

	n = n + 1;
	int row = 0;
	int result = 1;
	while(n >= result) {
		result = result * 2;
		row++;
	}
	return row;
}
