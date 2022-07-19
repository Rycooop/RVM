#ifndef RVM_DECODE_H
#define RVM_DECODE_H

#include <vector>
#include <iterator>
#include <algorithm>

#include "execute.h"
#include "mnemomic.h"
#include "bit.h"
#include "instruction.h"


extern bool MachineRunning;

class Decode
{
public:
	Decode(Registers& regs);
	~Decode();

	void Interpret(Instruction& CurrInstruction);

private:
	Execute* c_Execute;
	Instruction* CurrInstruction;

};

#endif //RVM_DECODE_h