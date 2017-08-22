/*
 * Magic8BallTest.cpp
 *
 *  Created on: 2016¦~9¤ë1¤é
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
#include "FakeRandomNumber.h"
#include "33_Magic8Ball/Magic8Ball.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Magic8BallTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FakeRandomNumber_create();
    	Magic8Ball_create();
    }

    void teardown()
    {

    }

};

TEST(Magic8BallTest, Test_AskAgain)
{
	char expect[] =
			"What's your question? Will I be rich and famous?\n"
			"Ask again later.\n";

	char input[] = "Will I be rich and famous?\n";

	FakeRandomNumber_SetFirstAndIncrement(3, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	Magic8Ball_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(Magic8BallTest, Test_Yes)
{
	char expect[] =
			"What's your question? Will I be rich and famous?\n"
			"Yes.\n";

	char input[] = "Will I be rich and famous?\n";

	FakeRandomNumber_SetFirstAndIncrement(0, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	Magic8Ball_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(Magic8BallTest, Test_No)
{
	char expect[] =
			"What's your question? Will I be rich and famous?\n"
			"No.\n";

	char input[] = "Will I be rich and famous?\n";

	FakeRandomNumber_SetFirstAndIncrement(1, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	Magic8Ball_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(Magic8BallTest, Test_Maybe)
{
	char expect[] =
			"What's your question? Will I be rich and famous?\n"
			"Maybe.\n";

	char input[] = "Will I be rich and famous?\n";

	FakeRandomNumber_SetFirstAndIncrement(2, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	Magic8Ball_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
