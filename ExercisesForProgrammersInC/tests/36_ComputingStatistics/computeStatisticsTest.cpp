/*
 * computeStatisticsTest.cpp
 *
 *  Created on: 2017¦~8¤ë16¤é
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
#include "36_ComputingStatistics/computeStatistics.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(computeStatisticsTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	computeStatistics_create();
    }

    void teardown()
    {

    }

};

TEST(computeStatisticsTest, zeroNumber)
{
	char expect[] =
			"Enter a number: done\n"
			"Numbers: 0\n"
			"The average is 0.\n"
			"The minimum is 0.\n"
			"The maximum is 0.\n"
			"The standard deviation is 0.00.\n";
	char input[] = "done\n";

	FakeConsoleIO_setKeyInBuffer(input);
	computeStatistics_run_interact();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(computeStatisticsTest, oneNumber)
{
	char expect[] =
			"Enter a number: 100\n"
			"Enter a number: done\n"
			"Numbers: 100\n"
			"The average is 100.\n"
			"The minimum is 100.\n"
			"The maximum is 100.\n"
			"The standard deviation is 0.00.\n";
	char input[] = "100\ndone\n";

	FakeConsoleIO_setKeyInBuffer(input);
	computeStatistics_run_interact();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(computeStatisticsTest, aFewNumbers)
{
	char expect[] =
			"Enter a number: 100\n"
			"Enter a number: 200\n"
			"Enter a number: 1000\n"
			"Enter a number: 300\n"
			"Enter a number: done\n"
			"Numbers: 100, 200, 1000, 300\n"
			"The average is 400.\n"
			"The minimum is 100.\n"
			"The maximum is 1000.\n"
			"The standard deviation is 353.55.\n";
	char input[] = "100\n200\n1000\n300\ndone\n";

	FakeConsoleIO_setKeyInBuffer(input);
	computeStatistics_run_interact();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(computeStatisticsTest, inputFromFile)
{
	char expect[] =
			"Numbers: 100, 200, 1000, 300\n"
			"The average is 400.\n"
			"The minimum is 100.\n"
			"The maximum is 1000.\n"
			"The standard deviation is 353.55.\n";
	char filename[] = "TestData/computeStatisticsData.txt";

	computeStatistics_run_file(filename);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
