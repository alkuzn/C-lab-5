#include <stdio.h>
#include <string.h>
#include "task1.h"
#include <time.h>
int main()
{
	srand(time(0));
	char str[256], bufstr[256];
	char *pop[50];
	FILE *pfile = fopen("text.txt", "rt");
	if (!pfile)
	{
		printf("Err\n");
		return 1;
	}
	printf("Source:\n");
	while (!feof(pfile))
	{
		fgets(str, 256, pfile);
		if (str[strlen(str)-1] == '\n')str[strlen(str)-1] = '\0';
		printf("%s\n", str);
	}
	rewind(pfile);
	printf("Result:\n");
	while (!feof(pfile))
	{
		fgets(str, 256, pfile);
		if (str[strlen(str) - 1] == '\n')str[strlen(str) - 1] = '\0';
		printf("%s\n", randomWords(str, bufstr));
	}

	return 0;
}