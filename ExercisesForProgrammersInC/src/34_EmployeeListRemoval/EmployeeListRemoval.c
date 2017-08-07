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

void EmployeeListRemoval_remove(NameList * namelist) {
	int numOfNames = 0;
	char firstName[40];
	int i = 0;

	numOfNames = namelist->num;

	ConsoleIO_printf("There are %d employees:\n", numOfNames);

	printNames(namelist);

	ConsoleIO_printf("\nEnter an employee name to remove: ");
	Common_getStringFromConsole(firstName);
	if (firstName[0] == '\0')
		return;
	else {
		for (i = 0; i < namelist->num; i++) {
			if(strcmp(firstName, namelist->names[i]) == 0) {
				namelist->names[i] = NULL;
				numOfNames--;
			}
		}

		ConsoleIO_printf("\nThere are %d employees:\n", numOfNames);
		printNames(namelist);
	}
}
