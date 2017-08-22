/*
 * ComputingInterestTest.cpp
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

TEST_GROUP(ComputingInterestTest)
{

    void setup()
    {
    	ComputingInterest_create();
    }

    void teardown()
    {

    }

};

TEST(ComputingInterestTest, ZeroInterestTest)
{
	DOUBLES_EQUAL(100.0, ComputingInterest_calculateSimpleInterest(100.0, 0, 10), 0.01);
}

TEST(ComputingInterestTest, ZeroPrincipalTest)
{
	DOUBLES_EQUAL(0.0, ComputingInterest_calculateSimpleInterest(0, 10, 10), 0.01);
}

TEST(ComputingInterestTest, ZeroTimeTest)
{
	DOUBLES_EQUAL(100.0, ComputingInterest_calculateSimpleInterest(100, 10, 0), 0.01);
}

TEST(ComputingInterestTest, NormalTest)
{
	DOUBLES_EQUAL(1758.0, ComputingInterest_calculateSimpleInterest(1500, 4.3, 4), 0.01);
}

TEST(ComputingInterestTest, RoundTest)
{
	DOUBLES_EQUAL(1446.25, ComputingInterest_calculateSimpleInterest(1234, 4.3, 4), 0.001);
}

IGNORE_TEST(ComputingInterestTest, ConsoleInterfaceTest)
{
	char expect[] = "After 4 years at 4.3%, the investment will be worth $1758.\n";

	STRCMP_EQUAL(expect, ComputingInterest_calInterestWithConsoleInput());
}
