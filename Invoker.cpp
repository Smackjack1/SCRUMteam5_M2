#include "Invoker.h"

int Invoker::executeCommand(std::string code, int argument)
{
	for (auto& x : codes)
	{
		if (x->code.compare(code) == 0)
		{
			x->execute(argument);
			
			return 0;
		}
	}
	return -1;
}
