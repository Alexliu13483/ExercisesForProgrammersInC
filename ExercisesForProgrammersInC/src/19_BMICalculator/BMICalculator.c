/*
 * BMICalculator.c
 *
 *  Created on: 2016¦~3¤ë18¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include "Common\ConsoleIO.h"
#include "Common\Common.h"

void BMICalculator_create() {

}

void BMICalculator_run() {
	char inBuff[80];
	double weight;
	double height;
	double bmiValue;

	ConsoleIO_printf("Enter your weight (Kg): ");
	Common_getStringFromConsole(inBuff);
	weight = atof(inBuff);
	ConsoleIO_printf("Enter your height (cm): ");
	Common_getStringFromConsole(inBuff);
	height = atof(inBuff) / 100.0;

	bmiValue = weight / (height * height);
	ConsoleIO_printf("Your BMI is %.1f.\n", bmiValue);
	if (bmiValue >= 25)
		ConsoleIO_printf("You are overweight. You should see your doctor.\n");
	else if (bmiValue > 18.5)
		ConsoleIO_printf("You are within the ideal weight range.\n");
	else
		ConsoleIO_printf("You are underweight. You should see your doctor.\n");
}
