/*
 * FakeConsoleIOTest.cpp
 *
 *  Created on: 2016¦~3¤ë17¤é
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
#include "Common/Common.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(FakeConsoleIOTest)
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

TEST(FakeConsoleIOTest, setKeyInBufferTest_oneInputData)
{
	char inData1[] = "123\n";
	char expect[] = "123";
	char outputBuff[80] = "";

	FakeConsoleIO_setKeyInBuffer(inData1);
	Common_getStringFromConsole(outputBuff);
	STRCMP_EQUAL(expect, outputBuff);
}

TEST(FakeConsoleIOTest, setKeyInBufferTest_twoInputData)
{
	char inData1[] = "123\n";
	char inData2[] = "456\n";
	char expect1[] = "123";
	char expect2[] = "456";
	char outputBuff[80] = "";

	FakeConsoleIO_setKeyInBuffer(inData1);
	FakeConsoleIO_setKeyInBuffer(inData2);
	Common_getStringFromConsole(outputBuff);
	STRCMP_EQUAL(expect1, outputBuff);
	Common_getStringFromConsole(outputBuff);
	STRCMP_EQUAL(expect2, outputBuff);
}
