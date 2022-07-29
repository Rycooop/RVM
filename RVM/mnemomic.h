#ifndef RVM_MNEMONIC_H
#define RVM_MNEMONIC_H


enum InstructionSet
{
	HOP = 0x20,		//acts similarly to a near jump in x86 assembly, address must be within 4096 bytes ----register. Stored in VR4
	FLY = 0x25,		//acts similarly to a far jump of 0xFF in x86,64 assembly, address is also relative to current address. Stored in VR4
	REROUTE = 0x1E,	  //redirects execution flow to another function, arguments are pushed onto the stack beforehand via STACKADD
	LIBCALL = 0x2E,  //call to any RVM standard library functions, arguments are also pushed onto the stack
	RETURN = 0x99,	 //return to the address being stored at the top of the callstack
	STACKADD = 0x35,  //add a value to the top of the stack, utilized by function calls
	STACKGRAB = 0x36,   //grab a value from the stack, this is relative to the current stack pointer
	COPY = 0x38,   //Acts as a mov does in x86 asm. Used as follows: COPY <reg* or addr>, <val*>
	COMPARE = 0x39, //If two values are equal, VR4 is set to 1, else it is set to 0
	EMPTY = 0x40, //Acts as a NO-OP
	CLEANREG = 0x41, //Zeroes the register
	REGINC = 0x42, //Increments the register
	REGSUB = 0x43, //Decrements the register

	//Arithmetic
	ADD = 0x50, //Add
	SUB = 0x60, //Subtract
	MUL = 0x70, //Multiply
	DIV = 0x80, //Divide
	ZERO = 0x90, //Zero out value pointed to

	//Virtual Registers
	VIP = 0xA0,
	VSP = 0xA1,

	//Multi Purpose registers
	VR0 = 0xA2,
	VR1 = 0xA3,
	VR2 = 0xA4,
	VR3 = 0xA5,
	VR4 = 0xA6
};

#endif //RVM_MNEMONIC_H