#include "definitions.h"
int sliderCom[4];

void comSend(){
  for(int i=0; i<4; i++){
    Serial1.write(201+i);
    Serial1.write(getSliderComVals(i));
  } 
  if(slowModeOn){   
    Serial1.write(205);
    Serial1.write(1);
  }
  else{
    Serial1.write(205);
    Serial1.write(0);
  }
}

void comReceive(){
  
}

int getSliderComVals(int sliderIndex){
  sliderCom[0] = constrain(map(slider1Set, 0, 1023, 0, 200), 0, 200);
  sliderCom[1] = constrain(map(slider2Set, 0, 1023, 0, 200), 0, 200);
  sliderCom[2] = constrain(map(slider3Set, 0, 1023, 0, 200), 0, 200);
  sliderCom[3] = constrain(map(slider4Set, 0, 1023, 0, 200), 0, 200);
  return sliderCom[sliderIndex];
}
