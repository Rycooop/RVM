#include "exception.h"


Exception::Exception() {};

Exception::~Exception() {};

[[nodiscard]] bool Exception::ThrowException(std::uint8_t ExceptionCode) noexcept
{
	this->ExceptionCount++;

	switch (ExceptionCode)
	{

		default:
		{
			return 0;
		}
	}
}