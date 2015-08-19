#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "MyHeap.h"
#include "MyQueue.h"

static struct HeapNode *nextPosition(struct HeapNode **element);
static void swapParent(struct HeapNode **parent, struct HeapNode **child, RelationToParent n); 
static int getRow(int n);
static void heapify(struct HeapNode **element, int n);
static void maxHeap(struct HeapNode **element);
static struct HeapNode ** getNodeAt(struct HeapNode **element, int i);

static struct HeapNode * nextPosition(struct HeapNode **element) {

	if((*element) == NULL) {
		return *element;
	}

	bool foundPos = false;
	struct HeapNode * nodeToReturn = NULL;
	struct HeapNode * iterator = NULL;
	struct node *queue = NULL;
	int sizeOfIterator = sizeof(iterator);
	insert(&queue, (&iterator), sizeOfIterator);

	while(foundPos == false) {
printf("%s\n","dog");
		iterator = *(struct HeapNode **)frontElement(&queue);	
		if((iterator)->leftChild == NULL) {
			foundPos = true;
			nodeToReturn = iterator;
		} else {
			if((iterator)->rightChild == NULL) {
				foundPos = true;
				nodeToReturn = iterator;
			}
		}

		if(foundPos == false) {
			struct HeapNode ** leftChild = &(iterator)->leftChild;
			struct HeapNode ** rightChild = &(iterator)->rightChild;
			int sizeOfLeft = sizeof(*leftChild);
			int sizeOfRight = sizeof(*rightChild);
			insert(&queue, leftChild, sizeOfLeft);
			insert(&queue, rightChild, sizeOfRight);
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
		struct HeapNode *prtNode = nextPosition(element);
		if((prtNode) == NULL) {
		}
		printf("%s\n","here");
		if((prtNode)->leftChild == NULL) {
			//nodeToAdd->parent = *prtNode;
			(prtNode)->leftChild = nodeToAdd;
			//printf("%s\n","okok");
		} else {
			//nodeToAdd->parent = *prtNode;
			(prtNode)->rightChild = nodeToAdd;
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
	printf("%s", "gogog");
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
	//printf("%s\n", "trying to free");
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

void sort(struct HeapNode **element) {

	int numOfNodes = sizeOfHeap(element, 0);
	//int highestIndex = numOfNodes - 1;
	heapify(element, numOfNodes);
	printf("%s\n", "dude");

}

static void heapify(struct HeapNode **element, int n) {
	int numOfNodes = n;
	int highestIndex = numOfNodes - 1;
	int counterIndex = (highestIndex - 1) / 2;

	//printf("%s %d\n", "starting index ", counterIndex); 

	for(int i = counterIndex; i >= 0; i--) {
		//printf("%s %d\n", "counting", i);
		struct HeapNode **temp = getNodeAt(element, i);
		//printf("%s %d\n","returned id",  temp);
		printf("%s %d\n","max heaping ", (*temp)->data);
		maxHeap(temp);	
		printf("%s\n", "reprinting");
		//bfs(element);
	}
	printf("%s\n", "here999");
	printf("%s\n", "here999");
	//bfs(element);
}

static void maxHeap(struct HeapNode **element) {

	//printf("%s\n", "uuuokok");
	assert(*element != NULL);
	bool hasChild = true;
	if((*element)->leftChild == NULL) {
		hasChild = false;
	}
	if(hasChild == true) {

		bool leftBiggerSib = false;
		int parentData;
		int rightChildData;
		int leftChildData;

		parentData = (*element)->data;

		if((*element)->rightChild != NULL) {
			rightChildData = (*(&((*element)->rightChild)))->data;
		} else {
			leftBiggerSib = true;
		}
		leftChildData = (*(&((*element)->leftChild)))->data;

		if(leftBiggerSib == true) {
			if(parentData < leftChildData) {
				swapParent(element, &((*element)->leftChild), left);

				maxHeap(&((*element)->leftChild));

							}
		} else {
			if(rightChildData > leftChildData) {
				leftBiggerSib = false;
				if(parentData < rightChildData) {
					//struct HeapNode ** t; 

					swapParent(element, &((*element)->rightChild), right);
					

					maxHeap(&((*element)->rightChild));
									}
			} else {
				leftBiggerSib = true;
				if(parentData < leftChildData) {
					swapParent(element, &((*element)->leftChild), left);
					
					maxHeap(&((*element)->leftChild));
					
					printf("%s\n", "switching");
				}
			}
		}
	}
}

static void swapParent(struct HeapNode **parent, struct HeapNode **child,
		RelationToParent n) {

	assert(*parent != NULL);
	assert(*child != NULL);
	int num  = (*child)->data;
	(*child)->data = (*parent)->data;
	(*parent)->data = num;
	/*printf("%s ", "switching");
	printf("%d %d", (*parent)->data, (*child)->data);


	struct HeapNode **temp = NULL;
	struct HeapNode **childLeftChild = &((*child)->leftChild);
	printf("%s %d\n", "childleftchild add: ", childLeftChild);
	struct HeapNode **childRightChild = &((*child)->rightChild);
	printf("%s %d\n", "childrightchild add: ", childRightChild);
	struct HeapNode **parentLeftChild = &((*parent)->leftChild);
	printf("%s %d\n", "parentleftchild add: ", parentLeftChild);
	struct HeapNode **parentRightChild = &((*parent)->rightChild);
	printf("%s %d\n", "parentrightchild add: ", parentRightChild);

	printf("%s %d\n", "parent address ", *parent);
	printf("%s %d\n", "child address ", *child);

	temp = parent;
	*parent = *child;
	*child = *temp;

	printf("%s %d\n", "childleftchild add: ", *childLeftChild);
	printf("%s %d\n", "childrightchild add: ", *childRightChild);
	printf("%s %d\n", "parentleftchild add: ", *parentLeftChild);
	printf("%s %d\n", "parentrightchild add: ", *parentRightChild);

	printf("%s %d\n", "new parent address ", *parent);
	printf("%s %d\n", "new child address ", *child);

	printf("%d\n", (*parent)->leftChild);
	printf("%d\n", (*parent)->rightChild);
	printf("%d\n", (*child)->leftChild);
	printf("%d\n", (*child)->rightChild);
*/
	/*(*(&((*parent)->rightChild))) = parentRightChild;
	(*(&((*parent)->leftChild))) = parentLeftChild;

	(*(&((*child)->leftChild))) = childLeftChild;
	(*(&((*child)->rightChild))) = childRightChild; */
/*
	(*parent)->leftChild = *parentLeftChild;
	(*parent)->rightChild = *parentRightChild;


	(*child)->leftChild = *childLeftChild;
	(*child)->rightChild = *childRightChild; 
	*/
}

static struct HeapNode ** getNodeAt(struct HeapNode **element, int i) {

	assert(*element != NULL);
	//printf("%s\n", "here");
	//printf("%s %d\n", "at ", i);
	int counter = 0;
	struct node *queue = NULL;
	struct HeapNode ** current = element;
	insert(&queue, &current, sizeof(current));
	//printf("%s %d\n", "current ", (*current)->data);
	//counter++;
	while(counter <= i) {
		current = *(struct HeapNode ***)frontElement(&queue);
		//printf("%s %d\n", "current ", (*current)->data);
		if((*current)->leftChild != NULL) {
			struct HeapNode **leftChild = &((*current)->leftChild);
			insert(&queue, &leftChild, sizeof(leftChild));
		}

		if((*current)->rightChild != NULL) {
			struct HeapNode **rightChild = &((*current)->rightChild);
			insert(&queue, &rightChild, sizeof(rightChild));
		}
		deque(&queue);
		counter++;
	}
	freeQueue(&queue);
	//printf("%s %d\n", "sending ", current);
	return current;
}
