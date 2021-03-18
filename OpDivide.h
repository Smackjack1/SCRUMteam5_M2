/*
OpDivide.h and OpDivide.cpp written by Tyler
*/
#ifndef __OPDIVIDE__
#define __OPDIVIDE__
#include "MathOpCode.h"

class OpDivide : public MathOpCode
{
public:
	OpDivide();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
