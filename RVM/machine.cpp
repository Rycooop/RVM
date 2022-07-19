#include "machine.h"


int Machine::CycleCount = 0;

Machine::Machine(char& FileStream)
{
	this->file = &FileStream; 
}

Machine::~Machine() {};

void Machine::Run()
{
	if (!this->Initialize())
		return;

	std::cout << "\n<MACHINE RUNNING>" << std::endl;

	//VM loop 
	while (MachineRunning /* running*/)
	{
		this->c_Decode->Interpret(this->c_Fetch->GetNextInstruction());
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		Machine::CycleCount++;
	}

	this->Shutdown();
}

void Machine::Shutdown()
{
	if (this->c_Fetch)
		this->c_Fetch->~Fetch();

	if (this->c_Decode)
		this->c_Decode->~Decode();

	if (this->c_Registers)
		this->c_Registers->Shutdown();
}

bool Machine::Initialize()
{
	this->c_FileHeader = new Header((char*)this->file);
	this->HeaderInfo = new Header::HEADER_INFORMATION();

	if (!c_FileHeader->ParseHeader(*this->HeaderInfo))
		return false;

	this->c_Registers = new Registers();

	c_Registers->Initialize();

	//Set VIP to the entry point
	this->c_Registers->GetVIP().UpdateRegister(this->HeaderInfo->EntryPoint);
	this->c_Fetch = new Fetch(this->c_Registers->GetVIP(), *this->file);

	this->c_Decode = new Decode(*this->c_Registers);

	return true;
}