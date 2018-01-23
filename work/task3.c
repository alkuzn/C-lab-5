#include <stdio.h>
#include <string.h>
#include <time.h>
#include "task3.h"

#define IN 1
#define OUT 0

char *mixLine(char *instr, char * outstr)
{
	int flag = OUT;
	int i = 0, j = 0;
	int n = 0;
	int count = 0;
	char *bufin;
	char *bufout;
	while (instr[i] != '\0')
	{
		if (instr[i] != ' ' && flag == OUT)
		{
			flag = IN;
			bufin = &instr[i];
		}
		else if ((instr[i] == ' ' && flag == IN)||(instr[i] == '\n' && flag == IN))
		{
			flag = OUT;
			bufout = &instr[i-1];
			mixChars(bufin, bufout);
			j++;
		}
		i++;
	}
	i = 0;
		while (instr[i] != '\0')
		{
			outstr[i] = instr[i++];
		}
	outstr[i] = '\0';
	return outstr;
}


char *mixChars(char *in, char *out)
{
	srand(time(0));
	int i = 1;
	int sword = out - in;
	char cword = 0;
	int j = 0, k = 0;
	for (int i = 0; i < sword-1; i++)
	{
		j = rand() % (sword-1) + 1;
		k = rand() % (sword-1) + 1;
			cword = in[j];
			in[j] = in[k];
			in[k] = cword;
	}
	return in;
}