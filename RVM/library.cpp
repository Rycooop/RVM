#include "library.h"


void Library::Print(const std::string& Str) noexcept
{
	std::cout << Str.c_str() << std::endl;
}

std::vector<std::string> Library::Delimate(const std::string& str1, const char delimater)
{
	std::vector<std::string> Contains;

	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == delimater) {
			std::string curr(str1.begin(), str1.begin() + i);
			Contains.push_back(curr);
		}
	}

	return Contains;
}

std::string Library::Strip(std::string ToStrip)
{
	ToStrip.erase(std::remove(ToStrip.begin(), ToStrip.end(), ' '), ToStrip.end());

	return ToStrip;
}