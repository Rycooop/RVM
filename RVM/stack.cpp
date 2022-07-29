#include "stack.h"


Stack::Stack()
{
}

Stack::~Stack() {};

Stack::Stack(Register& VSP, Register& VBP, std::vector<std::int32_t> CommandArgs)
{
	std::vector<std::int32_t> BaseFrame;
	BaseFrame.push_back(0); //Push back the return addr of 0 identifying the entry point function
	
	for (const auto& CurrArg : CommandArgs)
		BaseFrame.push_back(CurrArg);

	this->Frames.push_back(BaseFrame);
}
