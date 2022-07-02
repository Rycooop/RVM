#ifndef RVM_REGISTER_H
#define RVM_REGISTER_H

#include <iostream>


class Register
{
public:
	Register();
	~Register();
	
	void ClearRegister();
	void UpdateRegister(std::uintptr_t reg);
	std::uintptr_t GetValue() const;

private:
	std::uintptr_t value;
};

#endif //RVM_REGISTER_H