#include "MemoryInvoker.h"

int MemoryInvoker::executeCommand(std::string code, int argument)
{
	for (auto& x : codes)
	{
		if (x->code.compare(code) == 0)
		{
			x->execute(argument);
			
			return 0;
		}
	}
	return mathInvoker.executeCommand(code,argument); // send command down the chain if we don't find it here
}
