#include "definitions.h"
int reading = 0;
int touchNum = 0;
bool touch[4];
int touchPin[] = {A0, A1, A2, A3};
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  setPinModes();
  FastLED.addLeds<NEOPIXEL, neopixelPin>(leds, 32);
}

void loop() {
  while(Serial1.available() >= 16){
    comReceive();
  }
  getTouch();
  runNeoPixels();
  Serial.print(touch[0]);
  Serial.print(" ");
  Serial.print(touch[1]);
  Serial.print(" ");
  Serial.print(touch[2]);
  Serial.print(" ");
  Serial.print(touch[3]);
  Serial.println();
}

void comSend(){
  for (int i = 0; i < 4; i++){
    Serial1.write(201+i);
    Serial.write(1);
  }
}

void comReceive(){
  reading = Serial1.read();
  if(reading == 201){
    reading = Serial1.read();
    if(reading <= 200){
      slider1Set = map(reading, 0, 200, 0, 1023);
    }
  }
  
  if(reading == 202){
    reading = Serial1.read();
    if(reading <= 200){
      slider2Set = map(reading, 0, 200, 0, 1023);
    }
  }
  
  if(reading == 203){
    reading = Serial1.read();
    if(reading <= 200){
      slider3Set = map(reading, 0, 200, 0, 1023);
    }
  }
  
  if(reading == 204){
    reading = Serial1.read();
    if(reading <= 200){
      slider4Set = map(reading, 0, 200, 0, 1023);
    }
  }
  
  if(reading == 205){
    reading = Serial1.read();
    if(reading <= 200){
      if(reading == 1){
        slowModeOn = true;
      }
      else{
        slowModeOn = false;
      }
    }
  }
}

void getTouch(){
  if(touchNum < 4){
    touchNum++;
  }
  else{
    touchNum = 0;
  }
  if(ADCTouch.read(touchPin[touchNum]) > 750){
    touch[touchNum] = true;
  }
  else{
    touch[touchNum] = false;
  }
}
