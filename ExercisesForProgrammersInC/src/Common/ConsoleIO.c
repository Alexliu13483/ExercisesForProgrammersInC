/*
 * ConsoleIO.c
 *
 *  Created on: 2016¦~3¤ë4¤é
 *      Author: Alex.Liu
 */

#include <stdarg.h>
#include <stdio.h>
#include <conio.h>

int ConsoleIO_printfImplement( const char * format, ... ) {
	char dest[1024 * 16];
	va_list argptr;
	va_start(argptr, format);
	vsprintf(dest, format, argptr);
	va_end(argptr);
	return printf(dest);
}

int (*ConsoleIO_printf) ( const char * format, ... ) = ConsoleIO_printfImplement;
int (* ConsoleIO_getchar) () = getchar;
int (* ConsoleIO_getch) () = getch;
int (* ConsoleIO_putchar) (int) = putchar;
