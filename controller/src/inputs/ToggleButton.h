#ifndef TOGGLE_BUTTON_H
#define TOGGLE_BUTTON_H

#include <Arduino.h>

class ToggleButton
{
public:
    ToggleButton(byte pin_, byte inputType_ = INPUT, bool invert_ = false)
    {
        pin = pin_;
        inputType = inputType_;
        invert = invert_;
        lastState = false;
    }

    void setup();
    bool get();
private:
    byte pin;

    bool lastState;

    // Settings
    byte inputType;
    bool invert;
};

#endif