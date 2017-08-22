/*
 * TaxCalculatorTest.cpp
 *
 *  Created on: 2016¦~2¤ë24¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 *  DOUBLES_EQUAL(expected,actual,threshold);
 */



extern "C"
{
#include "14_TaxCalculator/TaxCalculator.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TaxCalculatorTest)
{

    void setup()
    {
    	TaxCalculator_create();
    }

    void teardown()
    {

    }

};

TEST(TaxCalculatorTest, testWI)
{
	char expect[] = "The subtotal is $10.00.\nThe tax is $0.55.\nThe total is $10.55.\n";
	char state[] = "WI";

	STRCMP_EQUAL(expect, TaxCalculator_calculateTax(10.0, state));
}

TEST(TaxCalculatorTest, testMN)
{
	char expect[] = "The total is $10.00\n";
	char state[] = "MN";

	STRCMP_EQUAL(expect, TaxCalculator_calculateTax(10.0, state));
}

TEST(TaxCalculatorTest, testAmount20inWI)
{
	char expect[] = "The subtotal is $20.00.\nThe tax is $1.10.\nThe total is $21.10.\n";
	char state[] = "WI";

	STRCMP_EQUAL(expect, TaxCalculator_calculateTax(20.0, state));
}
