/*
Invoker.h and Invoker.cpp written by Quinton
*/
#ifndef __MEMORYINVOKER__
#define __MEMORYINVOKER__
#include "MathInvoker.h"
#include"OpLoad.h"
#include"OpStore.h"
#include<vector>
#include<iostream>
#include<string>
class MemoryInvoker
{
private:
	MathInvoker mathInvoker = MathInvoker();
	std::vector<MemoryOpCode*> codes = {new OpLoad(), new OpStore()};
public:
	MemoryInvoker() = default;
	int executeCommand(std::string code, int argument);
		
};

#endif
