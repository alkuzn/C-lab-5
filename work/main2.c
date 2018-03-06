#include "task2.h"
#include <time.h>

int main()
{ 
	srand(time(0));
	char arr[M][M];
	clock_t now;
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		system("cls");
		printMatrix(arr);
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC));
	}
	return 0;

}