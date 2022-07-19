#include "bit.h"



void RVM::BIT::CopyReverse(std::uint8_t* Begin, std::uint8_t Length, std::uint8_t* Buffer)
{
	for (int i = 0; i < Length; i++)
		Buffer[i] = (std::uint8_t)((*(std::uint32_t*)Begin >> (24 - (i * 8))) & 0xFF);
}

std::uint8_t RVM::BIT::GetLastByte(std::int32_t Val)
{
	return (std::uint8_t)((Val >> 24) & 0xFF);
}