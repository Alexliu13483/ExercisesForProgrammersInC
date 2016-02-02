/*
 * RetirementCalculatorTest.cpp
 *
 *  Created on: 2016¦~1¤ë28¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 */



extern "C"
{
#include "06_RetirementCalculator/RetirementCalculator.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(RetirementCalculatorTest)
{

    void setup()
    {
    	RetirementCalculator_create();
    }

    void teardown()
    {

    }

};

TEST(RetirementCalculatorTest, testRetirement25_65)
{
	char expect[] = "You have 40 years left until you can retire.\nIt's 2016, so you can retire in 2056.";
	STRCMP_EQUAL(expect, RetirementCalculator_calculate(25, 65));
}

IGNORE_TEST(RetirementCalculatorTest, testInputFromConsole)
{
	char expect[] = "You have 40 years left until you can retire.\nIt's 2016, so you can retire in 2056.";
	RetirementCalculator_calculateInputFromConsole();
	STRCMP_EQUAL(expect, RetirementCalculator_getOutputString());
}
