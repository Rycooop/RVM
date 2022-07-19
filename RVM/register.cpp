#include "register.h"


Register::Register() { this->value = 0; }
Register::~Register() { this->ClearRegister(); }

void Register::ClearRegister() { this->value = 0; }

void Register::UpdateRegister(std::int32_t Val) { this->value = Val; }

std::int32_t Register::GetValue() const { return this->value; }