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

typedef struct {
	int min;
	int max;
	double sd;
	double avg;
} Statistic_Result;

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

static void calStatistics(int countNum, Statistic_Result * results) {
	if (countNum != 0) {
		results->avg = calMeanValue(countNum);
		results->min = findMinimum(countNum);
		results->max = findMaximum(countNum);
		results->sd = calStandardDeviation(countNum, results->avg);
	}
}

void computeStatistics_run_interact() {
	int countNum = 0;
	Statistic_Result result;
	result.min = 0;
	result.max = 0;
	result.sd = 0.0;
	result.avg = 0.0;

	countNum = getInputNumbers();

	calStatistics(countNum, &result);

	outputResults(countNum, result.avg, result.min, result.max, result.sd);
}

static void stripNewLine(char * inString) {
	for (int i = 0; i < 100; i++)
		if (inString[i] == '\0' || inString[i] == '\n' || inString[i] == '\r') {
			inString[i] = '\0';
			break;
		}
}

static int readNumbersFromFile(char * inString, FILE* file) {
	int countNum = 0;
	while (countNum < MAX_ARRAY_NUMBER) {
		if (fgets(inString, 100, file) == NULL)
			break;

		stripNewLine(inString);
		if (Common_isIntegerString(inString)) {
			numbers[countNum] = atoi(inString);
			countNum++;
		}
	}
	return countNum;
}

void computeStatistics_run_file(char * filename) {
	FILE * file = fopen(filename, "r");
	char inString[100];
	int countNum = 0;
	Statistic_Result result;
	result.min = 0;
	result.max = 0;
	result.sd = 0.0;
	result.avg = 0.0;

	if (file == NULL) {
		ConsoleIO_printf("Open file [%s] failed!!!\n", filename);
		return;
	}

	countNum = readNumbersFromFile(inString, file);
	fclose(file);

	calStatistics(countNum, &result);

	outputResults(countNum, result.avg, result.min, result.max, result.sd);
}
