#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "MyHeap.h"
#include "MyQueue.h"

static int getRow(int n);
static void heapify(struct HeapNode **element, int n);
static void maxHeap(struct HeapNode **element);
static struct HeapNode **getNodeAt(struct HeapNode **element, int i);
static void swap(struct HeapNode **p, struct HeapNode **c);

void addHeapNode(struct HeapNode **element, int n) {
	//printf("%s %d\n", "adding ", n);
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
			//printf("%s\n", "still looking for next position");
			struct HeapNode *currentHeapNode = *((struct HeapNode **)frontElement(&queue));
			assert(currentHeapNode != NULL);
			//printf("%s %d\n", "current next position is: ", currentHeapNode->data);
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

void freeHeap(struct HeapNode *element) {
	bool heapIsEmpty = false;
	if((element) == NULL) {
		heapIsEmpty = true;
	}

	if(heapIsEmpty == false) {
		if(element->leftChild != NULL) {
			freeHeap(element->leftChild);
		}
		if(element->rightChild != NULL) {
			freeHeap(element->rightChild);
		}
		free(element);
	}
}

int sizeOfHeap(struct HeapNode *element, int n) {
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

void sort(struct HeapNode **element) {
	int numOfNodes = sizeOfHeap((*element), 0);
	heapify(element, numOfNodes);
}

static void heapify(struct HeapNode **element, int n) {

	int highestIndex = n - 1;
	int counterIndex = (highestIndex - 1) / 2;
	printf("%s %d\n", "starting index: ", counterIndex);
	for(int i = counterIndex; i >= 0; i--) {
		struct HeapNode **current = getNodeAt(element, i);
		printf("%s %d\n", "max heaping ", (*current)->data);
		maxHeap(current);
	}

}

void maxHeap(struct HeapNode **element) {

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
		if(leftChildData > parentData || rightChildData > parentData) {
			if(leftChildData >= rightChildData) {
				swap(element, &((*element)->leftChild));
			} else {
				swap(element, &((*element)->rightChild));
			}
		}
	}

	if(hasRightChild == false) {
		int parentData = (*element)->data;
		int leftChildData = ((*element)->leftChild)->data;
		if(leftChildData > parentData) {
			swap(element, &((*element)->leftChild));
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
			printf("%s\n", "trying to switch addresses");

		} else {
			((*p)->leftChild) = origParentLC;
			((*p)->rightChild) = tempAddr;
			((*p)->rightChild)->leftChild = origChildLC;
			((*p)->rightChild)->rightChild = origChildRC;
		}
		
	}
}
