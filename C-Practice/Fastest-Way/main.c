/*
   Codeeval.com solution to "WHICH WAY IS FASTER?" problem.
 */

#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
bool validIndex(int x, int y, int dx, int dy);
int getXBFS(int counter, int dx, int dy);
int getYBFS(int counter, int dx, int dy);
int squareRootInt(int x);
static const int WIDTH = 4;
static const int HEIGHT = 4;

int unitDistance(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1);
void printArray(char ar[WIDTH][HEIGHT]);
void printIntArray(int ar[WIDTH][HEIGHT]);
void processInput(const char * line, char ar[WIDTH][HEIGHT],int dr[WIDTH][HEIGHT]);

struct node {
	struct node * next;
	int x;
	int y;
	int data;
};

struct queue {
	struct node * tail;
	int size;
};

void initializeQueue(struct queue * q);
void enqueue(struct queue * q, int x, int y, int data);
void deque(struct queue * q);
void destroyQueue(struct queue * q);
void destroyNode(struct node * n);
void printQueue(struct queue * q);
struct node peek(struct queue * q);

int main(int argc, const char * argv[]) {

	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while(fgets(line, 1024, file)) {
		// Do something with the line
		//printf("%s", line);
		char inputMatrix[WIDTH][HEIGHT];
		int distanceMatrix[WIDTH][HEIGHT];
		processInput(line, inputMatrix, distanceMatrix);
		printIntArray(distanceMatrix);
		//unitDistance(inputMatrix, distanceMatrix, 0, 0, 3, 3);
	}


	/*struct queue myQueue;
	initializeQueue(&myQueue);
	enqueue(&myQueue, 0, 0, 8);
	enqueue(&myQueue, 0, 0, 2);
	enqueue(&myQueue, 0, 0, 8);
	enqueue(&myQueue, 0, 0, 0);
	struct node tn = peek(&myQueue);
	printf("%s %d\n","peeking: ", tn.data);
	printQueue(&myQueue);
	deque(&myQueue);
	printf("%s\n", "here");
	enqueue(&myQueue, 0, 0, 90);
	enqueue(&myQueue, 0, 0, 10);
	struct node sn = peek(&myQueue);
	printf("%s %d\n","peeking: ", sn.data);
	deque(&myQueue);
	deque(&myQueue);
	printQueue(&myQueue);
	destroyQueue(&myQueue);*/

	fclose(file);
	return 0;
}

//
bool validIndex(int x, int y, int dw, int dh) {

	if(x < 0) {
		return false;
	}

	if(y < 0) {
		return false;
	}

	if(x > (dw - 1)) {
		return false;
	}

	if(y > (dh - 1)) {
		return false;
	}

	return true;
}

int getXBFS(int counter, int dx, int dy) {

	int x;
	int sqr = squareRootInt(counter);
	int lowerRange = sqr * sqr;
	int upperRange = (((sqr + 1) * (sqr + 1)) - 1);
	int range = upperRange - lowerRange + 1;
	int midRange = (range / 2) + lowerRange;
	if(counter < midRange) {
		x =  counter - lowerRange;
	} else {
		x = sqr;
	}
	return x;
}

int getYBFS(int counter, int dx, int dy) {

	int y;
	int sqr = squareRootInt(counter);
	int lowerRange = sqr * sqr;
	int upperRange = (((sqr + 1) * (sqr + 1)) - 1);
	int range = upperRange - lowerRange + 1;
	int midRange = (range / 2) + lowerRange;
	if(counter > midRange) {
		y =  upperRange - counter;
	} else {
		y = sqr;
	}
	return y;
}

int squareRootInt(int x) {

	int counter = 0;
	int square = counter * counter;
	while(square <= x) {

		counter++;
		square = counter * counter;
	}

	counter--;
	square = counter * counter;
	return counter;
}

void processInput(const char * line, char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT]) {

	for(int i = 0; i < 4; i++) {
		int counter = ((HEIGHT - 1) * (HEIGHT - 1));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
			}

	for(int i = 7; i < 11; i++) {
		int counter = ((HEIGHT - 2) * (HEIGHT - 2));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 7;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}

	for(int i = 14; i < 18; i++) {
		int counter = ((HEIGHT - 3) * (HEIGHT - 3));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 14;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}

	for(int i = 21; i < 25; i++) {
		int counter = ((HEIGHT - 4) * (HEIGHT - 4));
		int y = getYBFS(counter, WIDTH, HEIGHT);
		int x = i - 21;
		char tempChar = *(line + i); 
		ar[x][y] = tempChar;
	}

	for(int i = 0; i < WIDTH; i++) {

		for(int k = 0; k < HEIGHT; k++) {
			dr[i][k] = -1;			 
		}

	}
}

