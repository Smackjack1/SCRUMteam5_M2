/*
Invoker.h and Invoker.cpp written by Quinton
*/
#ifndef __BRANCHINVOKER__
#define __BRANCHINVOKER__
#include"LastInvoker.h"
#include "BranchOpCode.h"
#include"OpBranch.h"
#include"OpBranchNeg.h"
#include"OpBranchZero.h"
#include<vector>
#include<iostream>
#include<string>
class BranchInvoker
{
private:
	LastInvoker lastInvoker = LastInvoker();
	std::vector<BranchOpCode*> codes = {new OpBranch(), new OpBranchNeg(), new OpBranchZero()};
public:
	BranchInvoker() = default;
	int executeCommand(std::string code, int argument);

};

#endif
