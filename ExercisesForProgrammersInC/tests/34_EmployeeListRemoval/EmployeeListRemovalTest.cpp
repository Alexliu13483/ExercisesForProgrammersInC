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


TEST_GROUP(EmployeeListRemovalTest)
{
	char * namearray[5];
	NameList nameList;

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

    	namearray[0] = name1;
    	namearray[1] = name2;
    	namearray[2] = name3;
    	namearray[3] = name4;
    	namearray[4] = name5;
    	nameList.names = namearray;
    	nameList.num = 5;
    }

};

TEST(EmployeeListRemovalTest, promptTest)
{
	char expect[] = "There are 5 employees:\nJohn Smith\n"
					"Jackie Jackson\nChris Jones\nAmanda Cullen\n"
					"Jeremy Goodwin\n\nEnter an employee name to remove: \n";
	char input[] = "\n";

	FakeConsoleIO_setKeyInBuffer(input);
	EmployeeListRemoval_remove(&nameList);
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
	EmployeeListRemoval_remove(&nameList);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(EmployeeListRemovalTest, name_not_exist)
{
	char expect[] = "There are 5 employees:\nJohn Smith\n"
					"Jackie Jackson\nChris Jones\nAmanda Cullen\n"
					"Jeremy Goodwin\n\nEnter an employee name to remove: Wells Allen\n\n"
					"Error! The name doesn\'t exist.\n";
	char input[] = "Wells Allen\n";

	FakeConsoleIO_setKeyInBuffer(input);
	EmployeeListRemoval_remove(&nameList);
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(EmployeeListRemovalTest, name_list_in_file)
{
	char expect[] =	"John Smith\n"
					"Jackie Jackson\n"
					"Amanda Cullen\n"
					"Jeremy Goodwin\n";
	char input[] = "Chris Jones";
	char testdata[] = "John Smith\n"
						"Jackie Jackson\n"
						"Chris Jones\n"
						"Amanda Cullen\n"
						"Jeremy Goodwin\n";

	char filename[] = "TestData/namelistdata.txt";
	char output[1024];
	int actual_size = 0;

	FILE * f = fopen(filename, "w");
	fprintf(f, "%s", testdata);
	fclose(f);
	EmployeeListRemoval_removeFromFile(filename, input);
	f = fopen(filename, "r");
	actual_size = fread(output, sizeof(char), sizeof(output), f);
	fclose(f);
	STRNCMP_EQUAL(expect, output, actual_size);
}

