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
	char inputRecords[] = "";

	SortingRecords_sort(inputRecords);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(SortingRecordsTest, oneInputData)
{
	char expect[] = "Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n"
					"John Johnson        | Manager           | 2016-12-31\n";
	char inputRecords[] = "John,Johnson,Manager,2016-12-31\n";

	SortingRecords_sort(inputRecords);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(SortingRecordsTest, sixInputData)
{
	char expect[] = "Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n"
					"Jacquelyn Jackson   | DBA               |  \n"
					"Jake Jacobson       | Programmer        |  \n"
					"John Johnson        | Manager           | 2016-12-31\n"
					"Michaela Michaelson | District Manager  | 2015-12-19\n"
					"Sally Weber         | Web Developer     | 2015-12-18\n"
					"Tou Xiong           | Software Engineer | 2016-10-05\n";
	char inputRecords[] =
							"John,Johnson,Manager,2016-12-31\n"
							"Tou,Xiong,Software Engineer,2016-10-05\n"
							"Michaela,Michaelson,District Manager,2015-12-19\n"
							"Jake,Jacobson,Programmer, \n"
							"Jacquelyn,Jackson,DBA, \n"
							"Sally,Weber,Web Developer,2015-12-18\n";

	SortingRecords_sort(inputRecords);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
