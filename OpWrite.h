/*
OpWrite.h and OpWrite.cpp writen by Tyler
*/
#ifndef __OPWRITE__
#define __OPWRITE__
#include "OpCode.h"

class OpWrite : public OpCode
{
public:
	OpWrite();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif