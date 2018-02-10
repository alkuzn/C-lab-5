#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define S 200

char * mixChars(char *in, char *out)
{
	int i = 0, j=0;
	int count_char = 0;
	int rdig = 0;
	char temp_ch;
	srand(time(0));
	
	int len = strlen(in);
	for (int i = 0; i < len; i++)
	{
		out[i] = in[i];

	}
	
	len = strlen(in);
	if (len < 4)
	{
		*out = *in;
		return out;
	}

	for (i = 0; i < len; i++)
	{
		out[i]=in[i];
		count_char++;
	}
	do
	{
		while (len > 1)
		{
			for (j = 1; j < len; j++)
			{
				rdig = rand() % len;
				if (rdig == 0)
					continue;
				else
				{
					temp_ch = out[j];
					out[j] = out[rdig];
					out[rdig] = temp_ch;
				}
			}
			len--;
		}
	} while (strcmp(in, out) == 0);
	
	return out;
}

char * mixLine(char *in, char *out)
{
	char word[S];
	char *out_temp=out;
	char temp[S] = { 0 };
	int count = 0;
	int count_p = 0;
	int flag = 0;
	int len = 0;
	int i = 0, j=0,k = 0;
	int len_str = 0, len_temp = 0;;

	len_str = strlen(in);
	in[len_str] = ' ';

	while (in[i])
	{
		if (in[i] != ' ' && flag == 0)
		{
			flag = 1;
			len = 1;
			word[j++] = in[i];
		}
		else if ((in[i] == ' ') && (flag == 1))
		{
			flag = 0;
			if (j == len)
			{
				count++;
				word[j++] = '\0';
						
				mixChars(word, temp);
				for (int p = 0; p < j-1; p++)
			    {
					*out = temp[p];
					out++;
				}
				*out = ' ';
				out++; 
		 	}
			len = j = 0;
		}
		else if (in[i] != ' ' && flag == 1)
		{
			word[j++] = in[i];
			len++;
		}

		i++;
	}	
	*out = '\0';
	return out_temp;
}
