#include <stdio.h>
#include <stdlib.h>
#include "task3.h"
#define IN 1
#define OUT 0

char *mixChars(char *in, char *out)  //перемешивание символов в одном слове
{
	int random = 0; 
	int numberOfChars = 0;
	int number = 0;

	char *in_t = in;
	char *out_t = out;

	char tmp = '\0';

	while (*in_t != '\0' && *in_t != ' ')
	{
		*out_t = *in_t;
		*out_t++;
		*in_t++;
		numberOfChars++;
	}
	*out_t = *in_t;

	number = numberOfChars - 1;
	while (number > 2)
	{
		random = rand() % number;
		if ((random != (number - 1)) && random)
		{
			tmp = out[number - 1];
			out[number - 1] = out[random];
			out[random] = tmp;
		}
		number--;
	}

	return out;
}

char *mixLine(char *in_string, char *out_string)  //перемешивание для целой строки
{
	char word_in[S] = { NULL };
	char word_out[S] = { NULL };

	char *string_out_t = out_string;
	char *p = NULL;
	char *p_t = NULL;

	int i = 0;
	int flag = OUT;
	int count = 0;

	while (in_string[i])
	{
		if (in_string[i] != ' ' && flag == OUT)
		{
			flag = IN;
			p_t = word_in;
			*p_t = in_string[i];
			if (in_string[i + 1] == '\0')
			{
				flag = OUT;
				count++;
				*(++p_t) = '\0';
				mixChars(word_in, word_out);
				p = word_out;
				while (*p != '\0')
					*string_out_t++ = *p++;
				break;
			}
		}
		else if (in_string[i] == ' ' && flag == IN)
		{
			*(++p_t) = '\0';
			mixChars(word_in, word_out);
			p = word_out;
			while (*p != '\0')
				*string_out_t++ = *p++;
			*string_out_t++ = ' ';
			flag = 0;
			count++;
		}
		else if (in_string[i] != ' ' && flag == IN)
		{
			*(++p_t) = in_string[i];
			if (in_string[i + 1] == '\0')
			{
				flag = OUT;
				count++;
				*(++p_t) = '\0';
				mixChars(word_in, word_out);
				p = word_out;
				while (*p != '\0')
					*string_out_t++ = *p++;
				break;
			}
		}
		i++;
	}
	*string_out_t = '\0';

	return out_string;
}
