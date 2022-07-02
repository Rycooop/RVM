#ifndef RVM_REGISTERS_H
#define RVM_REGISTERS_H

//The machine will carry 5 multi-purpose registers, as well as a virtual stack pointer and virtual instruction pointer
//
//  VIP    Virtual Instruction Pointer
//  VSP    Virtual Stack Pointer
//  VR0	   Multipurpose register 1
//  VR1	   Multipurpose register 2
//  VR2	   Multipurpose register 3
//  VR3	   Multipurpose register 4
//  VR4	   Multipurpose register 5


//VR0 will always be reserved to hold return addresses for functions, instead of being kept in a call stack, VR0 will be
//flushed as soon as execution returns

#include "register.h"


class Registers
{
public:
	Registers();
	~Registers();

	void Initialize();
	void Shutdown();

	Register& GetVIP();
	Register& GetVSP();

	Register* VR0;
	Register* VR1;
	Register* VR2;
	Register* VR3;
	Register* VR4;

private:
	void ClearRegisters();
	
	Register* VIP;
	Register* VSP;
};

#endif //RVM_REGISTERS_H