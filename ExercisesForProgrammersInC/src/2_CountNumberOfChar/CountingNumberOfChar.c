/*
 * CountingNumberOfChar.c
 *
 *  Created on: 2016¦~1¤ë22¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void CountNumberOfChar_inputByConsole() {
	char str[80];

	printf("\nWhat is the input string? ");
	scanf("%79s", str);
	CountNumberOfChar_setInputString(str);
	printf("%s\n", outputString);
}
