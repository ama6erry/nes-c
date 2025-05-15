#ifndef CPU_6502_H
#define CPU_6502_H

typedef enum {
  NONE, 
  IMP, //implicit
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
  IXD, //indexed indirect 
  IDX, //indirect indexed 
} addressMode;

typedef enum {
  LDA,
  LDX,
  LDY,
  STA,
  STX,
  STY,
  TAX,
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
  addressMode mode;
  opcode code;
}

#endif // !CPU_6502_H


