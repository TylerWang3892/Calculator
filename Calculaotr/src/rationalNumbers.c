/********************************************************************
	Name: RationalNumbers.c	Author: Tyler Wang

	Description: Functions for rational numbers

*********************************************************************/

//start include statements
#include "pch.h"
#include "../Calculator.h"
//end include statements


//start macro decloration

//end macro decloration

/**
addFractions

	Description:
		Adds two fractions that are created using the fraciton structure. 
	Param:
		firstFraction: the first fraction of addition.
		secondFraction: the second fraction of addition.
	Return:
		summation of firstFraction and secondFraction.

	firstFraction + secondFraction = RETURN

	Error Codes: 
		0 -- success
		-1 -- sign miss missmatch, returns null


		1 -- numerator too large, returns null
		2 -- denominator too large, returns null
*/
fraction* addFractions(fraction* firstFraction, fraction* secondFraction)
{
	//makes sure signes are valid in fracitons
	if (!((firstFraction->sign == POSITIVE || firstFraction != POSITIVE) &&
		(secondFraction->sign == POSITIVE || secondFraction->sign == NEGETIVE)))
	{
		setErrorCode(-1);
		return NULL;
	}

	//variable decloration
	fraction returnFraction;
	fraction** queue = (fraction**)malloc(2 * sizeof(fraction));

	if (firstFraction->sign == secondFraction->sign)
		goto same;
	if (firstFraction->sign == POSITIVE)
	{
		if (firstFraction->numerator >= secondFraction->numerator)
		{
			returnFraction.sign = POSITIVE;
			queue[0] = firstFraction;
			queue[1] = secondFraction;
		}
		else
		{
			returnFraction.sign = NEGETIVE;
			queue[0] = secondFraction;
			queue[1] = firstFraction;
		}
	}
	else
	{
		queue[0] = secondFraction;
		queue[1] = firstFraction;
		if (firstFraction->numerator >= secondFraction->numerator)
		{
			returnFraction.sign = NEGETIVE;
			queue[0] = firstFraction;
			queue[1] = secondFraction;
		}
		else
		{
			returnFraction.sign = POSITIVE;
			queue[0] = secondFraction;
			queue[1] = firstFraction;
		}
	}

	returnFraction.denominator = firstFraction->denominator * secondFraction->denominator;
	returnFraction.numerator = queue[0]->numerator * queue[1]->denominator - queue[1]->numerator * queue[0]->denominator;
	setErrorCode(0);
	return reduce(&returnFraction, );

same:
	returnFraction.sign = firstFraction->sign;
	returnFraction.denominator = firstFraction->denominator * secondFraction->denominator;
	returnFraction.numerator = firstFraction->denominator * secondFraction->numerator + 
		secondFraction->denominator * firstFraction->numerator;
	
	setErrorCode(0);
	return reduce(&returnFraction);
	
}

/**
reduce
	Description:
		Takes in a fraction and returns it in its simplest form
	Param:
		inputFraction: fraction to input to function.
		errorCode: provied the error code for the function.
	Return:
		Reduced Fraciton
	Error Codes:
		0 -- success
		-1 -- sign miss missmatch, returns null
*/
fraction* reduce(fraction* inputFraction, char* errorCode)
{
	unsigned long long factor = gcf(inputFraction->denominator, inputFraction->numerator);

}

