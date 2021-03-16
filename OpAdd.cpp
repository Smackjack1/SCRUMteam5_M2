#include "OpAdd.h"

OpAdd::OpAdd()
{
	this->code = "30";
}

void OpAdd::execute(int argument)
{
	int accValue = 0;
	this->memory->read(ACC, &accValue);
	int memoryValue = 0;
	this->memory->read(argument, &memoryValue);
	int result = accValue + memoryValue;
	this->memory->write(ACC, &result);
}