void printArray(char ar[WIDTH][HEIGHT]) {

	printf("%s\n", "Printing Array: ");

	for(int i = HEIGHT - 1; i >= 0; i--) { 

		for(int k = 0; k < WIDTH; k++) {
			printf("%c ", ar[k][i]);
		}
		printf("%c", '\n');
	}
}

void printIntArray(int ar[WIDTH][HEIGHT]) {

	printf("%s\n", "Printing Array: ");

	for(int i = HEIGHT - 1; i >= 0; i--) { 

		for(int k = 0; k < WIDTH; k++) {
			printf("%d ", ar[k][i]);
		}
		printf("%c", '\n');
	}
}

int unitDistance(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1) {

	//printf("%s\n", "getting distance");
	bool validPoint = validIndex(x0, y0, WIDTH, HEIGHT);
	if(validPoint == true) {
		struct queue q;
		initializeQueue(&q);
		enqueue(&q, x0, y0, 0);

		while(q.size > 0) {

			printf("%s", "looping");
			struct node temp = peek(&q);
			int currentDistance = temp.data;
			int newDistance = currentDistance + 1;
			int currentX = temp.x;
			int currentY = temp.y;


			int upperX = currentX;
			int upperY = currentY + 1;
			if(validIndex(upperX, upperY, WIDTH, HEIGHT)) {
				if(dr[upperX][upperY] != -1) {
					enqueue(&q, upperX, upperY, newDistance);
				}
			}

			int rightX = currentX + 1;
			int rightY = currentY;
			if(validIndex(rightX, rightY, WIDTH, HEIGHT)) {
				if(dr[rightX][rightY] != -1) {
					enqueue(&q, rightX, rightY, newDistance);
				}
			}

			int leftX = currentX - 1;
			int leftY = currentY;
			if(validIndex(leftX, leftY, WIDTH, HEIGHT)) {
				if(dr[leftX][leftY] != -1) {
					enqueue(&q, leftX, leftY, newDistance);
				}
			}

			int lowerX = currentX;
			int lowerY = currentY - 1;
			if(validIndex(lowerX, lowerY, WIDTH, HEIGHT)) {
				if(dr[lowerX][lowerY] != -1) {
					enqueue(&q, lowerX, lowerY, newDistance);
				}
			}		

			deque(&q);

		}

		destroyQueue(&q);
	} else {
		return -1;
	}

	return 0;
}


void initializeQueue(struct queue * q) {

	q->tail = NULL;
	q->size = 0;

}

void enqueue(struct queue * q, int x, int y, int data) {

	if(q->tail == NULL) {
		struct node * tempNode = (struct node *)malloc(sizeof(struct node));
		tempNode->x = x;
		tempNode->y = y;
		tempNode->data = data;
		tempNode->next = NULL;
		q->tail = tempNode;
		q->size = (q->size) + 1;
		
	} else {
		struct node * tempNext = q->tail;

		struct node * tempNode = (struct node *) malloc(sizeof(struct
					node));
		tempNode->x = x;
		tempNode->y = y;
		tempNode->data = data;
		tempNode->next = tempNext;

		q->tail = tempNode;
		q->size = (q->size) + 1;
	}
}

void deque(struct queue * q) {

	if(q->tail != NULL) {
		struct node * iterator = q->tail;
		if(iterator->next == NULL) {
			free(iterator);
			q->tail = NULL;
			q->size = q->size - 1;
		} else {
			while((iterator->next)->next != NULL) {
				iterator = iterator->next;
			}
			free(iterator->next);
			iterator->next = NULL;
			q->size = q->size - 1;
		}
	}
}

void destroyQueue(struct queue * q) {
	struct node * temp = q->tail;
	destroyNode(temp);
	q->tail = NULL;
}

void destroyNode(struct node * n) {
	if(n != NULL) {
		destroyNode(n->next);
		free(n);
	}
}

void printQueue(struct queue * q) {

	int size = q->size;
	printf("%s %d\n", "len of queue is: ", size);
	struct node * iterator = q->tail;
	for(int i = 0; i < size; i++) {
		int t = iterator->data;
		printf("%d ", t);
		iterator = iterator->next;
	}
	printf("%c", '\n');
}

struct node peek(struct queue * q) {
	
	if(q->tail == NULL) {
		struct node temp;
		temp.x = -1;
		temp.y = -1;
		temp.data = -1;
		temp.next = NULL;
		return temp;
	} else {
		struct node * iterator = q->tail;
		//int size = q->size;
		while(iterator->next != NULL) {
			iterator = iterator->next;
		}
		struct node temp = *iterator;
		return temp;
	}
}
