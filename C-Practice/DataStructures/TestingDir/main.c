#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MyLinkedList.h"
#include "myadd.h"

int main(int argc, char ** argv) {

	struct node *head = NULL;
	//initializeLinkedList(&head);
	insertFront(10,&head);
	insertFront(7,&head);
	//insertBack(45, &head);
	insertFront(86,&head);
	insertFront(55,&head);	
	insertBack(13,&head);	
	deleteBack(&head);
	insertBack(673, &head);
	deleteFront(&head);
	insertBack(40, &head);
	
	int num1 = 8;	
	if(contains(num1, &head) == true) {
		//printf("%d\n",contains(num1, &head));
		printf("%s %d\n", "does contain", num1);
	} else {
		//printf("%d\n",contains(num1, &head));
		printf("%s %d\n", "doesnt contain", num1);
	}
	int num2 = 40;
	if(contains(num2, &head) == true) {
		printf("%s %d\n", "does contain", num2);
		//printf("%d\n",contains(num2, &head));
	} else {
		printf("%s %d\n", "doesnt contain", num2);
		//printf("%d\n",contains(num2, &head));
	}
	//int a = add(1,8);
	//printf("%d\n", a);
	printf("%s\n", "printing list: ");
	printLinkedList(&head);

	destroyLinkedList(&head);

	return 0;
}
