#include "task1.h"
char *randomWords(char *in, char *out)
{
	int i = 0, j = 0,len=0,flagChar=0,countWord=0,symbol=0;
	int k = 0;
	char buf = 0;
	char *midl[SIZE];
	char *result;
	while (in[j]!='\n')//look out end of string with '\n'
	{
		if (in[j] ==' ')
			in[j] = '\0';
		j++;
	}
	len = j - 1;
    in[j] = '\0';//shange '\n'to '\0'
	for (j = 0;j <= len;j++)
	{
		if (flagChar == OUT && in[j] != '\0')
		{
			midl[i++] = &in[j];
			flagChar++;
		}
		else
		{
			if (in[j] == '\0') {
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

	for (i=countWord=0;midl[countWord] != NULL;countWord++)
	{
		for (j=0;((*(midl+countWord))[j])!=NULL;j++)
		{
			out[i++] = (*(midl + countWord))[j];
		}
		out[i++] = ' ';
	
	}
	out[i] = '\0';
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