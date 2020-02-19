void classicMode(){
  classicScore = 0;
  unsigned long toneTime;
  bool toneOn = false;
  unsigned long startTime = millis();
  bool state = true;
  int padNum;
  lcd.clear();
  lcd.print("Game Start");
  lcd.setCursor(0, 0);
  
  while(state){
    toneOn =false;
    padNum = random(8);
    while(padNum == 5 || padNum == 7 || padNum ==1) padNum = random(8);
    SR74HC595.shift(ledShiftVal[padNum]);
    prevTime = millis();
    while(state){

      if((millis()-startTime) > classicTime){
        state=false;
        noTone(speakerPin);
        break;
      }
      
      readSensors();
      if(sensorVal[padNum] > (sensorValConst[padNum] + sensorThreshold)){
        toneOn = true;
        toneTime = millis();
        tone(speakerPin, 4000, 200);
        classicScore++;
        break;
      }
      
      else if((millis()-prevTime)> initalWaitTime){
        toneOn = true;
        toneTime = millis();
        tone(speakerPin, 2000, 200);
        break;
      }
    }
    delay(10);
  }

  SR74HC595.shift(0);
  lcd.clear();
  lcd.print("Time up!");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.setCursor(7,1);
  lcd.print(classicScore);

  tone(speakerPin, 4000, 200);
  delay(200);
  tone(speakerPin, 3000, 200);
  delay(200);
  tone(speakerPin, 2000, 200);
  delay(200);
  tone(speakerPin, 1000, 200);
  delay(200);
  tone(speakerPin, 3000, 200);

}

