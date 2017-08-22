/*
 * ConsoleIO.h
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 *
 *  This module provides a interface that groups the APIs which access to the console.
 *  The purpose of this module is to do unit tests automatically with test doubles.
 */

#ifndef INCLUDE_COMMON_CONSOLEIO_H_
#define INCLUDE_COMMON_CONSOLEIO_H_

extern int (* ConsoleIO_printf) ( const char * format, ... );
extern int (* ConsoleIO_getchar) ();
extern int (* ConsoleIO_getch) ();
extern int (* ConsoleIO_putchar) (int);
#endif /* INCLUDE_COMMON_CONSOLEIO_H_ */
