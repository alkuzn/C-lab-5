#include <stdlib.h>
#include <time.h>

//Перемешивание массива символов (перемешивание символов в одном 
//слове за исключением первого и последнего символов)
char *mixChars(char *in, char *out)
{
	strcpy(out, in);	//Копируем входную строку в выходную
	srand(time(NULL));
	int i, k;
	char buf;	//Буферная переменная
	int n; //Длинна слова
	//Вычисляем длинну слова
	for (n = 0; out[n] != ' ' && out[n] != '\0' && out[n] != '\n'; n++);
	//Выполняем перемешивание
	for (i = 1; i < n - 2; i++)
	{
		k = i + rand() % (n - i - 1);	//Всего слова (кроме последнего символа)
		buf = out[i];
		out[i] = out[k];
		out[k] = buf;
	}
	return out;
}

char *mixLine(char *instr, char * outstr)	//перемешивание для целой строки
{
	for (int i = 0; instr[i] != '\0' && instr[i] != '\n'; i++)
	{
		if (instr[i] != ' ' && (i == 0 || instr[i - 1] == ' '))
		{
			mixChars(&(instr[i]), &(outstr[i]));
		}
		else if (instr[i] == ' ')
		{
			outstr[i] = instr[i];
		}
	}
	outstr[strlen(instr)] = '\0';
	return outstr;
}
