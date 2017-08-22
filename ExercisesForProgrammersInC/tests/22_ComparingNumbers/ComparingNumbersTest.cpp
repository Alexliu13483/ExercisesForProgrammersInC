/*
 * ComparingNumbersTest.cpp
 *
 *  Created on: 2016¦~3¤ë30¤é
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
#include "22_ComparingNumbers/ComparingNumbers.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ComparingNumbersTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	ComparingNumbers_create();
    }

    void teardown()
    {

    }

};

TEST(ComparingNumbersTest, findTheMaximum)
{
	char expect[] = "Enter the first number: 1\n"
					"Enter the second number: 51\n"
					"Enter the third number: 2\n"
					"Enter the fourth number: 21\n"
					"Enter the fifth number: 32\n"
					"Enter the sixth number: 26\n"
					"Enter the seventh number: 62\n"
					"Enter the eighth number: 29\n"
					"Enter the ninth number: 12\n"
					"Enter the tenth number: 102\n"
					"The largest number is 102.\n";
	char inputNum1[] = "1\n51\n2\n21\n32\n26\n62\n29\n12\n102\n";

	FakeConsoleIO_setKeyInBuffer(inputNum1);
	ComparingNumbers_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(ComparingNumbersTest, duplicatedNumber)
{
	char expect[] = "Enter the first number: 23\n"
					"Enter the second number: 51\n"
					"Enter the third number: 23\n"
					"23 has been existed. Please enter the number again : 66\n"
					"Enter the fourth number: 21\n"
					"Enter the fifth number: 32\n"
					"Enter the sixth number: 26\n"
					"Enter the seventh number: 62\n"
					"Enter the eighth number: 29\n"
					"Enter the ninth number: 12\n"
					"Enter the tenth number: 102\n"
					"The largest number is 102.\n";

	char inputNum1[] = "23\n";
	char inputNum2[] = "51\n";
	char inputNum3[] = "23\n";
	char inputNum4[] = "66\n21\n32\n26\n62\n29\n12\n102\n";

	FakeConsoleIO_setKeyInBuffer(inputNum1);
	FakeConsoleIO_setKeyInBuffer(inputNum2);
	FakeConsoleIO_setKeyInBuffer(inputNum3);
	FakeConsoleIO_setKeyInBuffer(inputNum4);
	ComparingNumbers_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
