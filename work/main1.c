#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"task1.h"

#define N 100

int main()
{
	char str[N];
	char out[N];
	char *word[N];
	printf("Enter line \n");
	fgets(str, N, stdin);
	str[strlen(str) - 1] = '\0';
	printf("%s", randomWords(str, out));
	return 0;
}
