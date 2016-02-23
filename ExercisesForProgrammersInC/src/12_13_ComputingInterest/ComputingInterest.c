/*
 * ComputingInterest.c
 *
 *  Created on: 2016¦~2¤ë23¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Common/Common.h"

static char outputStr[128];

void ComputingInterest_create() {
	outputStr[0] = '\0';
}

double ComputingInterest_calculateSimpleInterest(double principal, double interestRate, int time) {
	return round(principal * (1 + (interestRate/100.0) * time) * 100.0) / 100.0;
}

char * ComputingInterest_calInterestWithConsoleInput() {
	char principalStr[20];
	char interestStr[20];
	char timeStr[20];
	double principal;
	double interestRate;
	int years;
	double result;

	printf("\n");
	do {
		printf("Enter the principal: ");
		Common_getStringFromConsole(principalStr);
	} while (!Common_isDoubleString(principalStr));
	principal = atof(principalStr);

	do {
		printf("Enter the rate of interest: ");
		Common_getStringFromConsole(interestStr);
	} while (!Common_isDoubleString(interestStr));
	interestRate = atof(interestStr);

	do {
		printf("Enter the number of years: ");
		Common_getStringFromConsole(timeStr);
	} while (!Common_isIntegerString(timeStr));
	years = atoi(timeStr);

	result = ComputingInterest_calculateSimpleInterest(principal, interestRate, years);
	sprintf(outputStr, "After %d years at %.1f\%, the investment will be worth $%.0f.\n", years, interestRate, result);
	puts(outputStr);
	return outputStr;
}
