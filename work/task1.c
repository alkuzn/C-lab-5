/*
 * task1.c
 *
 *  Created on: 17 янв. 2018 г.
 *      Author: michael
 */

#include <string.h>
#include <stdlib.h>

char * randomWords(char * in, char *out){
	char * pointers[64][2];
	int cur_word = 0;
	int in_word = 0;
	int word_count = 0;
	int length = strlen(in);
	int i = 0;
	for (; i < length; i++){
		if (in_word == 0 && in[i] != ' '){
			in_word = 1;
			word_count++;
			pointers[cur_word][0] = in + i;
		}else if (in_word == 1 && in[i] == ' '){
			in_word = 0;
			pointers[cur_word][1] = in + i;
			cur_word++;
		}
	}
	pointers[cur_word][1] = in + i;

	int rand_index = 0;
	int swap_count = word_count - 1;
	for (;swap_count > 0; swap_count--){
		rand_index = rand()%(word_count - 1);
		memcpy(pointers[word_count],pointers[swap_count],sizeof(char*)*2);
		memcpy(pointers[swap_count],pointers[rand_index],sizeof(char*)*2);
		memcpy(pointers[rand_index],pointers[word_count],sizeof(char*)*2);
	}


	int place = 0;
	for (int i = 0; i < word_count; i++){
		int j = 0;
		while (pointers[i][0] + j < pointers[i][1]){
			out[place] = *(pointers[i][0] + j);
			j++;
			place++;
		}
		out[place] = ' ';
		place++;
	}
	out[place-1] = '\0';

	return out;
}
