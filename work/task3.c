#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define OUT 0
#define IN 1


char *mixChars(char *in, char *out)
{
	int count=0;
	char temp =0;
	int rnd_index;
	int i = 0;
	
	int len = strlen(in);

	while (in[count] != ' '&& in[count] != '\0')
	{
		count++;
	}
	

	while (i<count)
	{
		
		out[i] = in[i];
		i++;
	}
	
	if (count < 4)
		return out;


	else
	{
		count--;
		do
		{
			for (int j = 1; j < len-2; j++)
			{
				rnd_index = j;
				while(rnd_index==j)
				rnd_index = rand() % (len-1);
				
				temp = out[j];
				out[j] = out[rnd_index];
				out[rnd_index] = temp;
			}
		} while (in == out);
		
	}

	printf("%s\n", out);
	return out;

}


char *mixLine(char *in_str, char *out_str)
{
	char word_In[MAXSIZE] = { 0 };
	char word_Out[MAXSIZE] = { 0 };
	char *p_out = out_str;
	//char *p = NULL;
	int i = 0;
	int flag = OUT;
	size_t lenght = strlen(in_str);

	if (in_str[lenght - 1] == '\n')
		in_str[lenght - 1] = '\0';


	while (i < lenght)
	{
		if (*in_str!=' ' && flag == OUT)
		{
			flag = IN;
			mixChars(in_str, out_str);

		}
		if (*in_str==' ' && flag == IN)
		{
			i++;
		}
		if (*in_str==' ' && flag == IN)
		{
			flag = IN;
			out_str[i] = ' ';
		}

		i++;
	}

	






	return out_str;
}





	/*
	enum States state = State_Start;

	const size_t lenght = strlen(inStr);
	while (*inStr)
	{
		for (size_t i = 0; i != lenght; i++)
		{
			const char current = inStr[i];
			switch (state)
			{
			case State_Start:
				if (isdigit(inStr[i]))
				{
					state = State_Number;
				}
				else if (isalpha(inStr[i]))
				{
					state = State_Word;
				}
				break;
			case State_Number:
				if (isspace(inStr[i]))
				{
					//FoundNumber();
					state = State_Start;
				}
				else if (!isdigit(inStr[i]))
				{

					state = State_Skip;
				}
				break;
			case State_Word:
				if (isspace(inStr[i]))
				{
					mixChars(words, words_out);
					state = State_Start;
				}
				else if (!isalpha(inStr))
				{
					state = State_Skip;
				}
				break;
			case State_Skip:
				if (isspace(inStr))
				{
					state = State_Start;
				}
				break;
			}
		}
	}

	return outStr;
	   
*/












/*
char *mixLine(char *instr, char *outstr)
{
	char word_out[MAXSIZE] = { '\0' };
	char *p_out = NULL;

	for (int i = 0; i < MAXSIZE; i++)
		outstr[i] = 0;

	p_out = outstr;
	//  char *p_wordOut=NULL;
	char add_space = ' ';


	int i = 0, j = 0;
	int len = 0;
	len = strlen(instr);


	//  if(instr[len-1]=='\0')
	//  instr[len-1]='\n';

	for (int x = 0; x<MAXSIZE; x++)//инициализируем word_out
		word_out[x] = 0;


	int num_words=0;

	int index = 0;
	//подсчет слов
	for (int i = 1; i<len; i++)
	{
		if (instr[i - 1] == ' ')
			continue;
		else if (instr[i] == ' ')
			num_words++;
		else index = i;
	}
	if (index + 1<len)
		num_words--;

	char *words[MAXSIZE] = { '\0' };//массив указателей на лексемы

	char *sep = " ;:.,!?";
	words[j] = strtok(instr, sep);//все лексемы - в word

	i++;                       // при первом вызове strtok(str,sep), параметр str указывает на начало строки,

	int y = 0;
	while (words[y - 1] != NULL)
	{
		words[y] = strtok(NULL, sep);//...при последующих - используется нулевой указатель
		y++;
	}

	char *p_words = NULL;//указатель на word[]


	for (i = 0; i<num_words; i++)//
	{
		p_words = words[i];//передаем слова через указатели
		word_out[i] = *p_words;//-//-
		mixChars(p_words, word_out);//p_words - массив с преобразованными словами


	   printf("p_words:%s\n",p_words);

		*p_out = '\0';
		for (j = 0; j<num_words; j++)
		p_out = &word_out[j];
		*p_out = '\0';
		*p_out = '\n';



		//   if(*p_words==p_words[strlen(p_words)])
		//     *p_words++=' '; //??

		printf("%s", p_out);

		strcat(p_out, &add_space);
		strcat(p_out, p_words);
	}

	outstr = p_out;

	printf("instr:%s   outstr:%s\n",instr, outstr);
	*/
