/*
 * Common.c
 *
 *  Created on: 2016¦~1¤ë27¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include "Common/ConsoleIO.h"

int (* Common_rand) () = rand;

void Common_getStringFromConsole(char * str) {
	char c;
	int i = 0;

	do {
		c = (char)ConsoleIO_getchar();
		if(c == '\n' || c == '\r')
			c = '\0';
		str[i++] = c;
	} while (c != '\0');
}

bool Common_isIntegerString(char * str) {
	int length = strlen(str);
	int i = 0;

	if (!length)
		return false;

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; i < length; i++)
		if (!isdigit((int)str[i]))
			return false;

	return true;
}

bool Common_isDoubleString(char * str) {
	int length = strlen(str);
	bool gotDot = false;

	if (!length)
		return false;

	for (int i=0; i < length; i++) {
		if (str[i] == '.' && !gotDot)
			gotDot = true;
		else if (str[i] == '.' && gotDot)
			return false;
		if (!isdigit((int)str[i]) && str[i] != '.')
			return false;
	}
	return true;
}

void Common_getStringFromConsoleAndNoEcho(char * str) {
	char c;
	int i = 0;

	do {
		c = (char)ConsoleIO_getch();
		if(c == '\n' || c == '\r')
			c = '\0';
		str[i++] = c;
		if ( c != '\0' )
			ConsoleIO_putchar('*');
	} while (c != '\0');
	ConsoleIO_putchar('\n');
}

