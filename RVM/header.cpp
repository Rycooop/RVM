#include "header.h"


Header::Header(char* FileHeader)
{
	this->FileHeader = (FILE_HEADER*)FileHeader; 
}

Header::~Header() {};  


bool Header::ParseHeader(HEADER_INFORMATION& info)
{
	info.version = 0;
	info.EntryPoint = 0;

	if (!this->VerifyHeader(info))
		return false;

	return true;
}

bool Header::VerifyHeader(HEADER_INFORMATION& hInfo)
{
	if (!this->FileHeader)
		return false;

	std::string fSig(FileHeader->Signature, 3);

	if (fSig != "RVM")
	{
		std::cout << "[-] Not a valid RVM executable, invalid header signature" << std::endl;
		return false;
	}
	
	if (FileHeader->version != RVM_VERSION)
	{
		std::cout << "[-] Invalid version " << this->FileHeader->version << " running on machine version: " << RVM_VERSION << ". Please update accordingly" << std::endl;
		return false;
	}

	hInfo.version = RVM_VERSION;

	if (!FileHeader->EntryPoint)
	{
		std::cout << "[-] Entry point not found" << std::endl;
		return false;
	}

	hInfo.EntryPoint = FileHeader->EntryPoint;
	std::cout << "[+] Entry Point Found: 0x" << std::hex << FileHeader->EntryPoint << std::endl;

	return true;
}