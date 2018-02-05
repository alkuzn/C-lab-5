/*
 * main3.c
 *
 *  Created on: 18 янв. 2018 г.
 *      Author: michael
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"

#define M_TASK3 256
#define N_TASK3 64

int main(){
	char arr[N_TASK3][M_TASK3];
	char * out_not_needed;
	int count = 0;
	char fname[32];
	FILE* fp;

	scanf("%s", fname);
	fp = fopen(fname,"r");
	while(count < N_TASK3 && fgets(arr[count],256,fp) != NULL){
		if (arr[count][strlen(arr[count])-1] == '\n')
			arr[count][strlen(arr[count])-1] = 0;
		count++;
	}
	fclose(fp);

	srand(time(NULL));
	fp = fopen("result","w");
	for (int i = 0; i < count; i++){
		mixLine(arr[i], out_not_needed);
		if (i+1 < count)
			arr[i][strlen(arr[i])] = '\n';
		fputs(arr[i], fp);
	}

	fclose(fp);
	return 1;
}
