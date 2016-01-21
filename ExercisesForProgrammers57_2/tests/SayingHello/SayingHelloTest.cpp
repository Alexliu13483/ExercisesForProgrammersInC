/*
 * SayingHelloTest.cpp
 *
 *  Created on: 2016¦~1¤ë20¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * STRCMP_EQUAL(expect, result);
 * LONGS_EQUAL(expect, result);
 * BYTES_EQUAL(expect, result);
 * POINTERS_EQUAL(expect, result);
 */


extern "C"
{
#include "SayingHello.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(SayingHelloTest)
{

    void setup()
    {
    	SayingHello_Create();
    }

    void teardown()
    {

    }

};

TEST(SayingHelloTest, TestBrian)
{
	char name[] = "Brian";
	SayingHello_SetInputName(name);
	STRCMP_EQUAL("Hello, Brian, nice to meet you!", SayingHello_GetOutput());
}

TEST(SayingHelloTest, TestAndrew)
{
	char name[] = "Andrew";
	SayingHello_SetInputName(name);
	STRCMP_EQUAL("Hello, Andrew, nice to meet you!", SayingHello_GetOutput());
}

TEST(SayingHelloTest, TestLongLongName)
{
	char name[55];
	int i;
	for (i=0; i < 54; i++)
		name[i] = 'A';
	name[i] = '\0';
	SayingHello_SetInputName(name);
	STRCMP_EQUAL("Hello, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA, nice to meet you!", SayingHello_GetOutput());
}

IGNORE_TEST(SayingHelloTest, TestInputAndOuputOnScreen)
{
	SayingHello_InputAndOuputOnScreen();
	STRCMP_EQUAL("Hello, Andrew, nice to meet you!", SayingHello_GetOutput());
}
