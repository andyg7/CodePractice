#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	char c[] = "abcdef";
	char *p;
	p = &c[0];
	for(int i = 0; i < 6; i++){
		printf("%c", *p);
		p++;
	
	}

	
	return 0;
}