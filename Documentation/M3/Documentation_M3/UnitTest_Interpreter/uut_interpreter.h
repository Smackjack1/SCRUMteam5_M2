#pragma once

#ifndef __UUT_INTERPRETER__
#define __UUT_INTERPRETER__
#include <string>
#include"Memory.h"


class uut_interpreter
{
public:
	bool parseCommand(std::string command);
private:
	int stopCase;
	int incrementor = 0;
	int wordLength;
	bool allDigits;
	int maxMemory;
	std::string firstFourDigits = ""; // this is the first half of a 6 digit decimal input
	bool timeForSixDigit = false;
	bool firstRun = true;

};

#endif

