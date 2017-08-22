/*
 * KarvonenHeartRateTest.cpp
 *
 *  Created on: 2016¦~7¤ë21¤é
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
#include "31_KarvonenHeartRate/KarvonenHeartRate.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(KarvonenHeartRateTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	KarvonenHeartRate_create();
    }

    void teardown()
    {

    }

};

TEST(KarvonenHeartRateTest, KHR_Cal01_Test)
{
	int expect = 138;
	int age = 22;
	int restingHR = 65;
	int intensity = 55;
	int result;

	result = KarvonenHeartRate_calculate(age, restingHR, intensity);
	LONGS_EQUAL(expect, result);
}

TEST(KarvonenHeartRateTest, KHR_Cal02_Test)
{
	int expect = 145;
	int age = 22;
	int restingHR = 65;
	int intensity = 60;
	int result;

	result = KarvonenHeartRate_calculate(age, restingHR, intensity);
	LONGS_EQUAL(expect, result);
}

TEST(KarvonenHeartRateTest, OutputTableTest)
{
	char expect[] =
			"Resting Pulse: 65\nAge: 22\n\n"
			"Intensity   | Rate\n"
			"------------|--------\n"
			"55%         | 138 bpm\n"
			"60%         | 145 bpm\n"
			"65%         | 151 bpm\n"
			"70%         | 158 bpm\n"
			"75%         | 165 bpm\n"
			"80%         | 171 bpm\n"
			"85%         | 178 bpm\n"
			"90%         | 185 bpm\n"
			"95%         | 191 bpm\n";

	char input[] = "65\n22\n";

	FakeConsoleIO_setKeyInBuffer(input);

	KarvonenHeartRate_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(KarvonenHeartRateTest, OutputTableWithWrongInputTest)
{
	char expect[] =
			"Resting Pulse: 5Q\n"
			"Resting Pulse: 65\n"
			"Age: 2b\n"
			"Age: 22\n\n"
			"Intensity   | Rate\n"
			"------------|--------\n"
			"55%         | 138 bpm\n"
			"60%         | 145 bpm\n"
			"65%         | 151 bpm\n"
			"70%         | 158 bpm\n"
			"75%         | 165 bpm\n"
			"80%         | 171 bpm\n"
			"85%         | 178 bpm\n"
			"90%         | 185 bpm\n"
			"95%         | 191 bpm\n";

	char input[] = "5Q\n65\n2b\n22\n";

	FakeConsoleIO_setKeyInBuffer(input);

	KarvonenHeartRate_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}
