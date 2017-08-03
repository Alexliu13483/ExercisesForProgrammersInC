/*
 * EmployeeListRemovalTest.cpp
 *
 *  Created on: 2017�~8��3��
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
#include "34_EmployeeListRemoval\EmployeeListRemoval.h"
}

#include "CppUTest/TestHarness.h"

char name1[] = "John Smith";
char name2[] = "Jackie Jackson";
char name3[] = "Chris Jones";
char name4[] = "Amanda Cullen";
char name5[] = "Jeremy Goodwin";
char name6[] = "";


TEST_GROUP(EmployeeListRemovalTest)
{
	char * nameList[6];

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	EmployeeListRemoval_create();
    	prepareTestData();
    }

    void teardown()
    {

    }

    void prepareTestData() {

    	nameList[0] = name1;
    	nameList[1] = name2;
    	nameList[2] = name3;
    	nameList[3] = name4;
    	nameList[4] = name5;
    	nameList[5] = name6;
    }

};

TEST(EmployeeListRemovalTest, promptTest)
{
	char expect[] = "There are 5 employees:\nJohn Smith\n"
					"Jackie Jackson\nChris Jones\nAmanda Cullen\n"
					"Jeremy Goodwin\n\nEnter an employee name to remove: \n";
	char input[] = "\n";

	FakeConsoleIO_setKeyInBuffer(input);
	EmployeeListRemoval_remove(nameList);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(EmployeeListRemovalTest, remove_one)
{
	char expect[] = "There are 5 employees:\nJohn Smith\n"
					"Jackie Jackson\nChris Jones\nAmanda Cullen\n"
					"Jeremy Goodwin\n\nEnter an employee name to remove: Chris Jones\n\n"
					"There are 4 employees:\n"
					"John Smith\n"
					"Jackie Jackson\n"
					"Amanda Cullen\n"
					"Jeremy Goodwin\n";
	char input[] = "Chris Jones\n";

	FakeConsoleIO_setKeyInBuffer(input);
	EmployeeListRemoval_remove(nameList);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

