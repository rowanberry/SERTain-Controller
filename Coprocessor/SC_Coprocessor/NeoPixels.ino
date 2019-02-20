#include "definitions.h"
int bright = 255;
int dim = 30;
void runNeoPixels(){
  if(slowModeOn){
    hue = 160;
  }
  else{
    hue = 0;
  }
  
  for(int i = 0; i <= 6; i++){
    if(i < constrain(map(slider1Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel1[i]] = CHSV(hue, 255, bright);
    }
    else if (i > constrain(map(slider1Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel1[i]] = CHSV(hue, 255, dim);
    }
    else{
      leds[neopixel1[i]] = CHSV(hue, 255, constrain(map(map(slider1Set, 100, 920, 0, 600), i*100, i*100+100, 0, bright), 0, bright));
    }
    leds[neopixel1[0]] = CHSV(hue, 255, bright);
  }


  for(int i = 0; i <= 6; i++){
    if(i < constrain(map(slider2Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel2[i]] = CHSV(hue, 255, bright);
    }
    else if (i > constrain(map(slider2Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel2[i]] = CHSV(hue, 255, dim);
    }
    else{
      leds[neopixel2[i]] = CHSV(hue, 255, constrain(map(map(slider2Set, 100, 920, 0, 600), i*100, i*100+100, 0, bright), 0, bright));
    }
    leds[neopixel2[0]] = CHSV(hue, 255, bright);
  }


  for(int i = 0; i <= 6; i++){
    if(i < constrain(map(slider3Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel3[i]] = CHSV(hue, 255, bright);
    }
    else if (i > constrain(map(slider3Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel3[i]] = CHSV(hue, 255, dim);
    }
    else{
      leds[neopixel3[i]] = CHSV(hue, 255, constrain(map(map(slider3Set, 100, 920, 0, 600), i*100, i*100+100, 0, bright), 0, bright));
    }
    leds[neopixel3[0]] = CHSV(hue, 255, bright);
  }


  for(int i = 0; i <= 6; i++){
    if(i < constrain(map(slider4Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel4[i]] = CHSV(hue, 255, bright);
    }
    else if (i > constrain(map(slider4Set, 100, 920, 0, 6), 0, 6)){
      leds[neopixel4[i]] = CHSV(hue, 255, dim);
    }
    else{
      leds[neopixel4[i]] = CHSV(hue, 255, constrain(map(map(slider4Set, 100, 920, 0, 600), i*100, i*100+100, 0, bright), 0, bright));
    }
    leds[neopixel4[0]] = CHSV(hue, 255, bright);
  } 
  FastLED.show();
}
