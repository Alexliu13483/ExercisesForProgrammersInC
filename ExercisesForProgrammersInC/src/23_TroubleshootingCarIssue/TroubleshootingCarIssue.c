/*
 * TroubleshootingCarIssue.c
 *
 *  Created on: 2016¦~7¤ë5¤é
 *      Author: Alex.Liu
 */

#include "Common/ConsoleIO.h"
#include "Common/Common.h"

char * question[] = {
	"Is the car silent when you turn the key? ",
	"Are the battery terminals corrected? ",
	"Does the car make a clicking noise? ",
	"Does the car crank up but fail to start? ",
	"Does the engine start and then die? ",
	"Does your car have fuel injection? "
};

char * response[] = {
	"Clean terminals and try starting again.\n",
	"Replace cables and try again.\n",
	"Replace the battery.\n",
	"Check spark plug connections.\n",
	"Check to ensure the choke is opening and closing.\n",
	"Get it in for service.\n"
};

void TroubleshootingCarIssue_creat() {

}

void TroubleshootingCarIssue_run() {
	char input[80];

	ConsoleIO_printf(question[0]);
	Common_getStringFromConsole(input);
	if (input[0] == 'y') {
		ConsoleIO_printf(question[1]);
		Common_getStringFromConsole(input);
		if (input[0] == 'y')
			ConsoleIO_printf(response[0]);
		else
			ConsoleIO_printf(response[1]);
	} else {
		ConsoleIO_printf(question[2]);
		Common_getStringFromConsole(input);
		if (input[0] == 'y')
			ConsoleIO_printf(response[2]);
		else {
			ConsoleIO_printf(question[3]);
			Common_getStringFromConsole(input);
			if (input[0] == 'y')
				ConsoleIO_printf(response[3]);
			else {
				ConsoleIO_printf(question[4]);
				Common_getStringFromConsole(input);
				if (input[0] == 'y') {
					ConsoleIO_printf(question[5]);
					Common_getStringFromConsole(input);
					if (input[0] == 'n')
						ConsoleIO_printf(response[4]);
					else
						ConsoleIO_printf(response[5]);
				} else
					ConsoleIO_printf(response[5]);

			}

		}
	}

}
