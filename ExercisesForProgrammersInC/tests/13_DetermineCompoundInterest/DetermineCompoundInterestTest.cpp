/*
 * DetermineCompoundInterestTest.cpp
 *
 *  Created on: 2016¦~2¤ë23¤é
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
#include "12_ComputingSimpleInterest/ComputingInterest.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CompoundInterestTest)
{

    void setup()
    {
    	ComputingInterest_create();
    }

    void teardown()
    {

    }

};

TEST(CompoundInterestTest, CompountCaseTest)
{
	DOUBLES_EQUAL(1938.84, ComputingInterest_calculateCompoundInterest(1500, 4.3, 6, 4), 0.001);
}

TEST(CompoundInterestTest, ZeroNumberOfTimeTest)
{
	DOUBLES_EQUAL(1500.0, ComputingInterest_calculateCompoundInterest(1500, 4.3, 6, 0), 0.001);
}
