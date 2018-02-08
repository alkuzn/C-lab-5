#include <stdio.h>
#include <string.h>
#include "task1.h"

int main()
{
	char in[512] = { 0 };
	char out[512] = { 0 };
	
	fgets(in, 512, stdin);
	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] == '\n') {
			in[i] = '\0';
			break;
		}
	}
	printf("%s\n", randomWords(in, out));
	return 0;
}
