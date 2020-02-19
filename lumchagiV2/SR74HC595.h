#ifndef SR74HC595_h
#define SR74HC595_h

#include "Arduino.h"

class SR74HC595
{
  public:
    SR74HC595(int latch, int clk, int data);
    void shift(int byteVal);
  private:
    int _latch;
    int _clk;
    int _data;
};

#endif
