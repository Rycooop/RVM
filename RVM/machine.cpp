#include "machine.h"


Machine::Machine(char& FileStream)
{
	this->file = &FileStream; 
}

Machine::~Machine() {};

void Machine::Run()
{
	if (!this->Initialize())
		return;

	std::cout << "Running..." << std::endl;

	//VM loop 


}

void Machine::Shutdown()
{
	if (this->c_Registers)
		this->c_Registers->Shutdown();
}

bool Machine::Initialize()
{
	this->c_FileHeader = new Header((char*)this->file);
	this->HeaderInfo = new Header::HEADER_INFORMATION();

	if (!c_FileHeader->ParseHeader(*this->HeaderInfo))
	{
		return false;
	}

	this->c_Registers = new Registers();
	this->c_Stack = new Stack();

	c_Registers->Initialize();
	c_Stack->Initialize(c_Registers->GetVSP());

	return true;
}