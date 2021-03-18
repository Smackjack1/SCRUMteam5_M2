/*
OpWrite.h and OpWrite.cpp writen by Tyler
*/
#ifndef __OPWRITE__
#define __OPWRITE__
#include "GUIOpCode.h"

class OpWrite : public GUIOpCode
{
public:
	OpWrite();//memory goes in the squiggly and in the constructor
	std::string execute(int argument, std::string input = ""); // input here can just be empty
};

#endif
