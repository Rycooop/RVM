#ifndef RVM_FETCH_H
#define RVM_FETCH_H

#include "registers.h"
#include "instruction.h"


class Fetch
{
public:
	Fetch(Register& rRip, char* inFile);
	~Fetch();

	Instruction* GetCurrentInstruction() const;
	void Update();

private:
	Register* RIP;
	char* file;
};

#endif //RVM_FETCH_H