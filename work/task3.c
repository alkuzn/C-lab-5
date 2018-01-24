/*
 * task3.c
 *
 *  Created on: 18 янв. 2018 г.
 *      Author: michael
 */

void mixChars(char *in){
	char buff;
	int count = 0;
	int index = 0;
	int rand_index = 0;
	while ( in[count] != ' ' && in[count] != '\0'){
		count++;
	}
	count-=2;

	for (; count > 0; count--){
		rand_index = (rand()%count);
		if (rand_index == 0) rand_index = 1;
		buff = in[count];
		in[count] = in[rand_index];
		in[rand_index] = buff;
	}
}

void mixLine(char *instr){
	int in_word = 0;
	for(int i = 0; instr[i] != '\0'; i++){
		if(instr[i] != ' ' && in_word == 0){
			in_word = 1;
			mixChars(instr+i);
		}else if(instr[i] == ' ' && in_word == 1){
			in_word = 0;
		}
	}
}

