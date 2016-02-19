/*
 * CurrencyConversionTest.cpp
 *
 *  Created on: 2016¦~2¤ë19¤é
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
#include "11_CurrencyConversion/CurrencyConversion.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CurrencyConversionTest)
{

    void setup()
    {
    	CurrencyConversion_create();
    }

    void teardown()
    {

    }

};

TEST(CurrencyConversionTest, ZeroDollar)
{
	DOUBLES_EQUAL(0, CurrencyConversion_convert(0, 0), 0.001);
}

TEST(CurrencyConversionTest, Test81Dollars)
{
	DOUBLES_EQUAL(111.38, CurrencyConversion_convert(81.0, 137.51), 0.001);
}

