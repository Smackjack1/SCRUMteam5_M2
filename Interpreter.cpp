/*
SCRUM Team 5
Project M1
written by: Ethan Olsen
*/
#include "pch.h"
#include "Interpreter.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool interpreter::parseCommand(std::string command)
{
	if (!timeForSixDigit)
	{
		int numbers = 0;
		stopCase = -99999; //added by kevin / Quinton
		wordLength = 5;
		allDigits = true;
		vmMemory* memory = vmMemory::getInstance();
		maxMemory = 100;
		if (command == "") // added by Q, need to look for empty input
		{
			throw std::runtime_error("no empty lines are allowed");
		}
		char firstChar = command.at(0);
		//test if first char is either = or -
		if (incrementor > maxMemory)
		{
			throw std::runtime_error("max memory exceeded, too many commands");
		}
		//here we see if there will be six digits of input for the next command
		if (command == "ZZZZ")
		{
			timeForSixDigit = true; // set our boolean to true so the next sequence of commands will run correctly
			return true; // leave
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
	else if (timeForSixDigit)
	{
		if (firstRun) // need a second set of booleans since we will hit this code twice
		{
			int numbers = 0;
			stopCase = -99999; //added by kevin / Quinton
			wordLength = 5;
			allDigits = true;
			vmMemory* memory = vmMemory::getInstance();
			maxMemory = 100;
			if (command == "") // added by Q, need to look for empty input
			{
				throw std::runtime_error("no empty lines are allowed");
			}
			char firstChar = command.at(0);
			//test if first char is either = or -
			if (incrementor > maxMemory)
			{
				throw std::runtime_error("max memory exceeded, too many commands");
			}
			//here we see if there will be six digits of input for the next command
			if (command == "ZZZZ")
			{
				timeForSixDigit = true; // set our boolean to true so the next sequence of commands will run correctly
				return true; // leave
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
			firstFourDigits = std::to_string(numbers);
			firstRun = false;
			return true;
		}
		else if (!firstRun)
		{
			int numbers = 0;
			stopCase = -99999; //added by kevin / Quinton
			wordLength = 4; // 4 because we no longer have -/+
			allDigits = true;
			vmMemory* memory = vmMemory::getInstance();
			maxMemory = 100;
			if (command == "") // added by Q, need to look for empty input
			{
				throw std::runtime_error("no empty lines are allowed");
			}
			//test if first char is either = or -
			if (incrementor > maxMemory)
			{
				throw std::runtime_error("max memory exceeded, too many commands");
			}
			//here we see if there will be six digits of input for the next command
			//change string to an int
			try
			{
				numbers = stoi(command);
			}
			catch (std::invalid_argument) // only want to catch invalid argument right here
			{
				throw std::runtime_error("Incorrect argument, must be an integer");
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


			//test if they are all ints.
			for (unsigned int i = 0; i < command.length(); i++) {
				if (!isdigit(command[i])) {
					allDigits = false;
				}
			}
			if (allDigits == false) {
				throw std::runtime_error("invalid input:"); // changed by Quinton, changed to throw error instead of break
			}

			int finalNumber = stoi(firstFourDigits + std::to_string(numbers));
			memory->write(incrementor, &finalNumber);
			incrementor++;
			firstRun = true;
			timeForSixDigit = false;
			return true;
		}
	}
}
