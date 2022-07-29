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

	Stack(Register& VSP, Register& VBP, std::vector<std::int32_t> CommandArgs);

	inline void Push(const std::int32_t Val);
	std::int32_t Pop();

	inline std::uint32_t GetRetAddr() const noexcept { return this->Frames.back().front(); }

private:
	std::vector<std::vector<std::int32_t>> Frames;
};

#endif //RVM_STACK_H