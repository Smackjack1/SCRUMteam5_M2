#include "OpBranch.h"

OpBranch::OpBranch()
{
	this->code = "40";
}

void OpBranch::execute(int argument)
{
	int acc = 0;
	this->memory->read(ACC, &acc);
	this->memory->write(PC, &argument);
}
