#include <Arduino.h>
#include <iostream>
#include <sstream>
#include <Adafruit_NeoPixel.h>
#include "LightManager.h"
using namespace std;

#define NEOLED_PIN 12
//const int nbrOfLeds = 400;

// Private:

uint32_t LightManager::parseColor(string rgbString)
{
    int r, g, b;

    if (rgbString.at(0) == '#')
    {
        rgbString = rgbString.erase(0, 1);
    }
    std::istringstream(rgbString.substr(0, 2)) >> std::hex >> r;
    std::istringstream(rgbString.substr(2, 2)) >> std::hex >> g;
    std::istringstream(rgbString.substr(4, 2)) >> std::hex >> b;
    return (Adafruit_NeoPixel::Color(r, g, b));
}

// Public:

// ================================ Constructor ================================
LightManager::LightManager(int nbrOfLeds = 350, int brightness = 64)
{
    Serial.begin(115200);
    Serial.print("init");

    strip = Adafruit_NeoPixel(nbrOfLeds, NEOLED_PIN, NEO_GRB + NEO_KHZ800);
    strip.begin();
    strip.setBrightness(brightness);
    Serial.print("initialised");
}

void LightManager::off()
{
    strip.clear();
    strip.show();
}

void LightManager::fillColor(const string rgbString)
{
    strip.fill(parseColor(rgbString));
    strip.show();
}

void LightManager::setColor(const int led, string rgbString)
{
    strip.setPixelColor(led, parseColor(rgbString));
    strip.show();
}

void LightManager::setColor(int* leds, int ledsSize, string rgbString)
{
    uint32_t color = parseColor(rgbString);
    for (int i = 0; i < ledsSize; i++)
    {
        strip.setPixelColor(leds[i], color);
    }
    strip.show();
}
