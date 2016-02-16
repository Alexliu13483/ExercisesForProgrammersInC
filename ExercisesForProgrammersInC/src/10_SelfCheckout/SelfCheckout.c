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

void SelfCheckout_create() {

}

CheckoutResults * SelfCheckout_calculate(CheckoutInputData inputData[], int items) {
	static CheckoutResults results;

	results.subtotal = 0;
	for (int i = 0; i < items; i++)
		results.subtotal += inputData[i].price * inputData[i].quantity;
	results.tax = results.subtotal * TAX_RATE;
	results.total = results.subtotal + results.tax;

	return &results;
}

char * SelfCheckout_calculateAndTextOutput(CheckoutInputData inputData[], int items) {
	CheckoutResults * results;
	static char outputString[80];

	results = SelfCheckout_calculate(inputData, items);
	sprintf(outputString, "Subtotal: $%0.2f\nTax: $%0.2f\nTotal: $%0.2f", results->subtotal, results->tax, results->total);
	return outputString;
}

void SelfCheckout_inputItems(CheckoutInputData inputData[], int items) {
	char priceStr[20];
	char quantityStr[20];

	printf("\n");
	for (int i = 0; i < items; i++) {
		do {
			printf("Enter the price of item %d: ", i+1);
			Common_getStringFromConsole(priceStr);
		} while (!Common_isDoubleString(priceStr));
		inputData[i].price = atof(priceStr);

		do {
			printf("Enter the quantity of item %d: ", i+1);
			Common_getStringFromConsole(quantityStr);
		} while (!Common_isIntegerString(quantityStr));
		inputData[i].quantity = atoi(quantityStr);
	}
}
