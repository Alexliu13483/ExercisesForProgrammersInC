/*
 * NameSorterTest.cpp
 *
 *  Created on: 2017¦~9¤ë6¤é
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
#include "41_Name_Sorter/NameSorter.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(NameSorterTest)
{

    void setup()
    {
    	NameSorter_create();
    }

    void teardown()
    {
    	NameSorter_destroy();
    }

};

TEST(NameSorterTest, emptyFile)
{
	char expect[] = "Total of 0 names\n"
					"-----------------\n";
	char result[100];
	char filename[] = "TestData/empty.txt";

	NameSorter_output_string(filename, result);
	STRCMP_EQUAL(expect, result);
}

TEST(NameSorterTest, oneRecFile)
{
	char expect[] = "Total of 1 names\n"
					"-----------------\n"
					"Jones, Aaron\n";
	char result[100];
	char filename[] = "TestData/oneRec.txt";

	NameSorter_output_string(filename, result);
	STRCMP_EQUAL(expect, result);
}

TEST(NameSorterTest, aNamelistFile)
{
	char expect[] = "Total of 7 names\n"
					"-----------------\n"
					"Johnson, Jim\n"
					"Jones, Aaron\n"
					"Jones, Chris\n"
					"Ling, Mai\n"
					"Swift, Geoffrey\n"
					"Xiong, Fong\n"
					"Zarnecki, Sabrina\n";
	char result[1000];
	char filename[] = "TestData/NameListForSoring.txt";

	NameSorter_output_string(filename, result);
	STRCMP_EQUAL(expect, result);
}
