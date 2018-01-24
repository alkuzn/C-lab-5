/*
 * main2.c
 *
 *  Created on: 17 янв. 2018 г.
 *      Author: michael
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "task1.h"

int main(){
	char str[128];
	char random_str[128];

	puts("Enter string");
	fgets(str, 128, stdin);
	str[strlen(str)-1] = '\0';

	srand(time(NULL));
	randomWords(str, random_str);

	puts(random_str);

	return 1;
}
