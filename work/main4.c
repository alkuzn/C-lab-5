#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "task1.h"
#define SIZEM 128
#define LSTR 512

int main(int argc, char * argv[])
{
	char fin[256] = { 0 };
	char fout[256] = { 0 };

	switch (argc)
	{
	case 2:
	{
		strcpy(fin, argv[1]);
		strcpy(fout, argv[1]);
		break;
	}
	case 3:
	{
		strcpy(fin, argv[1]);
		strcpy(fout, argv[2]);
		break;
	}
	default:
	{
		strcpy(fin, "test.txt");
		strcpy(fout, "test1.txt");
		break;

	}
	}

	FILE *fp;
	char *in[SIZEM];	//Массив указателей на строки входной
	char *out[SIZEM];	//Массив указателей на строки выходной

	fp = fopen(fin, "r");
	if (fp == NULL) //Проверка наличия файла и его открытия
	{
		printf("error open file in\n");
		return -1;
	}
	int i;	//Счётчик прочитанных строк
	for (i = 0; i < SIZEM; i++)
	{
		char *stroka;	//Указатель на строку
		stroka = (char*)malloc(LSTR * sizeof(char));	//Выделяем память под строку и записываем адрес в указатель		
		in[i] = fgets(stroka, LSTR, fp);	//Чтение одной строки из файла
											//stroka[strlen(stroka)] = '\0';

											//Проверка на конец файла или ошибку чтения
		if (in[i] == NULL)
		{
			// Проверяем, что именно произошло: кончился файл или это ошибка чтения
			if (feof(fp) != 0)
			{
				//Если файл закончился, выводим сообщение о завершении чтения и выходим из бесконечного цикла
				//printf("read end file in\n");
				break;
			}
			else
			{
				//Если при чтении произошла ошибка, выводим сообщение об ошибке и выходим из бесконечного цикла
				printf("err read file in\n");
				break;
			}
		}
	}
	//Закрытие файла
	//printf("close file in\n");
	if (fclose(fp) == EOF)
	{
		printf("error close file in\n");
	}
	//Открываем выходной файл
	fp = fopen(fout, "w");
	if (fp == NULL)
	{
		//printf("error open file out\n");
		return -1;
	}

	//Содаём массив указателей на строки out. Передаём массивы указателей для перемешивания
	int len;
	for (int j = 0; j < i; j++)
	{
		char *stroka;	//Указатель на строку
		stroka = (char*)malloc(LSTR * sizeof(char));
		out[j] = stroka;
		if (in[j][0] != '\n')
		{
			randomWords(in[j], out[j]);//Передаём указатели на строки для перемешивания
			len = strlen(out[j]);
			out[j][len] = '\n';
			out[j][len + 1] = '\0';
		}
		else
		{
			out[j][0] = '\n';
			out[j][1] = '\0';
		}
		fwrite(out[j], sizeof(char), strlen(out[j]), fp);
		//fputc('\n', fp);
	}
	//Закрываем выходной файл
	if (fclose(fp) == EOF)
	{
		printf("error close file out\n");
	}
	return 0;
}