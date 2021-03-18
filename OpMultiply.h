/*
OpMultiply.h and OpMultiply.cpp written by Tyler
*/
#ifndef __OPMULTIPLY__
#define __OPMULTIPLY__
#include "MathOpCode.h"

class OpMultiply : public MathOpCode
{
public:
	OpMultiply();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
