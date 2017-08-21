/*
 * GuessTheNumberGame.c
 *
 *  Created on: 2016¦~8¤ë31¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

void GuessTheNumberGame_create() {
	srand(time(NULL));
}

static int getDifficulty(char * inputBuffer) {
	do {
		ConsoleIO_printf("Pick a difficulty level (1, 2, or 3): ");
		Common_getStringFromConsole(inputBuffer);
	} while (!Common_isIntegerString(inputBuffer));
	return atoi(inputBuffer);
}

static int getDivisor(int difficulty) {
	switch(difficulty) {
		case 1: return 10;
		case 2: return 100;
		case 3: return 1000;
		default: return 10;
	}
}

static int getGuessNumber(char * inputBuffer, int * counterRetry) {
	(*counterRetry)++;
	Common_getStringFromConsole(inputBuffer);
	while (!Common_isIntegerString(inputBuffer)) {
		ConsoleIO_printf("What\'s your guess? ");
		Common_getStringFromConsole(inputBuffer);
	}
	return atoi(inputBuffer);
}

void GuessTheNumberGame_run() {
	char inputBuffer[80];
	int difficulty;
	int guessedNumber;
	int randomNumber;
	int divisor = 10;
	int counterRetry = 0;

	ConsoleIO_printf("Let's play Guess the Number.\n");

	do {
		difficulty = getDifficulty(inputBuffer);
		divisor = getDivisor(difficulty);

		randomNumber = Common_rand() % divisor + 1;
		counterRetry = 0;

		ConsoleIO_printf("I have my number. What\'s your guess? ");
		guessedNumber = getGuessNumber(inputBuffer,	&counterRetry);

		do {
			if (guessedNumber > randomNumber) {
				ConsoleIO_printf("Too high. Guess again: ");
				guessedNumber = getGuessNumber(inputBuffer,	&counterRetry);
			} else if (guessedNumber < randomNumber) {
				ConsoleIO_printf("Too low.  Guess again: ");
				guessedNumber = getGuessNumber(inputBuffer,	&counterRetry);
			}
		} while (randomNumber != guessedNumber);
		ConsoleIO_printf("You got it in %d guesses!\n", counterRetry);

		ConsoleIO_printf("Play again? ");
		Common_getStringFromConsole(inputBuffer);
	} while (inputBuffer[0] == 'y');

	ConsoleIO_printf("Goodbye!\n");
}
