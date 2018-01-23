#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

int isStrEnd(char sym)
{
	return (sym == '\0') || (sym == '\n');
}

char * mixChars(char *in, char *out)
{
	int numChars = 0, currRand = 0, currNum = 0;
	char *inTmp = in, *outTmp = out;
	char tmp = '\0';

	while (*inTmp != '\0' && *inTmp != ' ')
	{
		*outTmp++ = *inTmp++;
		numChars++;
	}
	*outTmp = *inTmp;

	currNum = numChars - 1;
	while (currNum > 2)
	{
		currRand = rand() % currNum;
		if ((currRand != (currNum - 1)) && currRand)
		{
			tmp = out[currNum - 1];
			out[currNum - 1] = out[currRand];
			out[currRand] = tmp;
		}
		currNum--;
	}

	return out;
}

char * mixLine(char *instr, char *outstr)
{
	char wordIn[SIZE] = { NULL };
	char wordOut[SIZE] = { NULL };
	char *outstrT = outstr, *pT = NULL, *pwT = NULL;
	int i = 0, inWord = 0, count = 0;

	while (instr[i])
	{
		if (instr[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			pT = wordIn;
			*pT = instr[i];
			if (isStrEnd(instr[i + 1]))
			{
				inWord = 0;
				count++;

				*(++pT) = '\0';
				mixChars(wordIn, wordOut);

				pwT = wordOut;
				while (*pwT != '\0')
					*outstrT++ = *pwT++;

				break;
			}
		}
		else if (instr[i] == ' ' && inWord == 1)
		{
			*(++pT) = '\0';
			mixChars(wordIn, wordOut);

			pwT = wordOut;
			while (*pwT != '\0')
				*outstrT++ = *pwT++;
			*outstrT++ = ' ';

			inWord = 0;
			count++;
		}
		else if (instr[i] != ' ' && inWord == 1)
		{
			*(++pT) = instr[i];
			if (isStrEnd(instr[i + 1]))
			{
				inWord = 0;
				count++;

				*(++pT) = '\0';
				mixChars(wordIn, wordOut);

				pwT = wordOut;
				while (*pwT != '\0')
					*outstrT++ = *pwT++;

				break;
			}
		}
		i++;
	}

	*outstrT = '\0';

	return outstr;
}
