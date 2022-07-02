//
//  To output to a .RVM file, takes in a .ry file containing base code following the ry language syntax
//

#include <iostream>
#include <fstream>
#include <thread>

#include "log.h"


int main(int argc, const char* argv[])
{
	if (argc != 1)
		return -1;

	Log* console = new Log();

	std::ifstream Infile(argv[1]);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	return 0;
}