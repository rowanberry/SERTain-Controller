#include "definitions.h"
int sliderCom[4];

void comSend(){
  for(int i=0; i<4; i++){
    Serial1.write(201+i);
    Serial1.write(getSliderComVals(i));
  }
}

int getSliderComVals(int sliderIndex){
  sliderCom[0] = map(slider1Set, 0, 1023, 0, 200);
  sliderCom[1] = map(slider2Set, 0, 1023, 0, 200);
  sliderCom[2] = map(slider3Set, 0, 1023, 0, 200);
  sliderCom[3] = map(slider4Set, 0, 1023, 0, 200);
  return sliderCom[sliderIndex];
}
