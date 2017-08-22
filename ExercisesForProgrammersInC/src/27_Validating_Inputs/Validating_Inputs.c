/*
 * Validating_Inputs.c
 *
 *  Created on: 2016¦~7¤ë12¤é
 *      Author: alex.liu
 */
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"
#include "27_Validating_Inputs/Validating_Inputs.h"

void ValidateInput_create() {

}

VALID_INPUT_RESULT ValidateInput_ValidateName(char * name) {
	int len = strlen(name);

	if (len == 0)
		return VALID_INPUT_NULL;
	if (len < 2)
		return VALID_INPUT_SHORT_NAME;
	for (int i = 0; i < len; i++)
		if (!isalpha(name[i]))
			return VALID_INPUT_NON_ALPHABET;
	return VALID_INPUT_OK;
}

VALID_INPUT_RESULT ValidateInput_ValidateID(char * id) {
	int len = strlen(id);

	if (len == 0)
		return VALID_INPUT_OK;

	if (len < 5)
		return VALID_INPUT_WRONG_ID;

	for (int i = 0; i < 2; i++)
		if (!isalpha(id[i]))
			return VALID_INPUT_WRONG_ID;
	if (id[2] != '-')
		return VALID_INPUT_WRONG_ID;
	for (int i = 3; i < len; i++)
		if (!isdigit(id[i]))
			return VALID_INPUT_WRONG_ID;

	return VALID_INPUT_OK;
}

VALID_INPUT_RESULT ValidateInput_ValidateZIP(char * zip) {
	int len = strlen(zip);

	if (len == 0)
		return VALID_INPUT_OK;

	if (len != 5)
		return VALID_INPUT_WRONG_ZIP;

	for (int i = 0; i < len; i++)
		if (!isdigit(zip[i]))
			return VALID_INPUT_WRONG_ZIP;

	return VALID_INPUT_OK;
}

void ValidateInput_run() {
	char firstName[80] = "";
	char lastName[80] = "";
	char zipStr[80] = "";
	char idStr[80] = "";
	VALID_INPUT_RESULT checkResult;
	bool isOK = true;

	ConsoleIO_printf("Enter the first name: ");
	Common_getStringFromConsole(firstName);
	ConsoleIO_printf("Enter the last name: ");
	Common_getStringFromConsole(lastName);
	ConsoleIO_printf("Enter the ZIP code: ");
	Common_getStringFromConsole(zipStr);
	ConsoleIO_printf("Enter an employee ID: ");
	Common_getStringFromConsole(idStr);

	checkResult = ValidateInput_ValidateName(firstName);
	if (checkResult != VALID_INPUT_OK) {
		isOK = false;
		if (checkResult == VALID_INPUT_NULL)
			ConsoleIO_printf("The first name must be filled in.\n");
		else if (checkResult == VALID_INPUT_SHORT_NAME)
			ConsoleIO_printf("\"%s\" is not a valid first name. It is too short.\n", firstName);
	}


	checkResult = ValidateInput_ValidateName(lastName);
	if (checkResult != VALID_INPUT_OK) {
		isOK = false;
		if (checkResult == VALID_INPUT_NULL)
			ConsoleIO_printf("The last name must be filled in.\n");
		else if (checkResult == VALID_INPUT_SHORT_NAME)
			ConsoleIO_printf("\"%s\" is not a valid last name. It is too short.\n", lastName);
	}

	checkResult = ValidateInput_ValidateZIP(zipStr);
	if (checkResult != VALID_INPUT_OK) {
		isOK = false;
		if (checkResult == VALID_INPUT_NULL)
			ConsoleIO_printf("The ZIP code must be filled in.\n");
		else if (checkResult == VALID_INPUT_WRONG_ZIP)
			ConsoleIO_printf("The ZIP code must be numeric.\n");
	}

	checkResult = ValidateInput_ValidateID(idStr);
	if (checkResult != VALID_INPUT_OK) {
		isOK = false;
		if (checkResult == VALID_INPUT_NULL)
			ConsoleIO_printf("The ID must be filled in.\n");
		else if (checkResult == VALID_INPUT_WRONG_ID)
			ConsoleIO_printf("%s is not a valid ID.\n", idStr);
	}

	if (isOK)
		ConsoleIO_printf("There were no errors found.\n");

}
