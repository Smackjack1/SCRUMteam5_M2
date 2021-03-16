/*
OpBranch.h and OpBranch.cpp written by Quinton
*/
#ifndef __OPBRANCH__
#define __OPBRANCH__
#include "OpCode.h"

class OpBranch : public OpCode
{
public:
	OpBranch();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif