/*
 * PasswordValidationTest.cpp
 *
 *  Created on: 2016¦~3¤ë3¤é
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
#include "15_PasswordValidation/PasswordValidation.h"
#include "Common/Common.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testPasswordValidation)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	PasswordValidation_create();
    }

    void teardown()
    {

    }

};

TEST(testPasswordValidation, passwordCorrectTest)
{
	char password[] = "abc$123";
	CHECK(PasswordValidation_isCorrectPassword(password));
}

TEST(testPasswordValidation, passwordIncorrectTest)
{
	char password[] = "123456";
	CHECK(!PasswordValidation_isCorrectPassword(password));
}

TEST(testPasswordValidation, passwordCorrectStringTest)
{
	char password[] = "abc$123";
	char expectStr[] = "Welcome!";
	STRCMP_EQUAL(expectStr, PasswordValidation_checkAndReturnString(password));
}

TEST(testPasswordValidation, passwordIncorrectStringTest)
{
	char password[] = "123456";
	char expectStr[] = "I don't know you.";
	STRCMP_EQUAL(expectStr, PasswordValidation_checkAndReturnString(password));
}

TEST(testPasswordValidation, inputByConcoleTest)
{
	char password[80];
	char inputChars[] = "abc$123\n";
	char expectOutputStr[] = "Enter password: abc$123\nWelcome!";

	ConsoleIO_printf("Enter password: ");
	FakeConsoleIO_setKeyInBuffer(inputChars);
	Common_getStringFromConsole(password);
	ConsoleIO_printf(PasswordValidation_checkAndReturnString(password));
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(testPasswordValidation, inputByConcoleNoEchoTest)
{
	char inputChars[] = "abc$123\n";
	char expectOutputStr[] = "\nEnter password: *******\nWelcome!";

	FakeConsoleIO_setKeyInBuffer(inputChars);
	ConsoleIO_printf(PasswordValidation_getPasswordFromConsole());
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

TEST(testPasswordValidation, inputByConcoleNoEchoWithWrongPasswordTest)
{
	char inputChars[] = "1234567\n";
	char expectOutputStr[] = "\nEnter password: *******\nI don't know you.";

	FakeConsoleIO_setKeyInBuffer(inputChars);
	ConsoleIO_printf(PasswordValidation_getPasswordFromConsole());
	STRCMP_EQUAL(expectOutputStr, FakeConsoleIO_getOutputString());
}

