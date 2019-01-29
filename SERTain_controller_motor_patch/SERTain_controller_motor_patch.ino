
// Main Motors update for SERTain Controller - Fixes bug causing motors to behave erratically, more troubleshooting required to determine root cause

#include "definitions.h"  // all definitions for SERTain controller go here
void setup() {
  pinMode(slowModePin, INPUT_PULLUP);
  pinMode(motor1ReversePin, INPUT_PULLUP);
  pinMode(motor2ReversePin, INPUT_PULLUP);
  pinMode(motor3ReversePin, INPUT_PULLUP);
  pinMode(motor4ReversePin, INPUT_PULLUP);
  pinMode(motor1PWMPin, OUTPUT);
  pinMode(motor2PWMPin, OUTPUT);
  pinMode(motor3PWMPin, OUTPUT);
  pinMode(motor4PWMPin, OUTPUT);
  motor1.attach(motor1PWMPin);
  motor2.attach(motor2PWMPin);
  motor3.attach(motor3PWMPin);
  motor4.attach(motor4PWMPin);
  Serial.begin(9600);
}

void loop() { // replace runMainMotors() with this
  readInputs();
  getMotorSpeeds();
  writeToMotors();
  Serial.print(digitalRead(slowModePin));
  Serial.println();
}

void readInputs(){ // add this to read inputs
  slider1Val = analogRead(slider1SweepPin);
  slider2Val = analogRead(slider2SweepPin);
  slider3Val = analogRead(slider3SweepPin);
  slider4Val = analogRead(slider4SweepPin);

  motor1Direction = digitalRead(motor1ReversePin) ? -1:1;
  motor2Direction = digitalRead(motor2ReversePin) ? -1:1;
  motor3Direction = digitalRead(motor3ReversePin) ? -1:1;
  motor4Direction = digitalRead(motor4ReversePin) ? -1:1;
}

void getMotorSpeeds(){  // add this to runMainMotors tab
  if(!digitalRead(slowModePin)){
    scaleFactor = 500;
  }
  else{
    scaleFactor = 250;
  }
  motor1Speed = 1500 + map(slider1Val, 15, 920, 0, scaleFactor) * motor1Direction;
  motor2Speed = 1500 + map(slider2Val, 15, 929, 0, scaleFactor) * motor2Direction;
  motor3Speed = 1500 + map(slider3Val, 15, 930, 0, scaleFactor) * motor3Direction;
  motor4Speed = 1500 + map(slider4Val, 15, 930, 0, scaleFactor) * motor4Direction;

}

void writeToMotors(){ // add this to runMainMotors tab
  motor1.writeMicroseconds(motor1Speed); 
  motor2.writeMicroseconds(motor2Speed); 
  motor3.writeMicroseconds(motor3Speed); 
  motor4.writeMicroseconds(motor4Speed); 
}
