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
			"\n";
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

TEST(passwordGeneratorTest, alphetAndSpecialsTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 0\n"
			"Your password is\n"
			"abc#deAB&CD\n";
	char input[] = "8\n2\n0\n";
	int numbers[] = {	// Random number to choose password data
					3,	// length
					0, 0,	// a
					0, 1,	// b
					0, 2,	// c
					2, 2,	// #
					0, 3,	// d
					0, 4,	// e
					0, 26,	// A
					0, 27,	// B
					2, 6,	// &
					0, 28,	// C
					0, 29}; // D

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, alphetAndSpecialsAndNumbersTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#\n";
	char input[] = "8\n2\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 0,	// a
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 2,	// 2
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, tooManyAlphbetBeforeSpecialsTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#\n";
	char input[] = "8\n2\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 0,	// a
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 2,	// 2
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					0, 18,	// s
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, check_alphabet_table_boundary)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#\n";
	char input[] = "8\n2\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 52,	// a - check alphabet table boundary
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 2,	// 2
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					0, 18,	// s
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, check_number_table_boundary)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#\n";
	char input[] = "8\n2\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 52,	// a - check alphabet table boundary
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 22,	// 2 - check number table boundary
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					0, 18,	// s
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, check_special_table_boundary)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"aurn2$1s#\n";
	char input[] = "8\n2\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 52,	// a - check alphabet table boundary
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 22,	// 2 - check number table boundary
					2, 45,	// $ - check special table boundary
					1, 1,	// 1
					0, 18,	// s
					0, 18,	// s
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, minimumLengthTooLargeTest)
{
	char expect[] =
			"What's the minimum length 20\n"
			"How many special characters 2\n"
			"How many numbers 2\n"
			"Your password is\n"
			"\n";
	char input[] = "20\n2\n2\n";

	FakeConsoleIO_setKeyInBuffer(input);
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, specialCharsLengthTooLargeTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 20\n"
			"How many numbers 2\n"
			"Your password is\n"
			"\n";
	char input[] = "8\n20\n2\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					0, 0,	// a
					0, 20,	// u
					0, 17,	// r
					0, 13,	// n
					1, 2,	// 2
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					0, 18,	// s
					0, 18,	// s
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(passwordGeneratorTest, specialNumberLengthTooLargeTest)
{
	char expect[] =
			"What's the minimum length 8\n"
			"How many special characters 2\n"
			"How many numbers 8\n"
			"Your password is\n"
			"123456$1s1#\n";
	char input[] = "8\n2\n8\n";
	int numbers[] = {	// Random number to choose password data
					1,	// length
					3,	// length
					1, 1,	// 1
					1, 2,	// 2
					1, 3,	// 3
					1, 4,	// 4
					1, 5,	// 5
					1, 6,	// 6
					2, 3,	// $
					1, 1,	// 1
					0, 18,	// s
					1, 1,	// 1
					2, 2,	// #
	};

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_Multiple_SetNumbers(numbers, sizeof(numbers)/sizeof(int));
	passwordGenerator_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

