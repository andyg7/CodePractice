#include "MyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void initializeLinkedList(struct node ** element) {
	*element = NULL;

}

static void printHi() {
	printf("%s\n", "hi!!!");
}

void sayHi() {
	printHi();
}

static int sizeOfList(struct node **element) {

	int counter = 0;
	struct node *temp = *element;
		while(temp != NULL) {
			counter++;
			temp = temp->next;
		}
	return counter;
}

void insertBack(int n, struct node **element) {

	if((*element) == NULL) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		(*temp).data = n;
		(*temp).next = NULL;
		(*element) = temp;
	} else {
		insertBack(n, &(*element)->next);
	}	
}

void insertFront(int n, struct node **element) {
	
	if(*element == NULL) {
		*element = (struct node *) malloc(sizeof(struct node));
		(*element)->data = n;
		(*element)->next = NULL;		
	} else {
		struct node * front1 = *element;
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->data = n;
		temp->next = front1;
		(*element) = temp;
	}
}

void printFirstElement(struct node **element) {

	printf("%d\n", (*element)->data);

}

void deleteFront(struct node **frontElement) {

	if(*frontElement != NULL) {
		struct node *temp = (*frontElement)->next;
		free(*(frontElement));
		(*frontElement) = (temp);
	}
}

void deleteBack(struct node **element) {

	if(*element != NULL) {
		if((*element)->next != NULL) {
			struct node ** temp = &((*element)->next);
			deleteBack(temp);
		} else {
			free(*element);
			*element = NULL;
		}
	}
}

void printLinkedList(struct node ** element) {

	if((*element) != NULL) {
		int data = (*element)->data;
		printf("%d\n", data);
		//struct node *t = (*element)->next;
		printLinkedList(&(*element)->next);
	}

}

bool contains(int n, struct node **element) {

	//printf("%s %d\n", "size of list: ", sizeOfList(element));
	bool foundElement = false;
	int counter = 0;
	int nodes = sizeOfList(element);
	struct node *temp = *element;
	while(counter < nodes) {
		counter++;
		if((temp->data) == n) {
			foundElement = true;
			break;
		} else {
			temp = temp->next;
		}
	}
	return foundElement;
}

void destroyLinkedList(struct node **element) {

	if((*element) != NULL) {
		destroyLinkedList(&((*element)->next));
		free(*element);
	}
}

void insertWithLoops(int n, struct node **element) {

	if(contains(n, element) == true) {

	} else {
		insertBack(n, element);	
	}

}
