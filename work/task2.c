#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

void clearMatrix(char(*arr)[N])
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void fillMatrix(char(*arr)[N])
{
	srand(time(0));
	int i = 0, m, n;
	while (i < (M*N / 8))
	{
			m = rand() % (M / 2);
			n = rand() % (N / 2);
			arr[m][n] = '*';
			i++;
	}
}

void setMatrix(char(*arr)[N])
{
	int i = 0, j = 0;
	int m = M - 1;
	int n = N - 1;
	for (; i < M/2; i++)
	{
		for (j=0; j < N/2; j++)
		{
			arr[i][n - j] = arr[i][j];
			arr[m - i][j] = arr[i][j];
			arr[m - i][n - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}

}