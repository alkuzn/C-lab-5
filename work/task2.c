#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

void clearMatrix(char(*arr)[M]) 
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = GAP;
}

void fillMatrix(char(*arr)[M]) 
{
	int maxSym = M * M / 8;				// max number of symbols in the quadrant
	int i = 0, j = 0, k = 0;
	while (maxSym) 
	{
		i = rand() % (M / 2);
		j = rand() % (M / 2);
		if (arr[i][j] = GAP)
		{
			arr[i][j] = MARK;
			maxSym--;
		}
	}
}

void setMatrix(char(*arr)[M]) 
{
	for (int i = 0; i < M / 2; i++)
		for (int j = 0; j < M / 2; j++)
		{
			arr[M - i - 1][j] = arr[i][j];
			arr[i][M - j - 1] = arr[i][j];
			arr[M - i - 1][M - j - 1] = arr[i][j];
		}
}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}	
}