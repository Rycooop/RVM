#include "stack.h"


Stack::Stack()
{
	this->CallStack = new std::vector<std::uint32_t>();
	this->stack = new std::vector<std::uint32_t>();

	//Push back 0 as the "return" address for the entry point function
	this->CallStack->push_back(0);
}

Stack::~Stack() {};
