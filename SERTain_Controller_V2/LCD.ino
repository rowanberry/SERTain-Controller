#include "definitions.h"
void runLCD(){
  displayMotorVals();
}

void displayMotorVals(){
    lcdWrite(0, 0, "M1 ", constrain(abs(map(motor1Speed, 1000, 2000, -100, 100)), 0, scaleFactor/5), "  ");
    lcdWrite(1, 2, "M2 ", constrain(abs(map(motor2Speed, 1000, 2000, -100, 100)), 0, scaleFactor/5), "  ");
    lcdWrite(0, 8, "M3 ", constrain(abs(map(motor3Speed, 1000, 2000, -100, 100)), 0, scaleFactor/5), "  ");
    lcdWrite(1, 10, "M4 ", constrain(abs(map(motor4Speed, 1000, 2000, -100, 100)), 0, scaleFactor/5), "  ");
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
