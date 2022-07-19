#ifndef RVM_REGISTER_H
#define RVM_REGISTER_H

#include <iostream>


class Register
{
public:
	Register();
	~Register();

	void ClearRegister();
	void UpdateRegister(std::int32_t Val);
	std::int32_t GetValue() const;

private:
	std::uint32_t value;
};

#endif //RVM_REGISTER_H