#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task1.h"

#define SIZEBUF 200

int main()
{
	char bufIn[SIZEBUF];
	char bufOut[SIZEBUF];
	FILE *fp;
	fp = fopen("fp.txt", "r");
	if (fp == NULL)
	{
		printf("Error!\n");
		return 1;
	}
	else
	{
		while (feof(fp) == 0)
		{
			fgets(bufIn, SIZEBUF, fp);
			if (bufIn[strlen(bufIn) - 1] == '\n')
				bufIn[strlen(bufIn) - 1] = '\0';
			randomWords(bufIn, bufOut);
			printf("%s\n", bufOut);
		}
		fclose(fp);
	}
	return 0;
}