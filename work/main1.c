#include "task1.h"


int main()
{
	char in[SIZE] = { 0 };
	char out[SIZE] = { 0 };
	printf("Enter a string:\n");
	if (fgets(in, SIZE, stdin) == NULL)
	{
		printf("Invalid input!\n");
		return 1;
	}
	printf("%s",randomWords(in, out));
	return 0;
}