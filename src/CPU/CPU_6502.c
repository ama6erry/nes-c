#include <sdtio.h>
#include <stdlib.h>
#include <sdtint.h>

//Memory
unsigned char memory[65536] = {0};


unsigned short pc = 0; //16 bit register that points to the next instruction
unsigned char stack[256] = {0}; // stack - usually stored in $0100 - $01FF in memory but for simplicity I just made it its own array 
unsigned char sp = 0; //stack pointer
unsigned char acc = 0; //accumulator
unsigned char iX = 0; //Index X register - commonly used for holding counters / offsets | Can also be used to get a copy of the stack pointer
unsigned char iY = 0; //Index Y register - similar to X register 

unsigned char status = 0; //This register records some flags that change how the processor functions
//bit 0 : carry flag - Set if the last operation caused an overflow or an underflow
//bit 1 : zero flag - Set if the last operation was zero
//bit 2 : interrupt disable - Set if program executed SEI (Set Interrupt Disable) instruction
//bit 3 : decimal mode - While set, processor obeys the rules of Binary Coded Decimal during addition and subtraction
//bit 4 : break command - Set when BRK instruction is executed and an interrupt was generated to process it
//bit 5 : overflow flag - Set when arithmetic operation yieled and invalid two's compliment result
//bit 6 : negative flag - Set if the result of the previous operation had bit 7 set to one

void execute(){

}
