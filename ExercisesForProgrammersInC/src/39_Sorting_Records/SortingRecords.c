/*
 * SortingRecords.c
 *
 *  Created on: 2017¦~8¤ë23¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

typedef struct {
	char * firstName;
	char * lastName;
	char * position;
	char * sepDate;
} Personnel_Record;

#define MAX_DATABASE_SIZE	100

static Personnel_Record database[MAX_DATABASE_SIZE];
static int record_count;

void SortingRecords_create() {
	for (int i = 0; i < MAX_DATABASE_SIZE; i++) {
		database[i].firstName = NULL;
		database[i].lastName = NULL;
		database[i].position = NULL;
		database[i].sepDate = NULL;
	}
	record_count = 0;
}

void SortingRecords_destroy() {
	for (int i = 0; i < record_count; i++) {
		free(database[i].firstName);
		free(database[i].lastName);
		free(database[i].position);
		free(database[i].sepDate);
	}
}

static int extractRecords(char * inputData) {
	int cnt = 0;
	int len = 0;
	char * record;
	char str_token[] = ",\n";

	char* pch = strtok(inputData, str_token);
	while (pch != NULL) {
		len = strlen(pch);
		record = (char *) malloc(len+1);
		strcpy(record, pch);
		database[cnt].firstName = record;
		pch = strtok(NULL, str_token);

		len = strlen(pch);
		record = (char *) malloc(len+1);
		strcpy(record, pch);
		database[cnt].lastName = record;
		pch = strtok(NULL, str_token);

		len = strlen(pch);
		record = (char *) malloc(len+1);
		strcpy(record, pch);
		database[cnt].position = record;
		pch = strtok(NULL, str_token);

		len = strlen(pch);
		record = (char *) malloc(len+1);
		strcpy(record, pch);
		database[cnt].sepDate = record;
		pch = strtok(NULL, str_token);
		cnt++;
	}
	return cnt;
}

static void printDataBase(Personnel_Record ** data) {
	char strHeader[] =  "Name                | Position          | Separation Date\n"
						"--------------------|-------------------|----------------\n";

	ConsoleIO_printf(strHeader);

	int temLen = 0;
	int spaces = 0;
	for (int i = 0; i < record_count; i++) {
		temLen = strlen(data[i]->firstName) + strlen(data[i]->lastName);
		if (temLen >= 19)
			spaces = 0;
		else
			spaces = 19 - temLen;

		ConsoleIO_printf("%s %s", data[i]->firstName, data[i]->lastName);
		for (int j = 0; j < spaces; j++)
			ConsoleIO_printf(" ");

		temLen = strlen(data[i]->position);
		if (temLen >= 18)
			spaces = 0;
		else
			spaces = 18 - temLen;

		ConsoleIO_printf("| %s", data[i]->position);
		for (int j = 0; j < spaces; j++)
			ConsoleIO_printf(" ");

		ConsoleIO_printf("| %s\n", data[i]->sepDate);
	}

}

static void sortRecords(Personnel_Record ** sortedData) {
	int * orderlist = (int *) malloc(sizeof(int) * record_count);
	for (int i = 0; i < record_count; i++)
		orderlist[i] = i;

	for (int i = 0; i < record_count - 1; i++)
		for (int j = i + 1; j < record_count; j++) {
			if (strcmp(database[orderlist[i]].lastName, database[orderlist[j]].lastName) > 0) {
				int temp = orderlist[i];
				orderlist[i] = orderlist[j];
				orderlist[j] = temp;
			}
		}

	for (int i = 0; i < record_count; i++)
		sortedData[i] = &database[orderlist[i]];

	free(orderlist);
}

void SortingRecords_sort(char * inputRecords) {
	record_count = extractRecords(inputRecords);
	Personnel_Record ** sortedData = (Personnel_Record **)malloc(sizeof(Personnel_Record *) * record_count);
	sortRecords(sortedData);
	printDataBase(sortedData);
	free(sortedData);
}
