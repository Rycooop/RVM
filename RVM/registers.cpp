#include "registers.h"


Registers::Registers() {};
Registers::~Registers() {};

void Registers::Initialize()
{
	this->r_VIP = new Register();
	this->r_VSP = new Register();
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
	this->r_VR0->~Register();
	this->r_VR1->~Register();
	this->r_VR2->~Register();
	this->r_VR3->~Register();
	this->r_VR4->~Register();
}

Register& Registers::GetVIP() { return *this->r_VIP; }

Register& Registers::GetVSP() { return *this->r_VSP; }

void Registers::ClearRegisters()
{
	r_VIP->ClearRegister();
	r_VSP->ClearRegister();
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