/*
 * ConsoleIOTest.cpp
 *
 *  Created on: 2016�~3��4��
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
#include <stdio.h>
#include <string.h>
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testFakeConsoleIO)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
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

TEST(testFakeConsoleIO, fakeGetcharTest)
{
	char expect[] = "TDD";
	int expectLength = strlen(expect);

	FakeConsoleIO_setKeyInBuffer(expect);
	for (int i = 0; i < expectLength; i++)
		ConsoleIO_getchar();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(testFakeConsoleIO, fakePromptStringAndGetcharTest)
{
	char expect[] = "User name: Mary\n";
	char promptStr[] = "User name: ";
	char keyInName[] = "Mary\n";
	int keyInNameLength = strlen(keyInName);
	ConsoleIO_printf(promptStr);
	FakeConsoleIO_setKeyInBuffer(keyInName);
	for (int i = 0; i < keyInNameLength; i++)
		ConsoleIO_getchar();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}


