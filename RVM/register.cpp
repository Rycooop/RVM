#include "register.h"


Register::Register() { this->value = 0; }
Register::~Register() { this->ClearRegister(); }

Register Register::operator+(const Register& ToAdd) const noexcept
{
	Register newReg;
	newReg.UpdateRegister(this->GetValue() + ToAdd.GetValue());
	return newReg;
}

Register Register::operator-(const Register& ToSub) const noexcept
{
	Register newReg;
	newReg.UpdateRegister(this->GetValue() - ToSub.GetValue());
	return newReg;
}

void Register::operator++() noexcept { this->UpdateRegister(this->value + 1); }
void Register::operator--() noexcept { this->UpdateRegister(this->value - 1); }

void Register::operator+=(const int&& num) noexcept { this->UpdateRegister(this->value + num); }

void Register::ClearRegister() { this->value = 0; }

void Register::UpdateRegister(std::int32_t Val) { this->value = Val; }

std::int32_t Register::GetValue() const { return this->value; }