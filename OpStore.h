/*
OpStore.h and OpStore.cpp written by Tyler
*/
#ifndef __OPSTORE__
#define __OPSTORE__
#include "MemoryOpCode.h"

class OpStore : public MemoryOpCode
{
public:
	OpStore();//memory goes in the squiggly and in the constructor
	void execute(int argument);
};

#endif
