#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define N 100

char * randomWords(char * str, char *out)
{
	char *word[N];
	int count = 0;
	int inWord = 0;
	int i = 0, k = 0, j = 0;
	int len = 0;
	srand(time(0));

		while (str[i])
	{
		if (str[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			word[k] = &str[i];
			k++;
		}
		else if (str[i] == ' ')
		{
			inWord = 0;
		}
		i++;
	}
		
	int rDig = 0;
	count = k;
	int flag = 0;

	while (k>0)
	{
		rDig = rand() % count;
		int temp = 0;
		if (word[rDig] == 0)
			continue;
		else
		{
		    while(word[rDig][temp] != ' ')
			{
				if (word[rDig][temp] == '\0')
					break;

				out[j] = word[rDig][temp];
				j++;
				temp++;
			}
			word[rDig] = 0;
			out[j] = ' ';
			j++;
		}
		k--;
	}
	j--;
	out[j] = '\0';

	return out;
}
