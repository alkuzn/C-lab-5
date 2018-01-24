#include "task3.h"



char *mixChars(char *in ,char *out)// - перемешивание символов в одном слове
{
	int i = 0, j = 0, len = 0, flagChar = 0, countWord = 0, symbol = 0;
	int k = 0;
	char *midl[SIZE];
	char *result;
	while (in[j++] != '\0');//look out end of string with '\n'
	len = j - 1;
	for (i = 0;i < len;i++)
	{
		midl[i] = in[i];
		
	}
	midl[i] = '\0';
	countWord = i;
	srand(time(0));
	if (i > 3)//condition for the word more that 3 leters
	{
		for (k = (countWord-1);k > 2;k--)// random dont first letter 
		{
			j = k - 2;
			i = k - 1;
			while ((symbol = rand() % j + 1) == k);//don't last letter
				
			result = midl[i];
			midl[i] = midl[symbol];
			midl[symbol] = result;
		}
	}
	// random each a later woth first and last symbols
	for (i = 0;i<countWord;i++)
		(out[i] = midl[i]);
		
	out[i] = '\0';

	return out;
}
char *mixLine(char *instr, char *outstr)// - перемешивание для целой строки
{
	int i = 0, j = 0, len = 0, flagChar = 0, countWord = 0, symbol = 0;
	int k = 0;
	char *midl[SIZE];
	char buf[SIZE][SIZE];
	char *result;
	char *bufOut;
	char out[SIZE];
	char *in;
	while (instr[j] != '\n')//look out end of string with '\n'
	{
		if (instr[j] == ' ')
			instr[j] = '\0';
		j++;
	}
	len = j - 1;
	instr[j] = '\0';//shange '\n'to '\0'
	for (j = 0;j <= len;j++)
	{
		if (flagChar == OUT && instr[j] != '\0')
		{
			in = &instr[j];
			flagChar++;

		}
		else
		{
			if (instr[j] == '\0')
			{
				mixChars(in, out);
				strcpy(buf[i], out);
				midl[i] = buf[i];
					i++;
				flagChar = OUT;
			}
		}
	}
	midl[i] = '\0';
	countWord = i;
	srand(time(0));

	
	if (countWord == 2)//random condition for only two words
	{
		result = midl[1];
		midl[1] = midl[0];
		midl[0] = result;
	}
	for (;countWord >2;countWord--)// random for two and more words
	{
		j = countWord - 2;
		symbol = rand() % j;
		i = countWord - 1;
		result = midl[i];
		midl[i] = midl[symbol];
		midl[symbol] = result;
	}
	// random each a later woth first and last symbols
	

	for (i = countWord = 0;midl[countWord] != NULL;countWord++)
	{
		for (j = 0;((*(midl + countWord))[j]) != NULL;j++)
		{
			outstr[i++] = (*(midl + countWord))[j];
		}
		outstr[i++] = ' ';

	}
	outstr[i++] = '\n';
	outstr[i] = '\0';
	
	return outstr;
}
