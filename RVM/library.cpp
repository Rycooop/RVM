#include "library.h"


void Library::Print(const std::string& Str) noexcept
{
	std::cout << Str.c_str() << std::endl;
}

std::string Library::substr(const std::string& str1, const std::string&& substr)
{
	std::string Substring = "";

	if (int pos = str1.find(substr))
		Substring = str1[pos];

	return Substring;
}