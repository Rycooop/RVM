#include "log.h"


Log::Log() {};
Log::~Log() {};

void Log::Print(const char* Message)
{
	std::cout << "[*] " << Message << std::endl;
	this->Messages.push_back(Message);
}
