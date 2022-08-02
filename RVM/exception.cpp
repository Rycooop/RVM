#include "exception.h"


Exception::Exception() {};

Exception::~Exception() {};

void Exception::operator<<(const std::uint8_t& ExceptionCode) noexcept
{
	
}

[[nodiscard]] bool Exception::ThrowException(std::uint8_t ExceptionCode) noexcept
{
	*this << ExceptionCode;

	switch (ExceptionCode)
	{

		default:
		{
			return 0;
		}
	}

}