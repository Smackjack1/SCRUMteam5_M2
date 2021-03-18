#include "OpWrite.h"
#include <iostream>
using namespace std;

OpWrite::OpWrite()
{
	this->code = "11";
}

std::string OpWrite::execute(int argument, std::string input = "")
{
	int word;
	this->memory->read(argument, &word);
	return "The word at location " + std::to_string(argument) + " was " + std::to_string(word) + "\n";
	//cout << "The word at location " << argument << " was " << word << endl;
}
