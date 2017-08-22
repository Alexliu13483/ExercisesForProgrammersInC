/*
 * PrintQuotes.c
 *
 *  Created on: 2016¦~1¤ë26¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>
#include "Common/Common.h"

static char outputStr[256];

void PrintQuote_create() {
	outputStr[0] = '\0';
}

char * PrintQuote_outputString(char * author, char * quote) {
	return strcat(strcat(strcat(strcat(strcat(outputStr, author), " says, "), "\""), quote), "\"");
}

char * PrintQuote_inputByConsole() {
	char quote[80];
	char author[80];

	printf("\nWhat is the quote? ");
	Common_getStringFromConsole(quote);
	printf("\nWho said it? ");
	Common_getStringFromConsole(author);
	printf("%s\n", PrintQuote_outputString(author, quote));
	return outputStr;
}
