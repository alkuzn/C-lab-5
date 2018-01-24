/*
 * task2.c
 *
 *  Created on: 15 янв. 2018 г.
 *      Author: michael
 */
#include <time.h>
#include <stdio.h>

#define M_TASK2 16

void fillMatrix(char (* arr)[M_TASK2]){
	char count = (M_TASK2 / 2);
	srand(time(NULL));
	for (char i = 0; i < count; i++){
		arr[i][(rand()%count)] = '*';
	}
}

void printMatrix(char (*arr)[M_TASK2]){
	for (char i = 0; i < M_TASK2; i++){
		for (char j = 0; j < M_TASK2; j++){
			putchar(arr[i][j]);
		}
		putchar('\n');
	}
}

void clearMatrix(char (*arr)[M_TASK2]){
	for (char i = 0; i < M_TASK2; i++){
		for (char j = 0; j < M_TASK2; j++){
			arr[i][j] = ' ';
		}
	}
}

void setMatrix(char (*arr)[M_TASK2]){
	char count = (M_TASK2 / 2);
	char end = M_TASK2 - 1;
	for (char i = 0; i < count; i++){
		for (char j = 0; j < count; j++){
			arr[i][end - j] = arr[i][j];
		}
	}

	for (char i = 0; i < count; i++){
		for (char j = 0; j < M_TASK2; j++){
			arr[end - i][j] = arr[i][j];
		}
	}
}
