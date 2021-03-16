/*
SCRUM Team 5
Project M1
written by: Ethan Olsen
*/
#include "Interpreter.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

interpreter::interpreter() {

}

interpreter::~interpreter()
{
}

bool interpreter::parseCommand(std::string command)
{
	numbers = 0;
	stopCase = -99999; //added by kevin / Quinton
	wordLength = 5;
	allDigits = true;
	vmMemory* memory = vmMemory::getInstance();
	maxMemory = 100;

	firstChar = command.at(0);
	//test if first char is either = or -
	if (incrementor > maxMemory)
	{
		throw std::runtime_error("max memory exceeded, too many commands");
	}
	//change string to an int
	try
	{
		numbers = stoi(command);
	}
	catch (std::invalid_argument) // only want to catch invalid argument right here
	{
		throw std::runtime_error("Incorrect argument, must be an integer");
	}
	if (firstChar != '+' && firstChar != '-') {
		throw std::runtime_error("invalid first character"); // changed by Quinton, changed to throw error instead of break
	}
	//halt at command 9999, //fixed by Quinton, moved to first test case so that length is still validated without crashing on our hoa
	if (numbers == stopCase) {
		cout << "Halting" << endl;
		return false;
	}
	// error handling: length, four ints;
	if (command.length() != wordLength) {
		throw std::runtime_error("invalid input: input length"); // changed by Quinton, changed to throw error instead of break
	}


	//erase first char of the string.
	command.erase(0, 1);

	//test if they are all ints.
	for (unsigned int i = 0; i < command.length(); i++) {
		if (!isdigit(command[i])) {
			allDigits = false;
		}
	}
	if (allDigits == false) {
		throw std::runtime_error("invalid input:"); // changed by Quinton, changed to throw error instead of break
	}

	if (firstChar == '-') {
		numbers = numbers * -1;
	}

	memory->write(incrementor, &numbers);
	incrementor++;
	return true;
}
