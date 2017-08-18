/*
 * passwordGenerator.c
 *
 *  Created on: 2017¦~8¤ë18¤é
 *      Author: Alex.Liu
 */

#include "Common/Common.h"
#include "Common/ConsoleIO.h"

void passwordGenerator_create() {

}

void passwordGenerator_run() {
	char expect[] =
			"What's the minimum length 0\n"
			"How many special characters 0\n"
			"How many numbers 0\n"
			"Your password is\n"
			"0\n";
	ConsoleIO_printf("%s",expect);
}
