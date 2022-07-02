#include "machine.h"


int main(int argc, const char* argv[])
{
	std::fstream eFileStream;
	std::string fPath;

	if (argc > 1)
	{
		fPath = argv[1];
		eFileStream.open(argv[1], std::fstream::in | std::ifstream::binary);
		std::cout << "[*] Opening " << argv[1] << " for execution..." << std::endl;
	}
	else
	{
		std::cout << "[*] Enter executable file path: ";
		std::cin >> fPath;
		eFileStream.open(fPath.c_str(), std::fstream::in | std::ifstream::binary);
	}


	//If the file does not have the .rvm extension we should immidiately return and not bother loading it into memory
	if (strstr(fPath.c_str(), ".rvm") == 0)
	{
		std::cout << "[-] Not a valid .rvm file";
		return 0;
	}

	//Get the size of the file and read it into a char array
	eFileStream.seekg(0, std::ios::end);
	std::size_t FileSize = eFileStream.tellg();
	eFileStream.seekg(0, std::ios::beg);

	char* buff = new char[FileSize + 1];
	eFileStream.read(buff, FileSize);


	Machine* RVM = new Machine(*buff);

	RVM->Run();
	RVM->Shutdown();

	std::this_thread::sleep_for(std::chrono::seconds(2));

	return 0;
}