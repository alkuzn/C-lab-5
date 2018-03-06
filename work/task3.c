


char *mixChars(char *in, char *out)
{
	int rand_pos, lenght = strlen(in);
	char buf;
	int i = 0;
	while (out[i++] = in[i]);
	for (i = 1; i < lenght - 1; ++i)
	{
		rand_pos = 1 + rand() % (lenght - 2);
		buf = out[rand_pos];
		out[rand_pos] = out[i];
		out[i] = buf;
	}
	return out;
}

char *mixLine(char *in, char *out)
{
	char buf[256] = {0};
	char word[256] = {0};
	int begin = 0;
	int inword = 0, count = 0, strlenght = strlen(in);
	for (int i = 0; i < strlenght + 1; ++i)
	{
		if ((in[i] != ' ') && !inword)
		{
			inword = 1;
			begin = i;
		}
		else if ((in[i] == ' ' || in[i] == '\0') && inword)
		{
			int y = 0;
			for (int  f = begin; (f < i); ++y, ++f)
				word[y] = in[f];
			if (word[y - 1] == '\n')word[y- 1] = '\0';
			else word[y] = '\0';
			mixChars(word, buf);
			y = 0;
			for (int f = begin; f < i; ++y, ++f)
				out[f] = buf[y];
			out[i] = ' ';
			inword = 0;
		}
		else if (in[i] == ' ')out[i] = ' ';
	}
	if (inword)
		out[strlenght - 1] = '\0';
	else
		out[strlenght] = '\0';
	return out;
}