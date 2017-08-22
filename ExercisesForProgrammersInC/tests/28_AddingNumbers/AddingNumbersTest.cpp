/*
 * AddingNumbersTest.cpp
 *
 *  Created on: 2016¦~7¤ë20¤é
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
#include "28_AddingNumbers/AddingNumbers.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(AddingNumbersTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	AddingNumbers_create();
    }

    void teardown()
    {

    }

};

TEST(AddingNumbersTest, FirstTest)
{
	char expect[] =
			"Enter a number: 1\n"
			"Enter a number: 2\n"
			"Enter a number: 3\n"
			"Enter a number: 4\n"
			"Enter a number: 5\n"
			"The total is 15.\n";
	char input[] = "1\n2\n3\n4\n5\n";

	FakeConsoleIO_setKeyInBuffer(input);

	AddingNumber_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(AddingNumbersTest, SecondTest)
{
	char expect[] =
			"Enter a number: 1\n"
			"Enter a number: 2\n"
			"Enter a number: 3\n"
			"Enter a number: 4\n"
			"Enter a number: 15\n"
			"The total is 25.\n";
	char input[] = "1\n2\n3\n4\n15\n";

	FakeConsoleIO_setKeyInBuffer(input);

	AddingNumber_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(AddingNumbersTest, WrongInputTest)
{
	char expect[] =
			"Enter a number: 1A\n"
			"Enter a number: 1\n"
			"Enter a number: 2\n"
			"Enter a number: 3\n"
			"Enter a number: 4\n"
			"Enter a number: 15\n"
			"The total is 25.\n";
	char input[] = "1A\n1\n2\n3\n4\n15\n";

	FakeConsoleIO_setKeyInBuffer(input);

	AddingNumber_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
