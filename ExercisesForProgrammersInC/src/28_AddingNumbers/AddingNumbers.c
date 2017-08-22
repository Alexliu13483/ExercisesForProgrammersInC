/*
 * AddingNumbers.c
 *
 *  Created on: 2016¦~7¤ë20¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include "Common\ConsoleIO.h"
#include "Common\Common.h"

void AddingNumbers_create() {

}

void AddingNumber_run() {
	char input[80];
	int sum = 0;
	int count = 5;

	while (count > 0) {
		ConsoleIO_printf("Enter a number: ");
		Common_getStringFromConsole(input);
		if (Common_isIntegerString(input)) {
			sum += atoi(input);
			count--;
		}
	}
	ConsoleIO_printf("The total is %d.\n", sum);
}
