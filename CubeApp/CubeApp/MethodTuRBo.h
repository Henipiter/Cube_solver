#pragma once
#include "cubeSolver.h"
class MethodTuRBo : public cubeSolver
{
	MethodTuRBo(char up, char front, string scramble);

	virtual void method();
};

