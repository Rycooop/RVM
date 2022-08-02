#ifndef RVM_STACK_H
#define RVM_STACK_H

#include <vector>

#include "mnemomic.h"
#include "registers.h"


//The stack pointer(VSP) and base pointer(VBP) are an index position rather than a address. This allows for the use of a 2d vector
//array to act as the stack and the index positions to constantly be updated

class Stack
{
public:
	Stack();
	~Stack();

	Stack(Registers* c_Regs, Register& VSP, Register& VBP, std::vector<std::int32_t> CommandArgs);

	void StackAdd(const std::uint8_t Reg) noexcept;
	void StackGrab(const std::uint8_t Reg) noexcept;

private:
	Registers* c_Regs;
	Register* VSP;
	Register* VBP;
	std::vector<std::vector<std::int32_t>> Frames;
};

#endif //RVM_STACK_H