#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>
#include "../state.h"

class Lights
{
public:
    Lights(byte headlightsPin, byte brakelightsPin, byte indicatorLeftPin, byte indicatorRightPin);

    void setup();
    void update(State state);

private:
    // pins
    byte headlights;
    byte brakelights;
    byte indicatorLeft;
    byte indicatorRight;

    // state
    bool isAutomatic;
    bool isLightOn;

    // Indicators state
    bool indicatorLightState;
    unsigned long startTime;

    // helpers
    void lightsOn();
    void lightsOff();

    void flashIndicator(byte pin);
};

#endif