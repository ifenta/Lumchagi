void endlessMode(){
  unsigned long toneTime;
  bool toneOn = false;
  endlessScore = 0;
  int endlessMiss = 0;
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

      if(toneOn && (millis()-toneTime)>750){
        noTone(speakerPin);
      }
      
      if((millis()-prevTime)< initalWaitTime){
        noTone(speakerPin);
        toneOn = true;
        toneTime = millis();
        tone(speakerPin, 2000);
        endlessMiss +=1;
        if(endlessMiss >=3){
          state = false;
          break;
        }
      }
    }
    
  }
  ShiftReg.shift(0);
  lcd.print("Game Over");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.setCursor(7,1);
  lcd.print(endlessScore);
}

