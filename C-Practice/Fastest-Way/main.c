/*
   Codeeval.com solution to "WHICH WAY IS FASTER?" problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
bool validIndex(int x, int y, int dx, int dy);
int getXBFS(int counter, int dx, int dy);
int getYBFS(int counter, int dx, int dy);
int squareRootInt(int x);
int getMatrixDim(const char *line);
static int WIDTH = 0;
static int HEIGHT = 0;
static const char emptyCell = '*';
static const char port = 'P';
static const char start = 'S';
static const char finish = 'F';
static const char mountain = '^';
bool isEmptyCell(char ar[WIDTH][HEIGHT], int x0, int y0, const char c);
void getPortLocations(char ar[WIDTH][HEIGHT], int *pt, const char c);
void getLocation(char ar[WIDTH][HEIGHT], int *pt, const char c);

int unitDistance(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1);
int getSeaTime(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1, int p0x, int p0y, int p1x, int p1y);
int getLandTime(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1);

void printArray(char ar[WIDTH][HEIGHT]);
void printIntArray(int ar[WIDTH][HEIGHT]);
void processInput(char * line, char ar[WIDTH][HEIGHT],int dr[WIDTH][HEIGHT]);

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
	bool firstRun = true;
	while(fgets(line, 1024, file)) {
		// Do something with the line
		if(firstRun == true) {
			firstRun = false;
		} else {
			printf("%c", '\n');
		}
		WIDTH = getMatrixDim(line);
		HEIGHT = getMatrixDim(line);
		char inputMatrix[WIDTH][HEIGHT];
		int distanceMatrix[WIDTH][HEIGHT];
		processInput(line, inputMatrix, distanceMatrix);
		int * portLocations = (int *)malloc(4 * sizeof(int));
		getPortLocations(inputMatrix, portLocations, port);
		int * startLocation = (int *)malloc(2 * sizeof(int));
		getLocation(inputMatrix, startLocation, start);
		int * finishLocation = (int *)malloc(2 * sizeof(int));
		getLocation(inputMatrix, finishLocation, finish);
		int startingX = *(startLocation);
		int startingY = *(startLocation + 1);
		int destinationX = *(finishLocation);
		int destinationY = *(finishLocation + 1);
		int port1X = *(portLocations);
		int port1Y = *(portLocations + 1);
		int port2X = *(portLocations + 2);
		int port2Y = *(portLocations + 3);

		int seaTime1 = getSeaTime(inputMatrix, distanceMatrix, startingX, startingY, destinationX, destinationY, port1X, port1Y, port2X, port2Y);

		int seaTime2 = getSeaTime(inputMatrix, distanceMatrix, startingX, startingY, destinationX, destinationY, port2X, port2Y, port1X, port1Y);


		int landTime = getLandTime(inputMatrix, distanceMatrix, startingX, startingY, destinationX,
		destinationY);

		if(seaTime1 < seaTime2) {
			if(seaTime1 < landTime) {
				printf("%d", seaTime1);
			} else {
				printf("%d", landTime);
			}
		} else {
			if(seaTime2 < landTime) {
				printf("%d", seaTime2);
			} else {
				printf("%d", landTime);
			}
		}
		free(portLocations);
		free(startLocation);
		free(finishLocation);
	}

	fclose(file);
	return 0;
}

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

void processInput(char * line, char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT]) {


	int row = WIDTH - 1;

	char delim[4] = {' ', '|', ' '};
	char * token = strtok(line, delim);

	while(token != NULL) {
		//printf("%s\n", token);	
		for(int i = 0; i < WIDTH; i++) {
			 char temp = *(token + i);
			 ar[i][row] = temp;
		}
		row--;
		token = strtok(NULL, delim);
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

	int distance = 0;
	int destinationX = x1;
	int destinationY = y1;

	bool validPoint = validIndex(x0, y0, WIDTH, HEIGHT);
	bool validDestination = validIndex(destinationX, destinationY, WIDTH,
	HEIGHT);
	if(validPoint == true && validDestination) {
		struct queue q;
		initializeQueue(&q);
		const int startingDistance = 0;
		enqueue(&q, x0, y0, startingDistance);
		dr[0][0] = 0;
		bool atDestination = false;

		while(q.size > 0 && atDestination == false) {

			struct node temp = peek(&q);
			int currentDistance = temp.data;
			int newDistance = currentDistance + 1;
			int currentX = temp.x;
			int currentY = temp.y;


			int upperX = currentX;
			int upperY = currentY + 1;
			if(upperX == destinationX && upperY == destinationY) {
				atDestination = true;
				distance = newDistance;
			} else {
				if(validIndex(upperX, upperY, WIDTH, HEIGHT) == true && isEmptyCell(ar, upperX,
					upperY, emptyCell) == true) {
					if(dr[upperX][upperY] == -1) {
						enqueue(&q, upperX, upperY, newDistance);
						dr[upperX][upperY] = newDistance;
					}
				}
			}


			int rightX = currentX + 1;
			int rightY = currentY;
			if(rightX == destinationX && rightY == destinationY) {
				atDestination = true;
				distance = newDistance;
			} else {
				if(validIndex(rightX, rightY, WIDTH, HEIGHT) == true && isEmptyCell(ar, rightX,
					rightY, emptyCell) == true) {
					if(dr[rightX][rightY] == -1) {
						enqueue(&q, rightX, rightY, newDistance);
						dr[rightX][rightY] = newDistance;
					}
				}
			}


			int leftX = currentX - 1;
			int leftY = currentY;
			if(leftX == destinationX && leftY == destinationY) {
				atDestination = true;
				distance = newDistance;
			} else {
				if(validIndex(leftX, leftY, WIDTH, HEIGHT) == true &&
						isEmptyCell(ar, leftX, leftY, emptyCell) == true) {
					if(dr[leftX][leftY] == -1) {
						enqueue(&q, leftX, leftY, newDistance);
						dr[leftX][leftY] = newDistance;
					}
				}	}


			int lowerX = currentX;
			int lowerY = currentY - 1;
			if(lowerX == destinationX && lowerY == destinationY) {
				atDestination = true;
				distance = newDistance;
			} else {
				if(validIndex(lowerX, lowerY, WIDTH, HEIGHT) == true
						&& isEmptyCell(ar, lowerX, lowerY, emptyCell) == true) {
					if(dr[lowerX][lowerY] == -1) {
						enqueue(&q, lowerX, lowerY, newDistance);
						dr[lowerX][lowerY] = newDistance;
					}
				}
			}

			deque(&q);
		}

		destroyQueue(&q);
		for(int i = 0; i < WIDTH; i++) {
			for(int k = 0; k < HEIGHT; k++) {
				dr[i][k] = -1;			 
			}

	}

		if(atDestination == false) {
			distance = -1;
		}
	} else {
		return -1;
	}
	
	return distance;
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
		while(iterator->next != NULL) {
			iterator = iterator->next;
		}
		struct node temp = *iterator;
		return temp;
	}
}

bool isEmptyCell(char ar[WIDTH][HEIGHT], int x0, int y0, const char c) {

	if(ar[x0][y0] == c || ar[x0][y0] == 'P') {
		return true;
	} else {
		return false;
	}
}

void getPortLocations(char ar[WIDTH][HEIGHT], int * ptr, const char c) {

	int counter = 0;
	for(int i = 0; i < HEIGHT; i++) {
		for(int k = 0; k < WIDTH; k++) {
			if(ar[i][k] == c) {
				*(ptr + counter) = i;
				counter++;
				*(ptr + counter) = k;
				counter++;
			}
		}

	}

}

int getSeaTime(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0,
		int x1, int y1, int p0x, int p0y, int p1x, int p1y) {

	int startingX = x0;
	int startingY = y0;

	int destinationX = x1;
	int destinationY = y1;

	int port1X = p0x;
	int port1Y = p0y;

	int port2X = p1x;
	int port2Y = p1y;

	const int landMultiplier = 2;
	const int seaMultiplier = 1;
	const int timeToBoard = 1;

	int timeToPort1 = (unitDistance(ar, dr, startingX, startingY, port1X,
	port1Y) * landMultiplier);
	//printf("%s %d", "time to port1:", timeToPort1);

	int timeAtPort1 = timeToBoard;
	//printf("%s %d", "time at port 1: ", timeAtPort1);

	int timePort1ToPort2 = (unitDistance(ar, dr, port1X, port1Y, port2X,
	port2Y) * seaMultiplier);
	//printf("%s %d", "time p1 to p2: ", timePort1ToPort2); 

	int timeAtPort2 = timeToBoard;
	//printf("%s %d", "time at port 2: ", timeAtPort2);

	int port2ToDes = (unitDistance(ar, dr, port2X, port2Y, destinationX,
	destinationY) * landMultiplier);
	//printf("%s %d", "time port2 to des: ", port2ToDes); 

	int totalTime = timeToPort1 + timeAtPort1 + timePort1ToPort2 +
	timeAtPort2 + port2ToDes;
	//printf("%s %d", "total time: ", totalTime);	

	return totalTime;
}

void getLocation(char ar[WIDTH][HEIGHT], int *pt, const char c) {
	for(int i = 0; i < WIDTH; i++) { 
		for(int k = 0; k < HEIGHT; k++) {
			if(ar[i][k] == c) {
				*(pt) = i;
				*(pt + 1) = k;
			}
		}
	}
}

int getLandTime(char ar[WIDTH][HEIGHT], int dr[WIDTH][HEIGHT], int x0, int y0, int x1, int y1) {

	int startingX = x0;
	int startingY = y0;
	int destinationX = x1;
	int destinationY = y1;
	int landMultiplier = 2;
	int time = (unitDistance(ar, dr, startingX, startingY, destinationX, destinationY) * landMultiplier);

	return time;

}

int getMatrixDim(const char *line) {
	int counter = 0;
	while(*(line + counter) != ' ') {
		counter++;
	}
	return counter;
}
