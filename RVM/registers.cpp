#include "registers.h"


Registers::Registers() {};
Registers::~Registers() {};

void Registers::Initialize()
{
	this->r_VIP = new Register();
	this->r_VSP = new Register();
	this->r_VBP = new Register();
	this->r_VRRET = new Register();
	this->r_VR0 = new Register();
	this->r_VR1 = new Register();
	this->r_VR2 = new Register();
	this->r_VR3 = new Register();
	this->r_VR4 = new Register();
}

void Registers::Shutdown()
{
	this->r_VIP->~Register();
	this->r_VSP->~Register();
	this->r_VBP->~Register();
	this->r_VRRET->~Register();
	this->r_VR0->~Register();
	this->r_VR1->~Register();
	this->r_VR2->~Register();
	this->r_VR3->~Register();
	this->r_VR4->~Register();
}

void Registers::ClearRegisters()
{
	r_VIP->ClearRegister();
	r_VSP->ClearRegister();
	r_VBP->ClearRegister();
	r_VRRET->ClearRegister();
	r_VR0->ClearRegister();
	r_VR1->ClearRegister();
	r_VR2->ClearRegister();
	r_VR3->ClearRegister();
	r_VR4->ClearRegister();
}

Register* Registers::IsRegister(std::uint8_t Opcode)
{
	if (Opcode == VR0)
		return this->r_VR0;
	else if (Opcode == VR1)
		return this->r_VR1;
	else if (Opcode == VR2)
		return this->r_VR2;
	else if (Opcode == VR3)
		return this->r_VR3;
	else if (Opcode == VR4)
		return this->r_VR4;
	else return NULL;
}

std::uint8_t Registers::GetEmptyRegister()
{
	if (this->r_VR0->GetValue() == 0)
		return VR0;
	else if (this->r_VR1->GetValue() == 0)
		return VR1;
	else if (this->r_VR2->GetValue() == 0)
		return VR2;
	else if (this->r_VR3->GetValue() == 0)
		return VR3;
	else if (this->r_VR4->GetValue() == 0)
		return VR4;
	else return NULL;
}