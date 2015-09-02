#include <stdio.h>
#include <stdlib.h>

int createInt(int n[], int s, int start);
int stringLength(char s[]);

void push(int d);
int pop();
void display();

struct node {

	int data;
	struct node *ptr;
	
};

struct node *top;
struct node *top1;
struct node *temp;

int stackSize = 0;


int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while (fgets(line, 1024, file)) {
		// Do something with the line
	
	
		int lineLength = stringLength(line);
		
		if(line[lineLength -1] == '\n')
		{
			line[lineLength -1] = '\0';
			lineLength = lineLength - 1;
		}
		
		int numArry[lineLength];
		
		for(int i = 0; i < lineLength;i++) {
			numArry[i] = line[i] - '0';	
		}
	
		int counter = 0;
		int whiteSpaces = 0;
		int numberLength = 0;
		while(line[counter] != '\n' && line[counter] != '\0' ) {
			if(line[counter] == '-'){
			//	printf("%s\n","negative number");
				numArry[counter] = -1;
			}
			if(line[counter] == ' ') {
				int tempNumber = createInt(numArry, numberLength, counter-numberLength);
				push(tempNumber);
				//	printf("%s %d\n","Pushed: ",tempNumber);
				//printf("%c",line[counter]);
				numberLength = 0;
			} else {
				numberLength++;
			}
			counter++;
		}
		
		int tempNumber = createInt(numArry, numberLength, counter-numberLength);
		push(tempNumber);
		//		printf("%s %d\n","Pushed: ",tempNumber);
		
		int tempStackCounter = stackSize;
		//	printf("%s %d\n","Stack size: ",stackSize);
		for(int i = 0; i < tempStackCounter;i++) {
			int temN = pop();
			if((i % 2) == 0) {
				if(i == tempStackCounter - 2 || i == tempStackCounter - 1) {
					printf("%d\n",temN);
				} else {
					printf("%d ",temN);
				}
			} else {
				
			}
		}
	}
	fclose(file);
	return 0;
} 

void createStack() {
	top = NULL;
}

void push(int d) {
	
	if(top == NULL) {
		top = (struct node *) malloc(sizeof(struct node));
		(*top).ptr = NULL;
		(*top).data = d;
	} else {
		temp = (struct node *) malloc(sizeof(struct node));
		(*temp).ptr = top;
		(*temp).data = d;
		top = temp;
	}
	
	stackSize++;
}

int pop() {
	
	top1 = top;
	int numToPop;
	if(top == NULL) {
		printf("%s\n","Trying to pop empty stack");
		numToPop = -1;
	} else {
		numToPop = (*top1).data;
		top1 = (*top1).ptr;
		free(top);
		top = top1;
		stackSize--;
	}
	
	return numToPop;
}

int createInt(int n[], int s, int start) {
	
	int positive = 1;
	if(n[start] == -1){
		//	printf("%s\n","got a negative num here as well");
		positive = 0;
		start++;
		s--;
	}
	
	int len = s;
	int multiple = 1;
	for(int a = 0; a < (len - 1) ;a++){
		multiple = multiple * 10;
	}
	int number = 0;
	
	for(int i = 0; i < len; i++) {
		number = number + (multiple * n[i + start]);
		multiple = multiple / 10;
	}
	if(positive == 1){
		return number;
	} else {
		return number * -1;
	}
}

int stringLength(char s[]) {
	int l = 0;
	
	while(s[l] != '\0') {
		l++;
	}
	return l;
}
