#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

typedef int bool;
#define true 1
#define false 0

struct node {
	void *data;
	struct node *next;
};

void insert(struct node **element, void *d, int elementSize);
void deque(struct node **element);
int lengthOfQueue(struct node **element);
void printQueue(struct node **element);
void freeQueue(struct node **element);
bool isEmpty(struct node **element);
void *frontElement(struct node **element);
#endif
