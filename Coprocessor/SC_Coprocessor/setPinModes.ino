#include "definitions.h"

void setPinModes(){
  pinMode(neopixelPin, OUTPUT);
  pinMode(slider1TouchPin, INPUT_PULLUP);
  pinMode(slider2TouchPin, INPUT_PULLUP);
  pinMode(slider3TouchPin, INPUT_PULLUP);
  pinMode(slider4TouchPin, INPUT_PULLUP);
}
