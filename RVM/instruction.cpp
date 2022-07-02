#include "instruction.h"


Instruction::Instruction()
{
	
}

Instruction::~Instruction()
{

}

std::uint8_t Instruction::GetInstructionID() const { return this->InstructionID; }

char* Instruction::GetRemainingBytes() const { return (char*)&this->RemainingBytes[0]; }