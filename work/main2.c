#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

int main()
{
	srand(time(0));
	char arr[N][M] = { '\0' };
	clock_t now;
	int isClear = 0;

	while (1)
	{
		clearMatrix(arr);
		if (!isClear)
			isClear = 1;
		else
			puts("\n\n");
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC));
	}
			
	return 0;
}