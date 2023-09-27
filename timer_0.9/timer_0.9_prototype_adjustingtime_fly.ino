/*
  Count down timer.
  NODE MCU WITH DEACTIVATED WIFI, Rotary Encoder with button and LED RING.
 
  Made By Charles Busmanis.
  Version 0.9 MVP
*/


// –––––––––––––––––– //

// Wiring Diagram
// NODE MCU
// | A0       D0 |
// | RSV      D1 |------ ROTARY CLK (pulse/direction of rotation)
// | RSV      D2 |------ ROTARY DT (pulse/dierction of rotation)
// | SD3      D3 |------ ROTARY SW (button clidk)
// | SD2      D4 |------ LED RING IN
// | SD1     3V3 |
// | CMD     GND |
// | SD0      D5 | 
// | CLK      D6 |
// ROTARY GND  ------| GND      D7 |
// ROTARY +  ------| 3V3      D8 |
// | EN       RX |
// | RST      TX |
// LED RING GND  ------| GND     GND |
// LED RING VCC  ------| VIN     3V3 |

#include <FastLED.h>  // led control library
#include <RotaryEncoder.h> // encoder library

#define FASTLED_ALLOW_INTERRUPTS 0
#define LED_TYPE WS2812
#define CHIPSET WS2812
#define DATA_PIN 4  // led ring
#define COLOR_ORDER GRB
#define NUM_LEDS 60
CRGB leds[NUM_LEDS];

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 30
#define COOLING 70
#define SPARKING 150

bool gReverseDirection = false;
unsigned long debounceTimer = 0;

CRGBPalette16 gPal;
CRGBPalette16 timedownPal;

const byte CLKPin = D1;
const byte DTpin = D2;
const byte SWpin = D3;

RotaryEncoder encoder(CLKPin, DTpin, RotaryEncoder::LatchMode::TWO03);

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 20;
int lastEncoderValue = 0;

volatile int encdir = 0; 

int counter = 1;
int aState;
int aLastState;
int buttonState = 0;
int lastbuttonState = 0;
int startCountdown = 0;
int timer = 1000;
int whiteLed = 0; 
int encoderPos = 0;
