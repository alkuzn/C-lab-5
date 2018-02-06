#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

int main()
{
	char arr[M][M] = { '0' };
	int run = 100;
	clock_t now;

	while (run) {
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC));
		system("cls");
		run--;
	}
	return 0;
}