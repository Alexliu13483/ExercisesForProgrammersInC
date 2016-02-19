/*
 * CurrencyConversion.c
 *
 *  Created on: 2016¦~2¤ë19¤é
 *      Author: Alex.Liu
 */

#include <math.h>

void CurrencyConversion_create() {

}

double CurrencyConversion_convert(double dollar, double rate) {
	return round(dollar * rate) / 100.0;
}
