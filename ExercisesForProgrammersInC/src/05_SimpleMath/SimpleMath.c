/*
 * SimpleMath.c
 *
 *  Created on: 2016¦~1¤ë28¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "Common/Common.h"

static int sum;
static int difference;
static int product;
static int quotient;

void SimpleMath_create()
{
	sum = 0;
	difference = 0;
	product = 0;
	quotient = 0;
}
int SimpleMath_getSum()
{
	return sum;
}
int SimpleMath_getDifference()
{
	return difference;
}
int SimpleMath_getProduct()
{
	return product;
}
int SimpleMath_getQuotient()
{
	return quotient;
}
void SimpleMath_calTwoTextNumbers(char * number1, char *number2)
{
	int n1 = 0;
	int n2 = 0;

	n1 = atoi(number1);
	n2 = atoi(number2);
	sum = n1 + n2;
	difference = n1 - n2;
	product = n1 * n2;
	if (n2)
		quotient = n1 / n2;
	else
		quotient = INT_MAX;
}
void SimpleMath_inputFromConsole()
{
	char number1[16];
	char number2[16];

	printf("\n");
	do {
		printf("What is the first number? ");
		Common_getStringFromConsole(number1);
	} while (!Common_isIntegerString(number1));
	do {
		printf("What is the second number? ");
		Common_getStringFromConsole(number2);
	} while (!Common_isIntegerString(number2));
	SimpleMath_calTwoTextNumbers(number1, number2);
	printf("%s + %s = %d\n%s - %s = %d\n%s * %s = %d\n%s / %s = %d\n",
			number1, number2, sum,
			number1, number2, difference,
			number1, number2, product,
			number1, number2, quotient
			);
}
