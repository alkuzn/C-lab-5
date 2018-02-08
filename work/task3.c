#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "task3.h"
#define IN 1
#define OUT 0
#define N 64

void clearArray(char *arr) {
	int k = strlen(arr);
	for (int i = 0; i < k; i++)
		arr[i] = '\0';
}


char *mixChars(char *in, char *out) {
	if (strlen(in) < 4) {
		for (int i = 0; i < strlen(in); i++)
		{
			out[i] = in[i];
		}
		return out;
	}
	
	srand(time(0));

	//copy string
	for (int i = 0; i < strlen(in); i++)
	{
		out[i] = in[i];
	}

	//shuffle chars
	
	for (int i = 0; i < strlen(in) - 1; i++)
	{
		if (i != 0 && i != (strlen(in) - 1))
		{
			int j = (rand() % strlen(in) - 1) + 1;			
			if (j >= strlen(in) - 1)
				j--;
			if (j != i && j !=0)
			{
				int buff = out[i];
				out[i] = out[j];
				out[j] = (char)buff;
			}
		}
	}
	return out;
}

char *mixLine(char *instr, char * outstr) {
	int flag = OUT;
	char wordIn[N] = { '0' };
	char wordOut[N] = { '0' };
	int wordStart = 0;
	int wordInCounter = 0;
	for (int i = 0; i < strlen(instr) + 1; i++)
	{
		if ((instr[i] != ' ' || instr[i] != '\n' || instr[i] != '\0') && flag == OUT)
		{
			flag = IN;
			wordIn[wordInCounter++] = instr[i];
			wordStart = i;
		}
		else if ((instr[i] == ' ' || instr[i] == '\n' || instr[i] == '\0' || instr[i] == '?' || instr[i] == '.' || instr[i] == '!' || instr[i] == ',' || instr[i] == ':' || instr[i] == ';') && flag == IN)
		{
			flag = OUT;
			clearArray(wordOut);
			mixChars(wordIn, wordOut);
			int k, j = 0;
			for (j = wordStart, k = 0; k < strlen(wordOut); j++, k++)
			{
				outstr[j] = wordOut[k];
			}
			if (instr[i] == ' ' || instr[i] == '\n' || instr[i] == '\0' || instr[i] == '?' || instr[i] == '.' || instr[i] == '!' || instr[i] == ',' || instr[i] == ':' || instr[i] == ';')
				outstr[j] = instr[i];
			wordInCounter = 0;
			clearArray(wordIn);
		}
		else if (flag == IN)
		{
			wordIn[wordInCounter++] = instr[i];
		}
	}
	return outstr;
}