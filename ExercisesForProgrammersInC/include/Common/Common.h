/*
 * Common.h
 *
 *  Created on: 2016¦~1¤ë27¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_COMMON_COMMON_H_
#define INCLUDE_COMMON_COMMON_H_
#include <stdbool.h>

void Common_getStringFromConsole(char * str);
bool Common_isIntegerString(char * str);
bool Common_isDoubleString(char * str);
void Common_getStringFromConsoleAndNoEcho(char * str);
extern int (* Common_rand) ();

#endif /* INCLUDE_COMMON_COMMON_H_ */
