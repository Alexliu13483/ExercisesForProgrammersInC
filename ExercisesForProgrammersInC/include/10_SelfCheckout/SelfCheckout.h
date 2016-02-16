/*
 * SelfCheckout.h
 *
 *  Created on: 2016¦~2¤ë16¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_10_SELFCHECKOUT_SELFCHECKOUT_H_
#define INCLUDE_10_SELFCHECKOUT_SELFCHECKOUT_H_

typedef struct {
	float price;
	int quantity;
} CheckoutInputData;

typedef struct {
	float subtotal;
	float tax;
	float total;
} CheckoutResults;


void SelfCheckout_create();
CheckoutResults * SelfCheckout_calculate(CheckoutInputData inputData[], int items);
char * SelfCheckout_calculateAndTextOutput(CheckoutInputData inputData[], int items);
void SelfCheckout_inputItems(CheckoutInputData inputData[], int items);

#endif /* INCLUDE_10_SELFCHECKOUT_SELFCHECKOUT_H_ */
