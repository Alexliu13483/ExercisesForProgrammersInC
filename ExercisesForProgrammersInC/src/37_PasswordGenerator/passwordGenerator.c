/*
 * passwordGenerator.c
 *
 *  Created on: 2017¦~8¤ë18¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"
#include "37_PasswordGenerator/passwordGenerator.h"

static char password[MAX_PASSWORD_LENGTH + 1] = "\0";
static int minimumLen = 0;
static int numSpecial = 0;
static int numNumbers = 0;
static int numAlphbets = 0;
static int sizeOfNumbers;
static int sizeOfAlphabet;
static int sizeOfSpecials;

/************************   01234567890123456789012345   */
const char tblAlaphet[] =  "abcdefghijklmnopqrstuvwxyz"
						   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char tblSpecials[] = "!@#$%^&*()_+=-[]{}/.,";
const char tblNumbers[] =  "0123456789";

typedef enum {
	Alphet = 0,
	Number,
	Special,
	NUMBER_OF_TYPE
} Char_Type;

void passwordGenerator_create() {
	srand(time(NULL));
	minimumLen = 0;
	numSpecial = 0;
	numNumbers = 0;
	numAlphbets = 0;
	password[0] = '\0';

	sizeOfNumbers = sizeof(tblNumbers) - 1;
	sizeOfAlphabet = sizeof(tblAlaphet) - 1;
	sizeOfSpecials = sizeof(tblSpecials) - 1;
}

static Char_Type decideCharType() {
	return (Char_Type)(Common_rand() % NUMBER_OF_TYPE);
}

static void promptAndInputFromConsole() {
	char promptStr1[] = "What's the minimum length ";
	char promptStr2[] =	"How many special characters ";
	char promptStr3[] =	"How many numbers ";
	char promptStr4[] =	"Your password is\n";
	char inString[100];

	ConsoleIO_printf("%s", promptStr1);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		minimumLen = atoi(inString);
	}
	ConsoleIO_printf("%s", promptStr2);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		numSpecial = atoi(inString);
	}
	ConsoleIO_printf("%s", promptStr3);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		numNumbers = atoi(inString);
	}
	ConsoleIO_printf("%s", promptStr4);
}

static int getPasswordLength(int minimumLen) {
	if (minimumLen == 0
			|| minimumLen >= MAX_PASSWORD_LENGTH
			|| ((numSpecial + numNumbers)) >= MAX_PASSWORD_LENGTH)
		return 0;

	int len = 0;
	do {
		len = Common_rand() % (MAX_PASSWORD_LENGTH - minimumLen) + minimumLen;
	} while (len < (numSpecial + numNumbers));

	return len;
}

static char getNumber() {
	int inxWord = Common_rand() % sizeOfNumbers;

	return tblNumbers[inxWord];
}

static char getSpecialChar() {
	int inxWord = Common_rand() % sizeOfSpecials;

	return tblSpecials[inxWord];
}

static char getAlphabet() {
	int inxWord = Common_rand() % sizeOfAlphabet;
	return tblAlaphet[inxWord];
}

void passwordGenerator_run() {

	promptAndInputFromConsole();

	int length = getPasswordLength(minimumLen);
	if (length != 0) {
		numAlphbets = length - numSpecial - numNumbers;

		int count = 0;
		while (count < length) {
			Char_Type charType = decideCharType();

			if (charType == Number && numNumbers != 0) {
				numNumbers--;
				password[count++] = getNumber();
			} else if (charType == Special && numSpecial != 0) {
				numSpecial--;
				password[count++] = getSpecialChar();
			} else if (charType == Alphet && numAlphbets != 0) {
				numAlphbets--;
				password[count++] = getAlphabet();
			}
		}
		password[count] = '\0';
	}

	ConsoleIO_printf("%s\n",password);
}
