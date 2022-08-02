#include "stack.h"


Stack::Stack() {};
Stack::~Stack() {};

Stack::Stack(Registers* Regs, Register& VSP, Register& VBP, std::vector<std::int32_t> CommandArgs)
{
	this->c_Regs = Regs;
	this->VSP = &VSP;
	this->VBP = &VBP;
	this->c_Regs->r_VRRET->UpdateRegister(0);

	std::vector<std::int32_t> BaseFrame;
	BaseFrame.push_back(0); //Push back the return addr of 0 identifying the entry point function
	this->VBP++; //Set the Base pointer index
	this->VSP++; //Set the stack pointer index
	
	for (const auto& CurrArg : CommandArgs)
		BaseFrame.push_back(CurrArg); this->VSP++;

	this->Frames.push_back(BaseFrame);
}

void Stack::StackAdd(const std::uint8_t Reg) noexcept
{
	if (Register* ToPush = this->c_Regs->IsRegister(Reg)) {
		this->Frames.back().push_back(ToPush->GetValue());
		this->VSP++;
	}
	else {
		//Throw an exception of an invalid register trying to be pushed to stack
	}
}

void Stack::StackGrab(const std::uint8_t Reg) noexcept
{
	if (Register* ToPop = this->c_Regs->IsRegister(Reg)) {
		ToPop->UpdateRegister(this->Frames.back().back());
		this->VSP--;
	}
	else {
		//throw exception of invalid register trying to be popped from stack
	}

	if (this->VSP->GetValue() == 0) {
		this->Frames.pop_back();
		this->VSP->UpdateRegister(this->Frames.back().size() - 1);
		this->VBP--;
	}
}