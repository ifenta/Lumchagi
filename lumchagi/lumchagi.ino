//1 analog input for buttons
//3 shift register pins (digital)
//4 MCP3008 pins (digital)
//6 display pins (digital)
//1 pwm output for speaker

#include <LiquidCrystal.h>
#include <MCP3008.h>
#include "ShiftReg74HC595.h"

// Pins for Shift Register //
const uint8_t shift_latchPin = ;
const uint8_t shift_clkPin = ;
const uint8_t shift_dataPin = ;

// Pins for ADC //
const uint8_t adc_csPin = ;
const uint8_t adc_clkPin = ;
const uint8_t adc_misoPin = ;
const uint8_t adc_mosiPin = ;

// Pins for LCD //
const uint8_t lcd_rsPin = ;
const uint8_t lcd_enablePin = ;
const uint8_t lcd_d4Pin = ;
const uint8_t lcd_d5Pin = ;
const uint8_t lcd_d6Pin = ;
const uint8_t lcd_d7Pin = ;

const uint8_t buttonReadPin = ;

const uint8_t speakerPin = ;

int ledPinOn;
byte ledShiftVal[] = [1,2,4,8,16,32,64,128];
int sensorVal[8]; //value of pad sensors

int endlessScore;
int sensorThreshold = 200; //threshold to make a hit
unsigned long prevTime;
unsigned long initialWaitTime = 1500; //starting time for how long it takes to for someone to hit a pad
unsigned long classicTime = 30000; //how long classic mode is

MCP3008 adc(adc_clkPin, adc_mosiPin, adc_mosiPin, adc_csPin);
LiquidCrystal lcd(lcd_rsPin, lcd_enablePin, lcd_d4Pin, lcd_d5Pin, lcd_d6Pin, lcd_d7Pin);
ShiftReg74HC595 ShiftReg74HC595(shift_latchPin, shift_clkPin, shift_dataPin);

void setup() {
  pinMode(speakerPin, OUTPUT);

  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
}

void loop() {
  // put your main code here, to run repeatedly:

}
