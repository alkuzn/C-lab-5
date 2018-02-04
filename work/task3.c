#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#define SIZE 512
#define OUT 0
#define IN 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int check2part(int diff,char *in, char *out)
{
	if (*in==0 || *out==0)
		return *in;
	else return check2part(diff - *in + *out,in+1, out+1);
	
}

char *mixChars(char *in ,char *out)// - перемешивание символов в одном слове
{
	int i = 0, j = 0, len = 0, flagChar = 0, countWord = 0, symbol = 0;
	int diff = 0;// need for check of true mix letter
	int k = 0;
	
	char *p = (char*)malloc(strlen(in) * sizeof(char));
	strcpy(p, in);
	char midl[SIZE];//char *midl[SIZE];
	char result=' ';
	while (p[j++] != '\0');//look out end of string with '\n'
	len = j - 1;
	for (i = 0;i < len;i++)
	{
		midl[i] = p[i];
		
	}
	midl[i] =0;
	
	countWord = i;
	//srand(time(0));
	if (i > 3)//condition for the word more that 3 leters
	{
		for (k = (countWord - 1);k > 2;k--)// random dont first letter 
		{
			j = k - 2;
			i = k - 1;
			while ((symbol = rand() % j + 1) == k);//don't last letter
			result = midl[i];
			midl[i] = midl[symbol];
			midl[symbol] = result;
			
		
		}
		
	}
	// random each a later woth first and last symbols
	for (i = 0;i<countWord;i++)
		(out[i] = midl[i]);
		
	out[i] = 0;

	return out;
}
char *mixLine(char *instr, char *outstr)// - перемешивание для целой строки
{
	int i = 0, j = 0, len = 0, flagChar = 0, countWord = 0, symbol = 0;
	int k = 0;
	int diff = 0;
	char *p = (char*)malloc(strlen(instr) * sizeof(char));
	strcpy(p, instr);
	char *midl[SIZE];
	char buf[SIZE][SIZE];
	char *result;
	
	char out[SIZE];
	char *in;
	if (p[strlen(p) - 1] == '\n')
		p[strlen(p) - 1] = '\0';
	while (p[j] != 0)//look out end of string with '\n'
	{
		if (p[j] == ' ')  p[j] = 0;
		j++;
	}
	len = j ;
	for (j = 0;j <= len;j++)
	{
		if (flagChar == OUT && p[j] != '\0')
		{
			in = &p[j];
			flagChar++;

		}
		else
		{
			if ((p[j] == '\0')&&(flagChar==IN))
			{
				mixChars(in, out);
				
				strcpy(buf[i], out);
				midl[i] = buf[i];
					i++;
				flagChar = OUT;
			}
		}
	}
	midl[i] = NULL;
	countWord = i;
	srand(time(0));

	
	if (countWord == 2)//random condition for only two words
	{
		
		result = midl[1];
		midl[1] = midl[0];
		midl[0] = result;
	}

	for (;countWord >2;countWord--)// random for two and more words
	{
		j = countWord - 2;
		symbol = rand() % j;
		i = countWord - 1;
		result = midl[i];
		midl[i] = midl[symbol];
		midl[symbol] = result;
	}

	// random each a later exept first and last symbols
	

	for (i = countWord = 0;midl[countWord] != NULL;countWord++)
	{
		for (j = 0;(midl [countWord][j]) != '\0';j++,i++)
		{
			outstr[i] = (*(midl + countWord))[j];
		}
		outstr[i++] = ' ';

	}
	outstr[--i] = '\n';
	outstr[++i] = '\0';
	//free(p);
	return outstr;
}
