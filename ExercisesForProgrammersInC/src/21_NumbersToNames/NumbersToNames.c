/*
 * NumbersToNames.c
 *
 *  Created on: 2016¦~3¤ë24¤é
 *      Author: Alex.Liu
 */


void NumbersToNames_create() {
}

char * NumbersToNames_convertNumberToMonth(int num) {
	char * strMonth = "";

	switch (num) {
	case 1:
		strMonth = "January";
		break;
	case 2:
		strMonth = "February";
		break;
	case 3:
		strMonth = "March";
		break;
	case 4:
		strMonth = "April";
		break;
	case 5:
		strMonth = "May";
		break;
	case 6:
		strMonth = "June";
		break;
	case 7:
		strMonth = "July";
		break;
	case 8:
		strMonth = "August";
		break;
	case 9:
		strMonth = "September";
		break;
	case 10:
		strMonth = "October";
		break;
	case 11:
		strMonth = "November";
		break;
	case 12:
		strMonth = "December";
		break;
	default:
		break;
	}
	return strMonth;
}
