#include <stdio.h>
#include <time.h>
#include "task1.h"

#define BUFSIZE 256

int main()
{
	srand(time(0));
	char str[BUFSIZE];
	fgets(str, BUFSIZE, stdin);
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == '\n')
			str[i] = '\0';
	}
	char out[BUFSIZE];
	printf("%s\n", randomWords(str, out));
	return 0;
}