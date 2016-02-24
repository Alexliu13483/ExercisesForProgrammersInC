/*
 * TaxCalculator.c
 *
 *  Created on: 2016¦~2¤ë24¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char outputStr[128];
static double tax;
static double total;

void TaxCalculator_create() {
	outputStr[0] = '\0';
}

bool isTheSameState(char* state1, char *state2) {
	return !strcmp(state1, state2);
}

void calculateTotalAmount(double amount, double taxRate) {
	tax = amount * taxRate;
	total = amount + tax;
}

char * TaxCalculator_calculateTax(double amount, char * state) {

	if (isTheSameState(state, "WI")) {
		calculateTotalAmount(amount, 0.055);
		sprintf(outputStr, "The subtotal is $%.2f.\nThe tax is $%.2f.\nThe total is $%.2f.\n", amount, tax, total);
	}

	if (isTheSameState(state, "MN")) {
		calculateTotalAmount(amount, 0);
		sprintf(outputStr, "The total is $%.2f\n", total);
	}
	return outputStr;
}
