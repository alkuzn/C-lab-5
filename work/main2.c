#include "task2.h"

int main()
{
	while (1)
	{
		char arr[M][M] = { '\0' };
		clock_t now;

		clearMatrix(arr);
		srand(time(0));
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		
		now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
	}
	return 0;
}
