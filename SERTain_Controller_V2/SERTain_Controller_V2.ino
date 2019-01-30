#include "definitions.h"
void setup() {
  lcd.init();
  lcd.backlight();
  setPinModes();
  if(!digitalRead(enablePin)){
    startupSafety();
  }
  //createReferenceVals();
  FastLED.addLeds<NEOPIXEL, neopixelPin>(leds, 32);
  Serial.begin(9600);
}

void loop() {
  readInputs();
  runLights();
  runMainMotors();
  // runSliderMotors();
  menu();
}
