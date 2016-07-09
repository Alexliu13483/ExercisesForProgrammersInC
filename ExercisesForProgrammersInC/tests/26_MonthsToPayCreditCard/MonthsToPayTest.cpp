/*
 * MonthsToPayTest.cpp
 *
 *  Created on: 2016¦~4¤ë28¤é
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
#include "26_MonthsToPayCreditCard/MonthsToPay.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MonthsToPayTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	MonthsToPay_create();
    }

    void teardown()
    {

    }

};

TEST(MonthsToPayTest, ZeroBalanceTest)
{
	char expect[] =
			"What is your balance? 0\n"
			"What is the APR on the card (as a percent)? 12\n"
			"What is the monthly payment you can make? 100\n"
			"\nIt will take you 0 months to pay off this card.\n";
	char input1[] = "0\n";
	char input2[] = "12\n";
	char input3[] = "100\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);
	FakeConsoleIO_setKeyInBuffer(input3);

	MonthsToPay_runCalculateMonthsUntilPayOff();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(MonthsToPayTest, Balance5000Test)
{
	char expect[] =
			"What is your balance? 5000\n"
			"What is the APR on the card (as a percent)? 12\n"
			"What is the monthly payment you can make? 100\n"
			"\nIt will take you 70 months to pay off this card.\n";
	char input1[] = "5000\n";
	char input2[] = "12\n";
	char input3[] = "100\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);
	FakeConsoleIO_setKeyInBuffer(input3);

	MonthsToPay_runCalculateMonthsUntilPayOff();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(MonthsToPayTest, ZeroBalanceMonthlyPaymentTest)
{
	char expect[] =
			"What is your balance? 0\n"
			"What is the APR on the card (as a percent)? 12\n"
			"How many months do you take to pay off this card? 70\n"
			"\nYou will pay 0.00 dollars for 70 months.\n";
	char input1[] = "0\n";
	char input2[] = "12\n";
	char input3[] = "70\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);
	FakeConsoleIO_setKeyInBuffer(input3);

	MonthsToPay_runCalculateMonthlyPayment();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(MonthsToPayTest, Balance5000MonthlyPaymentTest)
{
	char expect[] =
			"What is your balance? 5000\n"
			"What is the APR on the card (as a percent)? 12\n"
			"How many months do you take to pay off this card? 70\n"
			"\nYou will pay 99.39 dollars for 70 months.\n";
	char input1[] = "5000\n";
	char input2[] = "12\n";
	char input3[] = "70\n";

	FakeConsoleIO_setKeyInBuffer(input1);
	FakeConsoleIO_setKeyInBuffer(input2);
	FakeConsoleIO_setKeyInBuffer(input3);

	MonthsToPay_runCalculateMonthlyPayment();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
