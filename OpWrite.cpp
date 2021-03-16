#include "OpWrite.h"
#include <iostream>
using namespace std;

OpWrite::OpWrite()
{
	this->code = "11";
}

void OpWrite::execute(int argument)
{
	int word;
	this->memory->read(argument, &word);
	cout << "The word at location " << argument << " was " << word << endl;
}
