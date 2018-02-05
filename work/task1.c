#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#define SIZE 512
#define OUT 0
#define IN 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
char *randomWords(char const *in, char *out)
{
	int i = 0, j = 0, len = 0, flagChar = 0, countWord = 0, symbol = 0;
	int k = 0;
	char* buf = (char*)malloc(strlen(in) * sizeof(char));
	char out1[512];
	strcpy(buf, in);
	char *midl[SIZE];
	char *result;
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	for (j = 0;buf[j] != '\0';j++)//look out end of string with '\n'
	{
		if (buf[j] == ' ')	buf[j] = '\0';
	}
	len = j ;
	if (0 >= len){
		strcpy(out, buf);
		return out;
}
	//buf[j] = NULL;//change '\n'to '\0'
	for (j = 0;j <= len;j++)
	{
		if (flagChar == OUT && buf[j] != '\0')
		{
			midl[i++] = &buf[j];
			flagChar++;
		}
		else
		{
			if ((buf[j] == '\0')&&(flagChar==IN))
			{
				flagChar = OUT;
			}
		}
	}
	midl[i] = NULL;
	countWord = i ;
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
			midl[i]=midl[symbol];
			midl[symbol] = result;
	}
	i=len= (strlen(out1));
	/*for (out[i];i>=0;i--)
	{
		out[i]= '\0';
	}
	*/
	
	for (i=countWord=0,len=0;midl[countWord] != NULL;countWord++)
	{
		while ((out1[i++] = *(midl[countWord])++)!= '\0')
		{
			//out1[i++] = *(midl[countWord]);continue;
		}

			out1[i-1] = ' ';
			//strcat(out, midl[countWord]);
		//strcat(out, " ");
		//len += strlen(midl[countWord]) + 1;
	}
	out1[i-1] = '\0';
	strcpy(out, out1);
	//free(buf);
	//buf = NULL;
	return out;
}

/*
Написать программу, которая принимает от пользователя строку и
выводит ее на экран, перемешав слова в случайном порядке.
Пояснение
Для входной строки создается массив указателей на char, в который заносятся адреса первых символов каждого слова.
Затем организуется новая строка, при использовании этого массива из указателей. 
Массив из указателей должен объявляться внутри функции randomWords.
Порядок слов может быть любым, но главное, чтобы слова не повторялись и строка отличалась от исходной.

Состав

Программа должна состоять из функций:

- char * randomWords(char * in, char *out) - функция, изменяющая порядок слов из in и записывающую их в out
- main() - организация ввода строки*/