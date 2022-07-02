#include "registers.h"


Registers::Registers() {};
Registers::~Registers() {};

void Registers::Initialize()
{
	this->VIP = new Register();
	this->VSP = new Register();
	this->VR0 = new Register();
	this->VR1 = new Register();
	this->VR2 = new Register();
	this->VR3 = new Register();
	this->VR4 = new Register();
}

void Registers::Shutdown()
{
	this->VIP->~Register();
	this->VSP->~Register();
	this->VR0->~Register();
	this->VR1->~Register();
	this->VR2->~Register();
	this->VR3->~Register();
	this->VR4->~Register();
}

Register& Registers::GetVIP() { return *this->VIP; }

Register& Registers::GetVSP() { return *this->VSP; }

void Registers::ClearRegisters()
{
	VIP->ClearRegister();
	VSP->ClearRegister();
	VR0->ClearRegister();
	VR1->ClearRegister();
	VR2->ClearRegister();
	VR3->ClearRegister();
	VR4->ClearRegister();
}
