#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"

int main()
{
	char instr[N] = { 0 };
	char outstr[N] = { 0 };
	FILE *fpInput = fopen("input.txt", "rt");
	FILE *fpOutput = fopen("output.txt", "wt");
	if (fpInput == NULL || fpOutput == NULL)
	{
		puts("File open error!");
		return 1;
	}
	while (fgets(instr, N, fpInput) != NULL)
	{
		fputs(randomWords(instr,outstr), fpOutput);
		if(*instr!='\n')
			fputc('\n', fpOutput);
	}
	if (fclose(fpInput) || fclose(fpOutput))
	{
		printf("File close error!!");
		return 1;
	}


	return 0;
}