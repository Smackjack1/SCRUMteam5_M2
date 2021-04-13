#include "pch.h"
#include "Executor.h"
using namespace std;
Executor::Executor()
{
	counter = 0;
}

string Executor::GetOpcode()
{
	int temp_mem_address = 0;
	int data = 0;
	MemInstance->read(PC, &temp_mem_address);//get address in PC register
	MemInstance->read(temp_mem_address, &data);

	string str = to_string(data);
	str = str.substr(0, 2);
	return str;
}

int Executor::GetOperand()
{
	int temp_mem_address = 0;
	int data = 0;
	MemInstance->read(PC, &temp_mem_address);//get address in PC register
	MemInstance->read(temp_mem_address, &data);
	string str = to_string(data);
	str = str.substr(2, str.size());
	return stoi(str);
}

void Executor::CallInvoker()
{
	int prog_counter = 0;
	int debug = 0;

	string opcode = "";
	int operand = 0;
	//todo??? make executor in charge of opRead and opWrite
	//while (GetOpcode() != "43")//43 = Halt, this was removed now whoever calls it should use this while loop
	//{
	opcode = GetOpcode();
	operand = GetOperand();

	if (InvokerInstance.executeCommand(opcode, operand) == -1)
	{
		//error
		throw std::runtime_error("invalid instruction for execution\n"); //fixed by Quinton, changed to throw instead of just break
	}

	if (opcode != "40" && opcode != "41" && opcode != "42") // fixed by Quinton, should have been opcode not GetOpCode()
	{
		int currentPC = 0;
		MemInstance->read(PC, &currentPC);
		currentPC += 1; // fixed by Quinton, was calling &mainmem which cannot be done, now it has a local variable that stores pc value, then increments by 1 and writes new value to PC
		MemInstance->write(PC, &currentPC);
	}

	//}
}
