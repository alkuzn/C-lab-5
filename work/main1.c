#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#define SIZE 512

int main()
{
	char inStr[SIZE];
	char outStr[SIZE];
	printf("Enter the string to process: ");
	fgets(inStr, SIZE, stdin);
	randomWords(inStr, outStr);
	printf("%s\n", outStr);
	return 0;
}