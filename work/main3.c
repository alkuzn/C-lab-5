#include <stdio.h>
#include <time.h>
#include "task3.h"

int main()
{
	srand(time(0));
	char in_str[256], out_str[256];
	FILE *file = fopen("text.txt", "rt");
	if (!file)
	{
		printf("Error.\n");
		return 1;
	}
	while (!feof(file))
	{
		fgets(in_str, 256, file);
		printf(".%s.\n", mixLine(in_str, out_str));
	}
	return 0;
}