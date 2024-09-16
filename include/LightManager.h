#ifndef LIGHT_MANAGER
#define LIGHT_MANAGER

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

using namespace std;

class LightManager {
private:
// Values
  Adafruit_NeoPixel strip;
  
// Methods
  uint32_t parseColor(string rgbString);

public:
// Values
// Methods
  LightManager(int nbrOfLeds, int brightness);
  void off();
  void fillColor(string rgbString);
  void setColor(int led, string rgbString);
  void setColor(int leds[], string rgbString);
};

#endif