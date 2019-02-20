#include "definitions.h"
void readInputs(){
  readSwitches();
  getSliderVal();
  slider1Set = slider1Val;
  slider2Set = slider2Val;
  slider3Set = slider3Val;
  slider4Set = slider4Val;
}

void readSwitches(){
  enabled = !digitalRead(enablePin);
  link1Pressed = digitalRead(link1Pin);
  link2Pressed = digitalRead(link2Pin);
  slowModeOn = digitalRead(slowModePin);
  accelerates = digitalRead(accelerationPin);
  motor1On = !digitalRead(motor1OnPin);
  motor2On = !digitalRead(motor2OnPin);
  motor3On = !digitalRead(motor3OnPin);
  motor4On = !digitalRead(motor4OnPin);
  motor1Reverse = digitalRead(motor1ReversePin);
  motor2Reverse = digitalRead(motor2ReversePin);
  motor3Reverse = digitalRead(motor3ReversePin);
  motor4Reverse = digitalRead(motor4ReversePin);
  rotaryButtonPressed = digitalRead(rotaryButtonPin);
}

void getSliderVal(){
  slider1Val = analogRead(slider1SweepPin);
  slider2Val = analogRead(slider2SweepPin);
  slider3Val = analogRead(slider3SweepPin);
  slider4Val = analogRead(slider4SweepPin);
}
