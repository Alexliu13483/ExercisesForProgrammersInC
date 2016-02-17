/*
 * SelfCheckout.c
 *
 *  Created on: 2016¦~2¤ë16¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Common/Common.h"
#include "10_SelfCheckout/SelfCheckout.h"

#define TAX_RATE	0.055
#define ESCAPE_CHAR	'\0'

CheckoutResults accumulatedResults;

void SelfCheckout_create() {
	accumulatedResults.subtotal = 0;
	accumulatedResults.tax = 0;
	accumulatedResults.total = 0;
}

void SelfCheckout_accumulateEachItem(float price, int quantity) {
	accumulatedResults.subtotal += price * quantity;
}

CheckoutResults * SelfCheckout_getAccumulatedResults() {
	accumulatedResults.tax = accumulatedResults.subtotal * TAX_RATE;
	accumulatedResults.total = accumulatedResults.subtotal + accumulatedResults.tax;

	return &accumulatedResults;
}

char * SelfCheckout_getTextOutput(CheckoutResults * resultsData) {
	static char outputString[80];

	sprintf(outputString, "Subtotal: $%0.2f\nTax: $%0.2f\nTotal: $%0.2f", resultsData->subtotal, resultsData->tax, resultsData->total);
	return outputString;
}

CheckoutResults * SelfCheckout_accumulateItemsByConcole() {
	char priceStr[20];
	char quantityStr[20];
	float price;
	int quantity;

	printf("\n");
	for (int i = 1; ;i++) {
		do {
			printf("Enter the price of item %d: ", i);
			Common_getStringFromConsole(priceStr);
		} while (!Common_isDoubleString(priceStr) && priceStr[0] != ESCAPE_CHAR);

		if (priceStr[0] == ESCAPE_CHAR) {
			printf("\n");
			break;
		} else
			price = atof(priceStr);

		do {
			printf("Enter the quantity of item %d: ", i);
			Common_getStringFromConsole(quantityStr);
		} while (!Common_isIntegerString(quantityStr));
		quantity = atoi(quantityStr);

		SelfCheckout_accumulateEachItem(price, quantity);
	}

	return SelfCheckout_getAccumulatedResults();
}
