/*
 * ComparingNumbers.c
 *
 *  Created on: 2016¦~3¤ë30¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

enum {MAX_NUMBERS = 10};
static int numbers[MAX_NUMBERS];
static char * promptOrderString[MAX_NUMBERS] = {
		"first", "second", "third", "fourth", "fifth",
		"sixth", "seventh", "eighth", "ninth", "tenth"
};

void ComparingNumbers_create() {
	for (int i = 0; i < MAX_NUMBERS; i++)
		numbers[i] = INT_MIN;
}

static bool isNumberExisted(int index) {
	for (int i = 0; i < MAX_NUMBERS; i++)
			if (index != i && numbers[i] == numbers[index] )
				return true;
	return false;
}

static int checkDuplicatedAndGetNumber(int index) {
	char buff[80] = "";

	while (isNumberExisted(index)) {
		ConsoleIO_printf("%d has been existed. Please enter the number again : ", numbers[index]);
		Common_getStringFromConsole(buff);
		numbers[index] = atoi(buff);
	}
	return numbers[index];
}

static int getInputNumber(int index) {
	char buff[80] = "";

	ConsoleIO_printf("Enter the %s number: ", promptOrderString[index]);
	Common_getStringFromConsole(buff);
	numbers[index] = atoi(buff);
	return checkDuplicatedAndGetNumber(index);

}

static int findMaximumVal() {
	int maximum = INT_MIN;

	for (int i = 0; i < MAX_NUMBERS; i++) {
		if (numbers[i] >= maximum)
			maximum = numbers[i];
	}

	return maximum;
}

void ComparingNumbers_run() {

	for (int i = 0; i < MAX_NUMBERS; i++) {
		numbers[i] = getInputNumber(i);
	}

	ConsoleIO_printf("The largest number is %d.\n", findMaximumVal());
}
