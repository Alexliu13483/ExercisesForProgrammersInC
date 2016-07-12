/*
 * Validating_Inputs.c
 *
 *  Created on: 2016¦~7¤ë12¤é
 *      Author: alex.liu
 */
#include <string.h>
#include <ctype.h>
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

	if (len != 7)
		return VALID_INPUT_WRONG_ID;

	for (int i = 0; i < 2; i++)
		if (!isalpha(id[i]))
			return VALID_INPUT_WRONG_ID;
	if (id[2] != '-')
		return VALID_INPUT_WRONG_ID;
	for (int i = 3; i < 7; i++)
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
	char str[] =
			"Enter the first name: J\n"
			"Enter the last name: \n"
			"Enter the ZIP code: ABCDE\n"
			"Enter an employee ID:  A12-1234\n"
			"\"J\" is not a valid first name. It is too short.\n"
			"The last name must be filled in.\n"
			"The ZIP code must be numeric.\n";


	ConsoleIO_printf(str);
}
