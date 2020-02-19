void classicMode(){
  classicScore = 0;
  unsigned long toneTime;
  bool toneOn = false;
  unsigned long startTime = millis();
  bool state = true;
  int padNum;
  while(state){
    padNum = random(8);
    ShiftReg.shift(ledShiftVal[padNum]);
    prevTime = millis();
    while(state){
      readSensors();
      if(sensorVal[padNum] > sensorThreshold){
        noTone(speakerPin);
        toneOn = true;
        toneTime = millis();
        tone(speakerPin, 4000);
        endlessScore++;
        break;
      }
      
      if((millis()-prevTime)< initalWaitTime){
        noTone(speakerPin);
        toneOn = true;
        toneTime = millis();
        tone(speakerPin, 2000)
        break;
      }

      if(toneOn && (millis()-toneTime)>750){
        noTone(speakerPin);
      }
      
      if((millis()-startTime) > classicTime){
        state=false;
        break;
      }
    }
    
  }

  ShiftReg.shift(0);
  lcd.print("Time up!");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.setCursor(7,1);
  lcd.print(classicScore);

}

