/*
Программа, переставляющая случайным образом символы каждого слова 
каждой строки текстового файла, кроме первого и последнего, 
то есть начало и конец слова меняться не должны.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

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
		fprintf(file_out, "%s\n", mixLine(string_in, string_out));

	fclose(file_in);
	fclose(file_out);

	return 0;
}