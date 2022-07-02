#ifndef RVM_DECODE_H
#define RVM_DECODE_H

#include "mnemomic.h"
#include "instruction.h"


class Decode
{
public:
	Decode();
	~Decode();

	void Update(Instruction& currInstr) const;

private:


	Instruction* currInstruction;

};

#endif //RVM_DECODE_h