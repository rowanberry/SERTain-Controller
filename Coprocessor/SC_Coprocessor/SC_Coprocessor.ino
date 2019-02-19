#include "definitions.h"
int reading = 0;
void setup() {
  Serial.begin(9600);
  Serial1.begin(2000000);
}

void loop() {
  while(Serial1.available() >= 2){
    comReceive();
  }
  Serial.print(slider1Set);
  Serial.print(" ");
  Serial.print(slider2Set);
  Serial.print(" ");
  Serial.print(slider3Set);
  Serial.print(" ");
  Serial.print(slider4Set);
  Serial.println();
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
}
