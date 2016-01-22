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
	outputString = calloc(sizeof(char), strlen(str)+20);
	sprintf(outputString, "%s has 5 characters.", str);
}

char * CountNumberOfChar_outputString() {
	return outputString;
}

