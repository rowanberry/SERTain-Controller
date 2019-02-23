#include "definitions.h"
void runSliderMotors(){
  slider1Set = 500;
  slider2Set = 500;
  slider3Set = 500;
  slider4Set = 500;
  if(enabled){
    pid();
  }
  else{
    setSliderMotors(1, 0);
    setSliderMotors(2, 0);
    setSliderMotors(3, 0);
    setSliderMotors(4, 0);
    slider1ErrorSum = 0;
    slider2ErrorSum = 0;
    slider3ErrorSum = 0;
    slider4ErrorSum = 0;
    lastPid = millis();
  }
  writeToSliderMotors();
}

#define pid_p_1 0.28
#define pid_i_1 0.001
#define pid_d_1 1.5
#define pid_p_2 0.28
#define pid_i_2 0.001
#define pid_d_2 1.5
#define pid_p_3 .28
#define pid_i_3 0.001
#define pid_d_3 1.5
#define pid_p_4 0.28
#define pid_i_4 0.001
#define pid_d_4 1.5

void pid(){
  pidTime = millis() - lastPid;
  
  slider1Error = slider1Set - slider1Val;
  slider2Error = slider2Set - slider2Val;
  slider3Error = slider3Set - slider3Val;
  slider4Error = slider4Set - slider4Val;

  
  if(abs(slider1Output) < 250){
     slider1ErrorSum += pidTime * slider1Error;
  }
  if(abs(slider2Output) < 250){
     slider2ErrorSum += pidTime * slider2Error;
  }
  if(abs(slider3Output) < 250){
     slider3ErrorSum += pidTime * slider3Error;
  }
  if(abs(slider4Output) < 250){
     slider4ErrorSum += pidTime * slider4Error;
  }
  
  slider1dError = (slider1Error - slider1OldError) / pidTime;
  slider2dError = (slider2Error - slider2OldError) / pidTime;
  slider3dError = (slider3Error - slider3OldError) / pidTime;
  slider4dError = (slider4Error - slider4OldError) / pidTime;
  
  slider1Output =  constrain(slider1Error * pid_p_1 + slider1ErrorSum * pid_i_1 + slider1dError * pid_d_1, -255, 255);
  slider2Output =  constrain(slider2Error * pid_p_2 + slider2ErrorSum * pid_i_2 + slider2dError * pid_d_2, -255, 255);
  slider3Output =  constrain(slider3Error * pid_p_3 + slider3ErrorSum * pid_i_3 + slider3dError * pid_d_3, -255, 255);
  slider4Output =  constrain(slider4Error * pid_p_4 + slider4ErrorSum * pid_i_4 + slider4dError * pid_d_4, -255, 255);

  //this helps with the poor response of the motors at low values
    
  if(abs(slider1Output) > 10 && abs(slider1Output) < 80) {
    if(slider1Output > 0) {
      slider1Output += 50;
    } else {
      slider1Output -=50;
    }
  }
  if(abs(slider2Output) > 10 && abs(slider2Output) < 80) {
    if(slider2Output > 0) {
      slider2Output += 50;
    } else {
      slider2Output -=50;
    }
  }
  if(abs(slider3Output) > 10 && abs(slider3Output) < 80) {
    if(slider3Output > 0) {
      slider3Output += 50;
    } else {
      slider3Output -=50;
    }
  }
  if(abs(slider4Output) > 10 && abs(slider4Output) < 80) {
    if(slider4Output > 0) {
      slider4Output += 50;
    } else {
      slider4Output -=50;
    }
  }
  
  setSliderMotors(1,slider1Output);
  setSliderMotors(2,slider2Output);
  setSliderMotors(3,slider3Output);
  setSliderMotors(4,slider4Output);

  slider1OldError = slider1Error;
  slider2OldError = slider2Error;
  slider3OldError = slider3Error;
  slider4OldError = slider4Error;
  
  lastPid = millis();
}



void setSliderMotors(int sliderNum, int speed){
  if(sliderNum == 1){
    sliderMotor1Speed = abs(speed);
    if(speed > 0){
      sliderMotor1Forwards = true;
    }
    else if (speed < 0){
      sliderMotor1Forwards = false;
    }
  }
  if(sliderNum == 2){
    sliderMotor2Speed = abs(speed);
    if(speed > 0){
      sliderMotor2Forwards = true;
    }
    else if (speed < 0){
      sliderMotor2Forwards = false;
    }
  }
  if(sliderNum == 3){
    sliderMotor3Speed = abs(speed);
    if(speed > 0){
      sliderMotor3Forwards = true;
    }
    else if (speed < 0){
      sliderMotor3Forwards = false;
    }
  }
  if(sliderNum == 4){
    sliderMotor4Speed = abs(speed);
    if(speed > 0){
      sliderMotor4Forwards = true;
    }
    else if (speed < 0){
      sliderMotor4Forwards = false;
    }
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
  if(sliderMotor2Forwards){
    digitalWrite(sliderMotor2ForwardsPin, HIGH);
    digitalWrite(sliderMotor2BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor2ForwardsPin, LOW);
    digitalWrite(sliderMotor2BackwardsPin, HIGH);
  }
  if(sliderMotor3Forwards){
    digitalWrite(sliderMotor3ForwardsPin, HIGH);
    digitalWrite(sliderMotor3BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor3ForwardsPin, LOW);
    digitalWrite(sliderMotor3BackwardsPin, HIGH);
  }
  if(sliderMotor4Forwards){
    digitalWrite(sliderMotor4ForwardsPin, HIGH);
    digitalWrite(sliderMotor4BackwardsPin, LOW);
  }
  else{
    digitalWrite(sliderMotor4ForwardsPin, LOW);
    digitalWrite(sliderMotor4BackwardsPin, HIGH);
  }
  analogWrite(sliderMotor1SpeedPin, sliderMotor1Speed);
  analogWrite(sliderMotor2SpeedPin, sliderMotor2Speed);
  analogWrite(sliderMotor3SpeedPin, sliderMotor3Speed);
  analogWrite(sliderMotor4SpeedPin, sliderMotor4Speed);
}
