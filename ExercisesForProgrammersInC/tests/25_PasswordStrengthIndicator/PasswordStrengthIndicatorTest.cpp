/*
 * PasswordStrengthIndicatorTest.cpp
 *
 *  Created on: 2016¦~7¤ë7¤é
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
#include "25_PasswordStrengthIndicator/PasswordStrengthIndicator.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(PasswordStrengthIndicatorTest)
{

    void setup()
    {
    	PasswordStrengthIndicator_create();
    }

    void teardown()
    {

    }

};

TEST(PasswordStrengthIndicatorTest, VeryWeakTest1)
{
	char password[] = "1234567";
	PasswordStrength expect = VERY_WEAK;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, VeryWeakTest2)
{
	char password[] = "12345";
	PasswordStrength expect = VERY_WEAK;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, WeakTest2)
{
	char password[] = "abcdefg";
	PasswordStrength expect = WEAK;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, StrongTest1)
{
	char password[] = "abcdefg6";
	PasswordStrength expect = STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, StrongTest2)
{
	char password[] = "abcdefg$";
	PasswordStrength expect = STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, StrongTest3)
{
	char password[] = "1245678$";
	PasswordStrength expect = STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, StrongTest4)
{
	char password[] = "abc123xyz";
	PasswordStrength expect = STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, AverageTest1)
{
	char password[] = "abcdefgh";
	PasswordStrength expect = AVERAGE;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, AverageTest2)
{
	char password[] = "@@@@$$$$";
	PasswordStrength expect = AVERAGE;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, AverageTest3)
{
	char password[] = "1234567890";
	PasswordStrength expect = AVERAGE;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, VeryStrongTest1)
{
	char password[] = "ab#defg6";
	PasswordStrength expect = VERY_STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, VeryStrongTest2)
{
	char password[] = "1337h@xor!";
	PasswordStrength expect = VERY_STRONG;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}


TEST(PasswordStrengthIndicatorTest, InvalidTest1)
{
	char password[] = "123 45678";
	PasswordStrength expect = INVALID;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, InvalidTest2)
{
	char password[] = "abc";
	PasswordStrength expect = INVALID;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

TEST(PasswordStrengthIndicatorTest, InvalidTest3)
{
	char password[] = "1234567890abc";
	PasswordStrength expect = INVALID;

	LONGS_EQUAL(expect, PasswordStrengthIndicator_passwordValidator(password));
}

