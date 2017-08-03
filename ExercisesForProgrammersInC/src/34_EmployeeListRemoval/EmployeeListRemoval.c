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

void EmployeeListRemoval_remove(char ** names) {
	int numOfNames = 0;
	char firstName[40];
	int i = 0;
	int removedNum = 0;

	while (names[numOfNames][0] != '\0') {
		numOfNames++;
	}

	ConsoleIO_printf("There are %d employees:\n", numOfNames);

	while (names[i][0] != '\0') {
		ConsoleIO_printf("%s\n", names[i++]);
	}

	ConsoleIO_printf("\nEnter an employee name to remove: ");
	Common_getStringFromConsole(firstName);
	if (firstName[0] == '\0')
		return;
	else {
		for (i = 0; i < numOfNames; i++) {
			if(strcmp(firstName, names[i]) == 0) {
				names[i] = NULL;
				removedNum++;
			}
		}

		ConsoleIO_printf("\nThere are %d employees:\n", numOfNames - removedNum);
		for (i = 0; i < numOfNames; i++) {
			if (names[i] != NULL)
				ConsoleIO_printf("%s\n", names[i]);
		}

	}
}
