#ifndef RVM_EXECUTE_H
#define RVM_EXECUTE_H

#include <iostream>
#include <string>

#include "stack.h"
#include "library.h"
#include "instruction.h"
#include "registers.h"
#include "exception.h"


class Execute
{
public:
	Execute(Registers& Regs);
	~Execute();


	//Virtual Instructions --
	void Hop(const std::uint32_t& AddrRel) noexcept;
	void Fly(const std::int32_t& AddrAbs) noexcept;
	void Reroute(std::vector<Instruction*> Arguments, std::uint32_t FunctionAddr) noexcept;
	void Libcall(const std::uint8_t& ID) const noexcept;
	void Return() noexcept;
	void StackAdd(std::uint8_t Reg) noexcept;
	void StackGrab(std::uint8_t Reg) noexcept;
	void Copy(std::uint8_t Reg, std::uint8_t Value) const noexcept;
	void CleanRegister(std::uint8_t Reg) const noexcept;
	void RegInc(std::uint8_t Reg) const noexcept;
	void RegSub(std::uint8_t Reg) const noexcept;

	//Arithmetics --
	void Add(std::uint8_t SumReg, std::int32_t n2) const noexcept;
	void Subtract(std::uint8_t DiffReg, std::int32_t n2) const noexcept;
	void Multiply(std::uint8_t Product, std::int32_t n2) const noexcept;
	void Divide(std::uint8_t Quotient, std::int32_t n2) const noexcept;

	void ThrowException(const std::uint8_t&& ExceptionCode) const noexcept;
	void UnknownInstruction() noexcept;

	template <typename Type> Type AddVals(Type n1, Type n2);

private:
	Registers* c_Regs;
	Exception* c_Exception;
	Stack* c_Stack;

	void PrintCon(const std::string& Message);
};


//Instantiate all templates with functionality defined in execute.cpp
template std::uint8_t Execute::AddVals<std::uint8_t>(std::uint8_t, std::uint8_t);

#endif //RVM_EXECUTE_H

