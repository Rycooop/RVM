#ifndef RVM_REGISTER_H
#define RVM_REGISTER_H

#include <iostream>


class Register
{
public:
	Register();
	~Register();

	//Operator Overloaders
	Register operator+(const Register& ToAdd) const noexcept;
	Register operator-(const Register& ToSub) const noexcept;
	void operator++() noexcept;
	void operator--() noexcept;
	void operator+=(const int&& num) noexcept;
	void operator-=(const int&& num) noexcept;

	void ClearRegister();
	void UpdateRegister(std::int32_t Val);
	std::int32_t GetValue() const;

private:
	std::uint32_t value;
};

#endif //RVM_REGISTER_H