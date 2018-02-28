#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"

#define IN 1
#define OUT 0

char *mixLine(char *instr, char * outstr)
{
	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	int flag = OUT;
	int i = 0, j = 0;
	int n = 0;
	int count = 0;
	char bufin[20] = { 0 };
	char bufout[20] = { 0 };
	while (instr[i] != '\0')
	{
		if (instr[i] != ' ' && instr[i] != '\0' && flag == OUT)
		{
			flag = IN;
			bufin[j++] = instr[i];
			count++;
		}
		else if (instr[i] != ' ' && instr[i] != '\0' && flag == IN)
		{
			bufin[j++] = instr[i];
			count++;
		}
		else if (instr[i] == ' ' && flag == IN)
		{
			flag = OUT;
			bufin[j] = '\0';
			mixChars(bufin, bufout);
			for (j = 0; j < count; j++)
				outstr[n++] = bufout[j];
			j = 0;
			count = 0;
			outstr[n++] = ' ';
		}
		i++;
	}
	if (instr[i] == '\0' && flag == IN)
	{
		flag = OUT;
		bufin[j] = '\0';
		mixChars(bufin, bufout);
		for (j = 0; j < count; j++)
			outstr[n++] = bufout[j];
		j = 0;
		count = 0;
		outstr[n++] = '\0';
	}

	while (outstr[strlen(outstr) - 1] == ' ')
	{
		outstr[strlen(outstr) - 1] = '\0';
	}
	return outstr;
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