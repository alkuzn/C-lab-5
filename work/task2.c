#include "task2.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
#define M 61// weight or 'x'
#define N 20//height or 'y'
#define limitX  (M/ 2)
#define limitY (N/ 2)
#define LIMITunit 15//(M / 2*(M*10/20))
#define STAR '*'
void printUnit(char(*arr)[M], int y, int x)
{
	if ((x > 0 || x < limitX) && (y>0 || y < limitY))
		arr[y][x] = STAR;
}

void romb(char(*arr)[M],int y, int x)
{

					printUnit(arr, y - 1, x);

		printUnit(arr, y , x-1);  printUnit(arr, y , x+1); 

					printUnit(arr, y +1, x);
	
}

void krest(char(*arr)[M], int y, int x)
{
													printUnit(arr, y - 2, x-2);   printUnit(arr, y -2, x + 2);
													printUnit(arr, y - 1, x-1);   printUnit(arr, y - 1, x + 1);
				printUnit(arr, y, x-2); printUnit(arr, y, x-1);  printUnit(arr, y , x); printUnit(arr, y, x+1); printUnit(arr, y, x+2);
													 printUnit(arr, y + 1, x-1);  printUnit(arr, y + 1, x + 1);
													printUnit(arr, y + 2, x-2);  printUnit(arr, y + 2, x + 2);


}

void zvezda(char(*arr)[M], int y, int x)
{
														printUnit(arr, y - 2, x);
														printUnit(arr, y - 1, x);
	printUnit(arr, y, x - 2); printUnit(arr, y, x - 1);  printUnit(arr, y, x); printUnit(arr, y, x + 1); printUnit(arr, y, x + 2);
														printUnit(arr, y + 1, x);
														printUnit(arr, y + 2, x);


}

void clearMatrix(char (*arr)[M])// - заполнение двумерного массива(матрицы) пробелами;
{
	int i = 0, j = 0;
	for (i = 0;i < N;i++)
	{
		j = 0;
		while (j<M)
		{
			arr[i][j++] = ' ';
		}
		arr[i][j] = '\0';
	}
}
void fillMatrix(char(*arr)[M])// - заполение верхнего левого квадранта матрицы звездочками
{
	int x = 0, y = 0, count = 0;
	srand(time(0));
	for (count = 0; count < LIMITunit;count++)
	{
	x = rand() % limitX;
	y = rand() % limitY;
		switch (rand() % 3)
		{
		case 0:
			romb(arr, y, x);
			break;
		case 1:
			krest(arr, y, x);
			break;
		case 2:
			zvezda(arr, y, x);
			break;
		}

	}

}
void setMatrix(char(*arr)[M])// - копирование элементов в другие области матрицы
{
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0;
	int x4 = 0, y4 = 0;
	char star = '*';
	//int limitY = M / 2;
	for (y1 = 0;y1 <= limitY;y1++)
	{
		
		for (x1 = 0;x1 <=limitX;x1++)
		{
			star = arr[y1][x1];
			if(star != ' ')
			{
					x2 = x1 + 2*(limitX-x1);
					arr[y1][x2] = star;//2
					y3 = y1 + 2*(limitY-y1);
					arr[y3][x2] = star;//3
					arr[y3][x1] = star;//4
			}
			
		}
	}
	
	
}
void printMatrix(char(*arr)[M])// - печать матрицы
{
	int x = 0, y = 0;
	
	for (x = 0;x < N;x++)
	{
		for (y = 0;y < M;y++)
		{
			printf("%c", arr[x][y]);
		}
		printf("\n");//printf("\n%2.d",x);
	}


	printf("\n\n\n\n\n");
}