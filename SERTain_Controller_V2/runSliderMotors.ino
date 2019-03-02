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

#define pid_p .3
#define pid_i .007
void pid(){
  s2Error = slider2Set - slider2Val;
  if(abs(s2Output) < 170){
    s2ErrorSum += (millis()-lastPid)/10 * s2Error;
  }
  s2Output = constrain(s2Error * pid_p + s2ErrorSum * pid_i, -255, 255);
  setSliderMotors(2, s2Output);
  lastPid = millis();
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
  analogWrite(sliderMotor2SpeedPin, constrain(sliderMotor2Speed, 0, 255));
}
