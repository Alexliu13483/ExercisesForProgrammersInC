/*
 * FakeRandomNumber.c
 *
 *  Created on: 2016¦~8¤ë31¤é
 *      Author: Alex.Liu
 */

#include "Common/Common.h"

static int seed;
static int increment;


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
