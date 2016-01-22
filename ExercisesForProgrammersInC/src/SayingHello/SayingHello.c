/*
 * SayingHello.c
 *
 *  Created on: 2016¦~1¤ë20¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char * output;

void SayingHello_Create()
{
	output = "";
}

void SayingHello_SetInputName(char * name)
{
	output = calloc(sizeof(char), strlen(name) + 27);
	sprintf(output, "Hello, %s, nice to meet you!", name);
}

char * SayingHello_GetOutput()
{
	return output;
}

void SayingHello_InputAndOuputOnScreen()
{
	char name[80];

	printf("What is your name? ");
	scanf("%79s", name);
	SayingHello_SetInputName(name);
	printf("%s", output);
}
