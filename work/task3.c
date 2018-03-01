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
	char *pointer = outstr;
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
	return pointer;
}


char *mixChars(char *in, char *out)
{
	int i = 0;
	int sword = 0;
	int j = 0;
	char cword = 0;

	while (in[sword] != '\0')
	{
		out[sword] = in[sword++];
	}
	out[sword] = '\0';
	if (sword > 3)
	{
		for (int i = 1; i < sword - 1; i++)
		{
			j = rand() % (sword - 2) + 1;
			cword = out[i];
			out[i] = out[j];
			out[j] = cword;
		}
	}
	return out;
}