#include "definitions.h"
void setup() {
  setPinModes();
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
//  Serial.print("slider1Val: ");
//  Serial.print(slider1Val);
//  Serial.print("  slider2Val: ");
//  Serial.print(slider2Val);
//  Serial.print("  slider3Val: ");
//  Serial.print(slider3Val);
//  Serial.print("  slider4Val: ");
//  Serial.print(slider4Val);
//  Serial.println();
//Serial.print("  slider1Touch: ");
//Serial.print(slider1Touch);
//Serial.print("  slider2Touch: ");
//Serial.print(slider2Touch);
//Serial.print("  slider3Touch: ");
//Serial.print(slider3Touch);
//Serial.print("  slider4Touch: ");
//Serial.print(slider4Touch);
//Serial.println();
//  Serial.print(slider1Mapped06);
//  Serial.print(slider2Mapped06);
//  Serial.print(slider3Mapped06);
//  Serial.print(slider4Mapped06);
//  Serial.println();
//Serial.print(motor3.read()); 
//Serial.println();
//Serial.print(analogRead(slider3SweepPin));
//Serial.println();
}
