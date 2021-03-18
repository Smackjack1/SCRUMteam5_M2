/*
OpBranchZero.h and OpBranchZero.cpp written by Quinton
*/
#ifndef __OPBRANCHZERO__
#define __OPBRANCHZERO__
#include "BranchOpCode.h"

class OpBranchZero : public BranchOpCode
{
public:
	OpBranchZero();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
