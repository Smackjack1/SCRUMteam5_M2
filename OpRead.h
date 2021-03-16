/*
OpRead.h and OpRead.cpp written by Tyler
*/
#ifndef __OPREAD__
#define __OPREAD__
#include "OpCode.h"
//#include memory.h
class OpRead : public OpCode
{
public:
	//std::string code = "10";
	OpRead();
	void execute(int argument);
};

#endif