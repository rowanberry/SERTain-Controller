#include "definitions.h"
byte loop_iteration;

void setup() {
  lcd.init();
  lcd.backlight();
  setPinModes();
  if(!digitalRead(enablePin)){
    startupSafety();
  }
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  readInputs();
  runLights();
  runMainMotors();
  loop_iteration++;
  if(loop_iteration > 100) {
    runLCD();
    loop_iteration = 0;
  }
  comSend();
  runSliderMotors();
  menu();
}
