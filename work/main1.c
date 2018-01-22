#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"

int main()
{
	srand(time(0));
	char in[BUF_SIZE + 1] = { '\0' };
	char out[BUF_SIZE + 1] = { '\0' };
	printf("Enter your string: ");
	fgets(in, BUF_SIZE, stdin);
	puts(randomWords(in, out));
	return 0;
}