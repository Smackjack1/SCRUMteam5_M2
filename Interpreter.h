/*
	Interpreter.h and Interpreter.cpp written by Ethan
*/
#ifndef __INTERPRETER__
#define __INTERPRETER__

#include <string>
#include"Memory.h"
class interpreter
{
public:
	interpreter();
	~interpreter();
	bool parseCommand(std::string command);
private:
	int numbers;
	char firstChar;
	int stopCase;
	int incrementor = 0;
	int wordLength;
	bool allDigits;
	int maxMemory;

};

#endif