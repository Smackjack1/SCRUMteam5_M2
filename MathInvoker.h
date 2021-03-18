/*
Invoker.h and Invoker.cpp written by Quinton
*/
#ifndef __MathINVOKER__
#define __MathINVOKER__
#include"MathOpCode.h"
#include "BranchInvoker.h"
#include"OpSubtract.h"
#include"OpDivide.h"
#include"OpMultiply.h"
#include<vector>
#include<iostream>
#include<string>
class MathInvoker
{
private:
	BranchInvoker branchInvoker = BranchInvoker();
	std::vector<MathOpCode*> codes = {new OpSubtract(), new OpDivide(), new OpMultiply()};
public:
	MathInvoker() = default;
	int executeCommand(std::string code, int argument);
};

#endif
