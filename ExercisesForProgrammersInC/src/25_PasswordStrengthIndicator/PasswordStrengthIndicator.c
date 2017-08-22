/*
 * PasswordStrengthIndicator.c
 *
 *  Created on: 2016¦~7¤ë7¤é
 *      Author: Alex.Liu
 */

#include "25_PasswordStrengthIndicator/PasswordStrengthIndicator.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Common/Common.h"

void PasswordStrengthIndicator_create() {

}

static bool isAlphabeticString(char * password) {
	int len = strlen(password);

	for (int i = 0; i < len; i++)
		if (!isalpha(password[i]))
			return false;
	return true;
}

static bool isThereSpecialChar(char * password) {
	int len = strlen(password);

	for (int i = 0; i < len; i++)
		if (isgraph(password[i]) && !isalnum(password[i]))
			return true;
	return false;
}

static bool isThereAlpha(char * password) {
	int len = strlen(password);

	for (int i = 0; i < len; i++)
		if (isalpha(password[i]))
			return true;
	return false;
}

static bool isThereNumber(char * password) {
	int len = strlen(password);

	for (int i = 0; i < len; i++)
		if (isdigit(password[i]))
			return true;
	return false;
}

static bool isGraphString(char * password) {
	int len = strlen(password);

	for (int i = 0; i < len; i++)
		if (!isgraph(password[i]))
			return false;
	return true;
}

PasswordStrength PasswordStrengthIndicator_passwordValidator(char * password) {
	PasswordStrength result = VERY_WEAK;
	int len = strlen(password);

	if (!isGraphString(password) || len < MINIMUN_PASSWORD_LENGTH || len > MAXIMUN_PASSWORD_LENGTH)
		return INVALID;

	if (len >= 8) {
		if (isThereSpecialChar(password) && isThereAlpha(password) && isThereNumber(password))
			result = VERY_STRONG;
		else if((isThereAlpha(password) && isThereNumber(password)) ||
				(isThereAlpha(password) && isThereSpecialChar(password)) ||
				(isThereSpecialChar(password) && isThereNumber(password)))
			result = STRONG;
		else
			result = AVERAGE;
	} else if (isAlphabeticString(password))
		result = WEAK;

	return result;
}
