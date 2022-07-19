#ifndef RVM_FETCH_H
#define RVM_FETCH_H

#include "registers.h"
#include "instruction.h"


class Fetch
{
public:
	Fetch(Register& rRip, char& inFile);
	~Fetch();

	Instruction& GetPreviousInstruction() const noexcept;
	[[nodiscard]] Instruction& GetNextInstruction() const noexcept;

private:
	std::vector<Instruction*> InstructionList;
	Register* RIP;
	char* File;
};

#endif //RVM_FETCH_H