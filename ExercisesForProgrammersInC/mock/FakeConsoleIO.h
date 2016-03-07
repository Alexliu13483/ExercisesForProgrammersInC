/*
 * FakeConsoleIO.h
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */

#ifndef MOCK_FAKECONSOLEIO_H_
#define MOCK_FAKECONSOLEIO_H_

#include "Common/ConsoleIO.h"

void FakeConsoleIO_create();
int FakeConsoleIO_printf( const char * format, ... );
char * FakeConsoleIO_getOutputString();
int FakeConsoleIO_getchar();
void FakeConsoleIO_setKeyInBuffer(char * InputKeyStrokes);
int FakeConsoleIO_getch();

#endif /* MOCK_FAKECONSOLEIO_H_ */
