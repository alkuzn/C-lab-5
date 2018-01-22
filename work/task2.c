#include "task2.h"

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M;i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';

}
void fillMatrix(char(*arr)[M])
{
	srand(time(0));
	for (int i = 0; i < M/2; i++)
		for (int j = 0; j < M/2; j++)
			if (rand()%2)
				arr[i][j] = '*';
}
void setMatrix(char(*arr)[M])
{
	int i ,j,k ;
	for (i = 0; i < M / 2; i++)
	{
		k = M / 2 - 1;
		for (j = M/2; j <M; j++)
			arr[i][j] = arr[i][k--];
	}
	
	k = M / 2;
	for (i = M/2; i < M; i++)
	{
		k--;
		for (j = 0; j <M; j++)
			arr[i][j] = arr[k][j];
	}

}
void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}