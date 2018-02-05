#include "task1.h"
#define SIZE 512
#define OUT 0
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	char ch = 0;
	char buf[SIZE] = {'0'};
	char *out;
	printf("Enter line of words: \n");
	fgets(buf, SIZE, stdin);
	//char *buf1 = "  papa love mama and sons";// need for a test
	out = (char*)malloc(strlen(buf) * sizeof(char));
	printf("%s \n", randomWords(buf, out));

	//free(out);
	//free(buf);
	return 0;

}