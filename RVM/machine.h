#ifndef RVM_MACHINE_H
#define RVM_MACHINE_H


// Following the basic Fetch - Decode - Execute sequence, I put together a very simple virtual machine that utillizes a stack and 7 registers
// Plans for the future is to support more languages in the compiler, as well as more libraries

// BIG ENDIAN

#include <fstream>
#include <iostream>
#include <vector>
#include <thread>

#include "header.h"
#include "registers.h"
#include "decode.h"
#include "fetch.h"


class Machine
{
public:
	Machine();
	~Machine();
	Machine(char& FileStream);


	static int CycleCount;

	void Run();
	void Shutdown();

private:
	bool Initialize();

	Header* c_FileHeader;
	Registers* c_Registers;
	
	Fetch* c_Fetch;
	Decode* c_Decode;

	char* file;
	Header::HEADER_INFORMATION* HeaderInfo;
	std::vector<std::string*> flags;
};

#endif //RMV_MACHINE_H