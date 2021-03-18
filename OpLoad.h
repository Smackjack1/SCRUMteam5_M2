/*
OpLoad.h and OpLoad.cpp written by Tyler
*/
#ifndef __OPLOAD__
#define __OPLOAD__
#include "MemoryOpCode.h"

class OpLoad : public MemoryOpCode
{
public:
	OpLoad();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
