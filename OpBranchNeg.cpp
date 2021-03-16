#include "OpBranchNeg.h"

OpBranchNeg::OpBranchNeg()
{
	this->code = "41";
}

void OpBranchNeg::execute(int argument)
{
	int acc = 0;
	this->memory->read(ACC, &acc);
	if (acc < 0)
	{
		this->memory->write(PC, &argument);
	}
}
