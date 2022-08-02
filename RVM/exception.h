#ifndef RVM_EXCEPTION_H
#define RVM_EXCEPTION_H

#include <iostream>
#include <vector>
#include <string>


enum Exceptions
{
	EXCEPTION_INVALID_INSTRUCTION = 0x1,
	EXCEPTION_BADREGISTER = 0x2,
	EXCEPTION_DIVIDE_BY_ZERO,
	EXCEPTION_UNKNOWN_INSTRUCTION,
	EXCEPTION_INVALID_JUMP,
};

class Exception
{
public:
	Exception();
	~Exception();

	void operator<<(const std::uint8_t& ExceptionCode) noexcept;

	[[nodiscard]] bool ThrowException(std::uint8_t ExceptionCode) noexcept;

private:
	std::vector<std::string> ExceptionInfo;
};


#endif //RVM_EXCEPTION_H