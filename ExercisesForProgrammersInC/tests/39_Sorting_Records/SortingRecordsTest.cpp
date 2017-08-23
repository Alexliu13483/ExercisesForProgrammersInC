/*
 * SortingRecordsTest.cpp
 *
 *  Created on: 2017¦~8¤ë23¤é
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
#include "39_Sorting_Records/SortingRecords.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(SortingRecordsTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	SortingRecords_create();
    }

    void teardown()
    {
    	SortingRecords_destroy();
    }

};

TEST(SortingRecordsTest, noneInputData)
{
	char expect[] = "Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n";
	char inputRecords[] = "Name, Position, Separation Date\n";

	SortingRecords_sort(inputRecords);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(SortingRecordsTest, oneInputData)
{
	char expect[] = "Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n"
					"John Johnson        | Manager           | 2016-12-31\n";
	char inputRecords[] = "Name, Position, Separation Date\n"
						  "John, Johnson, Manager, 2016-12-31\n";

	SortingRecords_sort(inputRecords);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
