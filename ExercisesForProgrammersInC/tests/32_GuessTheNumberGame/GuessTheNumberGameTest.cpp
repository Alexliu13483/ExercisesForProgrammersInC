/*
 * GuessTheNumberGameTest.cpp
 *
 *  Created on: 2016¦~8¤ë31¤é
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
#include "FakeRandomNumber.h"
#include "32_GuessTheNumberGame\GuessTheNumberGame.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(GuessTheNumberGameTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	FakeRandomNumber_create();
    	GuessTheNumberGame_create();
    }

    void teardown()
    {

    }

};

TEST(GuessTheNumberGameTest, TestDifficulty_1_Result_1)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 1\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\n1\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(10, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestDifficulty_1_Result_5)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 5\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\n5\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(24, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestPlayAgain)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 1\n"
			"You got it in 1 guesses!\n"
			"Play again? y\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 2\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\n1\ny\n1\n2\nn\n";

	FakeConsoleIO_setKeyInBuffer(input);
	FakeRandomNumber_SetFirstAndIncrement(0, 1);
	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestDifficulty_2_Result_23)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 2\n"
			"I have my number. What\'s your guess? 23\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "2\n23\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(122, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}


TEST(GuessTheNumberGameTest, TestTry3times)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 1\n"
			"Too low.  Guess again: 5\n"
			"Too high. Guess again: 2\n"
			"You got it in 3 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\n1\n5\n2\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(1, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestNonNumericDifficulty)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): a\n"
			"Pick a difficulty level (1, 2, or 3): t\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 1\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "a\nt\n1\n1\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(10, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestNonNumericGuess)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? a\n"
			"What\'s your guess? 1\n"
			"You got it in 1 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\na\n1\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(10, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(GuessTheNumberGameTest, TestTry3timesWithNonNumericGuess)
{
	char expect[] =
			"Let's play Guess the Number.\n"
			"Pick a difficulty level (1, 2, or 3): 1\n"
			"I have my number. What\'s your guess? 1\n"
			"Too low.  Guess again: 5\n"
			"Too high. Guess again: x\n"
			"What\'s your guess? 2\n"
			"You got it in 3 guesses!\n"
			"Play again? n\n"
			"Goodbye!\n";

	char input[] = "1\n1\n5\nx\n2\nn\n";

	FakeRandomNumber_SetFirstAndIncrement(1, 0);
	FakeConsoleIO_setKeyInBuffer(input);

	GuessTheNumberGame_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

