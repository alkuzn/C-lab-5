#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#define ITER 50

void clearMatrix(char(*arr)[SIZE + 1])	//заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < SIZE ; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][SIZE] = '\0';
	}
}

void fillMatrix(char(*arr)[SIZE + 1])	//заполнение верхнего левого квадранта матрицы звездочками
{
	int h = SIZE / 2;
	int w = SIZE / 2;
	for (int i = 0, j = 0, iter=0; iter < ITER; iter++)
	{
		i = rand() % w;
		j = rand() % h;
		arr[j][i] = '*';		
	}
}


void setMatrix(char(*arr)[SIZE + 1])	//копирование элементов в другие области матрицы
{
	for (int i = 0; i < SIZE/2; i++)
	{
		for (int j = SIZE - 1, x = 0; x < SIZE / 2; j--, x++)
		{
			arr[i][j] = arr[i][x];
		}
	}
	for (int i = 0, j = SIZE - 1; i < (SIZE / 2); i++, j--)
	{
		strcpy(arr[j], arr[i]);
	}
}



void printMatrix(char(*arr)[SIZE + 1])	//печать матрицы
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%s\n", arr[i]);
	}
}
