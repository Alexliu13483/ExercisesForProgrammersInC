/*
 * BloodAlcoholCalculatorTest.cpp
 *
 *  Created on: 2016¦~3¤ë15¤é
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
#include "17_BloodAlcoholCalculator/BloodAlcoholCalculator.h"
#include "FakeConsoleIO.h"

}

#include "CppUTest/TestHarness.h"

TEST_GROUP(BloodAlcoholCalculatorTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	BloodAlcoholCalculator_create();
    }

    void teardown()
    {

    }

};

TEST(BloodAlcoholCalculatorTest, BAC_calculationMaleTest)
{
	BAC_INPUT inputData;

	inputData.alcohol = 10.0;
	inputData.weight = 120.0;
	inputData.gender = Male;
	inputData.hours = 2.0;
	double result = 0;

	result = BloodAlcoholCalculator_calculate(&inputData);
	DOUBLES_EQUAL(0.283, result, 0.0005);
}

TEST(BloodAlcoholCalculatorTest, BAC_calculationFemaleTest)
{
	BAC_INPUT inputData;

	inputData.alcohol = 10.0;
	inputData.weight = 120.0;
	inputData.gender = Female;
	inputData.hours = 2.0;
	double result = 0;

	result = BloodAlcoholCalculator_calculate(&inputData);
	DOUBLES_EQUAL(0.253, result, 0.0005);
}

TEST(BloodAlcoholCalculatorTest, BAC_checkNotLegalTest)
{
	BAC_INPUT inputData;
	char expectOutputStr[] = "Your BAC is 0.253\nIt is not legal for you to drive.";

	inputData.alcohol = 10.0;
	inputData.weight = 120.0;
	inputData.gender = Female;
	inputData.hours = 2.0;

	BloodAlcoholCalculator_check(&inputData);
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(BloodAlcoholCalculatorTest, BAC_checkLegalTest)
{
	BAC_INPUT inputData;
	char expectOutputStr[] = "Your BAC is 0.033";

	inputData.alcohol = 2.0;
	inputData.weight = 120.0;
	inputData.gender = Male;
	inputData.hours = 2.0;

	BloodAlcoholCalculator_check(&inputData);
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}
