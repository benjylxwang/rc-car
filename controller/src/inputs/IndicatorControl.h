#ifndef INDICATOR_CONTROL_H
#define INDICATOR_CONTROL_H

#include <Arduino.h>

class IndicatorControl
{
public:
    IndicatorControl(byte leftPin, byte rightPin, byte mode = INPUT, bool invert = false);

    void setup();
    int8_t get();
private:
    byte leftPin;
    byte rightPin;

    bool invert;
    byte mode;
};

#endif