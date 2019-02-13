#include "definitions.h"
void runSliderMotors(){
  slider2Set = 500;
  if(enabled){
    pid();
  }
  else{
    setSliderMotors(2, 0);
    s2ErrorSum = 0;
    lastPid = millis();
  }
  writeToSliderMotors();
}

#define pid_p .1
#define pid_i .0009
void pid(){
  s2Error = slider2Set - slider2Val;
  s2ErrorSum += (millis() - lastPid)/10 * s2Error;
  if((s2Error > 0 && s2ErrorSum < 0)||(s2Error < 0 && s2ErrorSum > 0)){
    s2ErrorSum = 0;
  }
  setSliderMotors(2, constrain(s2Error * pid_p + s2ErrorSum * pid_i, -255, 255));
  lastPid = millis();
 // s2ErrorSum *= .5;
  

 // setSliderMotors(2, map(s2Error, 0, 1023, 0, 255));
}



void setSliderMotors(int sliderNum, int speed){
  if(sliderNum == 2){
    sliderMotor2Speed = abs(speed);
    if(speed > 0){
      sliderMotor2Forwards = true;
    }
    else if (speed < 0){
      sliderMotor2Forwards = false;
    }
  }
}



void writeToSliderMotors(){
  if(sliderMotor2Forwards){
    digitalWrite(sliderMotor2ForwardsPin, HIGH);
    digitalWrite(sliderMotor2BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor2ForwardsPin, LOW);
    digitalWrite(sliderMotor2BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor2SpeedPin, sliderMotor2Speed);
}
