README
-----------------------------------------
UVSIM takes a four digit decimal number preceded by the sign, such as +1023 (read word from keyboard, put it into memory location 23), +3031(add whatever is at location 31 to the accumulator) which will be read into system memory.
Each line follows this format, the first part should be a (+/-) which indicates the sign of the argument, the opcode portion will not be negative, careful using negative with arguments that specify memory location because there are no negative locations, next 2 digits are the opcode, and the last two digits are the argument. Four digit integer variables can be entered in a similar manner:

Command: (+/-)(2 digit opcode)(2 digit argument)
Variable: (+/-)(4 digit unsigned integer)

The program can handle 100 words in its main memory starting at location 00 ending at 99 before execution.
To stop adding lines of code to memory input “-99999” and the code will then execute, programs must have a halt command (43) or it won’t know to stop running. All inputs must be 5 characters, and any command that is executed that isn’t in the OpCodes list will crash the program.

GUI
----------
The user interface has a simple text entry area on the left to input the program similar to a console application. 
The box on the left displays the virtual machine's memory. 
The help button pulls up a readme file that gives more explanation on internal operation and programming.

OpCodes
----------------
Input/Output
Read: 10 - reads a word from user input into a memory location. Keyboard input just needs an integer and can have a - sign to be negative ex: -10, anything other than int will crash the program, also 4 digits max because of word size for memory
Write: 11 - reads a word from memory and writes it to the console

Load and Store Operations
Load: 20 - Loads the accumulator with data in main memory at the operand.
Store: 21 - whatever is in the accumulator will be written to memory at specified location

Arithmetic Operations
Add: 30 - Adds the word at the memory location specified in the argument to the value in the accumulator. Result is left in the accumulator.
Subtract: 31 - Subtract word from specified location and leaves it in accumulator, result left in accumulator
Divide: 32 - Divide the word in the accumulator by a word from a location in memory and leave it in the accumulator. memory location specified in argument
Multiply: 33 - Multiply the word in the accumulator by a word from a location in memory and leave it in the accumulator. memory location specified in argument

Control Operations
Branch: 40 - Branches to a specific memory location, memory location specified with 2 digits in the argument, program starts from the new pc location
Branch negative: 41 - Branches to a specific memory location if the accumulator is negative, memory location specified with 2 digits in the argument. program starts from the new pc location
Branch zero: 42 - Branches to a specific memory location if the accumulator is zero, memory location specified with 2 digits in the argument. program starts from the new pc location
Halt: 43 - Pause the program, must have an argument of any 2 digits, every program needs a halt
