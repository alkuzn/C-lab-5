#include "task3.h"

int main()
{
	char instr[SIZE] = { '0' };
	char outstr[SIZE] = { '0' };
	FILE *fpInput = fopen("input.txt", "rt");
	FILE *fpOutput = fopen("output.txt", "wt");

	if (fpInput == NULL || fpOutput == NULL)
	{
		puts("404! Couldn't find the file!");
		return 1;
	}

	while (fgets(instr, SIZE, fpInput) != NULL)
		fprintf(fpOutput, "%s\n", mixLine(instr, outstr));

	puts("Randomizing is done!");

	return 0;
}