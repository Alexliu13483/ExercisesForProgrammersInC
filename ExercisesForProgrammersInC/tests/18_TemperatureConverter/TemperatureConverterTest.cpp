/*
 * TemperatureConverterTest.cpp
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
#include "18_TemperatureConverter/TemperatureConverter.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TemperatureConverterTest)
{

    void setup()
    {
    	FakeConsoleIO_create();
    	UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);
    	UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);
    	UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);
    	UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar);
    	TemperatureConverter_create();
    }

    void teardown()
    {

    }

};

TEST(TemperatureConverterTest, CtoF)
{
	char expect[] = "Press C to convert from Fahrenheit to Celsius.\n"
			"Press F to convert from Celsius to Fahrenheit.\n"
			"Your choice: C\n\n"
			"Please enter the temperature in Fahrenheit: 32\n"
			"The temperature in Celsius is 0.\n";
	char inputDataData1[] = "C";
	char inputDataData2[] = "32\n";

	FakeConsoleIO_setKeyInBuffer(inputDataData1);
	FakeConsoleIO_setKeyInBuffer(inputDataData2);
	TemperatureConverter_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TemperatureConverterTest, FtoC)
{
	char expect[] = "Press C to convert from Fahrenheit to Celsius.\n"
			"Press F to convert from Celsius to Fahrenheit.\n"
			"Your choice: F\n\n"
			"Please enter the temperature in Celsius: 0\n"
			"The temperature in Fahrenheit is 32.\n";
	char inputDataData1[] = "F";
	char inputDataData2[] = "0\n";

	FakeConsoleIO_setKeyInBuffer(inputDataData1);
	FakeConsoleIO_setKeyInBuffer(inputDataData2);
	TemperatureConverter_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
