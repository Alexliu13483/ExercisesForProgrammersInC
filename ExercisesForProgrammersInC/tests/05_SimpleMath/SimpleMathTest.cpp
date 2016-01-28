/*
 * SimpleMathTest.cpp
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
#include "05_SimpleMath/SimpleMath.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(SimpleMathTest)
{

    void setup()
    {
    	SimpleMath_create();
    }

    void teardown()
    {

    }

};

TEST(SimpleMathTest, test_10and5)
{
	char num1[] = "10";
	char num2[] = "5";
	SimpleMath_calTwoTextNumbers(num1, num2);
	LONGS_EQUAL(15, SimpleMath_getSum());
	LONGS_EQUAL(5, SimpleMath_getDifference());
	LONGS_EQUAL(50, SimpleMath_getProduct());
	LONGS_EQUAL(2, SimpleMath_getQuotient());
}

TEST(SimpleMathTest, test_InputFromConsole)
{
	SimpleMath_inputFromConsole();
	LONGS_EQUAL(15, SimpleMath_getSum());
	LONGS_EQUAL(5, SimpleMath_getDifference());
	LONGS_EQUAL(50, SimpleMath_getProduct());
	LONGS_EQUAL(2, SimpleMath_getQuotient());
}
