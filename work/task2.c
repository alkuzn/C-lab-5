#include "task2.h"

int i = 0, j = 0;

void clearMatrix(char(*arr)[M])
{
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void fillMatrix(char(*arr)[M])
{
	int number1 = 0;
	int number2 = 0;

	for (i = 0; i < HALFARR; i++)
	{
		number1 = rand() % HALFARR;
		number2 = rand() % HALFARR;
		arr[number1][number2] = '*';
	}
}

void setMatrix(char(*arr)[M])
{
	char tmp;

	for (i = 0; i < HALFARR; i++)
	{
		for (j = 0; j < HALFARR; j++)
		{
			tmp = arr[i][j];
			arr[i + HALFARR][j + HALFARR] = tmp;
			arr[i + HALFARR][j] = tmp;
			arr[i][j + HALFARR] = tmp;
		}
	}
}

void printMatrix(char(*arr)[M])
{

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}