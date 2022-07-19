#include "execute.h"


bool MachineRunning = true;

Execute::Execute(Registers& Regs)
{
	this->c_Regs = &Regs;
	this->c_Exception = new Exception();
	this->c_Stack = new Stack();
}

Execute::~Execute()
{
	this->c_Stack->~Stack();
	this->c_Exception->~Exception();
}

void Execute::Hop(std::uint32_t AddrRel) noexcept
{
	std::uint32_t CurrAddr = this->c_Regs->GetVIP().GetValue();

	if ((CurrAddr - AddrRel >= 4096) || (CurrAddr - AddrRel <= -4096))
	{
		//Throw exception of wrong jmp
	}
	else
	{
		this->c_Regs->GetVIP().UpdateRegister(CurrAddr + AddrRel);
	}
}

void Execute::Fly(std::int32_t AddrAbs) noexcept
{
	this->c_Regs->GetVIP().UpdateRegister(AddrAbs);
}

void Execute::Reroute(std::vector<Instruction*> Arguments, std::uint32_t FunctionAddr) noexcept
{
	for (Instruction* currArg : Arguments)
	{
		if (currArg->GetInstruction() == STACKADD)
			this->c_Stack->PushToStack(currArg->GetRemainingBytes()->at(1));
	}

	//Push the return address onto the stack
	this->c_Stack->PushReturnAddr((std::uint32_t)(this->c_Regs->GetVIP().GetValue() + 4));
	
}

void Execute::Return() noexcept
{
	if (this->c_Stack->GetReturnAddr() == 0)
		MachineRunning = false;
	
	this->c_Regs->GetVIP().UpdateRegister(this->c_Stack->GetReturnAddr());
}

void Execute::StackAdd(std::uint32_t Value) noexcept
{
	this->c_Stack->PushToStack(Value);
}

void Execute::Copy(std::uint8_t Reg, std::uint8_t Value) const noexcept
{
	Register* TargetReg = c_Regs->IsRegister(Reg);
	if (!TargetReg)
		return;

	std::cout << "Copying: " << Value << std::endl;
	TargetReg->UpdateRegister(Value);
	
	this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 5);
}

void Execute::CleanRegister(std::uint8_t Reg) const noexcept
{
	if (Register* toClean = this->c_Regs->IsRegister(Reg))
		toClean->ClearRegister();
}

void Execute::RegInc(std::uint8_t Reg) const noexcept
{
	Register* R = c_Regs->IsRegister(Reg);
	if (!R)
		return;

	R->UpdateRegister(R->GetValue() + 1);
	this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 2);
}

void Execute::RegSub(std::uint8_t Reg) const noexcept
{
	Register* R = c_Regs->IsRegister(Reg);
	if (!R)
		return;

	R->UpdateRegister(R->GetValue() - 1);
	this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 2);
}

void Execute::Add(std::uint8_t SumReg, std::int32_t n2) const noexcept
{
	Register* n1 = c_Regs->IsRegister(SumReg);
	if (!n1)
		return;

	if (Register* Reg2 = this->c_Regs->IsRegister((std::uint8_t)n2))
	{
		std::cout << "Added: " << (int)n1->GetValue() << " + " << (int)Reg2->GetValue() << std::endl;
		n1->UpdateRegister(n1->GetValue() + Reg2->GetValue());
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 2);
	}
	else
	{
		std::cout << "Added: " << (int)n1->GetValue() << " + " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() + n2);
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 5);
	}

	//Increment VIP by 4
}

void Execute::Subtract(std::uint8_t DiffReg, std::int32_t n2) const noexcept
{
	Register* n1 = c_Regs->IsRegister(DiffReg);
	if (!n1)
		return;

	if (Register* Reg2 = this->c_Regs->IsRegister((std::uint8_t)n2))
	{
		std::cout << "Subtracted: " << n1->GetValue() << " - " << Reg2->GetValue() << std::endl;
		n1->UpdateRegister(n1->GetValue() - Reg2->GetValue());
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 2);
	}
	else
	{
		std::cout << "Subtracted: " << n1->GetValue() << " - " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() - n2);
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 5);
	}

}

void Execute::Multiply(std::uint8_t Product, std::int32_t n2) const noexcept
{
	Register* n1 = c_Regs->IsRegister(Product);
	if (!n1)
		return;

	if (Register* Reg2 = this->c_Regs->IsRegister((std::uint8_t)n2))
	{
		std::cout << "Multiplied: " << (int)n1->GetValue() << " * " << (int)Reg2->GetValue() << std::endl;
		n1->UpdateRegister(n1->GetValue() * Reg2->GetValue());
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 2);
	}
	else
	{
		std::cout << "Multiplied: " << (int)n1->GetValue() << " * " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() * n2);
		this->c_Regs->GetVIP().UpdateRegister(this->c_Regs->GetVIP().GetValue() + 5);
	}

}

void Execute::Divide(std::uint8_t Quotient, std::int32_t n2) const noexcept
{
	Register* n1 = c_Regs->IsRegister(Quotient);
	if (!n1)
		return;

	if (n2 == 0x0)
	{
		this->c_Exception->ThrowException(EXCEPTION_DIVIDE_BY_ZERO);
		MachineRunning = false;
		return;
	}
}

void Execute::UnknownInstruction() noexcept
{
	this->c_Exception->ThrowException(EXCEPTION_UNKNOWN_INSTRUCTION);
	MachineRunning = false;
}

template <typename Type> Type Execute::AddVals(Type n1, Type n2)
{
	return 0;
}

