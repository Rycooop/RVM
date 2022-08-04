#ifndef RVM_LIBRARY_H
#define RVM_LIBRARY_H

#include <iostream>
#include <string>
#include <vector>


namespace Library
{
	void Print(const std::string& Str) noexcept;

	template <typename CType>
	inline bool Compare(const CType& n1, const CType& n2) { return n1 == n2; }

	std::vector<std::string> Delimate(const std::string& str1, const char delimater);

	std::string Strip(std::string ToStrip);
}

enum LibIDs
{
	LibPrint = 0x0,
	LibCompare,
	LibSubstring,
	
};

#endif //RVM_LIBRARY_H