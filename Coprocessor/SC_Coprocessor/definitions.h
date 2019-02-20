
// all definitions for SERTain controller go here

#ifndef definitions//if the following hasn't yet been declared
#define definitions
#include <ADCTouch.h>
#include <FastLED.h>
#include <Wire.h> 
#define slider1TouchPin A0
#define slider2TouchPin A1
#define slider3TouchPin A2
#define slider4TouchPin A3
#define neopixelPin 6
CRGB leds[32];
bool link1On = false;
bool link2On = false;
bool slowModeOn = false;
bool accelerates = false;
bool motor1On = false;
bool motor2On = false;
bool motor3On = false;
bool motor4On = false;
int motor1Direction = 0;
int motor2Direction = 0;
int motor3Direction = 0;
int motor4Direction = 0;
int slider1Set = 0;
int slider2Set = 0;
int slider3Set = 0;
int slider4Set = 0;
int slider1Touch = 0;
int slider2Touch = 0;
int slider3Touch = 0;
int slider4Touch = 0;
bool slider1Touched = false;
bool slider2Touched = false;
bool slider3Touched = false;
bool slider4Touched = false;
int neopixel1[] = {0, 1, 2, 3, 4, 5, 6, 7};
int neopixel2[] = {15, 14, 13, 12, 11, 10, 9, 8};
int neopixel3[] = {16, 17, 18, 19, 20, 21, 22, 23};
int neopixel4[] = {31, 30, 29, 28, 27, 26, 25, 24};
int hue = 0;
int sat = 255;
int val = 255;
#endif
