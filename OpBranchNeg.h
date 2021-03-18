/*
OpBranchNeg.h and OpBranchNeg.cpp written by Quinton
*/
#ifndef __OPBRANCHNEG__
#define __OPBRANCHNEG__
#include "BranchOpCode.h"

class OpBranchNeg : public BranchOpCode
{
public:
	OpBranchNeg();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
