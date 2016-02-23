/*
 * CurrencyConversion.c
 *
 *  Created on: 2016¦~2¤ë19¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <math.h>
#include "11_CurrencyConversion/CurrencyConversion.h"

typedef struct {
	CountryCode country;
	double rate;
} CurrencyConversionRate;

static CurrencyConversionRate conversionRateTable[] = {
	{US, 100.0},
	{EU, 120.0},
	{TW, 3.03},
	{USER_DEF, 100}
};

void CurrencyConversion_create() {

}

double CurrencyConversion_convertToUS_Dollars(double dollar, CountryCode country) {
	double rate;

	rate = CurrencyConversion_getConversionRate(country);
	return round(dollar * rate) / 100.0;
}

static int lookUpConversionRateTable(CountryCode country) {
	int sizeOfTable = sizeof(conversionRateTable) / sizeof(CurrencyConversionRate);

	for (int i = 0; i < sizeOfTable; i++)
		if (conversionRateTable[i].country == country)
			return i;
	return -1; // error: nothing found.
}

void CurrencyConversion_updateConversionRate(CountryCode country, double rate) {
	int index;

	index = lookUpConversionRateTable(country);
	if (index >= 0)
		conversionRateTable[index].rate = rate;
	else
		conversionRateTable[index].rate = 0.0;
}

double CurrencyConversion_getConversionRate(CountryCode country) {
	int index;

	index = lookUpConversionRateTable(country);
	if (index >= 0)
		return conversionRateTable[index].rate;

	return 0.0;
}
