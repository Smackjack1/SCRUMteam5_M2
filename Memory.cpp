#include <cstdio>
#include<string>
#include"Memory.h"
vmMemory* vmMemory::instance = nullptr; // added by Q, this is just for static variable initialization
vmMemory* vmMemory::getInstance()
{
	if (instance == nullptr)
	{
		instance = new vmMemory(); // only make a new object if it is the first time we have called getInstance
	}
	return instance; // return the static instance variable
}

int vmMemory::write(int address, int* data)
{
	if ((address) > MEMSIZE) return -1;
	else //Write memory address with integer at data's address
	{
		mainMem[address] = *data;
		return 0;
	}
}

int vmMemory::read(int address, int* data)
{
	if ((address) > MEMSIZE) return -1;
	else//Read memory address with integer at data's address
	{
		*data = mainMem[address];
		return 0;
	}
}

int vmMemory::write_multiple(int address, int* data, int length)
{
	//Write memory addresses with integers at data's address + offset
	for (int i = 0; i < length; i++)
	{
		if ((address + i) > MEMSIZE) return -1;
		else
		{
			mainMem[(address + i)] = *(data + i);
		}
	}

	//If reached, finished nominally
	return 0;
}

std::string vmMemory::dump()
{
	//changed by Q, no longer prints, adds to returnString
	//Print PC and accumulator
	std::string returnString = "";
	returnString += "PC: " + std::to_string(mainMem[PC]) + "\nAccumulator: " + std::to_string(mainMem[ACC]) + "\n";
	//printf("PC: %d\nAccumulator: %d\n", mainMem[PC], mainMem[ACC]);

	//Print out main memory: 10 x 10
	int nlCount = 0;
	for (int i = 0; i < (MEMSIZE - XTRAREG); i++)
	{
		if (nlCount == 9)
		{
			returnString += std::to_string(mainMem[i]) + "\n";
			//printf("%d\n", mainMem[i]);
			nlCount = 0;
		}
		else
		{
			returnString += std::to_string(mainMem[i]) + "\t";
			//printf("%d\t", mainMem[i]);
			nlCount++;
		}
	}
	return returnString;
}

vmMemory::~vmMemory()
{
	delete instance;
}
