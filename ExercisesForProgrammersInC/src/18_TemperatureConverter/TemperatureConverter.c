/*
 * TemperatureConverter.c
 *
 *  Created on: 2016¦~3¤ë17¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include <stdbool.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

void TemperatureConverter_create() {

}

static bool readDoubleNumberFromConsole(char * buffer, double *result) {
	Common_getStringFromConsole(buffer);
	if (!Common_isDoubleString(buffer))
		return false;
	*result = atof(buffer);
	return true;
}

void TemperatureConverter_run() {
	char selConvertMode;
	char inputBuffer[80];
	double result;
	double inTemp;

	ConsoleIO_printf("Press C to convert from Fahrenheit to Celsius.\n"
				"Press F to convert from Celsius to Fahrenheit.\nYour choice: ");
	selConvertMode = ConsoleIO_getchar();
	if (selConvertMode == 'C') {
		ConsoleIO_printf("\n\nPlease enter the temperature in Fahrenheit: ");
		if (!readDoubleNumberFromConsole(inputBuffer, &inTemp))
			return;

		result = (inTemp - 32.0) * 5.0 / 9.0;
		ConsoleIO_printf("The temperature in Celsius is %.0f.\n", result);
	} else if (selConvertMode == 'F') {
		ConsoleIO_printf("\n\nPlease enter the temperature in Celsius: ");
		if (!readDoubleNumberFromConsole(inputBuffer, &inTemp))
			return;

		result = inTemp * 9.0 / 5.0 + 32.0;
		ConsoleIO_printf("The temperature in Fahrenheit is %.0f.\n", result);
	}

}

