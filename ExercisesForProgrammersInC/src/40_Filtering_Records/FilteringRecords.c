/*
 * FilteringRecords.c
 *
 *  Created on: 2017¦~8¤ë29¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"
#include "39_Sorting_Records/SortingRecords.h"

static int cntDatabase = 0;

void FilteringRecords_create() {
	SortingRecords_create();
}

void FilteringRecords_createDatabase(char * inputData) {
	cntDatabase = SortingRecords_CreateDatabase(inputData);
}

void FilteringRecords_destroy() {
	SortingRecords_destroy();
}

void FilteringRecords_run() {
	char input[100];

	int * results = (int *)malloc(cntDatabase * sizeof(int));

	for (int i = 0; i < cntDatabase; i++)
		results[i] = -1;

	ConsoleIO_printf("Enter a search string: ");
	Common_getStringFromConsole(input);
	SortingRecords_filter(input, results);
	/*for (int i = 0; i < cntDatabase; i++)
		printf("results[%d] = %d\n", i, results[i]);*/
	SortingRecords_printRecords(results);
	free(results);
}
