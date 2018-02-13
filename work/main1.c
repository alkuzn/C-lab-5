/*
Программа, которая принимает от пользователя строку и
выводит её на экран, перемешав слова в случайном порядке.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"

int main()
{
	srand(time(0));
	char in[S] = { '\0' };
	char out[S] = { '\0' };
	printf("Please, enter the string: \n");
	fgets(in, S, stdin);
	printf("%s\n", randomWords(in, out));

	return 0;
}
