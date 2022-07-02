#ifndef RVM_INSTRUCTION_H
#define RVM_INSTRUCTION_H

#include <iostream>
#include <vector>

#include "mnemomic.h"


class Instruction
{
public:
	Instruction();
	~Instruction();

	std::uint8_t GetInstructionID() const;
	char* GetRemainingBytes() const;

private:
	std::uint8_t InstructionID;
	std::vector<char> RemainingBytes;
};

#endif //RVM_INSTRUCTION_H