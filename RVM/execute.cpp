#include "execute.h"


bool MachineRunning = true;

Execute::Execute(Registers& Regs)
{
	std::vector<std::int32_t> ProgramArgs;

	this->c_Regs = &Regs;
	this->c_Exception = new Exception();
	this->c_Stack = new Stack(this->c_Regs, this->c_Regs->GetVSP(), this->c_Regs->GetVBP(), ProgramArgs);
}

Execute::~Execute()
{
	this->c_Stack->~Stack();
	this->c_Exception->~Exception();
}

void Execute::Hop(const std::uint32_t& AddrRel) noexcept
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

void Execute::Fly(const std::int32_t& AddrAbs) noexcept
{
	this->c_Regs->GetVIP().UpdateRegister(AddrAbs);
}

void Execute::Reroute(std::vector<Instruction*> Arguments, std::uint32_t FunctionAddr) noexcept
{
	this->c_Regs->r_VRRET->UpdateRegister(this->c_Regs->GetVIP().GetValue());
	
}

void Execute::Libcall(const std::uint8_t& ID) const noexcept
{
	switch (ID)
	{
	case LibPrint:
	{

	}
	}
}

void Execute::Return() noexcept
{
	std::int32_t RetAddr = this->c_Regs->r_VRRET->GetValue();
	
	if (RetAddr == 0)
		MachineRunning = false;
	
	this->c_Regs->GetVIP().UpdateRegister(RetAddr);
}

void Execute::StackAdd(std::uint8_t Reg) noexcept
{
	this->c_Stack->StackAdd(Reg);
}

void Execute::StackGrab(std::uint8_t Reg) noexcept
{
	this->c_Stack->StackGrab(Reg);
}

void Execute::Copy(std::uint8_t Reg, std::uint8_t Value) const noexcept
{
	Register* TargetReg = c_Regs->IsRegister(Reg);
	if (!TargetReg)
		return;

	std::cout << "Copying: " << Value << std::endl;
	TargetReg->UpdateRegister(Value);
	
	this->c_Regs->GetVIP() += 5;
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

	R++;
	this->c_Regs->GetVIP() += 2;
}

void Execute::RegSub(std::uint8_t Reg) const noexcept
{
	Register* R = c_Regs->IsRegister(Reg);
	if (!R)
		return;

	R--;
	this->c_Regs->GetVIP() += 2;
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
		this->c_Regs->GetVIP() += 2;
	}
	else
	{
		std::cout << "Added: " << (int)n1->GetValue() << " + " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() + n2);
		this->c_Regs->GetVIP() += 5;
	}
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
		this->c_Regs->GetVIP() += 2;
	}
	else
	{
		std::cout << "Subtracted: " << n1->GetValue() << " - " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() - n2);
		this->c_Regs->GetVIP() += 5;
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
		this->c_Regs->GetVIP() += 2;
	}
	else
	{
		std::cout << "Multiplied: " << (int)n1->GetValue() << " * " << (int)n2 << std::endl;
		n1->UpdateRegister(n1->GetValue() * n2);
		this->c_Regs->GetVIP() += 5;
	}

}

void Execute::Divide(std::uint8_t Quotient, std::int32_t n2) const noexcept
{
	Register* n1 = c_Regs->IsRegister(Quotient);
	if (!n1)
		return;

	if (n2 == 0x0)
	{
		this->ThrowException(EXCEPTION_DIVIDE_BY_ZERO);
		return;
	}
}

void Execute::ThrowException(const std::uint8_t&& ExceptionCode) const noexcept
{
	if (!this->c_Exception->ThrowException(ExceptionCode))
		MachineRunning = false;
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

void Execute::PrintCon(const std::string& Message)
{
	std::cout << Message << std::endl;
}