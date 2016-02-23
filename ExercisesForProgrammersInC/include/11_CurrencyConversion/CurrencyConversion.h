/*
 * CurrencyConversion.h
 *
 *  Created on: 2016¦~2¤ë19¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_CURRENCYCONVERSION_H_
#define INCLUDE_CURRENCYCONVERSION_H_

typedef enum {
	US,
	EU,
	TW,
	USER_DEF
} CountryCode;

void CurrencyConversion_create();
double CurrencyConversion_convertToUS_Dollars(double dollar, CountryCode country);
void CurrencyConversion_updateConversionRate(CountryCode country, double rate);
double CurrencyConversion_getConversionRate(CountryCode);
#endif /* INCLUDE_CURRENCYCONVERSION_H_ */
