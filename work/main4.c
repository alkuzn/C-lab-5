/*
Программа, которая читает построчно текстовый файл и
переставляет случайно слова в каждой строке
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"


int main()
{
	char string_in[S] = { '\0' };
	char string_out[S] = { '\0' };

	srand(time(0));

	FILE *file_in = fopen("string_in.txt", "r");
	if (file_in == NULL)
		puts("Can not find or open file!!!");

	FILE *file_out = fopen("string_out.txt", "w");
	if (file_out == NULL)
		puts("Error!!!");

	while (fgets(string_in, S, file_in) != NULL)
		fprintf(file_out, "%s\n", randomWords(string_in, string_out));

	fclose(file_in);
	fclose(file_out);

	return 0;
}
