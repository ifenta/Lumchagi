//1 analog input for buttons
//3 shift register pins (digital)
//4 MCP3008 pins (digital)
//6 display pins (digital)
//1 pwm output for speaker

#include <LiquidCrystal.h>
#include <MCP3008.h>
#include "SR74HC595.h"

// Pins for Shift Register //
const uint8_t shift_latchPin = 16;
const uint8_t shift_clkPin = 17;
const uint8_t shift_dataPin = 15;

// Pins for ADC //
const uint8_t adc_csPin = 2;
const uint8_t adc_clkPin = 5;
const uint8_t adc_misoPin = 4;
const uint8_t adc_mosiPin = 3;

// Pins for LCD //
const uint8_t lcd_rsPin = 7;
const uint8_t lcd_enablePin = 8;
const uint8_t lcd_d4Pin = 9;
const uint8_t lcd_d5Pin = 10;
const uint8_t lcd_d6Pin = 11;
const uint8_t lcd_d7Pin = 12;

const uint8_t buttonReadPin = A0;

const uint8_t speakerPin = 6;

int ledPinOn;
byte ledShiftVal[] = {1,2,4,8,16,32,64,128};
int sensorValConst[] = {0,0,0,0,0,0,0,0}; //inital values
int sensorVal[8]; //value of pad sensors

int classicScore;
int endlessScore;
int sensorThreshold = 100; //threshold to make a hit
unsigned long prevTime;
unsigned long initalWaitTime = 500; //starting time for how long it takes to for someone to hit a pad
unsigned long classicTime = 30000; //how long classic mode is

MCP3008 adc(adc_clkPin, adc_mosiPin, adc_misoPin, adc_csPin);
LiquidCrystal lcd(lcd_rsPin, lcd_enablePin, lcd_d4Pin, lcd_d5Pin, lcd_d6Pin, lcd_d7Pin);
SR74HC595 SR74HC595(shift_latchPin, shift_clkPin, shift_dataPin);

void setup() {
  pinMode(speakerPin, OUTPUT);

  for(int i =0; i<10; i++){
    for(int k=0; k<8; k++){
      sensorValConst[k] += adc.readADC(k);
    }
  }
  for(int i=0; i<8; i++){
    sensorValConst[i] /= 10;
  }

  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.print("Starting Game");
  lcd.setCursor(0, 0);


  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.print("Press Enter");
  lcd.setCursor(0, 0);

  while(analogRead(A0) > 600);
  classicMode();
  delay(100000);
}
