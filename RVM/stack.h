#ifndef RVM_STACK_H
#define RVM_STACK_H

#include <vector>

#include "mnemomic.h"
#include "register.h"

class Stack
{
public:
	Stack();
	~Stack();

	void Initialize(Register& StackRegister);

	std::uintptr_t GetStackPointer();

	void StackAdd(std::uintptr_t push);
	std::uintptr_t StackGrab();
	void StackTake();

private:
	void UpdateRSP(int move);

	Register* RSP;
	std::vector<std::uintptr_t*> stack;
};

#endif //RVM_STACK_H