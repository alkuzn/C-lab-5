#include <stdio.h>
#include <string.h>
#include <time.h>
#include "task2.h"

int main()
{
	clock_t now;
	char arr[M][N];
	while (1)
	{
		system("cls");
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		now = clock();
		while (clock() <= now + CLOCKS_PER_SEC);
	}
	return 0;
}