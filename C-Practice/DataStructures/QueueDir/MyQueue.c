#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MyQueue.h"

void insert(struct node **element, void * d, int elementSize) {

	if(*element == NULL) {
		*element = (struct node *)malloc(sizeof(struct
					node));
		if(*element != NULL) {
			(*element)->data = malloc(elementSize);
			memcpy((*element)->data, d, elementSize);
			(*element)->next = NULL;
		} else {
			printf("%s\n", "malloc failed could not add element");
		}

		
	} else {
		struct node * rear = (struct node *) malloc(sizeof(struct node));

		if(rear != NULL) {
			rear->data = malloc(elementSize);
			memcpy(rear->data, d, elementSize);
			rear->next = (*element);
			*(element) = rear;
		} else {
			printf("%s\n", "malloc failed could not add element");
		}

	}
}

void deque(struct node **element) {
	
	if(*(element) != NULL) {
		if((*element)->next != NULL) {
			deque(&(*element)->next);
		} else {
			free((*element)->data);
			free(*element);
			*(element) = NULL;
		}
	} else {

	}

}

void printQueue(struct node **element) {
	struct node *temp = *(element);

	//printf("%s %d\n", "length of queue ", 

	while(temp != NULL) {
		int * tempInt = (int *)(temp)->data;
		printf("%d ",*tempInt );
		temp = temp->next;
	}
	printf("%c", '\n');
}

void freeQueue(struct node **element) {

	//printf("%s\n", "hereeee");
	if(*(element) != NULL) {
		freeQueue(&((*element)->next));
		free((*element)->data);
		free(*(element));
	}
	//printf("%s\n", "hereeee");
}

int lengthOfQueue(struct node ** element) {
	struct node *iterator = *element;
	int counter = 0;
	while((iterator) != NULL) {
		counter++;
		iterator = (iterator)->next;
	}
	return counter;
}

bool isEmpty(struct node **element) {

	if(*element == NULL) {
		return true;
	} else {
		return false;
	}
}

void * frontElement(struct node **element) {

	void *temp = NULL;
	if(*(element) != NULL) {
		if((*element)->next != NULL) {
			temp = frontElement(&(*element)->next);
		} else {
			temp = ((*element)->data);
		}
	} 	
	//printf("%s %d\n", "returning from top of queue", temp);
	return temp;
}
