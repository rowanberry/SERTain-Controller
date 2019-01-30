#include "definitions.h"
void startupSafety(){
  lcdWrite(0, 0, "Disable to Start");
  for(int i = 0; i <= 6; i ++){
    if(!digitalRead(enablePin)){
      lcd.setBacklight(0);
      delay(10);
      lcd.setBacklight(1);
      delay(10);
    }
  }
  while(!digitalRead(enablePin));
}
