/*
OpAdd.h and OpAdd.cpp written by Quinton
*/
#ifndef __OPADD__
#define __OPADD__
#include "MathOpCode.h"

class OpAdd : public MathOpCode
{
public:
	OpAdd();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
