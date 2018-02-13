#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"


int main()
{
	char arr[SIZE][SIZE + 1];
	clock_t now;

	while (1)
	{		
		srand(time(NULL));
		clearMatrix(arr);	//Заполнение двумерного массива пробелами и прописывание в конце каждой строки '\0' 		
		fillMatrix(arr);	//Заполнение левой верхней части массива звёздочками в случайном порядке
		setMatrix(arr);
		//system("cls||clear");
		//system("cls");	//очистка экрана консоли
		printMatrix(arr);	//Печать матрицы
		//Организация задержки
		now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
	}
	return 0;
}