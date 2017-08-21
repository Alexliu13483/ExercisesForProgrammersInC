/*
 * FakeRandomNumberTest.cpp
 *
 *  Created on: 2017¦~8¤ë18¤é
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
#include "FakeRandomNumber.h"
#include "Common/Common.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(FakeRandomNumberTest_inc)
{

    void setup()
    {
    	FakeRandomNumber_create();
    }

    void teardown()
    {

    }

};

TEST(FakeRandomNumberTest_inc, zero_seed_zero_inc)
{
	int expect = 0;

	FakeRandomNumber_SetFirstAndIncrement(0, 0);
	LONGS_EQUAL(expect, Common_rand());
	LONGS_EQUAL(expect, Common_rand());
}

TEST(FakeRandomNumberTest_inc, zero_seed_one_inc)
{
	int expect = 0;

	FakeRandomNumber_SetFirstAndIncrement(0, 1);
	LONGS_EQUAL(expect++, Common_rand());
	LONGS_EQUAL(expect++, Common_rand());
	LONGS_EQUAL(expect++, Common_rand());
	LONGS_EQUAL(expect++, Common_rand());
	LONGS_EQUAL(expect++, Common_rand());
	LONGS_EQUAL(expect, Common_rand());
}

TEST_GROUP(FakeRandomNumberTest_Mul)
{

    void setup()
    {
    	FakeRandomNumber_Multiple_create();
    }

    void teardown()
    {

    }

};

TEST(FakeRandomNumberTest_Mul, one_number)
{
	int expect = 100;
	int numbers[1] = {100};

	FakeRandomNumber_Multiple_SetNumbers(numbers, 1);
	LONGS_EQUAL(expect, Common_rand());
}

TEST(FakeRandomNumberTest_Mul, threeNumbers)
{
	int numbers[] = {100, 200, 300};

	FakeRandomNumber_Multiple_SetNumbers(numbers, 3);
	for (int i = 0; i < 3; i++)
		LONGS_EQUAL(numbers[i], Common_rand());
}

TEST(FakeRandomNumberTest_Mul, overNumbers)
{
	int numbers[] = {100, 200, 300};
	int expect_error = 0;

	FakeRandomNumber_Multiple_SetNumbers(numbers, 3);
	for (int i = 0; i < 3; i++)
		LONGS_EQUAL(numbers[i], Common_rand());
	LONGS_EQUAL(expect_error, Common_rand());
}

