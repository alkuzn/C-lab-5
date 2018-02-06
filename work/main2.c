#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

int main() 
{
	char arr[M][M] = { NULL };
	srand(time(0));
	clock_t now;

	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");					// screen cleaning
		printMatrix(arr);
		now = clock();
		while (clock() <= now + CLOCKS_PER_SEC);
	}
	return 0;
}