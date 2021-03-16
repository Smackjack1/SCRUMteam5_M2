#include "OpLoad.h"

OpLoad::OpLoad()
{
	this->code = "20";
}

void OpLoad::execute(int argument)
{
	int word = 0;
	this->memory->read(argument, &word); // fixed by Kevin, should be &word and word as int not int*
	this->memory->write(ACC, &word);
}
