/*
 * FakeRandomNumber.c
 *
 *  Created on: 2016¦~8¤ë31¤é
 *      Author: Alex.Liu
 */

#include <stdlib.h>
#include <string.h>
#include "Common/Common.h"
#include "FakeRandomNumber.h"

static int seed;
static int increment;
static int * randomList;
static int sizeOfNumberList;
static int NumCcounter;

void FakeRandomNumber_SetFirstAndIncrement(int s, int i) {
	seed = s;
	increment = i;
}

int FakeRandomNumber_Get(void) {
	int result = seed;
	seed += increment;
	return result;
}

void FakeRandomNumber_Reset(void) {
	seed = -1;
	increment = -1;
}

void FakeRandomNumber_create() {
	Common_rand = FakeRandomNumber_Get;
	FakeRandomNumber_Reset();
}


static void FakeRandomNumber_Multiple_Reset() {
	randomList = (int *)NULL;
	sizeOfNumberList = 0;
	NumCcounter = 0;
}

void FakeRandomNumber_Multiple_create() {
	Common_rand = FakeRandomNumber_Multiple_Get;
	FakeRandomNumber_Multiple_Reset();
}

void FakeRandomNumber_Multiple_SetNumbers(int * numbers, int sizeOfNumbers) {
	randomList = numbers;
	sizeOfNumberList = sizeOfNumbers;
}

int FakeRandomNumber_Multiple_Get() {
	if (NumCcounter >= sizeOfNumberList)
		return 0;

	return randomList[NumCcounter++];
}

