#include "task2.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; ++i)
	{
		for (int y = 0; y < M; ++y)
		{
			arr[i][y] = ' ';
		}
	}
}


void fillMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; ++i)
	{
		for (int y = 0; y < M / 2; ++y)
		{
			arr[i][y] = (rand() % 10) < 5 ? '*':' ';
		}
	}
}
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M/2; ++i) //строки
	{
		for (int y = 0, z = M- 1; y < z; ++y, --z)
		{
			arr[i][z] = arr[i][y];
		}
	}
	for (int i = 0; i < M; ++i)//солбцы
	{
		for (int y = 0, z = M-1; y < z; ++y, --z)
		{
			arr[z][i] = arr[y][i];
		}
	}
	
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; ++i)
	{
		for (int y = 0; y < M; ++y)
		{
			printf("%c ", arr[i][y]);
		}
		printf("\n");
	}
}
