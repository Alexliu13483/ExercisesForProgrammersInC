/*
 * pickWinner.c
 *
 *  Created on: 2017¦~8¤ë14¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"

#define NUM_OF_NAMES 100
static char * names[NUM_OF_NAMES];

void pickWinner_create() {
	for (int i = 0; i < NUM_OF_NAMES; i++)
		names[i] = NULL;
	srand(time(NULL));
}

void pickWinner_destroy() {
	int i = 0;
	while(names[i] != NULL)
		free(names[i++]);
}

void pickWinner_run() {
	char promptStr[] = "Enter a name: ";
	char ResultPreStr[] = "The Winner is... ";
	char strNone[] = "None";
	char inBuffer[100] = "";
	char result[100] = "";
	int counter = 0;
	char * name;

	for (int i = 0; i < NUM_OF_NAMES; i++) {
		ConsoleIO_printf("%s", promptStr);
		Common_getStringFromConsole(inBuffer);
		if (inBuffer[0] == ' ' || inBuffer[0] == '\0')
			break;

		name = (char *)malloc(strlen(inBuffer)+1);
		strcpy(name, inBuffer);
		names[counter] = name;
		counter++;
	}

	if (counter == 0)
		strcpy(result, strNone);
	else {
		int i = Common_rand() % counter;
		strcpy(result, names[i]);
	}

	ConsoleIO_printf("%s%s\n", ResultPreStr, result);
}

