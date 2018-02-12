#define SIZE 512
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Перемешивание массива указателей но char
char *mixP(char *in[], int size)
{
	srand(time(NULL));
	int i, k;
	char * buf;	//Буферная переменная
	//Выполняем перемешивание всех указателей на char
	for (i = 0; i < size - 1; i++)
	{
		k = i + rand() % (size - i);
		buf = in[i];
		in[i] = in[k];
		in[k] = buf;
	}
	return in;
}

char * randomWords(char * in, char *out)
{
	char *arrp[SIZE];
	int count = 0;
	in[strlen(in) - 1] = '\0';
	for (int i = 0; in[i] != 0; i++)
	{
		if (in[i] != ' ' && in[i] != '\0' && (i == 0 || in[i - 1] == ' '))
		{
			arrp[count] = &(in[i]);
			count++;
		}
	}
	mixP(arrp, count);

	//Запись перемешанной строки в массив out
	int ind = 0;
	for (int i = 0; i < count; i++, ind++)	//Перебор указателей
	{
		for (int j = 0; arrp[i][j] != '\0' && arrp[i][j] != ' '; j++)
		{
			out[ind] = arrp[i][j];
			ind++;
		}
		out[ind] = ' ';
	}
	out[ind - 1] = '\0';
	
	return out;
}
