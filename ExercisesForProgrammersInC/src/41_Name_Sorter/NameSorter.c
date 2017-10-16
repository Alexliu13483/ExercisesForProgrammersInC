/*
 * NameSorter.c
 *
 *  Created on: 2017¦~9¤ë6¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "41_Name_Sorter/NameSorter.h"

static char * names[MAX_NAMES];
static int * resultIndex;
static int lineCount;

void NameSorter_create() {
	for (int i = 0; i < MAX_NAMES; i++)
		names[i] = NULL;
	resultIndex = NULL;
	lineCount = 0;
}

void NameSorter_destroy() {
	for (int i = 0; i < lineCount; i++)
		free(names[i]);
	free(resultIndex);
}

static void readDataFromFile(char * filename) {
	char temp[80];
	char * name;

	FILE * file = fopen(filename, "r");
	if (file == NULL)
		return;

	while(!feof(file)) {
		if (fgets(temp, 80, file) != NULL) {
			name = (char *)malloc(sizeof(char) * (strlen(temp)+1));
			strcpy(name, temp);
			names[lineCount++] = name;
		}
	}
	fclose(file);
}

static void sortNames(void) {
	if (lineCount == 0)
		return;

	resultIndex = (int *)malloc(sizeof(int) * lineCount);
	for (int i = 0; i < lineCount; i++)
		resultIndex[i] = i;

}

static void outputResultToString(char * outString) {
	char title[] =	"Total of %d names\n"
					"-----------------\n";
	sprintf(outString, title, lineCount);
	for (int i = 0; i < lineCount; i++)
		strcat(outString, names[resultIndex[i]]);
}

void NameSorter_output_string(char * filename, char * result) {
	readDataFromFile(filename);
	sortNames();
	outputResultToString(result);
}
