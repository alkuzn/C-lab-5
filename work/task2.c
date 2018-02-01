#include "task2.h"
#include <string.h>

void clearMatrix(char *arr[])	//заполнение двумерного массива(матрицы) пробелами
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][strlen(arr[i])] = '\0';
	}
}

void fillMatrix(char *arr[])	//заполнение верхнего левого квадранта матрицы звездочками
{
	int h = SIZE / 2;
	int w = SIZE / 2 - 1;




}

void setMatrix(char(*arr)[M])	//копирование элементов в другие области матрицы
{

}

void printMatrix(char(*arr)[M])	//печать матрицы
{

}
*/