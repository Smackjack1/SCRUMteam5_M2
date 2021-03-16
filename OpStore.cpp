#include "OpStore.h"

OpStore::OpStore()
{
	this->code = "21";
}

void OpStore::execute(int argument)
{
	int word;
	this->memory->read(ACC, &word);
	this->memory->write(argument, &word);
}
