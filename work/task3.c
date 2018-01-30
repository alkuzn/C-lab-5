#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define S 40

char * mixChars(char *in, char *out)
{
	int i = 0, j=0;
	int count_char = 0;
	int rdig = 0;
	char temp[S] = {0};
	char temp_ch;
	srand(time(0));
	
	//printf("mixCh_in %s|\n", in);
	while (in[i] != ' ' && in[i] != '\0')
	{
		temp[i] = in[i];
		i++;
		count_char++;
	}
	temp[i] = ' ';
	count_char--;
	
	while (i > 1)
	{
		for (j = 1; j < count_char; j++)
		{
			rdig = rand() % count_char;
			if (rdig == 0)
				continue;
			else
			{
				temp_ch = temp[j];
				temp[j] = temp[rdig];
				temp[rdig] = temp_ch;
			}
		}
		i--;  
	}
	//printf("mixCh_temp %s|\n", temp);
	for (j = 0; j <= count_char; j++)
	{
		out[j] = temp[j];
	}
	//printf("mixCh_out %s|\n\n", out);
	out[j++] = ' ';
	return &out[j];
}

char * mixLine(char *in, char *out)
{
	char  *in_ch[S];
	char  *out_ch[S];
	char word[S];
	int count_p = 0;
	int flag = 0;
	int len = 0;

	len = strlen(in);

	for (int i = 0; i < len; i++)
	{
		if (in[i] != ' ' && flag == 0)
		{
			in_ch[count_p] = &in[i];
			count_p++;
			flag = 1;
		}
		else if (in[i] == ' ')
			flag = 0;
	}

	for (int i = 0; i < count_p; i++)
	{
		out = mixChars(in_ch[i], out);
		if (count_p - i == 1)
		{
			out--;
			*out = '\0';
		}
	}
	out-= strlen(in)-1;
	return &out;
}
