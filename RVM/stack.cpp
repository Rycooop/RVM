#include "stack.h"


Stack::Stack() {};
Stack::~Stack() {};

void Stack::Initialize(Register& StackRegister) { this->RSP = &StackRegister; }

std::uintptr_t Stack::GetStackPointer() { return this->RSP->GetValue(); }

void Stack::StackAdd(std::uintptr_t push) { this->stack.push_back(&push); }

std::uintptr_t Stack::StackGrab()
{
	std::size_t top = this->stack.size();
	return *this->stack[top];
}

void Stack::StackTake() { this->stack.pop_back(); }

void Stack::UpdateRSP(int move)
{
	this->RSP->UpdateRegister((uintptr_t)(this->RSP->GetValue() + move));
}