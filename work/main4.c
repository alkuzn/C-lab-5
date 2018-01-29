#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
	char str[SIZE] = { NULL };
	char strmod[SIZE] = { NULL };

	FILE *fpr = fopen("task4in.txt", "rt");
	FILE *fpw = fopen("task4out.txt", "wt");
	if (fpr == NULL || fpw == NULL)
	{
		puts("Files not found! You must create files.");
		return 1;
	}
	while (fgets(str, SIZE, fpr) != NULL)
	{		
		fprintf(fpw, "%s\n", randomWords(str, strmod));			
	}
		
	fclose(fpr);
	fclose(fpw);

	return 0;
}
