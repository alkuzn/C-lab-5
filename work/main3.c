/*
 * main3.c
 *
 *  Created on: 12 февр. 2018 г.
 *      Author: michael
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "task3.h"


int main(){
	char str[256];
	char reversed_str[256];
	char f_in[64];
	FILE* fp_in;
	FILE* fp_out;

	scanf("%s", f_in);
	fp_in = fopen(f_in,"r");
	fp_out = fopen("result","w");

	srand(time(NULL));
	while (fgets(str, 256, fp_in) != NULL){
		if (str[strlen(str)-1] == '\n')
			str[strlen(str)-1] = '\0';

		mixLine(str,reversed_str);
		fputs(reversed_str,fp_out);
		fputs("\n",fp_out);
	}

	close(fp_in);
	close(fp_out);
	return 0;
}
