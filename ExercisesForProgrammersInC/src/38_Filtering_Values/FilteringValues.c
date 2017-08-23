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

static int filterEvenNumbers(char * inString, int * values) {
	int cnt = 0;

	char* pch = strtok(inString, " \n");
	while (pch != NULL) {
		if (Common_isIntegerString(pch)) {
			int n = atoi(pch);
			if (n % 2 == 0)
				values[cnt++] = n;
		}
		pch = strtok(NULL, " \n");
	}
	return cnt;
}

void FilteringValues_run() {
	char promptStr[] = "Enter a list of numbers, separated by spaces:\n";
	char inString[100];
	int values[100] = {0};
	char strNoEven[] = "There is no even number.\n";

	ConsoleIO_printf(promptStr);
	Common_getStringFromConsole(inString);
	int count = filterEvenNumbers(inString, values);
	if (count == 0)
		ConsoleIO_printf(strNoEven);
	else {
		ConsoleIO_printf("The even numbers are");
		for (int i = 0; i < count; i++)
			ConsoleIO_printf(" %d", values[i]);
		ConsoleIO_printf(".\n");
	}

}

void FilteringValues_filterFile(char * filename, char * outputFileName) {
	FILE * f = fopen(filename, "r");

	if (f == NULL)
		return;

	FILE * outputf = fopen(outputFileName, "w+");
	char line[100];
	int count = 0;
	int values[100];

	while (!feof(f)) {
		fgets(line, 100, f);
		count = filterEvenNumbers(line, values);
		for (int i = 0; i < count; i++) {
			fprintf(outputf, "%d", values[i]);
			if (i == count - 1)
				fprintf(outputf, "\n");
			else
				fprintf(outputf, " ");
		}
	}
	fclose(f);
	fclose(outputf);
}
