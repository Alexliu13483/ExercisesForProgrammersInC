/*
 * FakeConsoleIO.c
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */
#include <stdarg.h>
#include <stdio.h>

static char outputString[80 * 25];

int FakeConsoleIO_printf( const char * format, ... ) {
	va_list argptr;
	va_start(argptr, format);
	vsprintf(outputString, format, argptr);
	va_end(argptr);

	return printf(outputString);
}

char * FakeConsoleIO_getOutputString() {
	return outputString;
}
