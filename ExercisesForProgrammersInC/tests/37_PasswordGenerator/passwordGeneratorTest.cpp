/*
 * passwordGeneratorTest.cpp
 *
 *  Created on: 2017�~8��18��
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
#include "37_PasswordGenerator/passwordGenerator.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(passwordGeneratorTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FakeRandomNumber_create();
    	passwordGenerator_create();
    }

    void teardown()
    {

    }

};

TEST(passwordGeneratorTest, zeroLength)
{
	char expect[] =
			"What's the minimum length 0\n"
			"How many special characters 0\n"
			"How many numbers 0\n"
			"Your password is\n"
			"0\n";
	char input[] = "0\n0\n0\n";

	FakeConsoleIO_setKeyInBuffer(input);
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

IGNORE_TEST(passwordGeneratorTest, normalTest1)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#";
	char input[] = "0\n0\n0\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_SetFirstAndIncrement(9, 0);
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
