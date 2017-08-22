/*
 * TroubleshootingCarIssueTest.cpp
 *
 *  Created on: 2016¦~7¤ë5¤é
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
#include "23_TroubleshootingCarIssue/TroubleshootingCarIssue.h"
#include "FakeConsoleIO.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(TroubleshootingCarIssueTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	TroubleshootingCarIssue_creat();
    }

    void teardown()
    {

    }

};

TEST(TroubleshootingCarIssueTest, FirstPathTest)
{
	char expect[] = "Is the car silent when you turn the key? y\n"
					"Are the battery terminals corrected? y\n"
					"Clean terminals and try starting again.\n";
	char input[] = "y\ny\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, SecondPathTest)
{
	char expect[] = "Is the car silent when you turn the key? y\n"
					"Are the battery terminals corrected? n\n"
					"Replace cables and try again.\n";
	char input[] = "y\nn\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, ThirdPathTest)
{
	char expect[] = "Is the car silent when you turn the key? n\n"
					"Does the car make a clicking noise? y\n"
					"Replace the battery.\n";
	char input[] = "n\ny\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, FourthPathTest)
{
	char expect[] = "Is the car silent when you turn the key? n\n"
					"Does the car make a clicking noise? n\n"
					"Does the car crank up but fail to start? y\n"
					"Check spark plug connections.\n";
	char input[] = "n\nn\ny\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, FifthPathTest)
{
	char expect[] = "Is the car silent when you turn the key? n\n"
					"Does the car make a clicking noise? n\n"
					"Does the car crank up but fail to start? n\n"
					"Does the engine start and then die? y\n"
					"Does your car have fuel injection? n\n"
					"Check to ensure the choke is opening and closing.\n";
	char input[] = "n\nn\nn\ny\nn\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, SixthPathTest)
{
	char expect[] = "Is the car silent when you turn the key? n\n"
					"Does the car make a clicking noise? n\n"
					"Does the car crank up but fail to start? n\n"
					"Does the engine start and then die? y\n"
					"Does your car have fuel injection? y\n"
					"Get it in for service.\n";
	char input[] = "n\nn\nn\ny\ny\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(TroubleshootingCarIssueTest, SeventhPathTest)
{
	char expect[] = "Is the car silent when you turn the key? n\n"
					"Does the car make a clicking noise? n\n"
					"Does the car crank up but fail to start? n\n"
					"Does the engine start and then die? n\n"
					"Get it in for service.\n";
	char input[] = "n\nn\nn\nn\n";

	FakeConsoleIO_setKeyInBuffer(input);
	TroubleshootingCarIssue_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
