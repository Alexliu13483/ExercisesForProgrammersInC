/*
 * PasswordValidation.c
 *
 *  Created on: 2016¦~3¤ë3¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"

const char thePassword[] = "abc$123";
const char correctPassordSting[] = "Welcome!";
const char incorrectPasswordString[] = "I don't know you.";
char passwordString[80];

void PasswordValidation_create() {
	passwordString[0] = '\0';
}

bool PasswordValidation_isCorrectPassword(char * password) {
	return !strcmp(password, thePassword);
}

const char * PasswordValidation_checkAndReturnString(char * password) {
	if (PasswordValidation_isCorrectPassword(password))
		return correctPassordSting;
	return incorrectPasswordString;
}

char * PasswordValidation_getPasswordFromConsole() {
	ConsoleIO_printf("\nEnter password: ");
	Common_getStringFromConsoleAndNoEcho(passwordString);
	return (char *)PasswordValidation_checkAndReturnString(passwordString);
}
