#pragma once
/*
Memory.h and Memory.cpp written by Devan
*/
#ifndef __MEMORY__
#define __MEMORY__

#define XTRAREG 2
#define MEMSIZE (100 + XTRAREG)
#define PC 100
#define ACC 101

class vmMemory {
    int mainMem[MEMSIZE];
    vmMemory() = default;  // added by Q, private constructor so no one can accidentally make a new memory object
    vmMemory(const vmMemory&) = delete;  // added by Q, disables copy
    static vmMemory* instance;
    //CONSOLE forwards to console
public:
    static vmMemory* getInstance();  // added by Q, static member function returns an instance, this is essentially the constructor
    int write(int address, int* data);

    int read(int address, int* data);

    int write_multiple(int address, int* data, int length);

    std::string dump(void); //prints out the entire memory array /change by Q: now it returns a string for the dumped memory

    ~vmMemory(); // added by Q, add deconstructor to delete allocated instance variable

};


#endif

