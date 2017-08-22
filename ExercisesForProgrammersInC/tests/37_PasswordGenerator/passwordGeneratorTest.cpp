/*
 * passwordGeneratorTest.cpp
 *
 *  Created on: 2017¦~8¤ë18¤é
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
    	FakeRandomNumber_Multiple_create();
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

TEST(passwordGeneratorTest, alphetOnlyTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 0\n"
			"How many numbers 0\n"
			"Your password is\n"
			"abcdeABCD\n";
	char input[] = "8\n0\n0\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 0,
					0, 1,
					0, 2,
					0, 3,
					0, 4,	// "abcde"
					0, 26,
					0, 27,
					0, 28,
					0, 29}; // "ABCD"

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
