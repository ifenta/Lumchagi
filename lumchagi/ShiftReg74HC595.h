#ifndef ShiftReg74HC595_h
#define ShiftReg74HC595_h

#include "Arduino.h"

class ShiftReg74HC595
{
  public:
    ShiftReg74HC595(int latch, int clk, int data);
    void shift(int byteVal);
  private:
    int _latch;
    int _clk;
    int _data;
};

#endif
