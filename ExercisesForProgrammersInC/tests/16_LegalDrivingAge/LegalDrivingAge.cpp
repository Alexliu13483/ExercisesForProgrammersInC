/*
 * LegalDrivingAge.cpp
 *
 *  Created on: 2016¦~3¤ë14¤é
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
#include "16_LegalDrivingAge/LegalDrivingAge.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LegalDrivingAgeTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	LegalDrivingAge_create();
    }

    void teardown()
    {

    }

};

TEST(LegalDrivingAgeTest, Age15test)
{
	char inputChars[] = "15\n";
	char expectOutputStr[] = "What is your age? 15\nYou are not old enough to legally drive.";
	FakeConsoleIO_setKeyInBuffer(inputChars);
	LegalDrivingAge_doCheck();
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(LegalDrivingAgeTest, Age35test)
{
	char inputChars[] = "35\n";
	char expectOutputStr[] = "What is your age? 35\nYou are old enough to legally drive.";
	FakeConsoleIO_setKeyInBuffer(inputChars);
	LegalDrivingAge_doCheck();
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(LegalDrivingAgeTest, AgeWorngChartest)
{
	char inputChars[] = "3a\n";
	char expectOutputStr[] = "What is your age? 3a\nPlease enter a valid age!";
	FakeConsoleIO_setKeyInBuffer(inputChars);
	LegalDrivingAge_doCheck();
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(LegalDrivingAgeTest, AgeMinusNumberTest)
{
	char inputChars[] = "-22\n";
	char expectOutputStr[] = "What is your age? -22\nPlease enter a valid age!";
	FakeConsoleIO_setKeyInBuffer(inputChars);
	LegalDrivingAge_doCheck();
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}
