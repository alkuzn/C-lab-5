#include <stdio.h>
#include <stdlib.h>
#include "task2.h"

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = SYM_BACK;
}

void fillMatrix(char(*arr)[M])
{
	int spNum = M * N / 8, spCount = 0;
	int i = 0, j = 0;
	while (spCount < spNum)
	{
		i = rand() % (N / 2);
		j = rand() % (M / 2);
		if (arr[i][j] == SYM_BACK)
		{
			arr[i][j] = '*';
			spCount++;
		}
	}
}

void setMatrix(char(*arr)[M])
{
	int colBod = (M / 2), rowBod = (N / 2);
	for (int i = 0; i < rowBod; i++)
	{ 
		for (int j = 0; j < colBod; j++)
		{
			arr[N - 1 - i][j] = arr[i][j];
			arr[i][M - 1 - j] = arr[i][j];
			arr[N - 1 - i][M - 1 - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		if (i != (N - 1))
			putchar('\n');
	}
}