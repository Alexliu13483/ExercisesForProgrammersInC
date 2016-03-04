/*
 * FakeConsoleIO.h
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */

#ifndef MOCK_FAKECONSOLEIO_H_
#define MOCK_FAKECONSOLEIO_H_

#include "Common/ConsoleIO.h"

int FakeConsoleIO_printf( const char * format, ... );
char * FakeConsoleIO_getOutputString();

#endif /* MOCK_FAKECONSOLEIO_H_ */
