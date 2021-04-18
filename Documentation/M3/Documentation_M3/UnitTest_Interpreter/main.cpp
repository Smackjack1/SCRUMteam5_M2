#include "uut_interpreter.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

int incrementor = 0;

int main(void)
{
	//////////////////VARIABLES/////////////////////////
	string commandToTest;
	bool executionResult = false;
	int cntPass = 0;
	int cntFail = 0;
	int numTestsCompleted = 0;
	int expectedResult = 0;
	int actualResult = 0;
	string expectedString = "";

	uut_interpreter myInterpreter = uut_interpreter();
	vmMemory* myMemory = vmMemory::getInstance();

	////////////////////////////////////////////////////

	///////////////////////////////////////10 - read//////////////////////////////////////////////
	expectedString = "invalid input: input length";
	try
	{
		cout << "Test #" << numTestsCompleted + 1 << ": Input = +10105\n";
		commandToTest = "+10105";
		expectedResult = 1010;
		myInterpreter.parseCommand(commandToTest);
		myMemory->read(incrementor, &actualResult);
		cout << "Expected result: \"invalid input: input length\"" << "failed" << endl;
		cntFail++;


	}
	catch (const std::exception& error)
	{

		cout << "Expected result: \"invalid input: input length\"" << ", Actual result: " << error.what() << "...";
		string actualString = error.what();
		if (expectedString == actualString)
		{
			cntPass++;
			cout << "Pass" << endl;
		}
		else
		{
			cntFail++;
			cout << "Fail" << endl;
		}

	}
	numTestsCompleted++;


	/////////////////////////////////////empty line///////////////////////////////////
	cout << endl;
	expectedString = "no empty lines are allowed";
	try
	{
		cout << "Test #" << numTestsCompleted + 1 << ": Input = \"\"\n";
		commandToTest = "";
		expectedResult = 1010;
		myInterpreter.parseCommand(commandToTest);
		myMemory->read(incrementor, &actualResult);
		cout << "Expected result: \"no empty lines are allowed\"" << "failed" << endl;
		cntFail++;


	}
	catch (const std::exception& error)
	{

		cout << "Expected result: \"no empty lines are allowed\"" << ", Actual result: " << error.what() << "...";
		string actualString = error.what();
		if (expectedString == actualString)
		{
			cntPass++;
			cout << "Pass" << endl;
		}
		else
		{
			cntFail++;
			cout << "Fail" << endl;
		}

	}
	numTestsCompleted++;


	///////////////////////////////////not signed int/////////////////////////////////////////////
	cout << endl;
	expectedString = "Incorrect argument, must be an integer";
	try
	{
		cout << "Test #" << numTestsCompleted + 1 << ": Input = word\n";
		commandToTest = "word";
		expectedResult = 1010;
		myInterpreter.parseCommand(commandToTest);
		myMemory->read(incrementor, &actualResult);
		cout << "Expected result: \"Incorrect argument, must be an integer\"" << "failed" << endl;
		cntFail++;


	}
	catch (const std::exception& error)
	{

		cout << "Expected result: \"Incorrect argument, must be an integer\"" << ", Actual result: " << error.what() << "...";
		string actualString = error.what();
		if (expectedString == actualString)
		{
			cntPass++;
			cout << "Pass" << endl;
		}
		else
		{
			cntFail++;
			cout << "Fail" << endl;
		}

	}
	numTestsCompleted++;
	


	////////////////////////////////////invalid first character/////////////////////////////////////////////////
	cout << endl;
	expectedString = "invalid first character";
	try
	{
		cout << "Test #" << numTestsCompleted + 1 << ": Input = ^1596\n";
		commandToTest = "^1596";
		expectedResult = 1010;
		myInterpreter.parseCommand(commandToTest);
		myMemory->read(incrementor, &actualResult);
		cout << "Expected result: \"invalid first character\"" << "failed" << endl;
		cntFail++;


	}
	catch (const std::exception& error)
	{

		cout << "Expected result: \"invalid first character\"" << ", Actual result: " << error.what() << "...";
		string actualString = error.what();
		if (expectedString == actualString)
		{
			cntPass++;
			cout << "Pass" << endl;
		}
		else
		{
			cntFail++;
			cout << "Fail" << endl;
		}

	}
	numTestsCompleted++;


	//////////////////////////////////////////////zzzz input///////////////////////////////////////

	cout << endl;
	commandToTest = "ZZZZ";
	expectedResult = 0;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = ZZZZ\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;

	cout << endl;
	commandToTest = "+1112";
	expectedResult = 0;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +1112\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;

	cout << endl;
	commandToTest = "3456";
	expectedResult = 11123456;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = 3456\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;
	//cout << myMemory->dump();



	
	/////////////////////////////////////11 - write///////////////////////////////////////////////
	
	cout << endl;
	commandToTest = "+1155";
	expectedResult = 1155;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +1155\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	/////////////////////////////////////////20 - load///////////////////////////////////////////////

	cout << endl;
	commandToTest = "+2025";
	expectedResult = 2025;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +2025\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	/////////////////////////////////////////21 - store/////////////////////////////////////////////////

	cout << endl;
	commandToTest = "+2130";
	expectedResult = 2130;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +2130\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;


	////////////////////////////////////////30 - add/////////////////////////////////////////////////////


	cout << endl;
	commandToTest = "+3010";
	expectedResult = 3010;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +3010\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	//////////////////////////////////////////////31 - sub///////////////////////////////////////////


	cout << endl;
	commandToTest = "+3145";
	expectedResult = 3145;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +3145\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;



	///////////////////////////////////////////////32 - div////////////////////////////////////////


	cout << endl;
	commandToTest = "+3230";
	expectedResult = 3230;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +3230\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;
	
	///////////////////////////////////////////////33 - mult////////////////////////////////////////


	cout << endl;
	commandToTest = "+3316";
	expectedResult = 3316;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +3316\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	//////////////////////////////////////////////40 - br/////////////////////////////////////////////

	cout << endl;
	commandToTest = "+4089";
	expectedResult = 4089;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +4089\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;
	
	///////////////////////////////////////////////41 - brn////////////////////////////////////////

	cout << endl;
	commandToTest = "+4156";
	expectedResult = 4156;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +4156\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;
	//////////////////////////////////////////42 - brz///////////////////////////////////////////

	cout << endl;
	commandToTest = "+4236";
	expectedResult = 4236;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +4236\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	//////////////////////////////////////////43 - halt/////////////////////////////////////////

	cout << endl;
	commandToTest = "+4300";
	expectedResult = 4300;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = +4300\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;
	
	//////////////////////////////////////// negative number input //////////////////////////////////
	cout << endl;
	commandToTest = "-2365";
	expectedResult = -2365;
	myInterpreter.parseCommand(commandToTest);
	myMemory->read(incrementor, &actualResult);
	cout << "Test #" << numTestsCompleted + 1 << ": Input = -2365\n";
	cout << "Expected result: " << expectedResult << ", Actual result: " << actualResult << "...";
	if (expectedResult == actualResult)
	{
		cntPass++;
		cout << "Pass" << endl;
	}
	else
	{
		cntFail++;
		cout << "Fail" << endl;
	}
	numTestsCompleted++;
	incrementor++;

	///////////////////////////////////////////////MAX memory/////////////////////////////////////////////
	cout << "increasing incrementor to max memory" << endl;
	for (incrementor; incrementor < 100; incrementor++)
	{

		commandToTest = "+1111";
		myInterpreter.parseCommand(commandToTest);
	
	}
	cout << endl;
	expectedString = "max memory exceeded, too many commands";
	try
	{
		cout << "Test #" << numTestsCompleted + 1 << ": Input = +1234\n";
		commandToTest = "+1234";
		myInterpreter.parseCommand(commandToTest);
		myMemory->read(incrementor, &actualResult);
		cout << "Expected result: \"max memory exceeded, too many commands\"" << "failed" << endl;
		cntFail++;


	}
	catch (const std::exception& error)
	{

		cout << "Expected result: \"max memory exceeded, too many commands\"" << ", Actual result: " << error.what() << "...";
		string actualString = error.what();
		if (expectedString == actualString)
		{
			cntPass++;
			cout << "Pass" << endl;
		}
		else
		{
			cntFail++;
			cout << "Fail" << endl;
		}

	}
	numTestsCompleted++;

	cout << "Total number of tests: " << numTestsCompleted << endl;
	cout << "Passed: " << cntPass <<", Failed: " << cntFail << endl;

	cout << myMemory->dump();

	return 0;
}