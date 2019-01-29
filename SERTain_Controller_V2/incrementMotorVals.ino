#include "definitions.h"

void incrementMotorVals(int increment){
  if(sliderNum == 1){
    slider1Set += increment;
  }
  if(sliderNum == 2){
    slider2Set += increment;
  }
  if(sliderNum == 3){
    slider3Set += increment;
  }
  if(sliderNum == 4){
    slider4Set += increment;
  }
  increment = 0;
}
