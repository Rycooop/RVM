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
#include "mnemomic.h"


class Registers
{
public:
	Registers();
	~Registers();

	void Initialize();
	void Shutdown();

	inline Register& GetVIP() noexcept { return *this->r_VIP; }
	inline Register& GetVSP() noexcept { return *this->r_VSP; }
	inline Register& GetVBP() noexcept { return *this->r_VBP; }

	Register* r_VR0;
	Register* r_VR1;
	Register* r_VR2;
	Register* r_VR3;
	Register* r_VR4;
	Register* r_VRRET;

	Register* IsRegister(std::uint8_t Opcode);

private:
	void ClearRegisters();
	
	Register* r_VIP;
	Register* r_VSP;
	Register* r_VBP;
};

#endif //RVM_REGISTERS_H