#include "task1.h"
#define IN 1
#define OUT 0

char * randomWords(char * in, char *out)
{
	if (*in == '\n')
	{
		return in;
	}
		
	char* arrPtr[SIZE];
	int count = 0;
	int flag = OUT;
	int size=strlen(in);
	if (in[size - 1] == '\n')
		in[size - 1] = '\0';
	while (*in)
	{
		if (*in != ' ' && flag == OUT)
		{
			*(arrPtr+count++) = in;
			flag = IN;
		}
		else if (*in == ' ' && flag == IN)
			flag = OUT;
		in++;
	}
	srand(time(0));
	int random;
	char* temp = out;
	while (count)
	{
		random = rand() % count;
		while (*(arrPtr[random]) != ' ')
		{
			if (*(arrPtr[random]) == '\0')
				break;
			*out = *(arrPtr[random]++);
			out++;
		}
		*out++ = ' ';		
		if (random!=count-1)
			*(arrPtr + random) = *(arrPtr + count-1);
		count--;
	}
	out--;
	*out = '\0';
	return temp;
}