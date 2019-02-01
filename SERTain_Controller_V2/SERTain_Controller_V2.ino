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
  readInputs();
  runLights();
  runMainMotors();
  runLCD();
  // runSliderMotors();
  menu();
  Serial.print(slider1Touch);
  Serial.print("   ");
  Serial.print(slider2Touch);
  Serial.print("   ");
  Serial.print(slider3Touch);
  Serial.print("   ");
  Serial.print(slider4Touch);
  Serial.println();
}
