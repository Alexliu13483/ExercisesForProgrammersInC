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
#include <stdio.h>
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

TEST_GROUP(FilteringValuesFromFileTest)
{
    void setup()
    {
     	FilteringValues_create();
    }

    void teardown()
    {

    }

};

TEST(FilteringValuesFromFileTest, filteringValueInFile)
{
	char inputFileName[] = "TestData/filteringValue_Data.txt";
	char outputFileName[] = "TestData/filteringValue_Data_out.txt";
	char expect[] = "2 4 6 8\n"
					"102 104 106 108\n"
					"302 314 356 358\n";
	char result[100];

	FilteringValues_filterFile(inputFileName, outputFileName);
	FILE * f = fopen(outputFileName, "r");
	int count = 0;
	if (f != NULL) {
		count = fread(result, sizeof(char), 100, f);
		fclose(f);
	}
	result[count] = '\0';
	STRCMP_EQUAL(expect, result);
}

