#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "MyHeap.h"
#include "MyQueue.h"

static int getRow(int n);
static void heapify(struct HeapNode **element, int n, int (*f1)(const void *, const
void *));
static void maxHeap(struct HeapNode **element, int (*f1)(const void *, const void *));
static int sizeOfHeap(struct HeapNode *element, int n);
static struct HeapNode **getNodeAt(struct HeapNode **element, int i);
static void swap(struct HeapNode **p, struct HeapNode **c);
static void unrelateSwap(struct HeapNode **t, struct HeapNode **b);

void createHeap(struct HeapNode **element, int (*f1)(const void *, const void *)) {
	int numOfNodes = heapSize(element);
	heapify(element, numOfNodes, f1);
}

void addHeapNode(struct HeapNode **element, int n) {
	struct HeapNode *newNode = (struct HeapNode *)malloc(sizeof(struct HeapNode));
	newNode->data = n;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	struct node *queue = NULL;
	if(*element == NULL) {
		(*element) = newNode;	
	} else {
		struct HeapNode **iterator = (element);		
		int iteratorSize = sizeof(*iterator);
		insert(&queue, iterator, iteratorSize);
		bool foundPos = false;
		while(foundPos == false) {
			struct HeapNode *currentHeapNode = *((struct HeapNode **)frontElement(&queue));
			assert(currentHeapNode != NULL);
			if(currentHeapNode->leftChild == NULL) {
				foundPos = true;
				currentHeapNode->leftChild = newNode;
			} else if(currentHeapNode->rightChild == NULL) {
				foundPos = true;
				currentHeapNode->rightChild = newNode;
			}
			if(foundPos == false) {
				insert(&queue, &(currentHeapNode->leftChild), iteratorSize);
				insert(&queue, &(currentHeapNode->rightChild), iteratorSize);
				deque(&queue);
			}
		}
	}
	freeQueue(&queue);
}

