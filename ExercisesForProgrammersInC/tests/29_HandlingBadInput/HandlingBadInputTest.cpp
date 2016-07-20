/*
 * HandlingBadInputTest.cpp
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
#include "29_HandlingBadInput/HandlingBadInput.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(HandlingBadInputTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	HandlingBadInput_create();
    }

    void teardown()
    {

    }

};

TEST(HandlingBadInputTest, ValidInputTest1)
{
	char expect[] =
			"What is the rate of return? 4\n"
			"It will take 18 years to double your initial investment.\n";
	char input[] = "4\n";

	FakeConsoleIO_setKeyInBuffer(input);

	HandlingBadInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(HandlingBadInputTest, ValidInputTest2)
{
	char expect[] =
			"What is the rate of return? 6\n"
			"It will take 12 years to double your initial investment.\n";
	char input[] = "6\n";

	FakeConsoleIO_setKeyInBuffer(input);

	HandlingBadInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(HandlingBadInputTest, InvalidInput_0_Test)
{
	char expect[] =
			"What is the rate of return? 0\n"
			"Sorry. That's not a valid input.\n"
			"What is the rate of return? 4\n"
			"It will take 18 years to double your initial investment.\n";
	char input[] = "0\n4\n";

	FakeConsoleIO_setKeyInBuffer(input);

	HandlingBadInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(HandlingBadInputTest, InvalidInput_ABC_Test)
{
	char expect[] =
			"What is the rate of return? 0\n"
			"Sorry. That's not a valid input.\n"
			"What is the rate of return? ABC\n"
			"Sorry. That's not a valid input.\n"
			"What is the rate of return? 4\n"
			"It will take 18 years to double your initial investment.\n";
	char input[] = "0\nABC\n4\n";

	FakeConsoleIO_setKeyInBuffer(input);

	HandlingBadInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
