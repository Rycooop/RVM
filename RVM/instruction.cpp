#include "instruction.h"


Instruction::Instruction(char* rF, std::uint32_t Addr)
{
	this->RemainingBytes = new std::vector<std::uint8_t>();
	this->InstructionAddr = Addr;
	this->File = rF;
}

Instruction::~Instruction() {};

void Instruction::operator=(const Instruction& NewInstr)
{
	this->InstructionAddr = NewInstr.InstructionAddr;
	this->RemainingBytes = NewInstr.RemainingBytes;
}

[[nodiscard]] std::uint8_t Instruction::GetInstruction() const noexcept
{
	for (int i = 1; i < 6; i++)
	{
		if ((std::uint8_t)this->File[this->InstructionAddr])
			this->RemainingBytes->push_back(this->File[this->InstructionAddr + i]);
	}

	return (std::uint8_t)this->File[this->InstructionAddr]; 
}

std::vector<uint8_t>* Instruction::GetRemainingBytes() const { return this->RemainingBytes; }
