/*
 * PizzaParty.h
 *
 *  Created on: 2016¦~2¤ë4¤é
 *      Author: Alex.Liu
 */

#ifndef INCLUDE_08_PIZZAPARTY_PIZZAPARTY_H_
#define INCLUDE_08_PIZZAPARTY_PIZZAPARTY_H_

void PizzaParty_create();
void PizzaParty_dividePizzas(int people, int pizzas);
int PizzaParty_getPiecesEachPerson();
int PizzaParty_getPiecesLeftover();
char * PizzaParty_getOutputString();
int PizzaParty_calulateNeedOfPizzas(int people, int pieceOfPizza);

#endif /* INCLUDE_08_PIZZAPARTY_PIZZAPARTY_H_ */
