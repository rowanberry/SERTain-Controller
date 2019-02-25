#include "definitions.h"
void runLights() {
  runBlinky();
  presetLights();
  linkLights();
  mapSliderVals();
}

void mapSliderVals(){
  slider1Mapped06 = constrain(map(slider1Set, 100, 920, 0, 6), 0, 6);
  slider2Mapped06 = constrain(map(slider2Set, 100, 920, 0, 6), 0, 6);
  slider3Mapped06 = constrain(map(slider3Set, 100, 920, 0, 6), 0, 6);
  slider4Mapped06 = constrain(map(slider4Set, 100, 920, 0, 6), 0, 6);
}


void runBlinky(){
  if((millis() - lastBlink) > 250){
    if(enabled) {
      blinkyVal = !blinkyVal;
      digitalWrite(blinkyPin, blinkyVal);
      lastBlink = millis();
    } else {
      digitalWrite(blinkyPin, HIGH);
    }
  }

}

//void neoPixel(){
//  if(slowModeOn){
//    hue = 160;
//  }
//  else{
//    hue = 0;
//  }
//
//
//
//
//  for(int i = 0; i <= 6; i++){
//    if(i < constrain(map(slider1Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel1[i]] = CHSV(hue, 255, 255);
//    }
//    else if (i > constrain(map(slider1Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel1[i]] = CHSV(hue, 255, 0);
//    }
//    else{
//      leds[neopixel1[i]] = CHSV(hue, 255, constrain(map(map(slider1Set, 100, 920, 0, 600), i*100, i*100+100, 0, 255), 0, 255));
//    }
//    leds[neopixel1[0]] = CHSV(hue, 255, 255);
//  }
//
//
//  for(int i = 0; i <= 6; i++){
//    if(i < constrain(map(slider2Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel2[i]] = CHSV(hue, 255, 255);
//    }
//    else if (i > constrain(map(slider2Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel2[i]] = CHSV(hue, 255, 0);
//    }
//    else{
//      leds[neopixel2[i]] = CHSV(hue, 255, constrain(map(map(slider2Set, 100, 920, 0, 600), i*100, i*100+100, 0, 255), 0, 255));
//    }
//    leds[neopixel2[0]] = CHSV(hue, 255, 255);
//  }
//
//
//  for(int i = 0; i <= 6; i++){
//    if(i < constrain(map(slider3Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel3[i]] = CHSV(hue, 255, 255);
//    }
//    else if (i > constrain(map(slider3Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel3[i]] = CHSV(hue, 255, 0);
//    }
//    else{
//      leds[neopixel3[i]] = CHSV(hue, 255, constrain(map(map(slider3Set, 100, 920, 0, 600), i*100, i*100+100, 0, 255), 0, 255));
//    }
//    leds[neopixel3[0]] = CHSV(hue, 255, 255);
//  }
//
//
//  for(int i = 0; i <= 6; i++){
//    if(i < constrain(map(slider4Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel4[i]] = CHSV(hue, 255, 255);
//    }
//    else if (i > constrain(map(slider4Set, 100, 920, 0, 6), 0, 6)){
//      leds[neopixel4[i]] = CHSV(hue, 255, 0);
//    }
//    else{
//      leds[neopixel4[i]] = CHSV(hue, 255, constrain(map(map(slider4Set, 100, 920, 0, 600), i*100, i*100+100, 0, 255), 0, 255));
//    }
//    leds[neopixel4[0]] = CHSV(hue, 255, 255);
//  }
//  FastLED.show();
//}

void presetLights(){
  if(preset1LightOn){
    digitalWrite(preset1LightPin, HIGH);
  }
  else{
    digitalWrite(preset1LightPin, LOW);
  }
  if(preset2LightOn){
    digitalWrite(preset2LightPin, HIGH);
  }
  else{
    digitalWrite(preset2LightPin, LOW);
  }
  if(preset3LightOn){
    digitalWrite(preset3LightPin, HIGH);
  }
  else{
    digitalWrite(preset3LightPin, LOW);
  }
  if(preset4LightOn){
    digitalWrite(preset4LightPin, HIGH);
  }
  else{
    digitalWrite(preset4LightPin, LOW);
  }
}

void linkLights(){
  if (linkLight1On){
    digitalWrite(linkLight1Pin, HIGH);
  }
  else{
    digitalWrite(linkLight1Pin, LOW);
  }
  if (linkLight2On){
    digitalWrite(linkLight2Pin, HIGH);
  }
  else{
    digitalWrite(linkLight2Pin, LOW);
  }
}
