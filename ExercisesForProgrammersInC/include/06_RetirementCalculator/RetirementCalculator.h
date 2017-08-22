/*
 * RetirementCalculator.h
 *
 *  Created on: 2016¦~1¤ë28¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_06_RETIREMENTCALCULATOR_RETIREMENTCALCULATOR_H_
#define INCLUDE_06_RETIREMENTCALCULATOR_RETIREMENTCALCULATOR_H_

void RetirementCalculator_create();
char * RetirementCalculator_calculate(int currentAge, int retireAge);
char * RetirementCalculator_getOutputString();
void RetirementCalculator_calculateInputFromConsole();

#endif /* INCLUDE_06_RETIREMENTCALCULATOR_RETIREMENTCALCULATOR_H_ */
