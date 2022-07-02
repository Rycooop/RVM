#ifndef RVMCOMPILER_LOG_H
#define RVMCOMPILER_LOG_H

#include <iostream>
#include <string>
#include <vector>


class Log
{
public:
	Log();
	~Log();

	void Print(const char* Message);

	template <typename Response>
	Response GetInput(const char* Message)
	{
		Response Answer;

		std::cout << Message << " ";
		std::cin >> Answer;
		return Answer;
	}

private:
	std::vector<std::string> Messages;
};


#endif //RVMCOMPILER_LOG_H