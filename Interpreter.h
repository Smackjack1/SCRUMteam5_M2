/*
	Interpreter.h and Interpreter.cpp written by Ethan


	<Interpreter> Interpreter.h
The Interpreter takes the input of the program, runs error checks to make sure it is valid input then puts it into memory.
Int numbers - input is stored once it is saved as an integer.
string word - this is where the argument is stored once it is taken in as a string
Int stopCase -What that the Interpreter looks for to halt taking the programming
Int incrementor - this counts how many words get put into memory
Int wordLength – The value of the maximum word length to accept
allDigits - this is true after the first character is off and the rest of the word are digits
vmMemory* memory = vmMemory::getInstance();- a pointer to access the memory class
maxMemory - int, the maximum amount of words that can be put into memory.
Precondition: Interpreter is called to start taking input commands.
Postcondition: All the program input has been checked for errors and input into memory.
Functions:
bool interpreter::parseCommand(std::string command)
	returns true if the word was valid and entered into the main memory.

*/



#ifndef __INTERPRETER__
#define __INTERPRETER__
#include <string>
#include"Memory.h"


class interpreter
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
