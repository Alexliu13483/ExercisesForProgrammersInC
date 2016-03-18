/*
 * BMICalculatorTest.cpp
 *
 *  Created on: 2016¦~3¤ë18¤é
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
#include "19_BMICalculator\BMICalculator.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(BMICalculatorTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	BMICalculator_create();
    }

    void teardown()
    {

    }

};

TEST(BMICalculatorTest, BMI_WithinStandardRange)
{
	char expect[] = "Enter your weight (Kg): 70\n"
			"Enter your height (cm): 180\n"
			"Your BMI is 21.6.\nYou are within the ideal weight range.\n";
	char input1[] = "70\n";
	char input2[] = "180\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);

	BMICalculator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(BMICalculatorTest, BMI_OverStandardRange)
{
	char expect[] = "Enter your weight (Kg): 90\n"
			"Enter your height (cm): 180\n"
			"Your BMI is 27.8.\nYou are overweight. You should see your doctor.\n";
	char input1[] = "90\n";
	char input2[] = "180\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);
	BMICalculator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

