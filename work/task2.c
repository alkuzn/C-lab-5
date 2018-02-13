#include "task2.h"
#include <stdio.h>
#include <stdlib.h>  //для rand()
#define SPACE ' '

void clearMatrix(char(*arr)[M]) // очистка матрицы (заполнение матрицы пробелами)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = SPACE;
}

void fillMatrix(char(*arr)[M])  // заполнение верхнего левого квадранта матрицы символами '*'
{
	int squaresNumber = M * N / 8;  // количество клеток в квадранте
	int fillNumber = 0; //заполненные клетки квадранта
	int i = 0, j = 0;
	while (fillNumber < squaresNumber)
	{
		i = rand() % (N / 2);  //случайная координата '*' по х
		j = rand() % (M / 2);  //случайная координата '*' по y
		if (arr[i][j] = SPACE)
		{
			arr[i][j] = '*';
			fillNumber++;
		}
	}
}

void setMatrix(char(*arr)[M])  // копирование элементов из верхнего левого квадранта в другие области матрицы
{
	int lines = (N / 2);
	int columns = (M / 2);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[N - 1 - i][j] = arr[i][j];
			arr[i][M - 1 - j] = arr[i][j];
			arr[N - 1 - i][M - 1 - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[M])  // печать матрицы
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		if (i != (N - 1))
			putchar('\n');
	}
}