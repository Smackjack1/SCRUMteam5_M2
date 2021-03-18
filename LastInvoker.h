/*
Invoker.h and Invoker.cpp written by Quinton
*/
#ifndef __LASTINVOKER__
#define __LASTINVOKER__
#include"MemoryOpCode.h"
#include"MathOpCode.h"
#include"OpAdd.h"
#include"OpRead.h"
#include<vector>
#include<iostream>
#include<string>
class LastInvoker
{
private:
	std::vector<MathOpCode*> mathCodes = { new OpAdd()};
public:
	LastInvoker() = default;
	int executeCommand(std::string code, int argument);

};

#endif
