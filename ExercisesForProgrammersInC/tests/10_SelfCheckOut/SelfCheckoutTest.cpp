/*
 * SelfCheckoutTest.cpp
 *
 *  Created on: 2016¦~2¤ë16¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 * 	DOUBLES_EQUAL(expected,actual,threshold);
 */



extern "C"
{
#include <stdio.h>
#include "10_SelfCheckout/SelfCheckout.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(SelfCheckoutTest)
{

    void setup()
    {
    	SelfCheckout_create();
    }

    void teardown()
    {

    }

};

TEST(SelfCheckoutTest, CheckoutProcessTest)
{
	CheckoutInputData inputData[3];
	CheckoutResults * resultsData;

	inputData[0].price = 25;
	inputData[0].quantity = 2;
	inputData[1].price = 10;
	inputData[1].quantity = 1;
	inputData[2].price = 4;
	inputData[2].quantity = 1;

	resultsData = SelfCheckout_calculate(inputData, 3);
	DOUBLES_EQUAL(64.0, resultsData->subtotal, 0.001);
	DOUBLES_EQUAL(3.52, resultsData->tax, 0.001);
	DOUBLES_EQUAL(67.52, resultsData->total, 0.001);
}

TEST(SelfCheckoutTest, CheckoutProcessTextOutput)
{
	CheckoutInputData inputData[3];
	char expect[] = "Subtotal: $64.00\nTax: $3.52\nTotal: $67.52";

	inputData[0].price = 25;
	inputData[0].quantity = 2;
	inputData[1].price = 10;
	inputData[1].quantity = 1;
	inputData[2].price = 4;
	inputData[2].quantity = 1;

	STRCMP_EQUAL(expect, SelfCheckout_calculateAndTextOutput(inputData, 3));
}

IGNORE_TEST(SelfCheckoutTest, testInputProcess)
{
	CheckoutInputData inputData[3];
	char expect[] = "Subtotal: $64.00\nTax: $3.52\nTotal: $67.52";
	char * resultStr;

	SelfCheckout_inputItems(inputData, 3);
	resultStr = SelfCheckout_calculateAndTextOutput(inputData, 3);
	puts(resultStr);

	STRCMP_EQUAL(expect, SelfCheckout_calculateAndTextOutput(inputData, 3));
}
