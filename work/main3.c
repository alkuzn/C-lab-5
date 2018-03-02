#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define SIZE 256

int main()
{
	srand(time(0));
//	char *in = " mad  max   ";
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	char *outstr = 0;
	FILE *fp;
	fp = fopen("fp.txt", "r");
	if (fp == NULL)
	{
		printf("Error!\n");
		return 1;
	}

	while (feof(fp) == 0)
	{
		fgets(in, SIZE, fp);
		outstr = mixLine(in, out);
		printf("%s\n", outstr);
		for (int i = 0; i < SIZE; i++)
		{
			in[i] = 0;
			out[i] = 0;
		}
	}
	fclose(fp);

	return 0;
}