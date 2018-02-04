#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "task1.h"



#define OUT 0
#define SIZE 512
#include<string.h>
#include<time.h>
#include<stdlib.h>


int main()
{
	int i = 0, len = 0, j = 0;
	char buf_m[SIZE+1] ;
	char out_m[SIZE+1];
	
	FILE *fp = fopen("fp.txt", "r");
	FILE *fpFinal = fopen("fpFinal.txt", "w");
	if (fp==NULL||fpFinal==NULL)
	printf("ERROR file fp.txt: \n");
	
	while (fgets(buf_m, SIZE, fp)!=0)
	{
		randomWords(buf_m, out_m);
		fprintf(fpFinal, "%s\n", out_m);
	}

	fclose(fp);
	fclose(fpFinal);

	return 0;
}