#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "task2.h"

void clearMatrix(char *arr) {
	for (int i = 0; i < (M * M); i++)
	{
		arr[i] = ' ';
	}
}

void fillMatrix(char(*arr)[M]) {
	srand(time(0));
	for (int i = 0; i < (M / 2) + 1; i++) {
		for (int j = 0; j < (M / 2) + 1; j++) {
			int k = rand() % 2;
			if (k)
				arr[i][j] = '*';
		}
	}

}
void setMatrix(char(*arr)[M]) {
	for (int i = 0; i < M / 2 + 1; i++)
	{
		for (int j = 0; j < M / 2; j++)
			arr[i][(M - 1) - j] = arr[i][j];
	}
	
	for (int i = 0; i < M / 2 + 1; i++)
	{
		for (int j = 0; j < M; j++)
			arr[(M - 1) - i][j] = arr[i][j];
	}
}
void printMatrix(char(*arr)[M]) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++) 
			putchar(arr[i][j]);
		putchar('\n');
	}
}