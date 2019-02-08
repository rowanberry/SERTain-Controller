#include "definitions.h"
void readInputs(){
  readSwitches();
  getSliderVal();
  getSliderTouch();
  //getSliderNum();
  //sliderNum = 1;
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

/*void rotaryAISR() {
  if(digitalRead(rotaryPinA) != digitalRead(rotaryPinB)){
    rotaryPos++;
    incrementMotorVals(1);
  }
  else{
    rotaryPos--;
    incrementMotorVals(-1);
  }
}

void rotaryBISR(){
  if(digitalRead(rotaryPinA) == digitalRead(rotaryPinB)){
    rotaryPos++;
    incrementMotorVals(1);
  }
  else{
    rotaryPos--;
    incrementMotorVals(-1);
  }
}*/


void getSliderVal(){
  slider1Val = analogRead(slider1SweepPin);
  slider2Val = analogRead(slider2SweepPin);
  slider3Val = analogRead(slider3SweepPin);
  slider4Val = analogRead(slider4SweepPin);
}

void getSliderTouch(){
  slider1Touch = ADCTouch.read(slider1TouchPin);
  slider2Touch = ADCTouch.read(slider2TouchPin);
  slider3Touch = ADCTouch.read(slider3TouchPin);
  slider4Touch = ADCTouch.read(slider4TouchPin);
}

void createReferenceVals(){
  ref1 = ADCTouch.read(slider1TouchPin);
  ref2 = ADCTouch.read(slider2TouchPin);
  ref3 = ADCTouch.read(slider3TouchPin);
  ref4 = ADCTouch.read(slider4TouchPin);
}
//
//void getSliderNum(){
//  if(!menuOpen){
//    if(slider1Touched){
//      sliderNum = 1;
//    }
//    if(slider2Touched){
//      sliderNum = 2;
//    }
//    if(slider3Touched){
//      sliderNum = 3;
//    }
//    if(slider4Touched){
//      sliderNum = 4;
//    }
//  }
//  else{
//    sliderNum = 0;
//  }
//}
