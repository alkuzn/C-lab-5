#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define SIZE 256



int main()
{
	srand(time(0));
	int i = 0;
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	FILE *wp;
	FILE *fp;
	fp = fopen("fp.txt", "r");
	wp = fopen("mp.txt", "wt");

	char *in1 = " mad  max  ";
//	mixLine(in1, out);
	if (fp == NULL || wp == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	else
	{
		while (feof(fp) == 0)
		{
			fgets(in, SIZE, fp);
			if (in[strlen(in) - 1] == '\n')
				in[strlen(in) - 1] = '\0';
			mixLine(in, out);
			fprintf(wp, "%s\n", out);
			for (i = 0; i < SIZE; i++)
			{
				in[i] = 0;
				out[i] = 0;
			}
		}
		fclose(fp);
		fclose(wp);
	}
//	printf("%s", out);
	return 0;
}