#include "Arduino.h"
#include "SR74HC595.h"

SR74HC595::SR74HC595(int latch, int clk, int data){
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data, OUTPUT);

  _latch = latch;
  _clk = clk;
  _data = data;
}

void SR74HC595::shift(int byteVal){
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clk, MSBFIRST, byteVal);  
  digitalWrite(_latch, HIGH);
}

