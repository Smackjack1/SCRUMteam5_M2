#include "OpRead.h"
#include <iostream>
using namespace std;

OpRead::OpRead()
{
	this->code = "10";
}

std::string OpRead::execute(int arguement,std::string input)
{
	unsigned int wordLength = 4;
	int inputWord = 0;
	char firstChar;
	//cout << "Enter data as an integer (4 digits max):\n";//user prompt added by Kevin
	//getline(cin,word);
	firstChar = input.at(0);
	if (firstChar == '-' or firstChar == '+')
	{
		wordLength = 5; // we can move our max length up by 1 to account for +/- if included
	}
	if (input.size() > wordLength)
	{
		throw std::runtime_error("Incorrect argument for read command, 4 digits is the max");
	}
	try 
	{
		inputWord = stoi(input);
	}
	catch(std::invalid_argument) // only want to catch invalid argument right here
	{
		throw std::runtime_error("Incorrect argument for read command, must be an integer");
	}
	this->memory->write(arguement, &inputWord);
	return ""; // does not need an output, so return ""
}
