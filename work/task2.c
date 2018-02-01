#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#define ITER 3

void clearMatrix(char *arr[])	//заполнение двумерного массива(матрицы) пробелами
{
	char buf[51] = { ' ' };
	for (int i = 0; i < SIZE; i++)
	{
		strcpy(arr[i], buf);
	}
	/*for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][strlen(arr[i])] = '\0';
	}*/
}

void fillMatrix(char *arr[])	//заполнение верхнего левого квадранта матрицы звездочками
{
	int h = SIZE / 2;
	int w = SIZE / 2 - 1;
	for (int i = 0, j = 0, count = 0; count < ITER; count++)
	{
		i = rand() % (w - 5);
		j = rand() % (h - 5);
		int flag = 0;
		for (int y = j; y < (j + 4); y++)
		{
			for (int x = i; y < (j + 4); y++)
			{
				if (arr[j][i] == '*')
				{
					flag = 1;
					break;
				}

			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			continue;
		}
		else
		{
			arr[j + 1][i + 2] = '*';
			arr[j + 2][i + 3] = '*';
			arr[j + 2][i + 1] = '*';
			arr[j + 3][i + 2] = '*';
		}
	}
}
/*
void setMatrix(char(*arr)[M])	//копирование элементов в другие области матрицы
{

}

void printMatrix(char(*arr)[M])	//печать матрицы
{

}
*/