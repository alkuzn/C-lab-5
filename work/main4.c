/*
 * main4.c
 *
 *  Created on: 20 янв. 2018 г.
 *      Author: michael
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "task1.h"

#define M_TASK4 256
#define N_TASK4 64



int main(){
	char arr[N_TASK4][M_TASK4];
	char out[N_TASK4][M_TASK4];
	int count = 0;
	char fname[32];
	FILE* fp;

	scanf("%s", fname);
	fp = fopen(fname,"r");
	while(count < N_TASK4 && fgets(arr[count],256,fp) != NULL){
		arr[count][strlen(arr[count])-1] = 0;
		count++;
	}
	fclose(fp);

	fopen("result","w");
	srand(time(NULL));
	for (int i = 0; i < count; i++){
		randomWords(arr[i],out[i]);
		out[i][strlen(out[i])] = '\n';
		fprintf(fp, out[i]);
	}
	fclose(fp);


	return 1;
}
