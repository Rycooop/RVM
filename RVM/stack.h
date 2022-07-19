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

	inline void PushToStack(std::uint32_t Value) { this->stack->push_back(Value); }
	std::uint32_t GrabTopStack() { return this->stack->back(); }
	inline void PopStack() { this->stack->pop_back(); }

	inline void PushReturnAddr(std::uint32_t RetAddr) { this->CallStack->push_back(RetAddr); }
	inline std::uint32_t GetReturnAddr() { return this->CallStack->back(); }

private:
	Register* c_Vsp;

	std::vector<std::uint32_t>* CallStack;
	std::vector<std::uint32_t>* stack;
};

#endif //RVM_STACK_H