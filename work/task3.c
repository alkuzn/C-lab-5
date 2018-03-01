#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define IN 1
#define OUT 0
#define SIZE 256


char *mixLine(char *instr, char * outstr)
{
	int n = 0;
	int count = 0;
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	int flag = OUT;
	int i = 0, j = 0;
	while (instr[i] != '\0')
	{
		if (instr[i] != ' '&& flag == OUT)
		{
			count = 0;
			j = 0;
			flag = IN;
			in[j++] = instr[i];
			count++;
		}
		else if (instr[i] != ' '&& instr[i] != '\n'&& flag == IN)
		{
			in[j++] = instr[i];
			count++;
		}
		else if ((instr[i] == ' ' || instr[i] == '\n') && flag == IN)
		{
			in[j] = '\0';
			flag = OUT;
			mixChars(in, out);
			for (j = 0; j < count; j++)
			{
				outstr[n++] = out[j];
			}
			outstr[n++] = ' ';
		}
		i++;
	}
	if (outstr[n - 1] == ' ')
		outstr[n - 1] = '\0';
	if (instr[i] == '\0'&& flag == IN)
	{
		in[j] = '\0';
		flag = OUT;
		mixChars(in, out);
		for (j = 0; j < count; j++)
		{
			outstr[n++] = out[j];
		}
		outstr[n++] = '\0';
	}
	return outstr;
}

char *mixChars(char *in, char *out)
{
	char tmp = 0;
	int len = strlen(in);
	for (int i = 0; i <= len; i++)
		out[i] = in[i];
	int randomCh = 0;
	if (len <= 3)
		return out;
	for (int i = 1; i < len - 1; i++)
	{
		randomCh = rand() % (len - 2) + 1;
		tmp = out[i];
		out[i] = out[randomCh];
		out[randomCh] = tmp;
	}
	return out;
}

