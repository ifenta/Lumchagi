void readSensors(){
  for(int i = 0; i<8;i++){
    sensorVal[i] = adc.readADC(i);
  }
}

