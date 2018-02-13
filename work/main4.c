#include "task1.h"

int main()
{
	srand(time(0));
	char input[SIZE] = { '0' };
	char output[SIZE] = { '0' };

	FILE *fpInput = fopen("input.txt", "rt");
	FILE *fpOutput = fopen("output.txt", "wt");

	if (fpInput == NULL || fpOutput == NULL)
	{
		puts("404! Couldn't find the file!");
		return 1;
	}
	//input to output
	while (fgets(input, SIZE, fpInput) != NULL)
		fprintf(fpOutput, "%s\n", randomWords(input, output));

	fclose(fpInput);
	fclose(fpOutput);
		
	return 0;
}