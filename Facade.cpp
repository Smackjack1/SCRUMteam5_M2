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

void Facade::incrementPC(int increment = 1)
{
    int currentPC = 0;
    myMemory->read(PC, &currentPC);
    currentPC += increment; // fixed by Quinton, was calling &mainmem which cannot be done, now it has a local variable that stores pc value, then increments by 1 and writes new value to PC
    myMemory->write(PC, &currentPC);
}

std::string Facade::getCurrentOpCode()
{
    return myExecutor.GetOpcode();
}

int Facade::getCurrentOperand()
{
    return myExecutor.GetOperand();
}
