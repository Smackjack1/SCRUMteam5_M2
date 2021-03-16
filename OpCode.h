/*
OpCode.h written by Quinton
*/
#ifndef __OPCODE__
#define __OPCODE__
#include<string>
#include"Memory.h"
//Abstract class, defines opcode classes to be used by invoker
class OpCode
{
public:
	vmMemory* memory = vmMemory::getInstance();
	std::string code;  // holds
	OpCode() = default;
	virtual std::string getCode()
	{
		return this->code;
	}
	virtual void execute(int argument) = 0;
};
#endif
