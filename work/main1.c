#include "task1.h"

int main()
{
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	
	printf("Enter string:\n");
	fgets(in, SIZE, stdin);
	in[strlen(in) - 1] = '\0';
	puts("After randomizer:");
	puts(randomWords(in, out));
	return 0;
}