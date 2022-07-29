#ifndef RVM_LIBRARY_H
#define RVM_LIBRARY_H

#include <iostream>
#include <string>
#include <vector>


enum LibIDs
{
	LibPrint = 0x0,
	LibCompare,
};

namespace Lib
{
	void Print(const std::string& Str) noexcept;

	template <typename CType>
	inline bool Compare(const CType& n1, const CType& n2) { return n1 == n2; }

}

#endif //RVM_LIBRARY_H