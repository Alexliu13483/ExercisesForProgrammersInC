/*
 * Magic8Ball_create.c
 *
 *  Created on: 2016¦~9¤ë1¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

#define MAX_ANSWERS		4

static char * answers[MAX_ANSWERS] = {
	"Yes",
	"No",
	"Maybe",
	"Ask again later"
};

void Magic8Ball_create() {
	srand(time(NULL));
}

void Magic8Ball_run() {
	char inputBuffer[80];
	int answerIndex = Common_rand() % MAX_ANSWERS;

	ConsoleIO_printf("What's your question? ");
	Common_getStringFromConsole(inputBuffer);
	ConsoleIO_printf("%s.\n", answers[answerIndex]);
}
