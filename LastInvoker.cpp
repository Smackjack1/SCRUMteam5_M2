#include "LastInvoker.h"

int LastInvoker::executeCommand(std::string code, int argument)
{
	for (auto& x : mathCodes)
	{
		if (x->code.compare(code) == 0)
		{
			x->execute(argument);

			return 0;
		}
	}
	return -1; // send command down the chain if we don't find it here
}
