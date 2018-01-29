#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"

char *mixChars(char *in, char *out) 
{
	int letters = 0;								// counter of letters in a word
	int randPos = 0;								// random letter position
	char tmp = NULL;

	while (in[letters] != ' ' && in[letters] != '\0')
	{
		letters++;
	}
	
	for (int i = 0; i < letters; i++)
	{
		out[i] = in[i];
	}

	if (letters < 4)
		return out;
	else
	{
		letters--;									// exclude last letter of word
		do {
			for (int j = 1; j < letters; j++)		// create word with random order of letters
			{
				randPos = rand() % letters;
				if (randPos == 0)
					randPos = 1;
				tmp = out[j];
				out[j] = out[randPos];
				out[randPos] = tmp;
			}
		} while (strcmp(in, out) == 0);
		return out;
	}
}

char *mixLine(char *instr, char *outstr) 
{
	int flag = 0;
	int i = 0;

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	while (i < strlen(instr))
	{
		if (instr[i] != ' ' && flag == 0)
		{
			flag = 1;
			mixChars(instr + i, outstr + i);
		}
		else if (instr[i] == ' ' && flag == 1)
		{
			flag = 0;
			outstr[i] = ' ';
		}
		i++;
	}
	return outstr;
}


