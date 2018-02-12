#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //для rand() & strcmp
#include <ctype.h> //для isspace()
#include <time.h>
#include "task1.h"
#define ATT_NUM 100
#define IN 1
#define OUT 0

char *randomWords(char *in, char *out)
{
	//создаём массив указателей на char, 
	//в который заносим адреса первых символов каждого слова:
	char *p_in[S] = { NULL };

	int str = strlen(in);
	if (in[str - 1] == '\n')
		in[str - 1] = '\0';

	int i = 0;
	int flag = OUT; // если в слове, то OUT=1  //если вне слова, то OUT=0
	int count = 0;


	while (in[i])
	{
		if (!isspace(in[i]) && flag == OUT)
		{
			flag = IN;  //в слове
			p_in[count] = &(in[i]);
			count++;
		}
		else if (isspace(in[i]) && flag == IN)
			flag = OUT;  //вышли из слова
		i++;
	}



	do
	{
		char *p = NULL;
		char *outT = out;

		//	
		// перестановка указателей в массиве случайным образом:

		char *tmp = NULL;
		int randomNumber = 0;
		int c = count; //current count
		while (c > 1)
		{
			randomNumber = rand() % c;
			if (randomNumber != c - 1)
			{
				tmp = p_in[c - 1];
				p_in[c - 1] = p_in[randomNumber];
				p_in[randomNumber] = tmp;
			}
			c--;
		}

		//
		//

		for (i = 0; i<count; i++)
		{
			p = p_in[i];
			while (*p != ' ' && *p != '\0')
				*outT++ = *p++;
			if (i < count - 1)
				*outT++ = ' ';
		}
		*outT = '\0';

	} while (strcmp(out, in) == 0 && count > 1);

	return out;
}

/*
*	Если нужно вывести строки по алфавиту.
*	В качестве функции для сравнения строк берём
*	функцию сравнения строк из библиотеки stdlib.h - strcmp:
*
*	strcmp (<строка 1>, <строка 2>);
*
*	Эта функция выдаёт:
*	- значение меньше нуля, если <строка 1>  меньше, чем <строка 2>
*	- 0, если <строка 1>  и <строка 2> равны
*	- значение больше нуля, если <строка 1>  больше, чем <строка 2>
*
*/