/*
Ececutor.cpp and Executor.h written by Kevin
*/
#ifndef __EXECUTOR__
#define __EXECUTOR__


#include"Invoker.h"
#include"Memory.h"
#include<string>

using namespace std;

class Executor
{
	int counter;
	Invoker InvokerInstance; //fixed by Quinton, this class needs to actually contain invoker, not take it in
	vmMemory* MemInstance = vmMemory::getInstance(); //fixed by Quinton, needed to not be static, had to call getInstance(), also needs to be a private variable
public:
	Executor();
	string GetOpcode();
	int GetOperand();
	void CallInvoker();
};

#endif
