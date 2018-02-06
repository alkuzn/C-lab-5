#include <stdio.h>
#include <stdlib.h>
#include "task1.h"

int main()
{
	char in[SIZE] = { NULL };
	char out[SIZE] = { NULL };
	
	printf("Enter a string, please:\n");
	fgets(in, SIZE, stdin);
	
	printf("Your string is randomized:\n");
	puts(randomWords(in, out));
	
	return 0;
}