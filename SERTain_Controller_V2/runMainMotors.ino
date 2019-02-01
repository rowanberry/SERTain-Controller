#include "definitions.h"
void runMainMotors(){
  getMotorDirection();
  getMotorSpeeds();
  writeToMotors();
}

void getMotorDirection(){
  motor1Direction = digitalRead(motor1ReversePin) ? -1:1;
  motor2Direction = digitalRead(motor2ReversePin) ? -1:1;
  motor3Direction = digitalRead(motor3ReversePin) ? -1:1;
  motor4Direction = digitalRead(motor4ReversePin) ? -1:1;
}

void getMotorSpeeds(){
  if(!digitalRead(slowModePin)){
    scaleFactor = 500;
  }
  else{
    scaleFactor = 250;
  }

  if(motor1On){
    motor1Speed = 1500 + map(slider1Val, 15, 920, 0, scaleFactor) * motor1Direction;
  }
  else{
    motor1Speed = 1500;
  }
  if(motor2On){
    motor2Speed = 1500 + map(slider2Val, 15, 929, 0, scaleFactor) * motor2Direction;
  }
  else{
    motor2Speed = 1500;
  }
  if(motor3On){
    motor3Speed = 1500 + map(slider3Val, 15, 930, 0, scaleFactor) * motor3Direction;
  }
  else{
    motor3Speed = 1500;
  }
  if(motor4On){
    motor4Speed = 1500 + map(slider4Val, 15, 930, 0, scaleFactor) * motor4Direction;
  }
  else{
    motor4Speed = 1500;
  }
}
void writeToMotors(){
  if(enabled){
    motor1.writeMicroseconds(motor1Speed); 
    motor2.writeMicroseconds(motor2Speed); 
    motor3.writeMicroseconds(motor3Speed); 
    motor4.writeMicroseconds(motor4Speed); 
  }
  else{
    motor1.writeMicroseconds(1500); 
    motor2.writeMicroseconds(1500); 
    motor3.writeMicroseconds(1500); 
    motor4.writeMicroseconds(1500); 
  }
}
