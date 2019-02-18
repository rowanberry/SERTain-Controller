#include "definitions.h"
void setup() {
  lcd.init();
  lcd.backlight();
  setPinModes();
  if(!digitalRead(enablePin)){
    startupSafety();
  }
  //createReferenceVals();
  //FastLED.addLeds<NEOPIXEL, neopixelPin>(leds, 32);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(linkLight2Pin, HIGH);
  readInputs();
  runLights();
  link();
  runMainMotors();
  runLCD();
  // runSliderMotors();
  menu();
  Serial.print(link1Pressed);
  Serial.print(link2Pressed);
  Serial.println();
}
