#include <Arduino.h>
#include "Lightmanager.h"
#include <ArduinoJson.h>

using namespace std;

// declarations:
#define NEOLED_PIN 12
#define NBR_LEDS 350

//const int nbrOfLeds = 350;
int brightness = 1;

const string testJson =
    "[{\"color\":\"#ffffff\",\"indexes\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20],\"time\":1000},{\"color\":\"#ffff00\",\"indexes\":[0,2,4,6,8,10,12,14,16,18,20],\"time\":1000},{\"color\":\"#ff00ff\",\"indexes\":[0,2,4,6,8,10,12,14,16,18,20],\"time\":1000},{\"color\":\"#00ffff\",\"indexes\":[0,2,4,6,8,10,12,14,16,18,20],\"time\":1000}]";

LightManager lightManager(NBR_LEDS, brightness);

void setup()
{
    Serial.begin(115200);
    // put your setup code here, to run once:
    // delay(1000);
    //lightManager.fillColor("#FF0000");

    JsonDocument doc;
    deserializeJson(doc, testJson);
    int instructionsSize = doc.size();
    int currentInstruction = 0;

    bool quit = false;
    while (!quit)
    {
        deserializeJson(doc, testJson);
        lightManager.setColor(doc[currentInstruction]["indexes"], doc[currentInstruction]["color"]);
        //Serial.println(doc[currentInstruction]["indexes"] + " " + doc[currentInstruction]["color"] + " " + doc[currentInstruction]["time"] );
        delay(doc[currentInstruction]["time"]);

        currentInstruction = (currentInstruction + 1) % instructionsSize;
    }
}

void loop()
{
}
