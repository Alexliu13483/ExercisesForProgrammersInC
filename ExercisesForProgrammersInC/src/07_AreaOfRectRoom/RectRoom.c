/*
 * RectRoom.c
 *
 *  Created on: 2016¦~2¤ë2¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include "Common/Common.h"

#define SQUARE_FEET_TO_SQUARE_METER_RATIO	0.09290304

char outputString[256];

void RectRoom_create() {
	outputString[0] = '\0';
}

float RectRoom_calAreaInFeet(float length, float width) {
	return length * width;
}

double RectRoom_convertSquareFeetToSquareMeter(float area) {
	return area * 0.09290304;
}

void RectRoom_calAreaInFeetFromConsole() {
	char lengthStr[80];
	char widthStr[80];
	float length;
	float width;
	float area;
	float areaInSquareMeter;

	do {
		printf("\nWhat is the length of the room in feet? ");
		Common_getStringFromConsole(lengthStr);
	} while (!Common_isDoubleString(lengthStr));
	length = atof(lengthStr);

	do {
		printf("What is the width of the room in feet? ");
		Common_getStringFromConsole(widthStr);
	} while (!Common_isDoubleString(widthStr));
	width = atof(widthStr);

	area = RectRoom_calAreaInFeet(length, width);
	areaInSquareMeter = RectRoom_convertSquareFeetToSquareMeter(area);
	sprintf(outputString,"You entered dimensions of %s feet by %s feet.\nThe area is \n%0.0f square feet\n%0.3f square meters\n",
			lengthStr, widthStr,
			area, areaInSquareMeter);
	printf("%s", outputString);
}

char * RectRoom_getConsoleOutput() {
	return outputString;
}
