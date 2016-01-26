/*
 * PrintQuotes.c
 *
 *  Created on: 2016¦~1¤ë26¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>

static char outputStr[256];

void PrintQuote_create() {
	outputStr[0] = '\0';
}

char * PrintQuote_outputString(char * author, char * quote) {
	return strcat(strcat(strcat(strcat(strcat(outputStr, author), " says, "), "\""), quote), "\"");
}
