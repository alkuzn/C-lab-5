/*
 * task3.c
 *
 *  Created on: 12 февр. 2018 г.
 *      Author: michael
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char *mixChars(char *in, char *out){
	char buff;
	int count = 0;
	int rand_index = 0;
	while ( in[count] != ' ' && in[count] != '\0'){
		count++;
	}
	count-=2;

	memcpy(out,in,strlen(in));

	for (; count > 0; count--){
		rand_index = (rand()%count);
		if (rand_index == 0) rand_index = 1;
		buff = out[count];
		out[count] = out[rand_index];
		out[rand_index] = buff;
	}

	return out;
}


char *mixLine(char *instr, char *outstr){
	int in_word = 0;
	int count = 0;
	char *start;
	for (int i = 0; i <= strlen(instr); i++){
		if (in_word == 0 && instr[i] != ' '){
			start = instr+i;
			in_word = 1;
			count++;
		}else if (in_word == 1 && instr[i] != ' ' && instr[i] != '\0'){
			count++;
		}else if (in_word == 1 && (instr[i] == ' ' || instr[i] == '\0')){
			char *word = (char*) malloc(count);
			char *reversed_word = (char*) malloc(count);
			memcpy(word,start,count);
			word[count] = '\0';
			mixChars(word, reversed_word);

			for (int i = 0; i < count; i++){
				outstr[(start - instr) + i] = reversed_word[i];
			}

			if (instr[i] != '\0'){
				outstr[i] = ' ';
			}else{
				outstr[i] = '\0';
			}

			free(word);
			free(reversed_word);
			count = 0;
			in_word = 0;

		}
	}

	return outstr;
}




