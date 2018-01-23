#include <stdio.h>
#include <string.h>
#include "task1.h"

#define IN 1
#define OUT 0
#define SIZEBUF 200

int main()
{
	char bufIn[SIZEBUF];
	char bufOut[SIZEBUF];



	printf("Enter a line please:\n");
	fgets(bufIn, SIZEBUF, stdin);
	bufIn[strlen(bufIn) - 1] = '\0';

	randomWords(bufIn, bufOut);

	printf("%s\n", bufOut);
	return 0;
}