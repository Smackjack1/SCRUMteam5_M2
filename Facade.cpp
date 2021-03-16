#include "Facade.h"

std::string Facade::getMemory()
{
    return myMemory->dump();
}

void Facade::execute()
{
    myExecutor.CallInvoker();
}

bool Facade::addCommand(std::string command)
{
    return myInterpreter.parseCommand(command);
}
