#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#define SIZE 512
#define OUT 0
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int i = 0, len = 0, j = 0,k=0,z=0;
	char buf[SIZE];
	char outstr[SIZE];
	char c = 0;
	char *p = "\n";
	FILE *fp = fopen("fp.txt", "r");
	FILE *fpFinal = fopen("fpFinal.txt", "w");
	if (fpFinal == NULL|| fp == NULL)
	{
		printf("Error of open file\n");
		return -1;
	}else printf("Open file fp.txt: \n");
	
	
	do {
		c = fgetc(fp);
		buf[i++]= c;
		if (c == '\0' || c == '\n')
		{
			buf[i] = '\0';
			//char *buf1 = "mad max";//need for test
			mixLine(buf, outstr);
			fputs(outstr, fpFinal);
			fputs(p, fpFinal);
			i = 0;
		}
	} while (c != EOF);
	fclose(fpFinal);
	fclose(fp);
	return 0;
}
/*
   Написать программу, переставляющую случайным образом символы каждого слова каждой строки текстового файла, 
   кроме первого и последнего, то есть начало и конец слова меняться не должны.

Программа открывает существующий тектстовый файл и читает его построч- но. Для каждой строки выполняется разбивка
на слова и независимая обра- ботка каждого слова
Состав

Программа должна состоять из функций:

   - char *mixChars(char *in char *out) -  перемешивание символов в одном слове
   - char *mixLine(char *instr, char * outstr) - перемешивание для целой строки
   - int main()
Создаются три файла: task3.h,task3.c,main3.c.*/