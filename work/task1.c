#include "task1.h"

#define IN 1
#define OUT 0

void *randomWords(char *in, char *out)
{
	char *arrPtr[SIZE] = { NULL };
	int flag = OUT;
	int count = 0;
	srand(time(0));
	int random = 0;
	char *temp = out;

	while (*in)
	{
		if (*in != ' ' && flag == OUT)
		{
			*(arrPtr + count++) = in;
			flag = IN;
		}
		else if (*in == ' ' && flag == IN)
			flag = OUT;
		in++;
	}


	//string randomizer
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
		if (random != count - 1)
			*(arrPtr + random) = *(arrPtr + count - 1);
		count--;
	}
	out[strlen(out) - 1] = '\0';
	return temp;
}