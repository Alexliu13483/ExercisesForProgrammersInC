/*
 * FakeRandomNumber.h
 *
 *  Created on: 2016¦~8¤ë31¤é
 *      Author: Alex.Liu
 */

#ifndef MOCK_FAKERANDOMNUMBER_H_
#define MOCK_FAKERANDOMNUMBER_H_

void FakeRandomNumber_SetFirstAndIncrement(int seed, int increment);
int FakeRandomNumber_Get(void);
void FakeRandomNumber_Reset(void);
void FakeRandomNumber_create(void);

#define MAX_RANDOM_NUMBERS		100
void FakeRandomNumber_Multiple_create();
void FakeRandomNumber_Multiple_SetNumbers(int * numbers, int sizeOfNumbers);
int FakeRandomNumber_Multiple_Get();

#endif /* MOCK_FAKERANDOMNUMBER_H_ */
