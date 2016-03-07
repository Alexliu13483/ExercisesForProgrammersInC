/*
 * CommonTest.cpp
 *
 *  Created on: 2016¦~1¤ë28¤é
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
#include <stdio.h>
#include <stdlib.h>
#include "Common/Common.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CommonTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    }

    void teardown()
    {

    }

};

TEST(CommonTest, testIsIntegerString_Normal)
{
	char str[] = "0123456789";

	CHECK_TRUE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsIntegerString_Abnormal)
{
	char str[] = "0ABC";

	CHECK_FALSE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsIntegerString_Negative)
{
	char str[] = "-1";

	CHECK_TRUE(Common_isIntegerString(str));
	//printf("%d\n", atoi(str));
}

TEST(CommonTest, testIsIntegerString_Positive)
{
	char str[] = "+1";

	CHECK_TRUE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsDoubleString_Normal)
{
	char str[] = "123.258";

	CHECK_TRUE(Common_isDoubleString(str));
}

TEST(CommonTest, testIsDoubleString_Alphabet)
{
	char str[] = "123Dot258";

	CHECK_FALSE(Common_isDoubleString(str));
}

TEST(CommonTest, testIsDoubleString_TwoDots)
{
	char str[] = "123..258";

	CHECK_FALSE(Common_isDoubleString(str));
}

TEST(CommonTest, testGetStringFromConsoleWithNewline)
{
	char inputChars[] = "Mary\n";
	char expect[] = "Mary";
	char outputBuff[80] = "";

	FakeConsoleIO_setKeyInBuffer(inputChars);
	Common_getStringFromConsole(outputBuff);
	STRCMP_EQUAL(expect, outputBuff);
}

TEST(CommonTest, testGetStringFromConsoleWithCarriageReturn)
{
	char inputChars[] = "Mary\r";
	char expect[] = "Mary";
	char outputBuff[80] = "";

	FakeConsoleIO_setKeyInBuffer(inputChars);
	Common_getStringFromConsole(outputBuff);
	STRCMP_EQUAL(expect, outputBuff);
	STRCMP_EQUAL(inputChars, FakeConsoleIO_getOutputString());
}

TEST(CommonTest, testGetStringFromConsoleWithCarriageReturnButNoEcho)
{
	char inputChars[] = "Mary\r";
	char expect[] = "Mary";
	char outputBuff[80] = "";

	FakeConsoleIO_setKeyInBuffer(inputChars);
	Common_getStringFromConsoleAndNoEcho(outputBuff);
	STRCMP_EQUAL(expect, outputBuff);
	STRCMP_EQUAL("****\n", FakeConsoleIO_getOutputString());
}