void bfs(struct HeapNode **element) {
	bool heapIsEmpty = false;
	if((*element) == NULL) {
		printf("%s\n", "Heap is empty");
		heapIsEmpty = true;
	}
	if(heapIsEmpty == false) {
		printf("%s", "Printing Heap: ");
		int nodeCounter = 0;
		int currentRow = 0;
		struct node *queue = NULL;
		struct HeapNode **iterator = element;
		int iteratorSize = sizeof(*iterator);
		insert(&queue, iterator, iteratorSize);
		while(isEmpty(&queue) == false) {
			struct HeapNode *currentHeapNode = *((struct HeapNode **)frontElement(&queue));
			assert(currentHeapNode != NULL);
			int currentData = currentHeapNode->data;
			if(currentHeapNode->leftChild != NULL) {
				insert(&queue, &(currentHeapNode->leftChild), iteratorSize);
			}
			if(currentHeapNode->rightChild != NULL) {
				insert(&queue, &(currentHeapNode->rightChild), iteratorSize);
			}
			int row = getRow(nodeCounter);
			if(row == currentRow) {
				printf("%d ", currentData);
			} else {
				printf("\n%s %d\n", "row", row);
				printf("%d ", currentData);
				currentRow = row;
			}
			deque(&queue);
			nodeCounter++;
		}
		printf("%c", '\n');
	}
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

void freeHeap(struct HeapNode **element) {
	bool heapIsEmpty = false;
	if((*element) == NULL) {
		heapIsEmpty = true;
	}

	if(heapIsEmpty == false) {
		if((*element)->leftChild != NULL) {
			freeHeap(&((*element)->leftChild));
		}
		if((*element)->rightChild != NULL) {
			freeHeap(&((*element)->rightChild));
		}
		free(*element);
	}
}

static int sizeOfHeap(struct HeapNode *element, int n) {
	if(element == NULL) {
		return 0;
	}
	int counter = n;
	counter++;
	if(element->leftChild != NULL) {
		counter = sizeOfHeap(element->leftChild, counter);
	}
	if(element->rightChild != NULL) {
		counter = sizeOfHeap(element->rightChild, counter);
	}

	return counter;
}

void sort(struct HeapNode **element, int (*f1)(const void *, const void *)) {
	int numOfNodes = heapSize(element);
	heapify(element, numOfNodes, f1);
	int lastIndex = numOfNodes - 1;
	for(int i = lastIndex; i > 0; i--) {
		struct HeapNode **nextBig = getNodeAt(element, 0);
		struct HeapNode **lastNode = getNodeAt(element, i);
		printf("%d ",(*nextBig)->data);
		if((*nextBig)->leftChild == (*lastNode) || (*nextBig)->rightChild ==
				(*lastNode)) {
			bool isLeft = false;
			if((*nextBig)->leftChild == *lastNode) {
				isLeft = true;
			}
			unrelateSwap(nextBig, lastNode);
			if(isLeft == true) {
				free((*nextBig)->leftChild);
				(*nextBig)->leftChild = NULL;
			} else {
				free((*nextBig)->rightChild);
				(*nextBig)->rightChild = NULL;

			}

		} else {
			unrelateSwap(nextBig, lastNode);
			free((*lastNode));
			(*lastNode) = NULL;
		}
		if( i > 1) {
			maxHeap(nextBig, f1);
		}

	}
	struct HeapNode **lastNode = getNodeAt(element, 0);
	printf("%d ",(*lastNode)->data);
	free((*lastNode));
	(*lastNode) = NULL;
	printf("%c", '\n');
}

static void heapify(struct HeapNode **element, int n, int (*f1)(const void *, const
void *)) {

	int highestIndex = n - 1;
	int counterIndex = (highestIndex - 1) / 2;
	for(int i = counterIndex; i >= 0; i--) {
		struct HeapNode **current = getNodeAt(element, i);
		maxHeap(current, f1);
	}

}

void maxHeap(struct HeapNode **element, int (*f1)(const void *, const void *)) {

	assert((*element) != NULL);
	assert((*element)->leftChild != NULL);
	bool hasRightChild = true;
	if((*element)->rightChild == NULL) {
		hasRightChild = false;
	}

	if(hasRightChild == true) {
		int parentData = (*element)->data;
		int leftChildData = ((*element)->leftChild)->data;
		int rightChildData = ((*element)->rightChild)->data;
		int compareResultParentLC = f1(&parentData, &leftChildData);
		int compareResultParentRC = f1(&parentData, &rightChildData);
		int compareResultLCRC = f1(&leftChildData, &rightChildData);
		if(compareResultParentLC == -1 || compareResultParentRC == -1) {
			if(compareResultLCRC != -1) {
				unrelateSwap(element, &((*element)->leftChild));
				if(((*element)->leftChild)->leftChild != NULL) {
					maxHeap(&((*element)->leftChild), f1);
				}
			} else {
				unrelateSwap(element, &((*element)->rightChild));
				if(((*element)->rightChild)->leftChild != NULL) {
					maxHeap(&((*element)->rightChild), f1);
				}
			}
		}
	}

	if(hasRightChild == false) {
		int parentData = (*element)->data;
		int leftChildData = ((*element)->leftChild)->data;
		int compareResult = f1(&parentData, &leftChildData);
		//printf("%s %d\n", "printing compare", compareResult);
		//printf("%d\n", parentData - leftChildData);
		if(compareResult == -1) {
			unrelateSwap(element, &((*element)->leftChild));
			if(((*element)->leftChild)->leftChild != NULL) {
				maxHeap(&((*element)->leftChild), f1);
			}
		}
	}

}

static struct HeapNode ** getNodeAt(struct HeapNode **element, int i) {

	if((*element) == NULL) {
		printf("%s\n", "could not execute getNode function");
		return NULL;
	}
	int counter = 0;
	int indexToGet = i;
	struct HeapNode **iterator = element;
	struct node *queue = NULL;
	int iteratorSize = sizeof(iterator);
	insert(&queue, &iterator, iteratorSize);
	struct HeapNode **currentHeapNode = *((struct HeapNode ***)frontElement(&queue));
	while(counter <= indexToGet) {
		currentHeapNode = *((struct HeapNode ***)frontElement(&queue));
		if((*currentHeapNode)->leftChild != NULL) {
			struct HeapNode **t = &((*currentHeapNode))->leftChild;
			insert(&queue, &t, iteratorSize);
		}
		if((*currentHeapNode)->rightChild != NULL) {
			struct HeapNode **t = &((*currentHeapNode))->rightChild;
			insert(&queue, &t, iteratorSize);
		}
		deque(&queue);
		counter++;
	}
	freeQueue(&queue);
	return currentHeapNode;

}

static void swap(struct HeapNode **p, struct HeapNode **c) {

	assert(*p != NULL);
	assert(*c != NULL);

	bool validInput = true;
	bool switchNum = false;
	if(((*p)->leftChild) != *c && (*p)->rightChild != *c) {
		printf("%s\n", "cant make that swap");
		validInput = false;
	}
	if(validInput == true && switchNum == true) {
		int tempInt = (*p)->data;
		(*p)->data = (*c)->data;
		(*c)->data = tempInt;
	}

	if(validInput == true && switchNum == false) {
		bool isLeftChild = false;
		if((*p)->leftChild == *c) {
			isLeftChild = true;
		}
		struct HeapNode *origParentLC = (*p)->leftChild;
		struct HeapNode *origParentRC = (*p)->rightChild;
		struct HeapNode *origChildLC = (*c)->leftChild;
		struct HeapNode *origChildRC = (*c)->rightChild;
		struct HeapNode *tempAddr = *p;
		(*p) = (*c);
		if(isLeftChild == true) {
			((*p)->leftChild) = tempAddr;
			((*p)->rightChild) = origParentRC;
			((*p)->leftChild)->leftChild = origChildLC;
			((*p)->leftChild)->rightChild = origChildRC;

		} else {
			((*p)->leftChild) = origParentLC;
			((*p)->rightChild) = tempAddr;
			((*p)->rightChild)->leftChild = origChildLC;
			((*p)->rightChild)->rightChild = origChildRC;
		}
		
	}
}

static void unrelateSwap(struct HeapNode **t, struct HeapNode **b) {

	assert(*t != NULL);
	assert(*b != NULL);
	struct HeapNode *origTopLC = (*t)->leftChild;
	struct HeapNode *origTopRC = (*t)->rightChild;
	struct HeapNode *origBottomLC = (*b)->leftChild;
	struct HeapNode *origBottomRC = (*b)->rightChild;

	struct HeapNode *tempAddr = *t;

	bool childParent = false;

	if((*t)->leftChild == (*b) || (*t)->rightChild == (*b)) {
		childParent = true;
	}

	if(childParent == false) {
		(*t) = (*b);
		(*t)->leftChild = origTopLC;
		(*t)->rightChild = origTopRC;
		(*b) = tempAddr;
		(*b)->leftChild = origBottomLC;
		(*b)->rightChild = origBottomRC;
	} else {

		bool isLeft = false;
		if((*t)->leftChild == (*b)) {
			isLeft = true;
		}
		if(isLeft == true) {
			(*t) = (*b);
			(*t)->leftChild = tempAddr;
			(*t)->rightChild = origTopRC;
			(((*t)->leftChild)->leftChild) = origBottomLC;
			(((*t)->leftChild)->rightChild) = origBottomRC;
		} else {
			(*t) = (*b);
			(*t)->rightChild = tempAddr;
			(*t)->leftChild = origTopLC;
			(((*t)->rightChild)->leftChild) = origBottomLC;
			(((*t)->rightChild)->rightChild) = origBottomRC;
		}
	}

}

int heapSize(struct HeapNode **element) {
	int size = sizeOfHeap(*element, 0);
	return size;
}
