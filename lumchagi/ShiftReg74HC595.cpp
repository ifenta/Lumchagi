#include "Arduino.h"
#include "ShiftReg74HC595.h"

ShiftReg74HC595::ShiftReg74HC595(int latch, int clk, int data){
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);

  _latch = latch;
  _clk = clk;
  _data = data;
}

void ShiftReg74HC595::shift(int byteVal){
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clk, MSBFIRST, byteVal);  
  digitalWrite(_latch, HIGH);
}

