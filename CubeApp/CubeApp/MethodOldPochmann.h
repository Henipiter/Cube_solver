#pragma once
#include "cubeSolver.h"

class MethodOldPochmann : public cubeSolver
{
public:
	MethodOldPochmann(char up, char front, string scramble);
	
	virtual void method();
};

