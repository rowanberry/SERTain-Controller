#include "definitions.h"
void runMainMotors(){
  getMotorSpeeds();
  writeToMotors();
  
}

void getMotorSpeeds(){
  motor1Speed = map(slider1Set, 15, 920, 1000, 2000);
  motor2Speed = map(slider2Set, 15, 929, 1000, 2000);
  motor3Speed = map(slider3Set, 15, 930, 1000, 2000);
  motor4Speed = map(slider4Set, 15, 930, 1000, 2000);
}

void writeToMotors(){
  if(slowModeOn){
    maxPosMotorVal = 1750;
    maxNegMotorVal = 1250;
  }
  else{
    maxPosMotorVal = 2000;
    maxNegMotorVal = 1000;
  }
  if(enabled){
    
    if(motor1On){
      if(motor1Reverse){
        motor1.writeMicroseconds(map(motor1Speed, 1000, 2000, 1500, maxPosMotorVal)); 
      }
      else{
        motor1.writeMicroseconds(map(motor1Speed, 1000, 2000, 1500, maxNegMotorVal));
      }
    }
    else{
      motor1.writeMicroseconds(1500);
    }


    
    if(motor2On){
      if(motor2Reverse){
        motor2.writeMicroseconds(map(motor2Speed, 1000, 2000, 1500, maxPosMotorVal)); 
      }
      else{
        motor2.writeMicroseconds(map(motor2Speed, 1000, 2000, 1500, maxNegMotorVal));
      }
    }
    else{
      motor2.writeMicroseconds(1500);
    }
    if(motor3On){
      if(motor3Reverse){
        motor3.writeMicroseconds(map(motor3Speed, 1000, 2000, 1500, maxPosMotorVal)); 
      }
      else{
        motor3.writeMicroseconds(map(motor3Speed, 1000, 2000, 1500, maxNegMotorVal));
      }
    }
    else{
      motor3.writeMicroseconds(1500);
    }
    if(motor4On){
      if(motor4Reverse){
        motor4.writeMicroseconds(map(motor4Speed, 1000, 2000, 1500, maxPosMotorVal)); 
      }
      else{
        motor4.writeMicroseconds(map(motor4Speed, 1000, 2000, 1500, maxNegMotorVal));
      }
    }
    else{
      motor4.writeMicroseconds(1500);
    }
  }
  else{
   motor1.writeMicroseconds(1500);
   motor2.writeMicroseconds(1500);
   motor3.writeMicroseconds(1500);
   motor4.writeMicroseconds(1500);
  }
}
