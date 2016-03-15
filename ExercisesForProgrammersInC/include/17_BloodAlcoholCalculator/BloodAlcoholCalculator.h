/*
 * BloodAlcoholCalculator.h
 *
 *  Created on: 2016¦~3¤ë15¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_17_BLOODALCOHOLCALCULATOR_BLOODALCOHOLCALCULATOR_H_
#define INCLUDE_17_BLOODALCOHOLCALCULATOR_BLOODALCOHOLCALCULATOR_H_

typedef enum { Male, Female } Gender;
typedef struct {
	double alcohol;
	double weight;
	Gender gender;
	double hours;
} BAC_INPUT;

void BloodAlcoholCalculator_create();
double BloodAlcoholCalculator_calculate(BAC_INPUT * data);
void BloodAlcoholCalculator_check(BAC_INPUT * data);

#endif /* INCLUDE_17_BLOODALCOHOLCALCULATOR_BLOODALCOHOLCALCULATOR_H_ */
