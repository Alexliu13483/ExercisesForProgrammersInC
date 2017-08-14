/*
 * pickWinner_test.cpp
 *
 *  Created on: 2017¦~8¤ë14¤é
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
#include "35_Picking_a_Winner/pickWinner.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(pickWinner_test)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FakeRandomNumber_create();
    	pickWinner_create();
    }

    void teardown()
    {
    	pickWinner_destroy();
    }

};

TEST(pickWinner_test, entry_blank)
{
	char expect[] = "Enter a name:  \n"
					"The Winner is... None\n";
	char input[] = " \n";

	FakeConsoleIO_setKeyInBuffer(input);
	pickWinner_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(pickWinner_test, entry_return)
{
	char expect[] = "Enter a name: \n"
					"The Winner is... None\n";
	char input[] = "\n";

	FakeConsoleIO_setKeyInBuffer(input);
	pickWinner_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(pickWinner_test, only_a_winner)
{
	char expect[] = "Enter a name: Homer\n"
					"Enter a name: \n"
					"The Winner is... Homer\n";
	char input[] = "Homer\n\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_SetFirstAndIncrement(0, 0);
	pickWinner_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(pickWinner_test, pick_a_winner)
{
	char expect[] = "Enter a name: Homer\n"
					"Enter a name: Bart\n"
					"Enter a name: Maggie\n"
					"Enter a name: Lisa\n"
					"Enter a name: Moe\n"
					"Enter a name: \n"
					"The Winner is... Maggie\n";
	char input[] = "Homer\nBart\nMaggie\nLisa\nMoe\n\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_SetFirstAndIncrement(2, 0);
	pickWinner_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
