#include <Adafruit_NeoPixel.h>

#define LEDPIN 6
#define PIRPIN 8
#define NUM_LEDS 60
#define BRIGHTNESS 50

volatile byte motionDetected;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LEDPIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  attachInterrupt(0, motionDetectedInterrupt, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:

 if(motionDetected){
   Serial.println("Motion detected handled.");
   motionDetected = false;
 }
}



void motionDetectedInterrupt(){
 if(motionDetected<255)
  motionDetected++;
}
