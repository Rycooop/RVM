#ifndef RVM_MNEMONIC_H
#define RVM_MNEMONIC_H


enum InstructionSet
{
	HOP = 0x20,		//acts similarly to a near jump in x86 assembly, address must be within 4096 bytes ----register
	FLY = 0x25,		//acts similarly to a far jump of 0xFF in x86,64 assembly, address is also relative to current address 
	REROUTE = 0x1E,	  //redirects execution flow to another function, arguments are pushed onto the stack beforehand via STACKADD
	LIBCALL = 0x2E,  //call to any c standard library functions, arguments are also pushed onto the stack
	RETURN = 0x99,	 //return to the address being stored in the VRET register
	STACKADD = 0x35,  //add a value to the top of the stack, utilized by function calls
	STACKGRAB = 0x36,   //grab a value from the stack, this is relative to the current stack pointer
	STACKTAKE = 0x37,  //removes the top value of the stack, acts identically to pop

	//Virtual Registers
	VIP = 0xA0,
	VSP = 0xA1,
	VR0 = 0xA2,
	VR1 = 0xA3,
	VR2 = 0xA4,
	VR3 = 0xA5,
	VR5 = 0xA6
};

#endif //RVM_MNEMONIC_H