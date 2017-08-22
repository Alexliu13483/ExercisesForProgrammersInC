/*
 * NumbersToNamesTest.cpp
 *
 *  Created on: 2016¦~3¤ë24¤é
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
#include "21_NumbersToNames/NumbersToNames.h"
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(NumbersToNamesTest)
{
	const char * expect[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

    void setup()
    {
    	NumbersToNames_create();
    }

    void teardown()
    {

    }

};

TEST(NumbersToNamesTest, convertNumToMonth)
{
	for (int i = 0; i < 12; i++)
		STRCMP_EQUAL(expect[i], NumbersToNames_convertNumberToMonth(i+1));
}

