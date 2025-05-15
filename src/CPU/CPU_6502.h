#ifndef CPU_6502_H
#define CPU_6502_H

#define NOPER {NOP, NONE}

typedef enum {
  NONE, 
  IMPL, //implicit
  ACC, //accumulator
  IMM, //immediate
  ZPG, //zero page
  ZPX, //zero page x
  ZPY, //zero page y
  REL, //relative
  ABS, //absolute
  ABX, //absolute x
  ABY, //absolute y 
  IND, //indirect
  IDX, //indexed indirect (x)
  IDY, //indirect indexed (y)
} addressMode;

typedef enum {
  LDA,
  LDX,
  LDY,
  STA,
  STX,
  STY,
  TAX,
  TAY,
  TXA,
  TYA,
  TSX,
  TXS,
  PHA,
  PHP,
  PLA,
  PLP,
  AND,
  EOR,
  ORA,
  BIT,
  ADC,
  SBC,
  CMP,
  CPX,
  CPY,
  INC,
  INX,
  INY,
  DEC,
  DEX,
  DEY,
  ASL,
  LSR,
  ROL,
  ROR,
  JMP,
  JSR,
  RTS,
  BCC,
  BCS,
  BEQ,
  BMI,
  BNE,
  BPL,
  BVC,
  BVS,
  CLC,
  CLD,
  CLI,
  CLV,
  SEC,
  SED,
  SEI,
  BRK,
  NOP,
  RTI,
} opcode;

typedef struct instruction {
  opcode code;
  addressMode mode;
} Instruction;


//unsigned char status = 0; //This register records some flags that change how the processor functions
//bit 0 : carry flag - Set if the last operation caused an overflow or an underflow
//bit 1 : zero flag - Set if the last operation was zero
//bit 2 : interrupt disable - Set if program executed SEI (Set Interrupt Disable) instruction
//bit 3 : decimal mode - While set, processor obeys the rules of Binary Coded Decimal during addition and subtraction
//bit 4 : break command - Set when BRK instruction is executed and an interrupt was generated to process it
//bit 5 : overflow flag - Set when arithmetic operation yieled and invalid two's compliment result
//bit 6 : negative flag - Set if the result of the previous operation had bit 7 set to one

