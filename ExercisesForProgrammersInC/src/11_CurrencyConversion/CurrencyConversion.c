/*
 * CurrencyConversion.c
 *
 *  Created on: 2016�~2��19��
 *      Author: Alex.Liu
 */

#include <math.h>

void CurrencyConversion_create() {

}

double CurrencyConversion_convert(double dollar, double rate) {
	return round(dollar * rate) / 100.0;
}
