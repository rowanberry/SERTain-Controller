#include "definitions.h"
void link(){
  if(link1On){
    motor2Speed = motor1Speed;
  }
  if(link2On){
    motor4Speed = motor3Speed;
  }
}
