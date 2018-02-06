#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task1.h"

#define IN 1
#define OUT 0

void randomizer(char *words[], int counter)     // change positions of words
{
	int tmp = 0;
	char *temp = NULL;

	while (counter > 1)                
	{
		tmp = rand() % counter;
		temp = words[tmp];
		words[tmp] = words[counter - 1];
		words[counter - 1] = temp;
		counter--;
	}
}

char *randomWords(char *in, char *out) 
{
	srand(time(0));
	int flag = OUT;
	int i = 0, k = 0;   
	int count = 0;
	char *words[SIZE] = { NULL };
	char *z = NULL;

	if (in[strlen(in) - 1] == '\n')
		in[strlen(in) - 1] = '\0';

	while (i < strlen(in))
	{
		if (in[i] != ' ' && flag == OUT)
		{
			flag = IN;
			words[count] = &in[i++];
			count++;
		}
		else if (in[i] != ' ' && flag == IN)
		{
			i++;
		}
		else if ((in[i] == ' ' || in[i] == '\0') && flag == IN)
		{
			flag = OUT;
			i++;
		}
	}		

	do {
		k = 0;
		randomizer(words, count);
		for (int j = 0; j < count; j++)		// create string "out" with random order of words
		{
			z = words[j];
			while (*z != ' ' && *z != '\0')
			{
				*(out + k) = *z++;
				k++;				
			}
			*(out + k) = ' ';
			k++;
		}
		*(out + k - 1) = '\0';
	} while (strcmp(in, out) == 0 && count > 1);

	return out;
}