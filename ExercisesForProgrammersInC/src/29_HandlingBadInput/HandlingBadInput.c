/*
 * HandlingBadInput.c
 *
 *  Created on: 2016¦~7¤ë20¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

void HandlingBadInput_create() {

}

void HandlingBadInput_run() {
	char input[80];
	double rate = 1.0;
	int years;
	bool isValid = false;

	do {
		ConsoleIO_printf("What is the rate of return? ");
		Common_getStringFromConsole(input);
		if (Common_isDoubleString(input)) {
			rate = atof(input);
			if (rate != 0.0) {
				years = (int)ceil(72.0 / rate);
				ConsoleIO_printf("It will take %d years to double your initial investment.\n", years);
				isValid = true;
			} else
				ConsoleIO_printf("Sorry. That's not a valid input.\n");
		} else
			ConsoleIO_printf("Sorry. That's not a valid input.\n");
	} while (isValid == false);
}
