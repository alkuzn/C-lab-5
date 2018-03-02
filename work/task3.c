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
	int rnd_index=0;
	int let_number = 0;
	char temp;
	let_number = strlen(in);
	*out = *in;
	*(out + let_number - 1) = *(in + let_number - 1);
	let_number -= 2;
	while (let_number >= 1)
	{
		rnd_index = rand() % let_number + 1;
		temp = out[let_number];
		out[let_number] = in[rnd_index];
		in[rnd_index] = in[let_number];
		let_number--;
	}
	//printf("out:%s\n", out);
	return out;

}


char *mixLine(char *in_str, char *out_str)
{
	char word_In[MAXSIZE] = { 0 };
	char word_Out[MAXSIZE] = { 0 };
	char *p_out = out_str;
	int i = 0;
	int flag = OUT;
	int lenght = 0;
	lenght = strlen(in_str);

	if (in_str[lenght - 1] == '\n')
		in_str[lenght - 1] = '\0';


	while (*in_str)
	{
		if (*in_str!=' ' && flag == OUT)
		{
			
			word_In[i] = *in_str;
			i++;
			flag = IN;
		}
		
		else if (*in_str!=' ' && flag == IN)
		{
			
			word_In[i] = *in_str;
			i++;
			flag = IN;
			
		}
		else if (*in_str == ' ' && flag == IN)
		{
			flag = OUT;
			word_In[i] = '\0';
	        mixChars(word_In, word_Out);
			for (int j = 0; j < i; j++)
			{
				*out_str = word_Out[j];
				out_str++;
			}
			*out_str = ' ';
		     out_str++;
		   	i = 0;
		}

		
		in_str++;
	}
	word_In[i] = '\0';
	mixChars(word_In, word_Out);
	

	for (int j = 0; j < i; j++)
	{
		*out_str = word_Out[j];
		out_str++;
	}

	*out_str = '\0';
	printf("p_out:%s\n", p_out);

	return p_out;
}





	










