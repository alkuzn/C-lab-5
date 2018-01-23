#include <stdio.h>
#include <string.h>
#include <time.h>
#include "task1.h"

#define IN 1
#define OUT 0
#define SIZEBUF 200

char * randomWords(char * in, char *out)
{
	srand(time(0));
	int flag = OUT;
	int i = 0, j = 0;
	int count = 0;
	char *buf[SIZEBUF];
	int n = 0;
	while (in[i] != '\0')
	{
		if (in[i] != ' ' && flag == OUT)
		{
			flag = IN;
			buf[j] = &in[i];
			j++;
		}
		else if (in[i] == ' ' && flag == IN)
			flag = OUT;
		i++;
	}
	count = j;
	for (i=0; i<j; i++)
	{
		int pos = rand() % count--;
		int k = 0;
		while (buf[pos][k] != '\0' && buf[pos][k] != ' ')
		{
			out[n++] = buf[pos][k++];
		}
		out[n++] = ' ';
		for (; pos < count; pos++)
		{
			buf[pos] = buf[pos+1];
		}
	}
	out[n] = '\0';
}
