#include "task3.h"

#define IN 1
#define OUT 0

char *mixChars(char *in, char *out)
{
	int i = 0, j = 0;   //for count
	int letters = 0;    //count for letters in a word
	int random = 0;     //letter position
	char tmp = NULL;

	while (in[letters] != ' ' && in[letters] != '\0')
	{
		letters++;
	}

	for (i = 0; i < letters; i++)
	{
		out[i] = in[i];
	}

	if (letters < 4)	//beginning and ending of a word shouldn't change!
		return out;

	else
	{
		letters--;
		do {
			for (j = 1; j < letters; j++)
			{
				random = rand() % letters;
				if (random == 0)
					random = 1;
				tmp = out[j];
				out[j] = out[random];
				out[random] = tmp;
			}
		} while (strcmp(in, out) == 0);
		return out;
	}
}

char *mixLine(char *instr, char *outstr)
{
	int k = 0;
	int flag = OUT;

	if (instr[strlen(instr) - 1] == '\n')
		instr[strlen(instr) - 1] = '\0';

	while (k < strlen(instr))
	{
		if (instr[k] != ' ' && flag == OUT)
		{
			flag = IN;
			mixChars(instr + k, outstr + k);
		}

		else if (instr[k] == ' ' && flag == IN)
		{
			flag = OUT;
			outstr[k] = ' ';
		}
		k++;
	}
	return outstr;
}