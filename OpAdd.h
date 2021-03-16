/*
OpAdd.h and OpAdd.cpp written by Quinton
*/
#ifndef __OPADD__
#define __OPADD__
#include "OpCode.h"

class OpAdd : public OpCode
{
public:
	OpAdd();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif