/*
 * BloodAlcoholCalculator.c
 *
 *  Created on: 2016¦~3¤ë15¤é
 *      Author: Alex.Liu
 */

#include "17_BloodAlcoholCalculator/BloodAlcoholCalculator.h"
#include "Common/ConsoleIO.h"

#define MALE_DISTRIBUTION_RATIO		0.73
#define FEMALE_DISTRIBUTION_RATIO	0.66

void BloodAlcoholCalculator_create() {

}

double BloodAlcoholCalculator_calculate(BAC_INPUT * data) {
	double distributionRatio = MALE_DISTRIBUTION_RATIO;
	if (data->gender == Female)
		distributionRatio = FEMALE_DISTRIBUTION_RATIO;
	return data->alcohol * 5.14 / data->weight * distributionRatio - 0.015 * data->hours;
}

void BloodAlcoholCalculator_check(BAC_INPUT * data) {
	double result = BloodAlcoholCalculator_calculate(data);
	if (result >= 0.08)
		ConsoleIO_printf("Your BAC is %0.3f\nIt is not legal for you to drive.", result);
	else
		ConsoleIO_printf("Your BAC is %0.3f", result);
}
