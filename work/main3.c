#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>



int main()
{
	srand((unsigned)time(NULL));

	char str_in[MAXSIZE] = "mad max";
	char str_out[MAXSIZE] = {'\0'};
	
	FILE *fp_in = fopen("in.txt", "r");
	FILE *fp_out = fopen("out.txt", "w");
	//   FILE *output_F=stdin;

	if (fp_in == NULL || fp_out == NULL)
	{
		perror("fopen");
		return 1;
	}

	while (fgets(str_in, MAXSIZE, fp_in) != NULL)
	{
		fprintf(fp_out, "%s\n", mixLine(str_in, str_out));

	}

	fclose(fp_in);
	fclose(fp_out);
	
	//printf("%s\n", mixLine(str_in, str_out));
	return 0;
}
