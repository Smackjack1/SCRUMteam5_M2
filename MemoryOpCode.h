/*
OpCode.h written by Quinton
*/
#ifndef __MEMORYOPCODE__
#define __MEMORYOPCODE__
#include<string>
#include"Memory.h"
//Abstract class, defines opcode classes to be used by invoker
class MemoryOpCode
{
public:
	vmMemory* memory = vmMemory::getInstance();
	std::string code;  // holds
	MemoryOpCode() = default;
	virtual std::string getCode()
	{
		return this->code;
	}
	virtual void execute(int argument) = 0;
};
#endif
