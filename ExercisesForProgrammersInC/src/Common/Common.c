/*
 * Common.c
 *
 *  Created on: 2016¦~1¤ë27¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>

void Common_getStringFromConsole(char * str) {
	char c;
	int i = 0;

	do {
		c = (char)getchar();
		if(c == '\n' || c == '\r')
			c = '\0';
		str[i++] = c;
	} while (c != '\0');
}
