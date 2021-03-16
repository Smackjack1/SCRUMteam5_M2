#include "OpBranchZero.h"

OpBranchZero::OpBranchZero()
{
	this->code = "42";
}

void OpBranchZero::execute(int argument)
{
	int acc = 0;
	this->memory->read(ACC, &acc);
	if (acc == 0)
	{
		this->memory->write(PC, &argument);
	}
}
