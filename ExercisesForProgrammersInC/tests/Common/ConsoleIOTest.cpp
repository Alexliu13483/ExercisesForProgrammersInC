/*
 * ConsoleIOTest.cpp
 *
 *  Created on: 2016¦~3¤ë4¤é
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
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testFakeConsoleIO)
{

    void setup()
    {
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    }

    void teardown()
    {

    }

};

TEST(testFakeConsoleIO, fakePrintfTest)
{
	char expect[] = "Hello World!";
	ConsoleIO_printf("%s", expect);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
