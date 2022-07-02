#include "register.h"


Register::Register() { this->value = 0; }
Register::~Register() { this->ClearRegister(); }

void Register::ClearRegister() { this->value = 0; }

void Register::UpdateRegister(std::uintptr_t reg) { this->value = reg; }

std::uintptr_t Register::GetValue() const { return this->value; }