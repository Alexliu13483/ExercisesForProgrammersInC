/*
 * PizzaPartyTest.cpp
 *
 *  Created on: 2016¦~2¤ë4¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 */



extern "C"
{
#include "08_PizzaParty/PizzaParty.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(PizzaPartyTest)
{

    void setup()
    {
    	PizzaParty_create();
    }

    void teardown()
    {

    }

};

TEST(PizzaPartyTest, NonePizzaForSharing)
{
	int people = 8;
	int pizzas = 0;

	PizzaParty_dividePizzas(people, pizzas);
	LONGS_EQUAL(0, PizzaParty_getPiecesEachPerson());
	LONGS_EQUAL(0, PizzaParty_getPiecesLeftover());
}

TEST(PizzaPartyTest, OnePizzaForSharing)
{
	int people = 8;
	int pizzas = 1;

	PizzaParty_dividePizzas(people, pizzas);
	LONGS_EQUAL(1, PizzaParty_getPiecesEachPerson());
	LONGS_EQUAL(0, PizzaParty_getPiecesLeftover());
}

TEST(PizzaPartyTest, TwoPizzasFor8Persons)
{
	int people = 8;
	int pizzas = 2;

	PizzaParty_dividePizzas(people, pizzas);
	LONGS_EQUAL(2, PizzaParty_getPiecesEachPerson());
	LONGS_EQUAL(0, PizzaParty_getPiecesLeftover());
}

TEST(PizzaPartyTest, NoPersons)
{
	int people = 0;
	int pizzas = 2;

	PizzaParty_dividePizzas(people, pizzas);
	LONGS_EQUAL(0, PizzaParty_getPiecesEachPerson());
	LONGS_EQUAL(0, PizzaParty_getPiecesLeftover());
}

TEST(PizzaPartyTest, OutputStringTest_plural)
{
	int people = 8;
	int pizzas = 2;
	char expect[] = "8 people with 2 pizzas\nEach person gets 2 pieces of pizza.\nThere are 0 leftover piece.";

	PizzaParty_dividePizzas(people, pizzas);
	STRCMP_EQUAL(expect, PizzaParty_getOutputString());
}

TEST(PizzaPartyTest, OutputStringTest_Single)
{
	int people = 8;
	int pizzas = 1;
	char expect[] = "8 people with 1 pizza\nEach person gets 1 piece of pizza.\nThere are 0 leftover piece.";

	PizzaParty_dividePizzas(people, pizzas);
	STRCMP_EQUAL(expect, PizzaParty_getOutputString());
}

TEST(PizzaPartyTest, OutputStringTest_LeftoverPlural)
{
	int people = 6;
	int pizzas = 1;
	char expect[] = "6 people with 1 pizza\nEach person gets 1 piece of pizza.\nThere are 2 leftover pieces.";

	PizzaParty_dividePizzas(people, pizzas);
	STRCMP_EQUAL(expect, PizzaParty_getOutputString());
}

