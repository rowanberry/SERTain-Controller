#include "definitions.h"
void runSliderMotors(){
  slider2Set = 500;
  pid();
  writeToSliderMotors();
}


void pid(){
  if(slider2Val < slider2Set){
  setSliderMotors(2, (map(abs(slider2Val-slider2Set), 0, 1023, 0, 255)), true);
  }
  else if(slider2Val > slider2Set){
  setSliderMotors(2, (map(abs(slider2Val-slider2Set), 0, 1023, 0, 255)), false);
  }
  else{
    setSliderMotors(2, 0, true);
  }
}



void setSliderMotors(int sliderNum, int speed, bool forwards){
  if(sliderNum == 1){
    sliderMotor1Speed = speed;
    sliderMotor1Forwards = forwards;
  }
  if(sliderNum == 2){
    sliderMotor2Speed = speed;
    sliderMotor2Forwards = forwards;
  }
  if(sliderNum == 3){
    sliderMotor3Speed = speed;
    sliderMotor3Forwards = forwards;
  }
  if(sliderNum == 4){
    sliderMotor4Speed = speed;
    sliderMotor4Forwards = forwards;
  }
}



void writeToSliderMotors(){
  if(sliderMotor1Forwards){
    digitalWrite(sliderMotor1ForwardsPin, HIGH);
    digitalWrite(sliderMotor1BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor1ForwardsPin, LOW);
    digitalWrite(sliderMotor1BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor1SpeedPin, sliderMotor1Speed);
  
  if(sliderMotor2Forwards){
    digitalWrite(sliderMotor2ForwardsPin, HIGH);
    digitalWrite(sliderMotor2BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor2ForwardsPin, LOW);
    digitalWrite(sliderMotor2BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor2SpeedPin, sliderMotor2Speed);
  
  if(sliderMotor3Forwards){
    digitalWrite(sliderMotor3ForwardsPin, HIGH);
    digitalWrite(sliderMotor3BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor3ForwardsPin, LOW);
    digitalWrite(sliderMotor3BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor3SpeedPin, sliderMotor3Speed);
  
  if(sliderMotor4Forwards){
    digitalWrite(sliderMotor4ForwardsPin, HIGH);
    digitalWrite(sliderMotor4BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor4ForwardsPin, LOW);
    digitalWrite(sliderMotor4BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor4SpeedPin, sliderMotor4Speed);
}
