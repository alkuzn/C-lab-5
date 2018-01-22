#include "task3.h"

char *mixChars(char *in, char *out)
{
	srand(time(0));
	int random;
	int count = strlen(in);
	*out = *in;
	*(out+count - 1) = *(in +count - 1);
	count -= 2;
	while (count>=1)
	{
		random = rand() % count+1;
		out[count] = in[random];
		if (random != count)
		{
			in[random] = in[count];
		}		
		count--;
	}
	return out;
}

char *mixLine(char *instr, char * outstr)
{
	char word[M];
	char out[M];
	int flag = OUT;
	int i = 0;
	char* temp = outstr;
	int size = strlen(instr);
	if (instr[size - 1] == '\n')
		instr[size - 1] = '\0';
	while (*instr)
	{
		if (*instr != ' ' && flag == OUT)
		{
			word[i] = *instr;
			i++;
			flag = IN;
		}
		else if (*instr != ' ' && flag == IN)
		{
			word[i] = *instr;
			i++;
			flag = IN;
		}
		else if (*instr == ' ' && flag == IN) 
		{
			flag = OUT;
			word[i] = '\0';
			if (mixChars(word, out)==NULL)
				printf("Error in function mixChars");
			for (int j = 0; j < i; j++)
			{
				*outstr = out[j];
				outstr++;
			}
			*outstr = ' ';
			outstr++;
			i = 0;
		}
			
		instr++;
	}
	word[i] = '\0';
	if (mixChars(word, out) == NULL)
		printf("Error in function mixChars");
	for (int j = 0; j < i; j++)
	{
		*outstr = out[j];
		outstr++;
	}
	*outstr = '\0';
	return temp;
}
