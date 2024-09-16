#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <iostream>
#include <sstream>
#include "Lightmanager.h"

using namespace std;

// declarations:

const int nbrOfLeds = 400;
int brightness = 1;
#define NEOLED_PIN 12


LightManager lightManager(350, 2);

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  // delay(1000);
  lightManager.fillColor("#FF0000");
}

void loop() {
  // put your main code here, to run repeatedly:
  lightManager.fillColor("#ff0000");
  delay(1000);
  lightManager.fillColor("#00ff00");
  delay(1000);
  lightManager.fillColor("#0000ff");
  delay(1000);
  Serial.print("working");
}

// class NeoPixel {
// private:
//   int rgb[3];

// public:
//   NeoPixel() { std::fill(rgb, rgb + 3, 0); };

//   void SetColor(string rgbString) {
//     // Remove the hashtag ...
//     if (rgbString.at(0) == '#') {
//       rgbString = rgbString.erase(0, 1);
//     }
//     // ... and extract the rgb values.
//     std::istringstream(rgbString.substr(0, 2)) >> std::hex >> rgb[0];
//     std::istringstream(rgbString.substr(2, 2)) >> std::hex >> rgb[1];
//     std::istringstream(rgbString.substr(4, 2)) >> std::hex >> rgb[2];
//   }

//   void write(){
//     neopixelWrite(pin, red, green, blue)
//   }
// };
