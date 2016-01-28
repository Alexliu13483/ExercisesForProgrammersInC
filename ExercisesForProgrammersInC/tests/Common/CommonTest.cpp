/*
 * CommonTest.cpp
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

TEST(CommonTest, testIsDigitalString_Normal)
{
	char str[] = "0123456789";

	CHECK_TRUE(Common_isDigitalString(str));
}

TEST(CommonTest, testIsDigitalString_Abnormal)
{
	char str[] = "0ABC";

	CHECK_FALSE(Common_isDigitalString(str));
}
