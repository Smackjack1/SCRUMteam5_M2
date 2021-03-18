#include "MathInvoker.h"

int MathInvoker::executeCommand(std::string code, int argument)
{
	for (auto& x : codes)
	{
		if (x->code.compare(code) == 0)
		{
			x->execute(argument);

			return 0;
		}
	}
	return branchInvoker.executeCommand(code, argument); // send command down the chain if we don't find it here
}
