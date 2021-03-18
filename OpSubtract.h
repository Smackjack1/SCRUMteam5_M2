/*
OpSubract.h and OpSubtract.cpp written by Quinton
*/
#ifndef __OPSUBTRACT__
#define __OPSUBTRACT__
#include "MathOpCode.h"

class OpSubtract : public MathOpCode
{
public:
	OpSubtract();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
