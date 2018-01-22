#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"

int main()
{
	srand(time(0));
	char strIn[BUF_SIZE] = { '\0' };
	char strOut[BUF_SIZE] = { '\0' };

	FILE *fpIn = fopen("str_in.txt", "r");
	FILE *fpOut = fopen("str_out.txt", "w+");
	if (fpIn == NULL || fpOut == NULL)
		puts("File error!");

	while (fgets(strIn, BUF_SIZE, fpIn) != NULL)
		fprintf(fpOut, "%s\n", randomWords(strIn, strOut));

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}