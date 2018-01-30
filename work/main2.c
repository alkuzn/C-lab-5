/*
ѕрограмма Ф алейдоскопФ, вывод€ща€ на экран изображение, 
составленное из симметрично расположенных звездочек Т*Т.
»зображение формируетс€ в двумерном символьном массиве, в одной 
его части, и симметрично копируетс€ в остальные его части.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

int main()
{
	srand(time(0));
	char arr[N][M] = { '\0' };

	while (1)
	{
		clearMatrix(arr);  //заполнение двумерного массива (матрицы) пробелами
		fillMatrix(arr);  //заполнение верхнего левого квадранта матрицы символами '*'
		setMatrix(arr);  //копирование элементов в другие области матрицы
		printMatrix(arr);  //печать матрицы

		printf("\n\n\n\n");

		clock_t now;
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC))  //временна€ задержка
			;
	}

	return 0;
}