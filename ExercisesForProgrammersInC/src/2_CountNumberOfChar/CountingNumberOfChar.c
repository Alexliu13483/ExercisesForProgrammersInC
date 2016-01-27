/*
 * CountingNumberOfChar.c
 *
 *  Created on: 2016¦~1¤ë22¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common/Common.h"

static char * outputString;

void CountNumberOfChar_create() {
	outputString = NULL;
}

void CountNumberOfChar_destroy() {
	free(outputString);
}

void CountNumberOfChar_setInputString(char * str) {
	int countStr = strlen(str);

	outputString = calloc(sizeof(char), countStr+32);
	sprintf(outputString, "%s has %d characters.", str, countStr);
}

char * CountNumberOfChar_outputString() {
	return outputString;
}

/*
static void getStringFromConsole(char * str) {
	char c;
	int i = 0;

	do {
		c = (char)getchar();
		if(c == '\n' || c == '\r')
			c = '\0';
		str[i++] = c;
	} while (c != '\0');
}
*/
void CountNumberOfChar_inputByConsole() {
	char str[80];

	do {
		printf("\nWhat is the input string? ");
		Common_getStringFromConsole(str);
		if (str[0] != '\0') {
			CountNumberOfChar_setInputString(str);
			printf("%s\n", outputString);
		} else {
			printf("Please enter something.\n");
		}

	} while (str[0] == '\0');
}
