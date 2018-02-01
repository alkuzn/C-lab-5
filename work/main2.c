#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

//#define SIZE 51





int main()
{
	char arr[SIZE][SIZE];
	clearMatrix(arr);	//«аполнение двумерного массива пробелами и прописывание в конце каждой строки '\0' 
	fillMatrix(arr);	//«аполнение левой верхней части массива звЄздочками в случайном пор€дке



	return 0;
}