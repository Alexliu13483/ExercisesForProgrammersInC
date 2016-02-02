/*
 * RetirementCalculator.c
 *
 *  Created on: 2016¦~1¤ë28¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Common/Common.h"

static char output[256];

void RetirementCalculator_create() {
	output[0] = '\0';
}

char * RetirementCalculator_calculate(int currentAge, int retireAge) {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	sprintf(output, "You have %d years left until you can retire.\nIt's %d, so you can retire in %d.",
			retireAge - currentAge,
			timeinfo->tm_year + 1900,
			retireAge - currentAge + timeinfo->tm_year + 1900);
	return output;
}

char * RetirementCalculator_getOutputString() {
	return output;
}

void RetirementCalculator_calculateInputFromConsole() {
	char current[16];
	char retire[16];
	int curAge = 0;
	int retAge = 0;

	printf("\n");
	do {
		printf("What is your current age? ");
		Common_getStringFromConsole(current);
	} while (!Common_isIntegerString(current));
	do {
		printf("At what age would you like to retire? ");
		Common_getStringFromConsole(retire);
	} while (!Common_isIntegerString(retire));

	curAge = atoi(current);
	retAge = atoi(retire);
	RetirementCalculator_calculate(curAge, retAge);
	printf("%s", output);
}
