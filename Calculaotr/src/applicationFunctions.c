/********************************************************************
	Name: applicationFunctions.c	Author: Tyler Wang

	Description: 

*********************************************************************/

//start include statements
#include "pch.h"

//end include statements

int errorCode = 0;

int getErrorCode()
{
	return errorCode;
}

void setErrorCode(int newErrorCode)
{
	errorCode = newErrorCode;
}