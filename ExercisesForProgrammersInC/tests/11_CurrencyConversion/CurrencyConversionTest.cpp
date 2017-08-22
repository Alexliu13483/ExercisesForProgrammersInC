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
	DOUBLES_EQUAL(0, CurrencyConversion_convertToUS_Dollars(0, US), 0.001);
}

TEST(CurrencyConversionTest, Test81Dollars)
{
	DOUBLES_EQUAL(81.0, CurrencyConversion_convertToUS_Dollars(81.0, US), 0.001);
}

TEST(CurrencyConversionTest, TestUpdateConversionRate)
{
	CountryCode countryCode = EU;
	double rate = 137.51;

	CurrencyConversion_updateConversionRate(countryCode, rate);
	DOUBLES_EQUAL(137.51, CurrencyConversion_getConversionRate(countryCode), 0.001);
}

TEST(CurrencyConversionTest, TestUpdateCurrencyRateByCountries)
{
	CountryCode countryCode = EU;
	double rate = 137.51;

	CurrencyConversion_updateConversionRate(countryCode, rate);
	DOUBLES_EQUAL(1.38, CurrencyConversion_convertToUS_Dollars(1, countryCode), 0.001);
}
