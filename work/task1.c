#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

void relocPtr(char *words[], int numWords)
{
	char *tmp = NULL;
	int currRand = 0, currNum = numWords;
	while (currNum > 1)
	{
		currRand = rand() % currNum;
		if (currRand != (currNum - 1))
		{
			tmp = words[currNum - 1];
			words[currNum - 1] = words[currRand];
			words[currRand] = tmp;

		}
		currNum--;
	}
}

char * randomWords(char *in, char *out)
{
	char *words[BUF_SIZE] = { NULL };
	char *p = NULL, *outT = out;
	int i = 0, inWord = 0, count = 0, attCount = 0;

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	while (in[i])
	{
		if (in[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			words[count] = &(in[i]);
			if (in[i + 1] == '\0')
			{
				inWord = 0;
				count++;
				break;
			}
		}
		else if (in[i] == ' ' && inWord == 1)
		{
			inWord = 0;
			count++;
		}
		else if (in[i] != ' ' && inWord == 1)
		{
			if (in[i + 1] == '\0')
			{
				inWord = 0;
				count++;
				break;
			}
		}
		i++;
	}

	do
	{
		p = NULL;
		outT = out;
		relocPtr(words, count);
		for (i = 0; i < count; i++)
		{
			p = words[i];
			while (*p != ' ' && *p != '\0')
				*outT++ = *p++;
			if (i < count - 1)
				*outT++ = ' ';
		}
		*outT = '\0';
		attCount++;
	} while (strcmp(out, in) == 0 && count > 1 && attCount <= ATT_NUM);

	return out;
}