#include "definitions.h"
void lcdWrite(int x, int y, String message){
  lcd.setCursor(x,y);
  lcd.print(message);
}

void displayMotorVals(){
  lcdWrite(0, 0, "M1 " + motor1Val);
}
