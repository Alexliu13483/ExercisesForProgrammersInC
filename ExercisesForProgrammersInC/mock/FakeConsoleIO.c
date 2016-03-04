/*
 * FakeConsoleIO.c
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

enum {	OUTPUT_STRING_SIZE = 80 * 25,
		INPUT_KEY_BUFFER_SIZE = 100};

static char outputString[OUTPUT_STRING_SIZE];
static int currentOutputIndex;
static char InputKeyStrokeBuffer[INPUT_KEY_BUFFER_SIZE];
static int currentInputIndex;


void FakeConsoleIO_create() {
	currentOutputIndex = 0;
	currentInputIndex = 0;
	for (int i = 0; i < OUTPUT_STRING_SIZE; i++) {
		outputString[i] = 0;
	}
}

int FakeConsoleIO_printf( const char * format, ... ) {
	char buffer[100];
	int strLength;

	va_list argptr;
	va_start(argptr, format);
	vsprintf(buffer, format, argptr);
	va_end(argptr);

	strcat(outputString, buffer);
	strLength = strlen(buffer);
	currentOutputIndex += strLength;
	return strLength;
}

char * FakeConsoleIO_getOutputString() {
	return outputString;
}

int FakeConsoleIO_getchar() {
	outputString[currentOutputIndex] = InputKeyStrokeBuffer[currentInputIndex++];
	return (int)outputString[currentOutputIndex++];
}

void FakeConsoleIO_setKeyInBuffer(char * InputKeyStrokes) {
	strncpy(InputKeyStrokeBuffer, InputKeyStrokes, strlen(InputKeyStrokes));
}
