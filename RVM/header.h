#ifndef RVM_HEADER_H
#define RVM_HEADER_H

#define RVM_VERSION 0x1

#include <iostream>


class Header
{
public:
	Header(char* FileHeader);
	~Header();

	//Define all header structures here so they can be used in the class
	typedef struct _FILE_HEADER
	{
		char Signature[3];  //in all valid .RVM files the first three bytes should spell RVM, similar to the MZ in windows portable executable format
		std::uint16_t version;
		char p0[5];
		std::uint32_t EntryPoint;
	}FILE_HEADER;

	typedef struct _HEADER_INFORMATION
	{
		std::uint16_t version;
		std::uint32_t EntryPoint;
		std::uint64_t FileSize;
	}HEADER_INFORMATION;

public:
	bool ParseHeader(HEADER_INFORMATION& info);

private:
	bool VerifyHeader(HEADER_INFORMATION& hInfo);

	FILE_HEADER* FileHeader;
};

#endif //RVM_HEADER_H