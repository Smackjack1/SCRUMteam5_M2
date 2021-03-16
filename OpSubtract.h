/*
OpSubract.h and OpSubtract.cpp written by Quinton
*/
#ifndef __OPSUBTRACT__
#define __OPSUBTRACT__
#include "OpCode.h"

class OpSubtract : public OpCode
{
public:
	OpSubtract();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif