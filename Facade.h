#ifndef __FACADE__
#define __FACADE__
#include"Executor.h"
#include"Memory.h"
#include"Interpreter.h"
class Facade
{
private:
	Executor myExecutor = Executor();
	interpreter myInterpreter = interpreter();
	vmMemory* myMemory = vmMemory::getInstance();
public:
	std::string getMemory();
	void execute();
	bool addCommand(std::string command);
	void incrementPC(int increment = 1);
	std::string getCurrentOpCode();
	int getCurrentOperand();
};
#endif
