/*
 * ComputingInterest.h
 *
 *  Created on: 2016¦~2¤ë23¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_12_COMPUTINGSIMPLEINTEREST_COMPUTINGINTEREST_H_
#define INCLUDE_12_COMPUTINGSIMPLEINTEREST_COMPUTINGINTEREST_H_

void ComputingInterest_create();
double ComputingInterest_calculateSimpleInterest(double principal, double interestRate, int time);
char * ComputingInterest_calInterestWithConsoleInput();
double ComputingInterest_calculateCompoundInterest(double principal, double interestRate, int time, int numOfTime);

#endif /* INCLUDE_12_COMPUTINGSIMPLEINTEREST_COMPUTINGINTEREST_H_ */
