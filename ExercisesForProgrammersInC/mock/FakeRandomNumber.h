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

#endif /* MOCK_FAKERANDOMNUMBER_H_ */
