/*
 * PasswordValidation.h
 *
 *  Created on: 2016¦~3¤ë3¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_PASSWORDVALIDATION_H_
#define INCLUDE_PASSWORDVALIDATION_H_

#include <stdbool.h>

void PasswordValidation_create();
bool PasswordValidation_isCorrectPassword(char * password);
const char * PasswordValidation_checkAndReturnString(char * password);
char * PasswordValidation_getPasswordFromConsole();

#endif /* INCLUDE_PASSWORDVALIDATION_H_ */
