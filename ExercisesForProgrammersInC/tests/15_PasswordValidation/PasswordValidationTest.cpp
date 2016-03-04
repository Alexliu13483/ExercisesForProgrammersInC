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
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testPasswordValidation)
{

    void setup()
    {
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

IGNORE_TEST(testPasswordValidation, inputByConcoleTest)
{
	char password[80];
	char expectStr[] = "Welcome!";

	printf("Enter password: ");
	scanf("%s", password);
	STRCMP_EQUAL(expectStr, PasswordValidation_checkAndReturnString(password));
}

IGNORE_TEST(testPasswordValidation, inputByConcoleNoEchoTest)
{
	char expectStr[] = "Welcome!";

	STRCMP_EQUAL(expectStr, PasswordValidation_getPasswordFromConsole());
}

