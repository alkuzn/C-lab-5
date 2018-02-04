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
char arr[N+2][M+2] ;
int main()
{
	int i = 0;
	clock_t now;
	while (i++<20)
	{
		now = clock();
		while (clock() < (now + 1*CLOCKS_PER_SEC));
			clearMatrix(arr);
			fillMatrix(arr);
			setMatrix(arr);
			printMatrix(arr);
	}
	return 0;
}



/*  Написать программу ”Калейдоскоп”, выводящую на экран изображение, составленное из симметрично расположенных звездочек ’*’.
   Изображение формируется в двумерном символьном массиве, в одной его части и симметрично копируется в остальные его части.
Пояснение

Решение задачи протекает в виде следующей последовательности шагов:

Очистка массива (заполнение пробелами)
Формирование случайным образом верхнего левого квадранта (из символов)
Копирование символов в другие квадранты массива
Очистка экрана
Вывод массива на экран (построчно)
Временная задержка
Переход к шагу 1.
Состав

Программа должна состоять из функций:

   void clearMatrix(char (* arr)[M]) - заполнение двумерного массива (матрицы) пробелами
   void fillMatrix(char (* arr)[M]) - заполение верхнего левого квадранта матрицы звездочками
   void setMatrix(char (* arr)[M]) - копирование элементов в другие области матрицы
   void printMatrix(char (* arr)[M]) - печать матрицы
   int main()
Создаются три файла: task2.h,task2.c,main2.c.*/