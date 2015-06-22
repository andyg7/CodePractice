#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *parent;
	struct node *leftChild;
	struct node *rightChild;

};

void insert(int n, struct node **leaf);
void destroyTree();
void createTree();
void displayTree();
void emptyArrays();
struct node * search(int , struct node * leaf);
void findPath(int index, int n, struct node *leaf);

struct node *root = NULL;
int firstArry[10];
int secondArry[10];

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];

	/*int n = 10;
	int * np = (int *)malloc(sizeof(int));
	np = &n;
	free(np);*/

	createTree(30);
	insert(8,&root);
	insert(52,&root);
	insert(3,&root);
	insert(20,&root);
	insert(10,&root);
	insert(29,&root);
	//displayTree(root);

	int arry[7] = {30,8,52,3,20,10,29};

	while(fgets(line, 1024, file)) {
		emptyArrays();
		struct node * tn = search(20,root);	
		//printf("%d\n", tn->data);
		struct node * sn = search(8,root);
	//	printf("%d\n", sn->data);
		findPath(1,20,tn);
		findPath(2,8,sn);
		for(int i = 0; i < 10; i++) {
			if(firstArry[i] != '\0') {
				printf("%d\n", firstArry[i]);
			}
			if(secondArry[i] != '\0') {
				printf("%d\n", secondArry[i]);
			}
		}
		int firstNum;
		int secondNum;
		int counter = 0;
	}

	destroyTree(root);
	return 0;
}

void createTree(int n) {
	if(root == NULL) {
		root = (struct node *) malloc(sizeof(struct node));
		(*root).data = n;
		(*root).parent = NULL;
		(*root).leftChild = NULL;
		(*root).rightChild = NULL;
	}
}

void insert(int n, struct node **leaf) {
	int currentNodeData = (*leaf)->data;
	if(n < currentNodeData) {
		if((*leaf)->leftChild == NULL) {
			struct node * temp = (struct node *) malloc(sizeof(struct node));
			(*temp).data = n;
			(*temp).parent = *leaf;
			(*temp).rightChild = NULL;
			(*temp).leftChild = NULL;
			(*leaf)->leftChild = temp;

		} else {
			insert(n, &(*leaf)->leftChild);
		}
	} else if(n > currentNodeData) {
		if((*leaf)->rightChild == NULL) {
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			(*temp).data = n;
			(*temp).parent = *leaf;
			(*temp).rightChild = NULL;
			(*temp).leftChild = NULL;
			(*leaf)->rightChild = temp;
		} else {
			insert(n, &(*leaf)->rightChild);
		}
	}
}

void displayTree(struct node * leaf) {
	if(leaf != NULL) {
		printf("%d\n", (*leaf).data);
		displayTree((*leaf).leftChild);
		displayTree((*leaf).rightChild);
	}
}

void destroyTree(struct node * leaf) {

	if(leaf != NULL){
		destroyTree((*leaf).leftChild);
		destroyTree((*leaf).rightChild);
		free(leaf);
	}

}

void emptyArrays() {
	for(int i = 0; i < 10; i++) {
		firstArry[i] = '\0';
		secondArry[i] = '\0';
	}
}

struct node *search(int n, struct node *leaf) {
	if(leaf == NULL) {
		return NULL;
	}
	int temp = (*leaf).data;
	if(temp == n) {
		return leaf;
		} else if(n < temp) {
			return search(n, leaf->leftChild);
		} else {
			return search(n, leaf->rightChild);
		}
}

void findPath(int index, int n, struct node * leaf) {
	if((*leaf).parent != NULL) {
		if(index == 1) {
			int counter = 0;
			while(firstArry[counter] != '\0') {
				counter++;
			}
			firstArry[counter] = ((*leaf).parent)->data;
			findPath(index, n, (*leaf).parent);
		} else {
			int counter = 0;
			while(secondArry[counter] != '\0') {
				counter++;
			}
			secondArry[counter] = ((*leaf).parent)->data;
			findPath(index, n, (*leaf).parent);
		}
	} 
}
