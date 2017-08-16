/*
 * computeStatistics.c
 *
 *  Created on: 2017¦~8¤ë16¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Common/Common.h"
#include "Common/ConsoleIO.h"

#define MAX_ARRAY_NUMBER	100
int numbers[MAX_ARRAY_NUMBER];

void computeStatistics_create() {
	for (int i = 0; i < MAX_ARRAY_NUMBER; i++) {
		numbers[i] = 0;
	}
}

static int getInputNumbers() {
	char inputPrompt[] = "Enter a number: ";
	char strDone[] = "done";
	char inString[100];
	int count = 0;

	while (count < MAX_ARRAY_NUMBER) {
		ConsoleIO_printf("%s", inputPrompt);
		Common_getStringFromConsole(inString);
		if (!strcmp(inString, strDone))
			break;

		if (Common_isIntegerString(inString)) {
			numbers[count] = atoi(inString);
			count++;
		}
	}
	return count;
}

static void outputResults(int countNum, double avg, int min, int max, double sd) {
	ConsoleIO_printf("Numbers: ");
	if (countNum == 0)
		ConsoleIO_printf("0");

	for (int i = 0; i < countNum; i++) {
		if (i != 0)
			ConsoleIO_printf(", ");

		ConsoleIO_printf("%d", numbers[i]);
	}
	ConsoleIO_printf("\nThe average is %.0f.\n", avg);
	ConsoleIO_printf("The minimum is %d.\n", min);
	ConsoleIO_printf("The maximum is %d.\n", max);
	ConsoleIO_printf("The standard deviation is %.2f.\n", sd);
}

static double calMeanValue(int countNum) {
	int sum = 0;
	for (int i = 0; i < countNum; i++) {
		sum += numbers[i];
	}
	return (double) sum / (double) countNum;
}

static int findMinimum(int countNum) {
	int min = numbers[0];
	for (int i = 1; i < countNum; i++) {
		if (min > numbers[i])
			min = numbers[i];
	}
	return min;
}

static int findMaximum(int countNum) {
	int max = numbers[0];
	for (int i = 1; i < countNum; i++) {
		if (max < numbers[i])
			max = numbers[i];
	}
	return max;
}

static double calStandardDeviation(int countNum, double avg) {
	double sqr_sum = 0.0;
	for (int i = 0; i < countNum; i++) {
		sqr_sum += pow((double) numbers[i] - avg, 2.0);
	}
	return sqrt(sqr_sum / (double) countNum);
}

void computeStatistics_run() {
	int countNum = 0;
	int min = 0;
	int max = 0;
	double sd = 0.0;
	double avg = 0.0;

	countNum = getInputNumbers();

	if (countNum != 0) {
		avg = calMeanValue(countNum);

		min = findMinimum(countNum);

		max = findMaximum(countNum);

		sd = calStandardDeviation(countNum, avg);
	}

	outputResults(countNum, avg, min, max, sd);
}
