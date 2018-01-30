#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

//Перемешивание массива символов (перемешивание символов в одном слове)
char *mixChars(char *in, char *out)
{
	strcpy(out, in);	//Копируем входную строку в выходную
	srand(time(NULL));
	int i, k;
	char buf;	//Буферная переменная
	int n; //Длинна слова
	//Вычисляем длинну слова
	for (n = 0; out[n] != ' ' && out[n] != '\0' && out[n] != '\n'; n++);
	//Выполняем перемешивание
	for (i = 0; i < n - 1; i++)
	{
		k = i + rand() % (n - i-1);	//Всего слова (кроме последнего символа)
		buf = out[i];
		out[i] = out[k];
		out[k] = buf;
	}
	return out;
}

int main()
{
	char in[] = "HomeWork\0";
	char out[128] = { 0 };
	mixChars(in, out);
	printf("%s\n", in);
	printf("%s\n", out);
	return 0;
}


