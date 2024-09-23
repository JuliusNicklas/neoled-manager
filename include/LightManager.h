#ifndef LIGHT_MANAGER
#define LIGHT_MANAGER

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

using namespace std;

class LightManager
{
private:
    // Values
    Adafruit_NeoPixel strip;

    // Methods
    static uint32_t parseColor(string rgbString);

public:
    // Values
    // Methods
    LightManager(int nbrOfLeds, int brightness);
    void off();
    void fillColor(const string rgbString);
    void setColor(int led, const string rgbString);
    void setColor(int leds[], int ledsSize, string rgbString);
};

#endif
