/*
 * PizzaParty.c
 *
 *  Created on: 2016¦~2¤ë4¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>

enum {PIECE_OF_PIZZA = 8};

static int piecesEachPerson;
static int piecesLeftover;
char outputString[256];
char s_String[] = "s";

void PizzaParty_create() {
	piecesEachPerson = 0;
	piecesLeftover = 0;
	outputString[0] = '\0';
}

void PizzaParty_dividePizzas(int people, int pizzas) {
	char * pizza_s = "";
	char * piece_s = "";
	char * leftover_s = "";

	if (people == 0) {
		piecesEachPerson = 0;
		piecesLeftover = 0;
		return;
	}

	piecesEachPerson = pizzas * PIECE_OF_PIZZA / people;
	piecesLeftover = pizzas * PIECE_OF_PIZZA % people;

	if (pizzas > 1)
		pizza_s = s_String;
	if (piecesEachPerson > 1)
		piece_s = s_String;
	if (piecesLeftover > 1)
		leftover_s = s_String;

	sprintf(outputString, "%d people with %d pizza%s\nEach person gets %d piece%s of pizza.\nThere are %d leftover piece%s.",
			people, pizzas, pizza_s,
			piecesEachPerson, piece_s,
			piecesLeftover, leftover_s);

}

int PizzaParty_getPiecesEachPerson() {
	return piecesEachPerson;
}

int PizzaParty_getPiecesLeftover() {
	return piecesLeftover;
}

char * PizzaParty_getOutputString() {
	return outputString;
}

int PizzaParty_calulateNeedOfPizzas(int people, int pieceOfPizza) {
	int totalPiece = people * pieceOfPizza;

	if (totalPiece % PIECE_OF_PIZZA)
		return totalPiece / PIECE_OF_PIZZA + 1;
	return totalPiece / PIECE_OF_PIZZA;
}
