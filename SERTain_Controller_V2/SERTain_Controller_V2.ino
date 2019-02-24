#include "definitions.h"
void setup() {
  lcd.init();
  lcd.backlight();
  setPinModes();
  if(!digitalRead(enablePin)){
    startupSafety();
  }
  lcdWrite(0, 0, "LCD disabled for PID testing");
  lcdWrite(1, 0, "PID testing");
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  readInputs();
  runLights();
  runMainMotors();
  //runLCD();       commented out to make pid work
  comSend();
  runSliderMotors();
  menu();
}
