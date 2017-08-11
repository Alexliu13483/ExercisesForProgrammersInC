/*
 * EmployeeListRemoval.c
 *
 *  Created on: 2017¦~8¤ë3¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include <string.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"
#include "34_EmployeeListRemoval\EmployeeListRemoval.h"

void EmployeeListRemoval_create() {

}

static void printNames(NameList * namelist) {
	for(int i = 0; i < namelist->num; i++)
		if (namelist->names[i] != NULL)
			ConsoleIO_printf("%s\n", namelist->names[i]);
}

static int removeName(char firstName[40], NameList* namelist) {
	int numOfNames = namelist->num;

	for (int i = 0; i < namelist->num; i++) {
		if (strcmp(firstName, namelist->names[i]) == 0) {
			namelist->names[i] = NULL;
			numOfNames--;
		}
	}
	return numOfNames;
}

static int ReleaseName(char firstName[40], NameList* namelist) {
	int numOfNames = namelist->num;

	for (int i = 0; i < namelist->num; i++) {
		if (strcmp(firstName, namelist->names[i]) == 0) {
			free(namelist->names[i]);
			namelist->names[i] = NULL;
			numOfNames--;
		}
	}
	return numOfNames;
}


void EmployeeListRemoval_remove(NameList * namelist) {
	char firstName[40];

	ConsoleIO_printf("There are %d employees:\n", namelist->num);

	printNames(namelist);

	ConsoleIO_printf("\nEnter an employee name to remove: ");
	Common_getStringFromConsole(firstName);
	if (firstName[0] == '\0')
		return;
	else {
		int numOfNames = removeName(firstName, namelist);

		if (numOfNames < namelist->num) {
			ConsoleIO_printf("\nThere are %d employees:\n", numOfNames);
			printNames(namelist);
		} else {
			ConsoleIO_printf("\nError! The name doesn\'t exist.\n");
		}
	}
}

void EmployeeListRemoval_removeFromFile(char * filename, char * removeName) {
	FILE * f = fopen(filename, "r");
	char name[100];
	char * nameStr;
	NameList namelist;
	char * names[100];

	namelist.num = 0;
	namelist.names = names;
	for (int i = 0; i < 100; i++)
		namelist.names[i] = NULL;

	while(fgets(name, 100, f) != NULL) {
		int len = strlen(name);
		nameStr = (char *)malloc(len);
		name[len-1] = '\0';
		strcpy(nameStr, name);
		namelist.names[namelist.num++] = nameStr;
	}
	fclose(f);

	int numOfNames = ReleaseName(removeName, &namelist);

	if (numOfNames < namelist.num) {
		f = fopen(filename, "w");
		for(int i = 0; i < namelist.num; i++) {
			if (namelist.names[i] != NULL)
				fprintf(f, "%s\n", namelist.names[i]);
		}
		fclose(f);
	} else {
		ConsoleIO_printf("Error! The name doesn\'t exist.\n");
	}

	for(int i = 0; i < namelist.num; i++) {
		if (namelist.names[i] != NULL)
			free(namelist.names[i]);
	}

}
