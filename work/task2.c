#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#define ITER 3

void clearMatrix(char *arr[], int size)	//заполнение двумерного массива(матрицы) пробелами
{
	/*char buf[51] = { ' ' };
	for (int i = 0; i < SIZE; i++)
	{
		strcpy(arr[i], buf);
	}*/
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][size] = '\0';
	}
}
/*
void fillMatrix(char *arr[], int size)	//заполнение верхнего левого квадранта матрицы звездочками
{
	int h = size / 2;
	int w = size / 2 - 1;
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
*/
/*
void setMatrix(char(*arr)[M])	//копирование элементов в другие области матрицы
{

}

void printMatrix(char(*arr)[M])	//печать матрицы
{

}
*/