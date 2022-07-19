#ifndef RVM_INSTRUCTION_H
#define RVM_INSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "mnemomic.h"


class Instruction
{
public:
	Instruction(char* rF, std::uint32_t Addr);
	~Instruction();

	[[nodiscard]] std::uint8_t GetInstruction() const noexcept;
	std::vector<uint8_t>* GetRemainingBytes() const;

private:
	std::uint32_t InstructionAddr;
	std::vector<uint8_t>* RemainingBytes;
	char* File;
};

#endif //RVM_INSTRUCTION_H