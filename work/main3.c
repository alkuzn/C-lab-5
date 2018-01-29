#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"

int main()
{
	srand(time(0));
	char str[SIZE] = { NULL };
	char strmod[SIZE] = { NULL };
	
	FILE *fpr = fopen("task3in.txt", "rt");
	FILE *fpw = fopen("task3out.txt", "wt");
	if (fpr == NULL || fpw == NULL)
	{
		puts("Files not found! You must create files.");
		return 1;
	}
	while (fgets(str, SIZE, fpr) != NULL)
	{
		fprintf(fpw, "%s\n", mixLine(str, strmod));
	}

	fclose(fpr);
	fclose(fpw);

	/*
	[Check]
	printf("Enter a string, please:\n");
	fgets(str, SIZE, stdin);

	printf("Your string is modificated:\n");
	puts(mixLine(str, strmod));
	*/

	return 0;
}