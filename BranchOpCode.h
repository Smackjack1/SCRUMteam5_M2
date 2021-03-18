/*
OpCode.h written by Quinton
*/
#ifndef __BRANCHOPCODE__
#define __BRANCHOPCODE__
#include<string>
#include"Memory.h"
//Abstract class, defines opcode classes to be used by invoker
class BranchOpCode
{
public:
	vmMemory* memory = vmMemory::getInstance();
	std::string code;  // holds
	BranchOpCode() = default;
	virtual std::string getCode()
	{
		return this->code;
	}
	virtual void execute(int argument) = 0;
};
#endif
