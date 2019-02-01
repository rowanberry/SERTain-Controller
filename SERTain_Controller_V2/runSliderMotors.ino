#include "definitions.h"
void runSliderMotors(){
  setMotors();
  sliderMotor1Forwards = true;
  sliderMotor1Speed = 100;
}

void setMotors(){

analogWrite(sliderMotor4SpeedPin, 255);
digitalWrite(sliderMotor4ForwardsPin, HIGH);
digitalWrite(sliderMotor4BackwardsPin, LOW);
  
//  analogWrite(sliderMotor1SpeedPin, sliderMotor1Speed);
//  if(sliderMotor1Forwards){
//    digitalWrite(sliderMotor1ForwardsPin, HIGH);
//    digitalWrite(sliderMotor1BackwardsPin, LOW);
//  }
//  else{
//    digitalWrite(sliderMotor1ForwardsPin, LOW);
//    digitalWrite(sliderMotor1BackwardsPin, HIGH);
//  }
//
//
//  
//  analogWrite(sliderMotor2SpeedPin, sliderMotor2Speed);
//  if(sliderMotor2Forwards){
//    digitalWrite(sliderMotor2ForwardsPin, HIGH);
//    digitalWrite(sliderMotor2BackwardsPin, LOW);
//  }
//  else{
//    digitalWrite(sliderMotor2ForwardsPin, LOW);
//    digitalWrite(sliderMotor2BackwardsPin, HIGH);
//  }
//
//
//  
//  analogWrite(sliderMotor3SpeedPin, sliderMotor3Speed);
//  if(sliderMotor3Forwards){
//    digitalWrite(sliderMotor3ForwardsPin, HIGH);
//    digitalWrite(sliderMotor3BackwardsPin, LOW);
//  }
//  else{
//    digitalWrite(sliderMotor3ForwardsPin, LOW);
//    digitalWrite(sliderMotor3BackwardsPin, HIGH);
//  }
//
//
//  
//  analogWrite(sliderMotor4SpeedPin, sliderMotor4Speed);
//  if(sliderMotor4Forwards){
//    digitalWrite(sliderMotor4ForwardsPin, HIGH);
//    digitalWrite(sliderMotor4BackwardsPin, LOW);
//  }
//  else{
//    digitalWrite(sliderMotor4ForwardsPin, LOW);
//    digitalWrite(sliderMotor4BackwardsPin, HIGH);
//  }
}
