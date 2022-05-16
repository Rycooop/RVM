#include "RVM.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "[-] Must pass through a .RVM file to execute";
		_sleep(3000);
		return -1;
	}

	std::string fileName = argv[1];
	if (fileName.find(".rvm") == std::string::npos/* || isValid != fileName.size() - 4*/)
	{
		std::cerr << "[-] Not a valid .rvm file";
		_sleep(3000);
		return -1;
	}

	FILE* rFile = fopen(fileName.c_str(), "r+");
	void* sfheader = malloc(64);

	if (!fread(sfheader, 1, 64, rFile))
	{
		std::cerr << "[-] Cannot read file";
		_sleep(3000);
		return 0;
	}
	
	FILE_HEADER* FileHeader = (FILE_HEADER*)sfheader;
	std::string sFileSignature(FileHeader->FileSignature, 3);
	
	if (sFileSignature != "RVM")
	{
		std::cerr << "[-] Invalid .RVM file, please recompile";
		_sleep(3000);
		return -1;
	}

	_sleep(4000);
	return 0;
}
