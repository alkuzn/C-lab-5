/*
 * main2.c
 *
 *  Created on: 15 янв. 2018 г.
 *      Author: michael
 */
#ifdef WIN32
#include <windiws.h>
#define CLEAR_WINDOW "cls"
#else
#define CLEAR_WINDOW "clear"
#endif

#include <time.h>
#include <stdlib.h>
#include "task2.h"


int main(){
	char arr[16][16];
	clock_t now;

	while(1){
		system(CLEAR_WINDOW);
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		printMatrix(arr);
		now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
	}
	return 0;
}