Instruction InstructionTable[256] = {
  //    Low 
  //High |    x0    |    x1    |  x2  |  x3  |    x4    |    x5    |    x6    |  x7  |    x8    |    x9    |    xA    |  xB  |  xC  |    xD    |    xE    |  xF  |
  /* 0x */{BRK, IMPL},{ORA, IND},NOPER,NOPER,   NOPER,  {ORA, ZPG}, {ASL, ZPG},NOPER, {PHP, IMPL},{ORA,IMM},{ASL, ACC},NOPER, NOPER, {ORA, ABS},{ASL, ABS}, NOPER,
  /* 1x */{BPL, REL} ,{ORA, IDY},NOPER,NOPER,   NOPER,  {ORA, ZPX}, {ASL, ZPX},NOPER, {CLC, IMPL},{ORA, ABY}, NOPER,   NOPER, NOPER, {ORA, ABX},{ASL, ABX}, NOPER, 
  /* 2x */{JSR, ABS} ,{AND, IDX},NOPER,NOPER, {BIT,ZPG},{AND, ZPG}, {ROL, ZPG},NOPER, {PLP, IMPL},{AND,IMM},{ROL, ACC},NOPER,{BIT,ABS},{AND,ABS},{ROL,ABS}, NOPER,
  /* 3x */{BMI, REL} ,{AND, IDY},NOPER,NOPER,   NOPER,  {AND, ZPX}, {ROL, ZPX},NOPER, {SEC, IMPL},{AND,ABY},  NOPER,   NOPER, NOPER, {AND, ABX},{ROL, ABX}, NOPER, 
  /* 4x */{RTI, IMPL},{EOR, IDX},NOPER,NOPER,   NOPER,  {EOR, ZPG}, {LSR, ZPG},NOPER, {PHA, IMPL},{EOR,IMM},{LSR, ACC},NOPER,{JMP,ABS},{EOR,ABS},{LSR,ABS}, NOPER,
  /* 5x */{BVC, REL} ,{EOR, IDY},NOPER,NOPER,   NOPER,  {EOR, ZPX}, {LSR, ZPX},NOPER, {CLI, IMPL},{EOR,ABY},  NOPER,   NOPER, NOPER, {EOR, ABX},{LSR, ABX}, NOPER,
  /* 6x */{RTS, IMPL},{ADC, IDX},NOPER,NOPER,   NOPER,  {ADC, ZPG}, {ROR, ZPG},NOPER, {PLA, IMPL},{ADC,IMM},{ROR, ACC},NOPER,{JMP,IND},{ADC,ABS},{ROR,ABS}, NOPER,
  /* 7x */{BVS, REL} ,{ADC, IDY},NOPER,NOPER,   NOPER,  {ADC, ZPX}, {ROR, ZPX},NOPER, {SEI, IMPL},{ADC,ABY},  NOPER,   NOPER, NOPER, {ADC, ABX},{ROR, ABX}, NOPER,
  /* 8x */  NOPER,    {STA, IDX},NOPER,NOPER, {STY,ZPG},{STA, ZPG}, {STX, ZPG},NOPER, {DEY, IMPL},  NOPER, {TXA, IMPL},NOPER,{STY,ABS},{STA,ABS},{STX,ABS}, NOPER,
  /* 9x */{BCC, REL} ,{STA, IDY},NOPER,NOPER, {STY,ZPX},{STA, ZPX}, {STX, ZPX},NOPER, {TYA, IMPL},{STA,ABY},{TXS,IMPL},NOPER, NOPER, {STA, ABX},   NOPER,   NOPER,
  /* Ax */{LDY, IMM},{LDA,IDY},{LDX,IMM},NOPER,{LDY,ZPG},{LDA,ZPG}, {LDX, ZPG},NOPER, {TAY, IMPL},{LDA,IMM},{TAX,IMPL},NOPER,{LDY,ABS},{LDA,ABS},{LDX,ABS}, NOPER,
  /* Bx */{BCS, REL} ,{LDA, IDY},NOPER,NOPER, {LDY,ZPX},{LDA, ZPX}, {LDX, ZPY},NOPER, {CLV, IMPL},{LDA,ABY},{TSX,IMPL},NOPER,{LDY,ABX},{LDA,ABX},{LDX,ABY}, NOPER,
  /* Cx */{CPY, IMM} ,{CMP, IDX},NOPER,NOPER, {CPY,ZPG},{CMP, ZPG}, {DEC, ZPG},NOPER, {INY, IMPL},{CMP,IMM},{DEX,IMPL},NOPER,{CPY,ABS},{CMP,ABS},{DEC,ABS}, NOPER,
  /* Dx */{BNE, REL} ,{CMP, IDY},NOPER,NOPER,   NOPER,  {CMP, ZPX}, {DEC, ZPX},NOPER, {CLD, IMPL},{CMP,ABY},  NOPER,   NOPER, NOPER, {CMP, ABX} ,{DEC,ABX}, NOPER, 
  /* Ex */{CPX, IMM} ,{SBC, IDX},NOPER,NOPER, {CPX,ZPG},{SBC, ZPG}, {INC, ZPG},NOPER, {INX, IMPL},{SBC,IMM},{NOP,IMPL},NOPER,{CPX,ABS},{SBC,ABS},{INC,ABS}, NOPER,
  /* Fx */{BEQ, REL} ,{SBC, IDY},NOPER,NOPER,   NOPER,  {SBC, ZPX}, {INC, ZPX},NOPER, {SED, IMPL},{SBC,ABY},  NOPER,   NOPER, NOPER, {SBC, ABX} ,{INC,ABX}, NOPER
}

typedef struct cpu {
  unsigned short pc;
  unsigned char sp;
  unsigned char acc;
  unsigned char iX;
  unsigned char IY;
  unsigned char status;
  Instruction current_instruction;
}

#endif // !CPU_6502_H


