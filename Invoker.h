/*
Invoker.h and Invoker.cpp written by Quinton
*/
#ifndef __INVOKER__
#define __INVOKER__
#include "OpCode.h"
#include"OpRead.h"
#include"OpWrite.h"
#include"OpLoad.h"
#include"OpStore.h"
#include"OpAdd.h"
#include"OpSubtract.h"
#include"OpDivide.h"
#include"OpBranch.h"
#include"OpBranchNeg.h"
#include"OpBranchZero.h"
#include"OpMultiply.h"
#include<vector>
#include<iostream>
#include<string>
class Invoker
{
private:
	std::vector<OpCode*> codes = { new OpRead(), new OpWrite(),new OpLoad(),new OpStore(),new OpAdd(),new OpSubtract(),
								   new OpDivide(),new OpMultiply(),new OpBranch(),new OpBranchNeg(),new OpBranchZero()};
public:
	Invoker() = default;
	int executeCommand(std::string code, int argument);
		
};

#endif
