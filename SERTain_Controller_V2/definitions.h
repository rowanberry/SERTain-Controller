
// all definitions for SERTain controller go here

#ifndef definitions//if the following hasn't yet been declared
#define definitions
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define enablePin 40
#define preset1Pin 34
#define preset2Pin 32
#define preset3Pin 36
#define preset4Pin 38
#define preset1LightPin 28
#define preset2LightPin 31
#define preset3LightPin 35
#define preset4LightPin 24
#define link1Pin 27
#define link2Pin 25
#define linkLight1Pin 30
#define linkLight2Pin 33
#define slowModePin 65
#define accelerationPin 64
#define motor1OnPin 50
#define motor2OnPin 46
#define motor3OnPin 69
#define motor4OnPin 42
#define motor1ReversePin 48
#define motor2ReversePin 68
#define motor3ReversePin 53
#define motor4ReversePin 13
#define motor1PWMPin 9
#define motor2PWMPin 10
#define motor3PWMPin 11
#define motor4PWMPin 12
#define rotaryPinA 33
#define rotaryPinB 16
#define rotaryButtonPin 29
#define slider1SweepPin A4
#define slider2SweepPin A5
#define slider3SweepPin A7
#define slider4SweepPin A6
#define sliderMotor1SpeedPin 2
#define sliderMotor2SpeedPin 3
#define sliderMotor3SpeedPin 5
#define sliderMotor4SpeedPin 4
#define sliderMotor1ForwardsPin 45
#define sliderMotor2ForwardsPin 51
#define sliderMotor3ForwardsPin 37
#define sliderMotor4ForwardsPin 41
#define sliderMotor1BackwardsPin 47
#define sliderMotor2BackwardsPin 52
#define sliderMotor3BackwardsPin 38
#define sliderMotor4BackwardsPin 43
#define blinkyPin 26
#define comSignalPin 6
#define dead_zone 60
LiquidCrystal_I2C lcd(0x3F,16,2);
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
bool enabled = false;
int presetNum = 0;
bool preset1LightOn = false;
bool preset2LightOn = false;
bool preset3LightOn = false;
bool preset4LightOn = false;
bool link1Pressed = false;
bool link2Pressed = false;
bool link1On = false;
bool link2On = false;
bool linkLight1On = false;
bool linkLight2On = false;
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
bool motor1Reverse = false;
bool motor2Reverse = false;
bool motor3Reverse = false;
bool motor4Reverse = false;
int motor1Val = 0;
int motor2Val = 0;
int motor3Val = 0;
int motor4Val = 0;
int motor1Speed = 0;
int motor2Speed = 0;
int motor3Speed = 0;
int motor4Speed = 0;
int rotaryPos = 0;
bool rotaryButtonPressed = false;
int slider1Set = 0;
int slider2Set = 0;
int slider3Set = 0;
int slider4Set = 0;
int slider1Val = 0;
int slider2Val = 0;
int slider3Val = 0;
int slider4Val = 0;
int slider1Touch = 0;
int slider2Touch = 0;
int slider3Touch = 0;
int slider4Touch = 0;
bool slider1Touched = false;
bool slider2Touched = false;
bool slider3Touched = false;
bool slider4Touched = false;
bool menuOpen = false;
int menuNum = 0;
int sliderNum = 0;
int ref1, ref2, ref3, ref4;
int loops = 0;
int neopixel1[] = {0, 1, 2, 3, 4, 5, 6, 7};
int neopixel2[] = {15, 14, 13, 12, 11, 10, 9, 8};
int neopixel3[] = {16, 17, 18, 19, 20, 21, 22, 23};
int neopixel4[] = {31, 30, 29, 28, 27, 26, 25, 24};
int hue = 0;
int sat = 255;
int val = 255;
int scaleFactor = 0;
int slider1Mapped06 = 0;
int slider2Mapped06 = 0;
int slider3Mapped06 = 0;
int slider4Mapped06 = 0;
int sliderMotor1Speed = 0;
int sliderMotor2Speed = 0;
int sliderMotor3Speed = 0;
int sliderMotor4Speed = 0;
bool sliderMotor1Forwards = false;
bool sliderMotor2Forwards = false;
bool sliderMotor3Forwards = false;
bool sliderMotor4Forwards = false;
int slider1Error = 0;
int slider2Error = 0;
int slider3Error = 0;
int slider4Error = 0;
int slider1ErrorSum = 0;
int slider2ErrorSum = 0;
int slider3ErrorSum = 0;
int slider4ErrorSum = 0;
short slider1Output = 0;
short slider2Output = 0;
short slider3Output = 0;
short slider4Output = 0;
int slider1dError = 0;
int slider2dError = 0;
int slider3dError = 0;
int slider4dError = 0;
int slider1OldError = 0;
int slider2OldError = 0;
int slider3OldError = 0;
int slider4OldError = 0;


long lastPid = 0;
long pidTime = 0;

#endif
