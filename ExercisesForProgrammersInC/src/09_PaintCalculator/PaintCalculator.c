/*
 * PaintCalculator.c
 *
 *  Created on: 2016¦~2¤ë16¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <math.h>

#define AREA_TO_PAINT_RATE	350.0

void PaintCalculator_creat() {

}

int PaintCalculator_calculatePaintNeed(float area) {
	return ceil(area / AREA_TO_PAINT_RATE);
}

char * PaintCalculator_OutputText(float area) {
	static char outputTxt[80];
	int paintGallons;

	paintGallons = PaintCalculator_calculatePaintNeed(area);
	sprintf(outputTxt, "You will need to purchase %d gallons of\npaint to cover %d square feet.", paintGallons, (int)area);
	return outputTxt;
}
