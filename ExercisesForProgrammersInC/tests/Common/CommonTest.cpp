/*
 * CommonTest.cpp
 *
 *  Created on: 2016�~1��28��
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
#include <stdio.h>
#include <stdlib.h>
#include "Common/Common.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CommonTest)
{

    void setup()
    {
    	
    }

    void teardown()
    {

    }

};

TEST(CommonTest, testIsIntegerString_Normal)
{
	char str[] = "0123456789";

	CHECK_TRUE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsIntegerString_Abnormal)
{
	char str[] = "0ABC";

	CHECK_FALSE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsIntegerString_Negative)
{
	char str[] = "-1";

	CHECK_TRUE(Common_isIntegerString(str));
	//printf("%d\n", atoi(str));
}

TEST(CommonTest, testIsIntegerString_Positive)
{
	char str[] = "+1";

	CHECK_TRUE(Common_isIntegerString(str));
}

TEST(CommonTest, testIsDoubleString_Normal)
{
	char str[] = "123.258";

	CHECK_TRUE(Common_isDoubleString(str));
}

TEST(CommonTest, testIsDoubleString_Alphabet)
{
	char str[] = "123Dot258";

	CHECK_FALSE(Common_isDoubleString(str));
}

TEST(CommonTest, testIsDoubleString_TwoDots)
{
	char str[] = "123..258";

	CHECK_FALSE(Common_isDoubleString(str));
}

