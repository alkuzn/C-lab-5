#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#define LENSTR 512

int main()
{
	char inStr[LENSTR];
	char outStr[LENSTR];
	printf("Enter the string to process: ");
	fgets(inStr, LENSTR, stdin);
	randomWords(inStr, outStr);
	printf("%s\n", outStr);
	return 0;
}