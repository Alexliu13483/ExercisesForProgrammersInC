/*
 * NumbersToNames.c
 *
 *  Created on: 2016¦~3¤ë24¤é
 *      Author: Alex.Liu
 */

const char * dictionaryMonth[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
};

void NumbersToNames_create() {
}

char * NumbersToNames_convertNumberToMonth(int num) {
	if (num < 1 || num > 12)
		return "";

	return (char *)dictionaryMonth[num - 1];
}
