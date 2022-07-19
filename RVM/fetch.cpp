#include "fetch.h"


Fetch::Fetch(Register& rRip, char& inFile)
{ 
	this->RIP = &rRip; 
	this->File = &inFile;
}

Fetch::~Fetch() {}

Instruction& Fetch::GetPreviousInstruction() const noexcept { return *this->InstructionList.back(); }

[[nodiscard]] Instruction& Fetch::GetNextInstruction() const noexcept
{
	static int CycleCount = 0;
	std::uint32_t CurrRIP = this->RIP->GetValue();
	CurrRIP++, CycleCount++;

	Instruction* NextInstruction = new Instruction(this->File, CurrRIP);
	std::cout << "<INSTRUCTION FETCHED> Cycle: " << CycleCount << " Curr Instruction: " << std::hex << (int)NextInstruction->GetInstruction() << std::endl;

	this->RIP->UpdateRegister(CurrRIP);
	return *NextInstruction;
}