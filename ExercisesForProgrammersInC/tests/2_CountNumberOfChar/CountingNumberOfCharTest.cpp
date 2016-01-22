/*
 * CountingNumberOfCharTest.cpp
 *
 *  Created on: 2016¦~1¤ë22¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 */



extern "C"
{
#include "2_CountNumberOfChar/CountingNumberOfChar.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CountNumberCharTest)
{

    void setup()
    {
    	CountNumberOfChar_create();
    }

    void teardown()
    {
    	CountNumberOfChar_destroy();
    }

};

TEST(CountNumberCharTest, testStringHomer)
{
	char str[] = "Homer";

	CountNumberOfChar_setInputString(str);

	STRCMP_EQUAL("Homer has 5 characters.", CountNumberOfChar_outputString());
}

TEST(CountNumberCharTest, testStringProgramming)
{
	char str[] = "Programming";

	CountNumberOfChar_setInputString(str);

	STRCMP_EQUAL("Programming has 11 characters.", CountNumberOfChar_outputString());
}

IGNORE_TEST(CountNumberCharTest, testInputByConsole)
{
	CountNumberOfChar_inputByConsole();

	STRCMP_EQUAL("Smart has 5 characters.", CountNumberOfChar_outputString());
}
