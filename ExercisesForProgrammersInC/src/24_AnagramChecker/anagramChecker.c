/*
 * anagramChecker.c
 *
 *  Created on: 2016¦~7¤ë6¤é
 *      Author: Alex.Liu
 */

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"

char inputSorted1[80];
char inputSorted2[80];

void anagramChecker_create() {
	memset(inputSorted1, 0, strlen(inputSorted1));
	memset(inputSorted2, 0, strlen(inputSorted2));
}

static void sortString(char * ori, char * dest) {
	int len = strlen(ori);

	for (int i = 0; i < len; i++)
		dest[i] = toupper(ori[i]);
	dest[len] = '\0';

	for (int i = 0; i < len; i++ ) {
		for (int j = i+1; j < len; j++) {
			if (dest[i] < dest[j]) {
				char tmp = dest[i];
				dest[i] = dest[j];
				dest[j] = tmp;
			}
		}
	}
}

bool anagramChecker_isAnagram(char * input1, char * input2) {
	sortString(input1, inputSorted1);
	sortString(input2, inputSorted2);
	if (!strcmp(inputSorted1, inputSorted2))
		return true;
	return false;
}

void anagramChecker_run() {
	char str1[] = "Enter two strings and I\'ll tell you if they are anagrams:\n"
 					"Enter the first string: ";
	char str2[] = 	"Enter the second string: ";
	char input1[80];
	char input2[80];
	char * result;
	char strNot[] = "not ";

	ConsoleIO_printf(str1);
	Common_getStringFromConsole(input1);
	ConsoleIO_printf(str2);
	Common_getStringFromConsole(input2);
	if (anagramChecker_isAnagram(input1, input2))
		result = "";
	else
		result = strNot;
	ConsoleIO_printf("\"%s\" and \"%s\" are %sanagrams.\n", input1, input2, result);
}
