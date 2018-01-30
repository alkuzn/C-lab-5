#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"task3.h"

#define S 40

int main()
 {
	char in[S] = {0};
	char out[S] = {0};
	
	FILE *inp;
	int count = 0;
	

	inp = fopen("txtIN.txt", "rt");

	if (inp == NULL)
	{
		puts("I can't open!");
		return 1;
	}

	int len_str = 0;
	int i = 0;

	while (count<S && fgets(in, S, inp) != NULL)
	{
		len_str = strlen(in);
		in[len_str - 1] = '\0';
		mixLine(in, out);
		printf("%s\n", out);
		count++;
		len_str = 0;
	}
	fclose(inp);
	
	return 0;
	}
