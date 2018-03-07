#include <string.h>
#include <stdlib.h>
#include "task3.h"
#include <time.h>

char *mixChars(char *in, char *out)
{
	int rand_pos, lenght = strlen(in);
	char buf;
	int i = 0;
	while (out[i++] = in[i]);
	for (i = 1; i < lenght - 2; ++i)
	{
		rand_pos = 1 + rand() % (lenght - 2);
		buf = out[rand_pos];
		out[rand_pos] = out[i];
		out[i] = buf;
	}
	return out;
}

char *mixLine(char *in, char *out)
{
	char buf[256] = {0};
	char word[256] = {0};
	int begin = 0;
	int inword = 0, count = 0, strlenght = strlen(in);
	int y = 0;
	int i = 0;
	for (i = 0; i < strlenght; ++i)
	{
		if ((in[i] != ' ' && in[i] != '\n') && !inword)
		{
			word[y++] = in[i];
			inword = 1;
			begin = i;
		}
		else if ((in[i] != ' ' && in[i] != '\n') && inword)
		{
			word[y++] = in[i];
		}else if ((in[i] == ' ') && inword)
		{
			word[y] = '\0';
			mixChars(word, buf);
			for (int f = begin, z=0; f < i; ++z, ++f)
				out[f] = buf[z];
			y = 0;
			out[i] = ' ';
			inword = 0;
		}else out[i] = ' ';
	}
	if (inword)
	{
		word[y] = '\0';
		mixChars(word, buf);
		int f  = begin ;
		for (int z = 0; f < i; ++z, ++f)
			out[f] = buf[z];
		out[f] = '\0';
	}
	else out[i] = '\0';
	return out;
}