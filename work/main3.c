#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "task3.h"
#define N 80

int main() {
	FILE *fp, *inp;
	inp = fopen("bura.txt", "rt");
	fp = fopen("output.txt", "wt");
	if (inp == NULL)
	{
		puts("File not found!");
		return 1;
	}

	char input[N][N] = { 0 };
	char output[N][N] = { 0 };
	char *str[N] = { input };
	int i = 0;

	while (fgets(input[i], N, inp))
	{
		str[i] = input + i;
		if (input[i][strlen(input[i]) - 1] == '\n')
			input[i][strlen(input[i]) - 1] = '\0';
		i++;
	}
	int k = i;
	for (int i = 0; i < k; i++)
	{
		mixLine(input[i], output[i]);
		fputs(output[i], fp);
		if (i < k - 1)
			fputs("\n", fp);
	}


}