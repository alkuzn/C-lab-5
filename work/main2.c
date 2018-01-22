#include "task2.h"

int main()
{
	char arr[M][M] = { 0 };
	clock_t now;
	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		//system("cls");
		system("clear");
		printMatrix(arr);
		
		now = clock();
		while (clock() <= now + CLOCKS_PER_SEC);
		
	}
	
	return 0;
}