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

TEST(SelfCheckoutTest, Checkout3Items)
{
	CheckoutResults * resultsData;

	SelfCheckout_accumulateEachItem(25.0, 2);
	SelfCheckout_accumulateEachItem(10.0, 1);
	SelfCheckout_accumulateEachItem(4.0, 1);
	resultsData = SelfCheckout_getAccumulatedResults();

	DOUBLES_EQUAL(64.0, resultsData->subtotal, 0.001);
	DOUBLES_EQUAL(3.52, resultsData->tax, 0.001);
	DOUBLES_EQUAL(67.52, resultsData->total, 0.001);
}

TEST(SelfCheckoutTest, Checkout3ItemsTextOutput)
{
	CheckoutResults * resultsData;
	char expect[] = "Subtotal: $64.00\nTax: $3.52\nTotal: $67.52";

	SelfCheckout_accumulateEachItem(25.0, 2);
	SelfCheckout_accumulateEachItem(10.0, 1);
	SelfCheckout_accumulateEachItem(4.0, 1);
	resultsData = SelfCheckout_getAccumulatedResults();

	STRCMP_EQUAL(expect, SelfCheckout_getTextOutput(resultsData));
}

IGNORE_TEST(SelfCheckoutTest, CheckoutInputByConcole)
{
	CheckoutResults * resultsData;
	char expect[] = "Subtotal: $64.00\nTax: $3.52\nTotal: $67.52";
	char * resultStr;

	resultsData = SelfCheckout_accumulateItemsByConcole();
	resultStr = SelfCheckout_getTextOutput(resultsData);
	puts(resultStr);

	STRCMP_EQUAL(expect, resultStr);
}
