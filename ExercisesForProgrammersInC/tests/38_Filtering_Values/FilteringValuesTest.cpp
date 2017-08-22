/*
 * FilteringValuesTest.cpp
 *
 *  Created on: 2017¦~8¤ë22¤é
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
#include "FakeConsoleIO.h"
#include "38_Filtering_Values/FilteringValues.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(FilteringValuesTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FilteringValues_create();
    }

    void teardown()
    {

    }

};

TEST(FilteringValuesTest, emptyInput)
{
	char expect[] = "Enter a list of numbers, separated by spaces:\n"
					"\n"
					"There is no even number.\n";
	char input[] = "\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FilteringValues_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(FilteringValuesTest, oneOddInput)
{
	char expect[] = "Enter a list of numbers, separated by spaces:\n"
					"1\n"
					"There is no even number.\n";
	char input[] = "1\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FilteringValues_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(FilteringValuesTest, oneEvenInput)
{
	char expect[] = "Enter a list of numbers, separated by spaces:\n"
					"2\n"
					"The even numbers are 2.\n";
	char input[] = "2\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FilteringValues_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(FilteringValuesTest, oneSequenceNumbersInput)
{
	char expect[] = "Enter a list of numbers, separated by spaces:\n"
					"1 2 3 4 5 6 7 8\n"
					"The even numbers are 2 4 6 8.\n";
	char input[] = "1 2 3 4 5 6 7 8\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FilteringValues_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
