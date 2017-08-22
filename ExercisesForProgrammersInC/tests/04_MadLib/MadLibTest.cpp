/*
 * MadLibTest.cpp
 *
 *  Created on: 2016¦~1¤ë27¤é
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
#include "04_MadLib/MadLib.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MadLibTest)
{

    void setup()
    {
    	MadLib_create();
    }

    void teardown()
    {

    }

};

TEST(MadLibTest, FirstTest)
{
	char noun[] = "dog";
	char verb[] = "walk";
	char adjective[] = "blue";
	char adverb[] = "quickly";

	MadLib_setNoun(noun);
	MadLib_setVerb(verb);
	MadLib_setAdjective(adjective);
	MadLib_setAdverb(adverb);

	STRCMP_EQUAL("Do you walk your blue dog quickly? That's hilarious!",
		MadLib_showOutput());
}

TEST(MadLibTest, SecondTest)
{
	char noun[] = "cat";
	char verb[] = "hit";
	char adjective[] = "good";
	char adverb[] = "quickly";

	MadLib_setNoun(noun);
	MadLib_setVerb(verb);
	MadLib_setAdjective(adjective);
	MadLib_setAdverb(adverb);

	STRCMP_EQUAL("Do you hit your good cat quickly? That's hilarious!",
		MadLib_showOutput());
}

IGNORE_TEST(MadLibTest, InputFromConsoleTest)
{
	STRCMP_EQUAL("Do you hit your good cat quickly? That's hilarious!",
		MadLib_InputByConcole());
}
