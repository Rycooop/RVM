#ifndef RVM_BIT_H
#define RVM_BIT_H

#include <cstdint>


namespace RVM::BIT
{
	void CopyReverse(std::uint8_t* Begin, std::uint8_t Length, std::uint8_t* Buffer);
	std::uint8_t GetLastByte(std::int32_t Val);
}

#endif // RVM_BIT_H