#include "definitions.h"
void runLCD(){
  getMotorVals();
  displayMotorVals();
}

void displayMotorVals(){
    lcdWrite(0, 0, "M1 ", constrain(abs(map(motor1Val, 1000, 2000, -100, 100)), 0, 100), "  ");
    lcdWrite(1, 2, "M2 ", constrain(abs(map(motor2Val, 1000, 2000, -100, 100)), 0, 100), "  ");
    lcdWrite(0, 8, "M3 ", constrain(abs(map(motor3Val, 1000, 2000, -100, 100)), 0, 100), "  ");
    lcdWrite(1, 10, "M4 ", constrain(abs(map(motor4Val, 1000, 2000, -100, 100)), 0, 100), "  ");
}






void getMotorVals(){
  if(enabled){
    motor1Val = 1500 + map(slider1Val, 15, 920, 0, scaleFactor) * motor1Direction;
    motor2Val = 1500 + map(slider2Val, 15, 920, 0, scaleFactor) * motor2Direction;
    motor3Val = 1500 + map(slider3Val, 15, 920, 0, scaleFactor) * motor3Direction;
    motor4Val = 1500 + map(slider4Val, 15, 920, 0, scaleFactor) * motor4Direction;
  }
  else{
    motor1Val = 1500;
    motor2Val = 1500;
    motor3Val = 1500;
    motor4Val = 1500;
  }
}








void lcdWrite(int y, int x, String message){ //Multiple lcdWrite fns to allow for extra arguments
  lcd.setCursor(x,y);
  lcd.print(message);
}

void lcdWrite(int y, int x, String message, int val){ //Allows for value argument
  lcd.setCursor(x,y);
  lcd.print(message);
  lcd.print(val);
}

void lcdWrite(int y, int x, String message, int val, String s){
  lcd.setCursor(x,y);
  lcd.print(message);
  lcd.print(val);
  lcd.print(s);
}

void lcdWrite(int y, int x, int val){
  lcd.setCursor(x,y);
  lcd.print(val);
}

void lcdWrite(int y, int x, int val, String s){
  lcd.setCursor(x,y);
  lcd.print(val);
  lcd.print(s);
}
