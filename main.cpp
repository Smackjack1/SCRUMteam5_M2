
#include<exception>
#include<iostream>
#include"Facade.h"

int main()
{
	try // try catch added by Quinton so errors will stop all execution
	{
		std::string command;
		Facade fac = Facade();
		cout << "Enter command";
		cin >> command;
		fac.addCommand(command);
		cout << "\n" << fac.getMemory();
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}
	
}