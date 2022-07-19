# RVM
A lightweight RISC style architecture and virtual machine designed to execute basic programs in a cross-platform friendly manner. This machine follows the traditional fetch-decode-execute CPU sequence, and attempts to emulate any modern day CPU.

This virtual machine is stack based, utilizing a call stack and stack frames for function calls. It also reads 32 bit numbers in big-endian notation, performing arithmetic operations as well as RVM architecture-specific operands.

After veryfying the file extension .rvm and first three file bytes in ASCII as RVM, the machine will parse the header, find the entry point, and begin execution. I have provided a sample file which executes basic arithmetic, then jumps back to the beginning of the function.
