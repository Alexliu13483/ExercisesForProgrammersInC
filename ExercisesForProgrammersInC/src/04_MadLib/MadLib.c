/*
 * MadLib.c
 *
 *  Created on: 2016¦~1¤ë27¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <string.h>
#include "Common/Common.h"

static char output[256];
static char noun[32];
static char adjective[32];
static char verb[32];
static char adverb[32];

void MadLib_create()
{
	output[0] = '\0';
}
void MadLib_setNoun(char * str)
{
	strcpy(noun, str);
}
void MadLib_setVerb(char * str)
{
	strcpy(verb, str);
}
void MadLib_setAdjective(char * str)
{
	strcpy(adjective, str);
}
void MadLib_setAdverb(char * str)
{
	strcpy(adverb, str);
}
char * MadLib_showOutput()
{
	return strcat(strcat(strcat(strcat(strcat(strcat(strcat(strcat(strcat(
			output, "Do you "), verb), " your "), adjective), " "), noun), " "), adverb), "? That's hilarious!");
}
char * MadLib_InputByConcole()
{
	printf("\nEnter a noun: ");
	Common_getStringFromConsole(noun);
	printf("Enter a verb: ");
	Common_getStringFromConsole(verb);
	printf("Enter a adjective: ");
	Common_getStringFromConsole(adjective);
	printf("Enter a adverb: ");
	Common_getStringFromConsole(adverb);
	printf("%s\n", MadLib_showOutput());
	return output;
}
