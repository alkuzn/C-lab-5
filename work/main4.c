#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "task1.h"


/*
#define OUT 0
#define SIZE 100
#include<string.h>
#include<time.h>
#include<stdlib.h>
*/

int main()
{
	int i = 0, len = 0, j = 0;
	char buf[SIZE] = { 0 };
	char bufOut[SIZE] = { 0 };
	char *out = bufOut;
	
	FILE *fp = fopen("fp.txt", "r");
	FILE *fpFinal = fopen("fpFinal.txt", "w");
	if (fp==NULL||fpFinal==NULL)
	printf("ERROR file fp.txt: \n");
	
	while (fgets(buf, SIZE, fp)!=0)
	{

		fprintf(fpFinal, "%s\n", randomWords(buf, out));
	}
	fclose(fp);
	fclose(fpFinal);

	return 0;
}