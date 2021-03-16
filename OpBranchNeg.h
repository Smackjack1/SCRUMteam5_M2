/*
OpBranchNeg.h and OpBranchNeg.cpp written by Quinton
*/
#ifndef __OPBRANCHNEG__
#define __OPBRANCHNEG__
#include "OpCode.h"

class OpBranchNeg : public OpCode
{
public:
	OpBranchNeg();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif