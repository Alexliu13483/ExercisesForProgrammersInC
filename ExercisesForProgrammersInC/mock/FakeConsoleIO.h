/*
 * FakeConsoleIO.h
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */

#ifndef MOCK_FAKECONSOLEIO_H_
#define MOCK_FAKECONSOLEIO_H_

#include "Common/ConsoleIO.h"

#define INIT_FAKE_CONSOLE()		    	FakeConsoleIO_create();\
										UT_PTR_SET(ConsoleIO_printf, FakeConsoleIO_printf);\
										UT_PTR_SET(ConsoleIO_getchar, FakeConsoleIO_getchar);\
										UT_PTR_SET(ConsoleIO_getch, FakeConsoleIO_getch);\
										UT_PTR_SET(ConsoleIO_putchar, FakeConsoleIO_putchar)

void FakeConsoleIO_create();
int FakeConsoleIO_printf( const char * format, ... );
char * FakeConsoleIO_getOutputString();
int FakeConsoleIO_getchar();
void FakeConsoleIO_setKeyInBuffer(char * InputKeyStrokes);
int FakeConsoleIO_getch();
int FakeConsoleIO_putchar(int);

#endif /* MOCK_FAKECONSOLEIO_H_ */
