/*
 * FilteringRecordsTest.cpp
 *
 *  Created on: 2017¦~8¤ë29¤é
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
#include "40_Filtering_Records/FilteringRecords.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(FilteringRecordsTest)
{
    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FilteringRecords_create();
    }

    void teardown()
    {
    	FilteringRecords_destroy();
    }

};

TEST(FilteringRecordsTest, emptyInputString)
{
	char inputRecords[] =
							"John,Johnson,Manager,2016-12-31\n"
							"Tou,Xiong,Software Engineer,2016-10-05\n"
							"Michaela,Michaelson,District Manager,2015-12-19\n"
							"Jake,Jacobson,Programmer, \n"
							"Jacquelyn,Jackson,DBA, \n"
							"Sally,Weber,Web Developer,2015-12-18\n";

	char expect[] = "Enter a search string: \n\n"
					"Results:\n"
					"Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n";
	char input[] = "\n";

	FilteringRecords_createDatabase(inputRecords);
	FakeConsoleIO_setKeyInBuffer(input);
	FilteringRecords_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}


TEST(FilteringRecordsTest, noResult)
{
	char inputRecords[] =
							"John,Johnson,Manager,2016-12-31\n"
							"Tou,Xiong,Software Engineer,2016-10-05\n"
							"Michaela,Michaelson,District Manager,2015-12-19\n"
							"Jake,Jacobson,Programmer, \n"
							"Jacquelyn,Jackson,DBA, \n"
							"Sally,Weber,Web Developer,2015-12-18\n";

	char expect[] = "Enter a search string: XYZ\n\n"
					"Results:\n"
					"Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n";
	char input[] = "XYZ\n";

	FilteringRecords_createDatabase(inputRecords);
	FakeConsoleIO_setKeyInBuffer(input);
	FilteringRecords_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(FilteringRecordsTest, oneResult)
{
	char inputRecords[] =
							"John,Johnson,Manager,2016-12-31\n"
							"Tou,Xiong,Software Engineer,2016-10-05\n"
							"Michaela,Michaelson,District Manager,2015-12-19\n"
							"Jake,Jacobson,Programmer, \n"
							"Jacquelyn,Jackson,DBA, \n"
							"Sally,Weber,Web Developer,2015-12-18\n";

	char expect[] = "Enter a search string: Sally\n\n"
					"Results:\n"
					"Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n"
					"Sally Weber         | Web Developer     | 2015-12-18\n";
	char input[] = "Sally\n";

	FilteringRecords_createDatabase(inputRecords);
	FakeConsoleIO_setKeyInBuffer(input);
	FilteringRecords_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(FilteringRecordsTest, multipleResults)
{
	char inputRecords[] =
							"John,Johnson,Manager,2016-12-31\n"
							"Tou,Xiong,Software Engineer,2016-10-05\n"
							"Michaela,Michaelson,District Manager,2015-12-19\n"
							"Jake,Jacobson,Programmer, \n"
							"Jacquelyn,Jackson,DBA, \n"
							"Sally,Weber,Web Developer,2015-12-18\n";

	char expect[] = "Enter a search string: Jac\n\n"
					"Results:\n"
					"Name                | Position          | Separation Date\n"
					"--------------------|-------------------|----------------\n"
					"Jake Jacobson       | Programmer        |  \n"
					"Jacquelyn Jackson   | DBA               |  \n";
	char input[] = "Jac\n";

	FilteringRecords_createDatabase(inputRecords);
	FakeConsoleIO_setKeyInBuffer(input);
	FilteringRecords_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
