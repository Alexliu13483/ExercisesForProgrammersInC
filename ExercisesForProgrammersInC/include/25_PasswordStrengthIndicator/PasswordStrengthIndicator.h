/*
 * PasswordStrengthIndicator.h
 *
 *  Created on: 2016¦~7¤ë7¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_25_PASSWORDSTRENGTHINDICATOR_PASSWORDSTRENGTHINDICATOR_H_
#define INCLUDE_25_PASSWORDSTRENGTHINDICATOR_PASSWORDSTRENGTHINDICATOR_H_

typedef enum {
	INVALID,
	VERY_WEAK,
	WEAK,
	AVERAGE,
	STRONG,
	VERY_STRONG
} PasswordStrength;

#define MINIMUN_PASSWORD_LENGTH		4
#define MAXIMUN_PASSWORD_LENGTH		12


void PasswordStrengthIndicator_create();
PasswordStrength PasswordStrengthIndicator_passwordValidator(char * password);

#endif /* INCLUDE_25_PASSWORDSTRENGTHINDICATOR_PASSWORDSTRENGTHINDICATOR_H_ */
