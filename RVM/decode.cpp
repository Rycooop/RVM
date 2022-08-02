#include "decode.h"


Decode::Decode(Registers& regs)
{
	this->c_Execute = new Execute(regs);
}

Decode::~Decode() {};

void Decode::Interpret(Instruction& CurrInstruction)
{
	std::vector<uint8_t>* RemainingBytes = CurrInstruction.GetRemainingBytes();
	std::uint8_t Instruction = CurrInstruction.GetInstruction();

	if (Instruction == 0x0)
	{
		MachineRunning = false;
		return;
	}

	switch (Instruction)
	{
		case EMPTY:
		{
			return;
		}
		case HOP:
		{
			std::uint32_t RelAddr;
			memcpy(&RelAddr, &RemainingBytes->at(1), 4);

			this->c_Execute->Hop(RelAddr);
			break;
		}
		case FLY:
		{
			std::uint32_t AbsAddr;
			memcpy(&AbsAddr, &RemainingBytes->front(), 4);

			std::cout << "Jumping to addr: " << AbsAddr << std::endl;
			this->c_Execute->Fly(AbsAddr);
			return;
		}
		case LIBCALL:
		{
			this->c_Execute->Libcall(RemainingBytes->front());
			break;
		}
		case RETURN:
		{
			this->c_Execute->Return();
			break;
		}
		case COPY:
		{
			this->c_Execute->Copy(RemainingBytes->front(), RemainingBytes->at(1));
			break;
		}
		case CLEANREG:
		{
			this->c_Execute->CleanRegister(RemainingBytes->front());
			break;
		}
		case REGINC:
		{
			this->c_Execute->RegInc(RemainingBytes->front());
			break;
		}
		case REGSUB:
		{

			break;
		}
		case ADD:
		{
			std::uint8_t SumReg = RemainingBytes->front();
			std::uint32_t ArgToInt;
			memcpy(&ArgToInt, &RemainingBytes->at(1), 4);

			this->c_Execute->Add(SumReg, ArgToInt);
			break;
		}
		case SUB:
		{
			std::uint8_t DiffReg = RemainingBytes->front();
			std::uint32_t ArgToInt;
			memcpy(&ArgToInt, &RemainingBytes->at(1), 4);

			this->c_Execute->Subtract(DiffReg, ArgToInt);
			break;
		}
		case MUL:
		{
			std::uint8_t ProductReg = RemainingBytes->front();
			std::int32_t ArgToInt;
			memcpy(&ArgToInt, &RemainingBytes->at(1), 4);

			this->c_Execute->Multiply(ProductReg, ArgToInt);
			break;
		}
		default:
		{
#ifdef _DEBUG
			std::cout << "Executing Unknown instruction..." << std::endl;
#else //_DEBUG
			//this->c_Execute->UnknownInstruction();
#endif
			break;
		}
	}

}