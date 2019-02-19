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
  // runSliderMotors();
  menu();
//  Serial.print(slider1Set);
//  Serial.print(" ");
//  Serial.print(slider2Set);
//  Serial.print(" ");
//  Serial.print(slider3Set);
//  Serial.print(" ");
//  Serial.print(slider4Set);
//  Serial.print(" ");
//  Serial.print(slowModeOn);
//  Serial.println();
}
