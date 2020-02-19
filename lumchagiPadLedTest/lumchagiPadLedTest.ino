#include <MCP3008.h>

// define pin connections
#define CS_PIN 2
#define CLOCK_PIN 5
#define MOSI_PIN 3
#define MISO_PIN 4

//Pin connected to ST_CP of 74HC595
int latchPin = 16;
//Pin connected to SH_CP of 74HC595
int clockPin = 17;
////Pin connected to DS of 74HC595
int dataPin = 15;

// put pins inside MCP3008 constructor
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

byte ledShiftVal[] = {1,2,4,8,16,32,64,128};

int sensorValConst[] = {0,0,0,0,0,0,0,0}; //value of pad sensors

int sensorVal[8];

int dataSendArray[8];

byte dataSend;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for(int i =0; i<10; i++){
    for(int k=0; k<8; k++){
      sensorValConst[k] += adc.readADC(k);
    }
  }
  for(int i=0; i<8; i++){
    sensorValConst[i] /= 10;
  }
}

void loop() {
  //count up routine
  for(int i =0; i<8; i++){
    sensorVal[i] = adc.readADC(i);
    if(sensorVal[i] > (sensorValConst[i] +150)) dataSendArray[i] = 1;
  }

  for(int j =0; j<8;j++){
    dataSend += ledShiftVal[j]*dataSendArray[j];
  }

   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, MSBFIRST, dataSend);   
   //return the latch pin high to signal chip that it 
   //no longer needs to listen for information
   digitalWrite(latchPin, HIGH);
   delay(10);
   
  for(int k=0; k<8; k++){
    dataSendArray[k] =0;
  }
  dataSend =0;
} 
