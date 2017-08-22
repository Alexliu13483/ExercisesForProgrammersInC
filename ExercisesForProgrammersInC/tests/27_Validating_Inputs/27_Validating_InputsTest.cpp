/*
 * 27_Validating_InputsTest.cpp
 *
 *  Created on: 2016¦~7¤ë12¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 *  DOUBLES_EQUAL(expected,actual,threshold);
 */



extern "C"
{
#include "FakeConsoleIO.h"
#include "27_Validating_Inputs/Validating_Inputs.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Validating_InputsTest)
{

    void setup()
    {
    	INIT_FAKE_CONSOLE();
    	ValidateInput_create();
    }

    void teardown()
    {

    }

};

TEST(Validating_InputsTest, FirstExampleTest)
{
	char expect[] =
			"Enter the first name: J\n"
			"Enter the last name: \n"
			"Enter the ZIP code: ABCDE\n"
			"Enter an employee ID: A12-1234\n"
			"\"J\" is not a valid first name. It is too short.\n"
			"The last name must be filled in.\n"
			"The ZIP code must be numeric.\n"
			"A12-1234 is not a valid ID.\n";
	char input[] = "J\n\nABCDE\nA12-1234\n";

	FakeConsoleIO_setKeyInBuffer(input);

	ValidateInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(Validating_InputsTest, SecondExampleTest)
{
	char expect[] =
			"Enter the first name: Jimmy\n"
			"Enter the last name: James\n"
			"Enter the ZIP code: 55555\n"
			"Enter an employee ID: TK-421\n"
			"There were no errors found.\n";
	char input[] = "Jimmy\nJames\n55555\nTK-421\n";

	FakeConsoleIO_setKeyInBuffer(input);

	ValidateInput_run();
	STRCMP_EQUAL(expect, FakeConsoleIO_getOutputString());
}

TEST(Validating_InputsTest, NameNullTest)
{
	VALID_INPUT_RESULT expect = VALID_INPUT_NULL;
	char input[] = "";

	LONGS_EQUAL(expect, ValidateInput_ValidateName(input));
}

TEST(Validating_InputsTest, NameFilledTest)
{
	VALID_INPUT_RESULT expect = VALID_INPUT_OK;
	char input[] = "John";

	LONGS_EQUAL(expect, ValidateInput_ValidateName(input));
}

TEST(Validating_InputsTest, ShortNameTest)
{
	char input[] = "J";
	VALID_INPUT_RESULT expect = VALID_INPUT_SHORT_NAME;

	LONGS_EQUAL(expect, ValidateInput_ValidateName(input));
}


TEST(Validating_InputsTest, NonAlphabetNameTest)
{
	char input[] = "J0hn";
	VALID_INPUT_RESULT expect = VALID_INPUT_NON_ALPHABET;

	LONGS_EQUAL(expect, ValidateInput_ValidateName(input));
}

TEST(Validating_InputsTest, ID_OK_Test)
{
	char input[] = "AA-1234";
	VALID_INPUT_RESULT expect = VALID_INPUT_OK;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, IncorrectID_length_Test)
{
	char input[] = "1234";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ID;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, IncorrectID_Header_Test)
{
	char input[] = "23-1234";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ID;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, IncorrectID_Hyphen_Test)
{
	char input[] = "AA+1234";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ID;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, IncorrectID_Number_Test)
{
	char input[] = "AA-12RR";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ID;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, ID_Null_Test)
{
	char input[] = "";
	VALID_INPUT_RESULT expect = VALID_INPUT_OK;

	LONGS_EQUAL(expect, ValidateInput_ValidateID(input));
}

TEST(Validating_InputsTest, ZIP_OK_Test)
{
	char input[] = "12345";
	VALID_INPUT_RESULT expect = VALID_INPUT_OK;

	LONGS_EQUAL(expect, ValidateInput_ValidateZIP(input));
}

TEST(Validating_InputsTest, Incorrect_ZIP_Length_Test)
{
	char input[] = "12";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ZIP;

	LONGS_EQUAL(expect, ValidateInput_ValidateZIP(input));
}

TEST(Validating_InputsTest, Incorrect_ZIP_Test)
{
	char input[] = "1225*";
	VALID_INPUT_RESULT expect = VALID_INPUT_WRONG_ZIP;

	LONGS_EQUAL(expect, ValidateInput_ValidateZIP(input));
}

TEST(Validating_InputsTest, ZIP_NULL_Test)
{
	char input[] = "";
	VALID_INPUT_RESULT expect = VALID_INPUT_OK;

	LONGS_EQUAL(expect, ValidateInput_ValidateZIP(input));
}





