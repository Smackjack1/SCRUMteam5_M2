#ifndef __FACADE__
#define __FACADE__
#include"Executor.h"
#include"Memory.h"
#include"Interpreter.h"
#include"OpRead.h"
#include"OpWrite.h"
class Facade
{
private:
	Executor myExecutor = Executor();
	interpreter myInterpreter = interpreter();
	vmMemory* myMemory = vmMemory::getInstance();
	OpRead reader = OpRead();
	OpWrite writer = OpWrite();
public:
	std::string getMemory();
	void execute();
	bool addCommand(std::string command);
	void incrementPC(int increment);
	std::string getCurrentOpCode();
	int getCurrentOperand();
	void opRead(std::string input); // give it the user input only, call it to execute opRead
	std::string opWrite(); // executes and returns it's required output

};
#endif
