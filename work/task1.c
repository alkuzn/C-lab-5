#include <time.h>
#include "task1.h" 
#include <time.h>
#include <string.h>

char * randomWords(char *in, char *out)
{
	char *buf[256];
	int inword = 0, count = 0, strlenght = strlen(in);
	for (int i = 0, y = 0; in[i]; ++i)
	{
		if ((in[i] != ' ') && !inword)
		{
			inword = 1;
			buf[y++] = in + i;
			count++;
		}
		else if ((in[i] == ' ') && inword)
		{
			inword = 0;
		}
	}
	char *chbuf;
	int num;
	for (int i = 0; i < count; ++i)
	{
		num = rand() % count;
		chbuf = buf[i];
		buf[i] = buf[num];
		buf[num] = chbuf;
	}

	int i = 0;
	for (int  y = 0; i < strlenght && y < count; ++i)
	{
		if (buf[y][0] != '\ ' && buf[y][0] != '\0')
		{
			out[i] = buf[y][0];
			buf[y]++;
		}
		else {
			out[i] = '\ ';
			y++;
		}
	}
	out[i] = '\0';
	return out;
}