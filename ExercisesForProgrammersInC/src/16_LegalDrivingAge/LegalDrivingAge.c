/*
 * LegalDrivingAge.c
 *
 *  Created on: 2016¦~3¤ë14¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

enum { LEGAL_DRIVING_AGE = 16 };

char ageStr[10];

void LegalDrivingAge_create() {
	ageStr[0] = '\0';
}

void LegalDrivingAge_doCheck() {
	int age;
	char * bufOutput = "";

	ConsoleIO_printf("What is your age? ");
	Common_getStringFromConsole(ageStr);
	if (Common_isIntegerString(ageStr)) {
		age = atoi(ageStr);
		if (age < 0)
			bufOutput = "Please enter a valid age!";
		else if (age < LEGAL_DRIVING_AGE)
			bufOutput = "You are not old enough to legally drive.";
		else
			bufOutput = "You are old enough to legally drive.";
	} else {
		bufOutput = "Please enter a valid age!";
	}
	ConsoleIO_printf(bufOutput);
}
