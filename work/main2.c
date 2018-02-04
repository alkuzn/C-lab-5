#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

#define SIZE 50





int main()
{
	char arr[SIZE][SIZE + 1];
	while (1)
	{
		
		//clearMatrix(arr);	//Заполнение двумерного массива пробелами и прописывание в конце каждой строки '\0' 
		clearMatrix(arr, SIZE);	//Заполнение двумерного массива пробелами и прописывание в конце каждой строки '\0' 

		srand(time(NULL));
		//fillMatrix(arr, SIZE);	//Заполнение левой верхней части массива звёздочками в случайном порядке
		for (int i = 0; i < SIZE; i++)
		{
			printf("%s\n", arr[i]);
		}


	}
	return 0;
}