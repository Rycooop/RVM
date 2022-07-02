#ifndef RVM_MACHINE_H
#define RVM_MACHINE_H


// Following the basic Fetch - Decode - Execute sequence, I put together a very simple virtual machine that utillizes a stack and 7 registers
// Plans for the future is to support more languages in the compiler, as well as more libraries

#include <fstream>
#include <iostream>
#include <vector>
#include <thread>

#include "header.h"
#include "registers.h"
#include "stack.h"
#include "decode.h"
#include "fetch.h"
#include "execute.h"


class Machine
{
public:
	Machine(char& FileStream);
	~Machine();

	void Run();
	void Shutdown();

private:
	bool Initialize();

	Header* c_FileHeader;
	Registers* c_Registers;
	Stack* c_Stack;

	char* file;
	Header::HEADER_INFORMATION* HeaderInfo;
	std::vector<std::string*> flags;
};

#endif //RMV_MACHINE_H