/******************************************************
	Name: pch.h		Author: N/A

	Description: An autogeneratred precompiled header file
******************************************************/

#pragma once

#ifdef DEBUG
#define console(str) printf(str)
#define stop system("pause");
#else
#define console(str) 
#define stop
#endif

//include statements start

#include<stdlib.h>
#include<Windows.h>

//include statements end

int getErrorCode();
void setErrorCode(int newErrorCode);
//end of PCH