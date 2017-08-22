/*
 * anagramCheckerTest.cpp
 *
 *  Created on: 2016年7月6日
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
#include "24_AnagramChecker/anagramChecker.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(anagramCheckerTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	anagramChecker_create();
    }

    void teardown()
    {

    }

};

TEST(anagramCheckerTest, FirstAnagramTest)
{
	char expect[] = "Enter two strings and I\'ll tell you if they are anagrams:\n"
 					"Enter the first string: note\n"
					"Enter the second string: tone\n"
					"\"note\" and \"tone\" are anagrams.\n";

	char input[] = "note\ntone\n";

	FakeConsoleIO_setKeyInBuffer(input);
	anagramChecker_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(anagramCheckerTest, SecondAnagramTest)
{
	char expect[] = "Enter two strings and I\'ll tell you if they are anagrams:\n"
 					"Enter the first string: tea\n"
					"Enter the second string: ate\n"
					"\"tea\" and \"ate\" are anagrams.\n";

	char input[] = "tea\nate\n";

	FakeConsoleIO_setKeyInBuffer(input);
	anagramChecker_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(anagramCheckerTest, NonAnagramTest)
{
	char expect[] = "Enter two strings and I\'ll tell you if they are anagrams:\n"
 					"Enter the first string: good\n"
					"Enter the second string: book\n"
					"\"good\" and \"book\" are not anagrams.\n";

	char input[] = "good\nbook\n";

	FakeConsoleIO_setKeyInBuffer(input);
	anagramChecker_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

/* These tests are testing the static function in the module.
IGNORE_TEST(anagramCheckerTest, sortString1Test)
{
	char expect[] = "TEA";
	char input[] = "tea";
	char result[80];


	sortString(input, result);
	STRCMP_EQUAL(expect, result);
}

IGNORE_TEST(anagramCheckerTest, sortString2Test)
{
	char expect[] = "TEA";
	char input[] = "ate";
	char result[80];


	sortString(input, result);
	STRCMP_EQUAL(expect, result);
}
*/
