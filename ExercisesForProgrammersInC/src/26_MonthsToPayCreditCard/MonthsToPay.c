/*
 * MonthsToPay.c
 *
 *  Created on: 2016¦~4¤ë28¤é
 *      Author: Alex.Liu
 */

#include "Common/ConsoleIO.h"
#include "Common/Common.h"
#include <stdlib.h>
#include <math.h>

void MonthsToPay_create() {

}

static int calculateMonthsUntilPayOff(float balance, float apr, float monthlyPayment) {
	float i = apr / 100.0 / 365.0;
	return ceil(-(1.0/30.0) * log(1.0 + balance * (1.0 - pow(1.0 + i, 30.0)) / monthlyPayment) / log(1.0 + i));
}

static double calculateMonthlyPayment(float balance, float apr, float months) {
	float i = apr / 100.0 / 365.0;
	return balance * (1.0 - pow(1.0 + i, 30)) / (pow(1.0 + i, -30 * months) - 1.0);
}

static double getDoubleWithPromptFromConsole(char const * promptStr) {
	char inString[80] = "";

	do {
		ConsoleIO_printf(promptStr);
		Common_getStringFromConsole(inString);
	} while (!Common_isDoubleString(inString));
	return atof(inString);
}

void MonthsToPay_runCalculateMonthlyPayment() {
	float balance = 0.0;
	float apr = 0.0;
	float monthlyPayment = 0.0;
	float months = 0;
	int m;

	balance = getDoubleWithPromptFromConsole("What is your balance? ");
	apr = getDoubleWithPromptFromConsole("What is the APR on the card (as a percent)? ");
	months = getDoubleWithPromptFromConsole("How many months do you take to pay off this card? ");

	monthlyPayment = calculateMonthlyPayment(balance, apr, months);
	m = ceil(months);
	ConsoleIO_printf("\nYou will pay %.2f dollars for %d months.\n", monthlyPayment, m);
}

void MonthsToPay_runCalculateMonthsUntilPayOff() {
	float balance = 0.0;
	float apr = 0.0;
	float monthlyPayment = 0.0;
	int months;

	balance = getDoubleWithPromptFromConsole("What is your balance? ");
	apr = getDoubleWithPromptFromConsole("What is the APR on the card (as a percent)? ");
	monthlyPayment = getDoubleWithPromptFromConsole("What is the monthly payment you can make? ");

	months = calculateMonthsUntilPayOff(balance, apr, monthlyPayment);
	ConsoleIO_printf("\nIt will take you %d months to pay off this card.\n", months);

}
