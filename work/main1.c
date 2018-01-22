#include "task1.h"


int main()
{
	char in[N] = { 0 };
	char out[N] = { 0 };
	printf("Enter a string:\n");
	if (fgets(in, N, stdin)==NULL)
	{
		printf("Invalid input!\n");
		return 1;
	}
	printf("%s",randomWords(in, out));
	return 0;
}