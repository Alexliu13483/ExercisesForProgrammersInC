/*
 * PrintingQuotesTest.cpp
 *
 *  Created on: 2016¦~1¤ë26¤é
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
#include "3_PrintQuotes/PrintQuote.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(PrintQuotesTest)
{

    void setup()
    {
    	PrintQuote_create();
    }

    void teardown()
    {

    }

};

TEST(PrintQuotesTest, PrintObiWanQuote)
{
	char author[] = "Obi-Wan Kenobi";
	char quote[] = "These aren\'t the droids you\'re looking for.";
	STRCMP_EQUAL("Obi-Wan Kenobi says, \"These aren't the droids you're looking for.\"",
			PrintQuote_outputString(author, quote));
}

IGNORE_TEST(PrintQuotesTest, PrintFromConsole)
{

	STRCMP_EQUAL("Obi-Wan Kenobi says, \"These aren't the droids you're looking for.\"", PrintQuote_inputByConsole());
}


