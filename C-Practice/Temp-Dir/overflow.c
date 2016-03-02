#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int a = 0;
	char arr_one[8];
	char arr_two[8];
	char *p = (char *)malloc(100 * sizeof(char));

	strcpy(arr_one, "one");
	strcpy(arr_two, "two");

	printf("a value: %d\n", a);
	
	printf("arr   address: %p\n", arr_one);
	printf("arr 2 address: %p\n", arr_two);
	printf("a     address: %p\n", &a);

	printf("arr value: %s\n", arr_one);

	strcpy(p, "two     hack        1");

	strcpy(arr_two, p);

	printf("arr value: %s\n", arr_one);
	printf("a value: %d\n", a);

	return 0;
}
