#include "fetch.h"


Fetch::Fetch(Register& rRip, char* inFile)
{ 
	this->RIP = &rRip; 
	this->file = inFile;
}

Fetch::~Fetch() {}

void Fetch::Update()
{
}