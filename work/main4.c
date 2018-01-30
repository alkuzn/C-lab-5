#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"task1.h"

#define N 100

int main()
{

	FILE *inp;
	int count = 0;
	char str[N];
	char out[N];
	
	inp = fopen("txtIN.txt", "rt");
	
	if (inp == NULL)
	{
		puts("I can't open!");
		return 1;
	}
	
	int len_str = 0;
	int i = 0;
 	while (count<N && fgets(str, N, inp) != NULL)
	{
		len_str = strlen(str);
		str[len_str-1] = '\0';
		printf("%s\n", randomWords(str, out));
		count++;
		len_str = 0;
	}
	
	fclose(inp);
	
	return 0;
}
