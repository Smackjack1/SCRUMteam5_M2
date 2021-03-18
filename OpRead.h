/*
OpRead.h and OpRead.cpp written by Tyler
*/
#ifndef __OPREAD__
#define __OPREAD__
#include "GUIOpCode.h"
//#include memory.h
class OpRead : public GUIOpCode
{
public:
	//std::string code = "10";
	OpRead();
	std::string execute(int argument, std::string input);
};

#endif
