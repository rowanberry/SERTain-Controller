#include "definitions.h"
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
  runLCD();
  comSend();
  runSliderMotors();
  menu();
}
