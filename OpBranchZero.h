/*
OpBranchZero.h and OpBranchZero.cpp written by Quinton
*/
#ifndef __OPBRANCHZERO__
#define __OPBRANCHZERO__
#include "OpCode.h"

class OpBranchZero : public OpCode
{
public:
	OpBranchZero();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif