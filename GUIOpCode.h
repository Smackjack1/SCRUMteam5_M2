/*
OpCode.h written by Quinton
*/
#ifndef __GUIOPCODE__
#define __GUIOPCODE__
#include<string>
#include"Memory.h"
//Abstract class, defines opcode classes to be used by invoker
class GUIOpCode
{
public:
	vmMemory* memory = vmMemory::getInstance();
	std::string code;  // holds
	GUIOpCode() = default;
	virtual std::string getCode()
	{
		return this->code;
	}
	virtual std::string execute(int argument, std::string input) = 0; // takes an input (some string for the execute to read) returns its output if it has one
};
#endif
