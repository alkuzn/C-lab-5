#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"
#define IN 1
#define OUT 0

char * randomWords(char * in, char *out)
{
	char * pOut[16] = { 0 };
	int flag = OUT;
	int i = 0;
	int j = 0;

	while (in[i])
	{
		if (in[i] != ' ' && flag == OUT)
		{
			flag = IN;
			pOut[j++] = &in[i];
		}
		else if (in[i] == ' ' && flag == IN)
		{
			flag = OUT;
		}
		i++;
	}

	srand(time(0));

	for (int i = 0; i < j; i++)
	{
		int j = rand() % (strlen(pOut) + 1);
		if (j != i)
		{
			int buff = pOut[i];
			pOut[i] = pOut[j];
			pOut[j] = buff;
		}
	}

	int n = 0;
	
	for (int k = 0; k < j; k++)
	{
		int u = 0;
		while (*(pOut[k] + u) != ' ' && *(pOut[k] + u) != '\0' && *(pOut[k] + u) != '\n')
		{
			out[n++] = *(pOut[k] + u++);
		}
		if (k != (j-1))
			out[n++] = ' ';
	}
	
	return out;

}