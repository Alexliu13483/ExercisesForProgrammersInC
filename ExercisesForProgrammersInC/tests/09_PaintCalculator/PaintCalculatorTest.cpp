/*
 * PaintCalculatorTest.cpp
 *
 *  Created on: 2016¦~2¤ë16¤é
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
#include "09_PaintCalculator/PaintCalculator.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(PaintCalculatorTest)
{

    void setup()
    {
    	PaintCalculator_creat();
    }

    void teardown()
    {

    }

};

TEST(PaintCalculatorTest, ZeroSquareFeet)
{
	LONGS_EQUAL(0, PaintCalculator_calculatePaintNeed(0));
}

TEST(PaintCalculatorTest, JustNeedOneGallonPaint)
{
	LONGS_EQUAL(1, PaintCalculator_calculatePaintNeed(350.0));
}

TEST(PaintCalculatorTest, BetweenOneAndTwoGallonsPaint)
{
	LONGS_EQUAL(2, PaintCalculator_calculatePaintNeed(400.0));
}

TEST(PaintCalculatorTest, UnderOneGallonsPaint)
{
	LONGS_EQUAL(1, PaintCalculator_calculatePaintNeed(300.0));
}

TEST(PaintCalculatorTest, CheckTextOutput_360SquareFeet)
{
	char expect[] = "You will need to purchase 2 gallons of\npaint to cover 360 square feet.";
	STRCMP_EQUAL(expect, PaintCalculator_OutputText(360.0));
}

