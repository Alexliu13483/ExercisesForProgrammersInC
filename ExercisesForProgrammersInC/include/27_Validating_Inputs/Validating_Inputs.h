/*
 * Validating_Inputs.h
 *
 *  Created on: 2016¦~7¤ë12¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_27_VALIDATING_INPUTS_VALIDATING_INPUTS_H_
#define INCLUDE_27_VALIDATING_INPUTS_VALIDATING_INPUTS_H_

typedef enum {
	VALID_INPUT_OK,
	VALID_INPUT_NULL,
	VALID_INPUT_SHORT_NAME,
	VALID_INPUT_NON_ALPHABET,
	VALID_INPUT_WRONG_ID,
	VALID_INPUT_WRONG_ZIP
} VALID_INPUT_RESULT;

void ValidateInput_create();
void ValidateInput_run();
VALID_INPUT_RESULT ValidateInput_ValidateName(char * name);
VALID_INPUT_RESULT ValidateInput_ValidateID(char * id);
VALID_INPUT_RESULT ValidateInput_ValidateZIP(char * zip);
#endif /* INCLUDE_27_VALIDATING_INPUTS_VALIDATING_INPUTS_H_ */
