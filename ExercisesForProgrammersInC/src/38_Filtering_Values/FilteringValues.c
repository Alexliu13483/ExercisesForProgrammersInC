/*
 * FilteringValues.c
 *
 *  Created on: 2017¦~8¤ë22¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

void FilteringValues_create() {

}

void FilteringValues_run() {
	char promptStr[] = "Enter a list of numbers, separated by spaces:\n";
	char inString[100];
	int values[100] = {0};
	int count = 0;
	char strNoEven[] = "There is no even number.\n";

	ConsoleIO_printf(promptStr);
	Common_getStringFromConsole(inString);
	char * pch = strtok (inString," ");
	while (pch != NULL) {
		if (Common_isIntegerString(pch)) {
			int n = atoi(pch);
			if (n % 2 == 0)
				values[count++] = n;
		}
		pch = strtok (NULL, " ");
	}

	if (count == 0)
		ConsoleIO_printf(strNoEven);
	else {
		ConsoleIO_printf("The even numbers are");
		for (int i = 0; i < count; i++)
			ConsoleIO_printf(" %d", values[i]);
		ConsoleIO_printf(".\n");
	}

}
