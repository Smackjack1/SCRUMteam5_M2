/*
OpCode.h written by Quinton
*/
#ifndef __MATHOPCODE__
#define __MATHOPCODE__
#include<string>
#include"Memory.h"
//Abstract class, defines opcode classes to be used by invoker
class MathOpCode
{
public:
	vmMemory* memory = vmMemory::getInstance();
	std::string code;  // holds
	MathOpCode() = default;
	virtual std::string getCode()
	{
		return this->code;
	}
	virtual void execute(int argument) = 0;
};
#endif
