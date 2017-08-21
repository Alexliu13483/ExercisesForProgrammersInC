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

#define MAX_PASSWORD_LENGTH		20
const char tblAlphets[] = "abcdefghijklmnopqrstuvwxyz";
const char tblSpecials[] = "!@#$%^&*()_+=-[]{}/.,";
const char tblNumbers[] = "0123456789";

typedef enum {
	Alphet = 0,
	Number,
	Special,
	NUMBER_OF_TYPE
} Char_Type;

void passwordGenerator_create() {
	srand(time(NULL));
}

static Char_Type decideCharType() {
	return (Char_Type)(Common_rand() % NUMBER_OF_TYPE);
}

void passwordGenerator_run() {
	char promptStr1[] = "What's the minimum length ";
	char promptStr2[] =	"How many special characters ";
	char promptStr3[] =	"How many numbers ";
	char promptStr4[] =	"Your password is\n";
	char inString[100];
	int minimumLen = 0;
	int numSpecial = 0;
	int numNumbers = 0;
	char password[MAX_PASSWORD_LENGTH + 1] = "\0";


	ConsoleIO_printf("%s",promptStr1);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		minimumLen = atoi(inString);
	}

	ConsoleIO_printf("%s",promptStr2);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		numSpecial = atoi(inString);
	}

	ConsoleIO_printf("%s",promptStr3);
	Common_getStringFromConsole(inString);
	if (Common_isIntegerString(inString)) {
		numNumbers = atoi(inString);
	}

	ConsoleIO_printf("%s",promptStr4);

	if (minimumLen == 0)
		strcpy(password, "0");
	else {
		int length = Common_rand() % (MAX_PASSWORD_LENGTH - minimumLen) + minimumLen;
		int count = 0;
		while (count < length) {
			Char_Type charType = decideCharType();

			if (charType == Number && numNumbers != 0) {
				numNumbers--;
				count++;

			} else if (charType == Special && numSpecial != 0) {
				numSpecial--;
				count++;

			} else if (charType == Alphet) {
				int tblSize = strlen(tblAlphets);
				int inxWord = Common_rand() % (tblSize * 2);
				char word;
				if (inxWord >= tblSize)
					word = toupper(tblAlphets[inxWord - tblSize]);
				else
					word = tblAlphets[inxWord];
				password[count++] = word;
			}
		}
		password[count] = '\0';
	}

	ConsoleIO_printf("%s\n",password);
}
