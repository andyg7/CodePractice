#ifndef _MYLINKEDLIST_H_
#define _MYLINKEDLIST_H_

typedef int bool;
#define true 1
#define false 0

struct node {
	int data;
	struct node *next;
};

void sayHi();
void initializeLinkedList(struct node ** e);
int getSize();
void printFirstElement(struct node **e);
void insertFront(int n, struct node **e);
void insertBack(int n, struct node **e);
void insertWithLoops(int n, struct node **e);
void deleteFront(struct node **e);
void deleteBack(struct node ** e);
void destroyLinkedList();
void printLinkedList(struct node **e);
bool contains(int n, struct node **e);

#endif
