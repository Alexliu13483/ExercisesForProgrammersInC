/*
 * KarvonenHeartRate.c
 *
 *  Created on: 2016¦~7¤ë21¤é
 *      Author: Alex.Liu
 */
#include <math.h>
#include <stdlib.h>
#include "Common/ConsoleIO.h"
#include "Common/Common.h"

void KarvonenHeartRate_create() {

}

int KarvonenHeartRate_calculate(int age, int restingHR, int intensity) {
	return (int)round((((220.0 - age) - restingHR) * intensity / 100.0) + restingHR);
}

void KarvonenHeartRate_run() {
	char input[80];
	int age;
	int restingHR;
	int thr;

	do {
		ConsoleIO_printf("Resting Pulse: ");
		Common_getStringFromConsole(input);
	}while (Common_isIntegerString(input) == false);
	restingHR = atoi(input);

	do {
		ConsoleIO_printf("Age: ");
		Common_getStringFromConsole(input);
	} while(Common_isIntegerString(input) == false);
	age = atoi(input);

	ConsoleIO_printf("\nIntensity   | Rate\n");
	ConsoleIO_printf("------------|--------\n");
	for (int i = 55; i < 100; i += 5) {
		thr = KarvonenHeartRate_calculate(age, restingHR, i);
		ConsoleIO_printf("%d\%         | %3d bpm\n", i, thr);
	}
}
