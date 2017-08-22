/*
 * AreaOfRectRoomTest.cpp
 *
 *  Created on: 2016¦~2¤ë2¤é
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
#include "07_AreaOfRectRoom/RectRoom.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(AreaOfRectRoomTest)
{

    void setup()
    {
    	RectRoom_create();
    }

    void teardown()
    {

    }

};

TEST(AreaOfRectRoomTest, CalRectAreaTest_15_20)
{
	DOUBLES_EQUAL(300.0, RectRoom_calAreaInFeet(15.0, 20.0), 0.000001);
}

TEST(AreaOfRectRoomTest, CalRectAreaTest_11_20)
{
	DOUBLES_EQUAL(220.0, RectRoom_calAreaInFeet(11.0, 20.0), 0.000001);
}

TEST(AreaOfRectRoomTest, ConvertSquareFeet2MeterTest)
{
	DOUBLES_EQUAL(27.871, RectRoom_convertSquareFeetToSquareMeter(300), 0.001);
}

IGNORE_TEST(AreaOfRectRoomTest, InputByConsoleTest)
{
	char expect[] = "You entered dimensions of 15 feet by 20 feet.\nThe area is \n300 square feet\n27.871 square meters\n";

	RectRoom_calAreaInFeetFromConsole();
	/*
	 * What is the length of the room in feet? 15
	 * What is the width of the room in feet? 20
	 *
	 */
	STRCMP_EQUAL(expect, RectRoom_getConsoleOutput());
}
