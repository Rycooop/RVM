
#include <iostream>

#ifndef RVM_HEADER_H
#define RVM_HEADER_H


typedef struct _FILE_HEADER
{
	char FileSignature[3];
	std::uint16_t Version;
	char buffer[5];
	std::uintptr_t EntryPoint;
}FILE_HEADER, *PFILE_HEADER;

#endif //RVM_HEADER_H