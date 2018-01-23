#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task3.h"

#define M 80



int main()
{
	int i = 0;
	char in[M] = { 0 };
	char out[M] = { 0 };
	FILE *wp;
	FILE *fp;
	fp = fopen("fp.txt", "r");
	wp = fopen("mp.txt", "wt");
	if (fp == NULL || wp == NULL)
	{
		printf("Error!\n");
		return 0;
	}
	else
	{
		while (feof(fp) == 0)
		{
			fgets(in, M, fp);
			if (in[strlen(in) - 1] != '\n')
				in[strlen(in)] = '\n';
			mixLine(in, out);
			fprintf(wp, "%s", out);
			for (i = 0; i < M; i++)
			{
				in[i] = 0;
				out[i] = 0;
			}
		}
		fclose(fp);
		fclose(wp);
	}


	return 0;
}